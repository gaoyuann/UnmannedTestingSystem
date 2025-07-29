#ifndef DBUTIL_H
#define DBUTIL_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QVariant>
#include <QVector>
#include <QMap>
#include <QSettings>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QStandardPaths>

class DBUtil : public QObject
{
    Q_OBJECT

public:
    enum DBType {
        SQLITE,
        MYSQL,
        POSTGRESQL
    };

    static DBUtil* instance();

    // 初始化方法
    bool initFromConfig(const QString &configPath = "");
    bool init(DBType type, const QString &host, const QString &database,
              const QString &username, const QString &password, int port,
              const QString &connectionName = "qt_sql_default_connection");

    // 数据库操作
    int execute(const QString &sql, const QVariantMap &params = QVariantMap());
    QVector<QVariantMap> query(const QString &sql, const QVariantMap &params = QVariantMap());
    QVariant querySingleValue(const QString &sql, const QVariantMap &params = QVariantMap());

    // 事务管理
    bool beginTransaction();
    bool commitTransaction();
    bool rollbackTransaction();

    // 实用功能
    bool tableExists(const QString &tableName);
    QString lastExecutedQuery() const;
    QString lastError() const;
    bool isConnectionValid();
    bool isInitialized() const;

private:
    explicit DBUtil(QObject *parent = nullptr);
    ~DBUtil();

    QSqlDatabase getDatabase() const;
    void bindValues(QSqlQuery &query, const QVariantMap &params);
    QVector<QVariantMap> resultToMapList(QSqlQuery &query);
    void logError(const QString &message);
    bool validateConfig(QSettings &settings);
    QString findConfigFile();

    static DBUtil* m_instance;
    QString m_connectionName;
    DBType m_dbType;
    QString m_lastQuery;
    QString m_lastError;
    bool m_initialized;
};

#endif // DBUTIL_H
