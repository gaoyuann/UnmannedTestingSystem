#include "DBUtil.h"

DBUtil* DBUtil::m_instance = nullptr;

DBUtil::DBUtil(QObject *parent) : QObject(parent),
    m_dbType(MYSQL),
    m_initialized(false)
{
}

DBUtil::~DBUtil()
{
    if (QSqlDatabase::contains(m_connectionName)) {
        QSqlDatabase::removeDatabase(m_connectionName);
    }
}

DBUtil* DBUtil::instance()
{
    if (!m_instance) {
        m_instance = new DBUtil();
    }
    return m_instance;
}

bool DBUtil::initFromConfig(const QString &configPath)
{
    QString actualConfigPath = configPath;
    if (actualConfigPath.isEmpty()) {
        actualConfigPath = findConfigFile();
        if (actualConfigPath.isEmpty()) {
            m_lastError = "无法找到配置文件";
            return false;
        }
    }

    QSettings settings(actualConfigPath, QSettings::IniFormat);

    if (!validateConfig(settings)) {
        return false;
    }

    QString typeStr = settings.value("Database/Type").toString().toLower();
    DBType type = MYSQL;
    if (typeStr == "sqlite") type = SQLITE;
    else if (typeStr == "postgresql") type = POSTGRESQL;

    return init(
        type,
        settings.value("Database/Host").toString(),
        settings.value("Database/Name").toString(),
        settings.value("Database/Username").toString(),
        settings.value("Database/Password").toString(),
        settings.value("Database/Port").toInt(),
        settings.value("Database/ConnectionName", "tencent_cloud_connection").toString()
        );
}

bool DBUtil::init(DBType type, const QString &host, const QString &database,
                  const QString &username, const QString &password, int port,
                  const QString &connectionName)
{
    m_dbType = type;
    m_connectionName = connectionName;
    m_lastQuery.clear();
    m_lastError.clear();
    m_initialized = false;

    // 检查驱动
    qDebug() << "可用数据库驱动:" << QSqlDatabase::drivers();
    if (m_dbType == MYSQL && !QSqlDatabase::isDriverAvailable("QMYSQL")) {
        m_lastError = "MySQL 驱动不可用";
        logError(m_lastError);
        return false;
    }

    // 清理现有连接
    if (QSqlDatabase::contains(m_connectionName)) {
        QSqlDatabase::removeDatabase(m_connectionName);
    }

    // 创建数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase(
        m_dbType == SQLITE ? "QSQLITE" :
            m_dbType == MYSQL ? "QMYSQL" : "QPSQL",
        m_connectionName
        );

    // 设置连接参数
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(username);
    db.setPassword(password);
    if (port > 0) db.setPort(port);

    // MySQL特定设置
    if (m_dbType == MYSQL) {
        db.setConnectOptions("MYSQL_OPT_RECONNECT=1;MYSQL_OPT_CONNECT_TIMEOUT=3;MYSQL_OPT_READ_TIMEOUT=10");
    }

    // 尝试连接
    if (!db.open()) {
        m_lastError = QString("数据库连接失败: %1").arg(db.lastError().text());
        logError(m_lastError);
        return false;
    }

    // MySQL连接初始化
    if (m_dbType == MYSQL) {
        QSqlQuery query(db);
        if (!query.exec("SET NAMES 'utf8mb4'")) {
            logError(QString("设置字符集失败: %1").arg(query.lastError().text()));
        }
        if (!query.exec("SET time_zone = '+8:00'")) {
            logError(QString("设置时区失败: %1").arg(query.lastError().text()));
        }
    }

    m_initialized = true;
    return true;
}

int DBUtil::execute(const QString &sql, const QVariantMap &params)
{
    if (!m_initialized) {
        m_lastError = "数据库未初始化";
        return -1;
    }

    m_lastQuery = sql;
    m_lastError.clear();

    QSqlDatabase db = getDatabase();
    QSqlQuery query(db);

    if (!query.prepare(sql)) {
        m_lastError = query.lastError().text();
        logError(QString("SQL准备失败: %1\nSQL: %2").arg(m_lastError).arg(sql));
        return -1;
    }

    bindValues(query, params);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        logError(QString("执行SQL失败: %1\nSQL: %2").arg(m_lastError).arg(sql));
        return -1;
    }

    return query.numRowsAffected();
}

QVector<QVariantMap> DBUtil::query(const QString &sql, const QVariantMap &params)
{
    if (!m_initialized) {
        m_lastError = "数据库未初始化";
        return QVector<QVariantMap>();
    }

    m_lastQuery = sql;
    m_lastError.clear();

    QSqlDatabase db = getDatabase();
    QSqlQuery query(db);

    if (!query.prepare(sql)) {
        m_lastError = query.lastError().text();
        logError(QString("SQL准备失败: %1\nSQL: %2").arg(m_lastError).arg(sql));
        return QVector<QVariantMap>();
    }

    bindValues(query, params);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        logError(QString("查询SQL失败: %1\nSQL: %2").arg(m_lastError).arg(sql));
        return QVector<QVariantMap>();
    }

    return resultToMapList(query);
}

QVariant DBUtil::querySingleValue(const QString &sql, const QVariantMap &params)
{
    QVector<QVariantMap> result = query(sql, params);
    if (result.isEmpty() || result.first().isEmpty()) {
        return QVariant();
    }
    return result.first().first();
}

bool DBUtil::beginTransaction()
{
    if (!m_initialized) {
        m_lastError = "数据库未初始化";
        return false;
    }
    return getDatabase().transaction();
}

bool DBUtil::commitTransaction()
{
    if (!m_initialized) {
        m_lastError = "数据库未初始化";
        return false;
    }
    return getDatabase().commit();
}

bool DBUtil::rollbackTransaction()
{
    if (!m_initialized) {
        m_lastError = "数据库未初始化";
        return false;
    }
    return getDatabase().rollback();
}

bool DBUtil::tableExists(const QString &tableName)
{
    if (!m_initialized) {
        m_lastError = "数据库未初始化";
        return false;
    }

    QString sql;
    switch (m_dbType) {
    case SQLITE:
        sql = QString("SELECT name FROM sqlite_master WHERE type='table' AND name='%1'").arg(tableName);
        break;
    case MYSQL:
        sql = QString("SHOW TABLES LIKE '%1'").arg(tableName);
        break;
    case POSTGRESQL:
        sql = QString("SELECT tablename FROM pg_tables WHERE tablename = '%1'").arg(tableName);
        break;
    default:
        return false;
    }

    QVariant result = querySingleValue(sql);
    return !result.isNull();
}

QString DBUtil::lastExecutedQuery() const
{
    return m_lastQuery;
}

QString DBUtil::lastError() const
{
    return m_lastError;
}

bool DBUtil::isConnectionValid()
{
    if (!m_initialized) return false;
    QSqlQuery query(getDatabase());
    return query.exec("SELECT 1");
}

bool DBUtil::isInitialized() const
{
    return m_initialized;
}

QSqlDatabase DBUtil::getDatabase() const
{
    return QSqlDatabase::database(m_connectionName);
}

void DBUtil::bindValues(QSqlQuery &query, const QVariantMap &params)
{
    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }
}

QVector<QVariantMap> DBUtil::resultToMapList(QSqlQuery &query)
{
    QVector<QVariantMap> result;
    const QSqlRecord record = query.record();
    const int columnCount = record.count();

    while (query.next()) {
        QVariantMap row;
        for (int i = 0; i < columnCount; ++i) {
            row.insert(record.fieldName(i), query.value(i));
        }
        result.append(row);
    }

    return result;
}

void DBUtil::logError(const QString &message)
{
    QString log = QString("[%1] %2")
    .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
        .arg(message);

    qCritical() << log;

    QFile file("database_error.log");
    if (file.open(QIODevice::Append)) {
        file.write(log.toUtf8() + "\n");
        file.close();
    }
}

bool DBUtil::validateConfig(QSettings &settings)
{
    QStringList requiredFields = {
        "Database/Type", "Database/Host",
        "Database/Name", "Database/Username",
        "Database/Password", "Database/Port"
    };

    foreach (const QString &field, requiredFields) {
        if (!settings.contains(field)) {
            m_lastError = QString("缺少必要的配置字段: %1").arg(field);
            return false;
        }
    }
    return true;
}

QString DBUtil::findConfigFile()
{
    // 1. 当前目录
    QString localConfig = "config.ini";
    if (QFile::exists(localConfig)) {
        return localConfig;
    }

    // 2. 应用配置目录
    QString appDataConfig = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/config.ini";
    if (QFile::exists(appDataConfig)) {
        return appDataConfig;
    }

    return QString();
}
