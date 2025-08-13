#include "UserManageWindow.h"
#include "ui_UserManageWindow.h"
#include "DBUtil.h"
#include "UserDialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

UserManageWindow::UserManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManageWindow),
    m_currentPage(1),
    m_pageSize(10),
    m_totalCount(0),
    m_totalPages(0)
{
    ui->setupUi(this);
    setupConnections();
    initTable();

    // 先隐藏窗口，加载完数据再显示
    this->hide();
    loadUserData();
    this->show();  // 数据加载完成后再显示
}

UserManageWindow::~UserManageWindow()
{
    delete ui;
}

void UserManageWindow::setupConnections()
{
    connect(ui->btnBack, &QPushButton::clicked,
            this, &UserManageWindow::onBtnBackClicked);
    connect(ui->btnAdd, &QPushButton::clicked,
            this, &UserManageWindow::onBtnAddClicked);
    connect(ui->btnEdit, &QPushButton::clicked,
            this, &UserManageWindow::onBtnEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked,
            this, &UserManageWindow::onBtnDeleteClicked);
    connect(ui->btnSearch, &QPushButton::clicked,
            this, &UserManageWindow::onBtnSearchClicked);
    connect(ui->btnFirst, &QPushButton::clicked,
            this, &UserManageWindow::onBtnFirstClicked);
    connect(ui->btnPrev, &QPushButton::clicked,
            this, &UserManageWindow::onBtnPrevClicked);
    connect(ui->btnNext, &QPushButton::clicked,
            this, &UserManageWindow::onBtnNextClicked);
    connect(ui->btnLast, &QPushButton::clicked,
            this, &UserManageWindow::onBtnLastClicked);
    connect(ui->comboPageSize, &QComboBox::currentTextChanged,
            this, &UserManageWindow::onComboPageSizeChanged);
    connect(ui->comboPage, &QComboBox::currentIndexChanged,
            this, &UserManageWindow::onComboPageChanged);
}

void UserManageWindow::initTable()
{
    // 设置表格属性
    ui->tableUsers->horizontalHeader()->setStretchLastSection(true);
    ui->tableUsers->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableUsers->setColumnWidth(0, 40);  // 选择框列
    ui->tableUsers->setColumnWidth(1, 120); // 用户名
    ui->tableUsers->setColumnWidth(2, 120); // 真实姓名
    ui->tableUsers->setColumnWidth(3, 150); // 所属机构
    ui->tableUsers->setColumnWidth(4, 120); // 联系电话
    ui->tableUsers->setColumnWidth(5, 80);  // 状态
    ui->tableUsers->setColumnWidth(6, 150); // 权限

    // 初始化分页控件
    ui->comboPageSize->setCurrentText("10 条/页");

    connect(ui->tableUsers, &QTableWidget::cellClicked, this, [=](int row, int col) {
        // 点击任意单元格时，同步复选框状态
        QTableWidgetItem* checkItem = ui->tableUsers->item(row, 0);
        if (checkItem) {
            Qt::CheckState newState = (checkItem->checkState() == Qt::Checked)
            ? Qt::Unchecked
            : Qt::Checked;
            checkItem->setCheckState(newState);
        }
    });
}

void UserManageWindow::loadUserData(const QString &keyword)
{
    // 清空表格
    ui->tableUsers->setRowCount(0);

    // 获取用户数据
    QVector<QVariantMap> users = getUsers(m_currentPage, m_pageSize, keyword);
    m_totalCount = getUserCount(keyword);
    m_totalPages = qMax(1, (m_totalCount + m_pageSize - 1) / m_pageSize);

    // 填充表格
    for (int i = 0; i < users.size(); ++i) {
        const QVariantMap &user = users[i];
        int row = ui->tableUsers->rowCount();
        ui->tableUsers->insertRow(row);

        // 复选框
        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        checkItem->setData(Qt::UserRole, user["user_id"]);
        ui->tableUsers->setItem(row, 0, checkItem);

        // 用户名（对应user_name）
        ui->tableUsers->setItem(row, 1, new QTableWidgetItem(user["user_name"].toString()));

        // 真实姓名（对应real_name）
        ui->tableUsers->setItem(row, 2, new QTableWidgetItem(user["real_name"].toString()));

        // 所属机构（对应org_id，转换为机构名称）
        ui->tableUsers->setItem(row, 3, new QTableWidgetItem(getOrganizationName(user["org_id"].toInt())));

        // 联系电话（对应phone）
        ui->tableUsers->setItem(row, 4, new QTableWidgetItem(user["phone"].toString()));

        // 状态（对应status，转换为状态文本）
        ui->tableUsers->setItem(row, 5, new QTableWidgetItem(getStatusText(user["status"].toInt())));

        // 权限（根据业务逻辑获取）
        ui->tableUsers->setItem(row, 6, new QTableWidgetItem(getPermissionText(user["user_id"].toInt())));

        // 设置单元格不可编辑
        for (int col = 1; col < 7; ++col) {
            ui->tableUsers->item(row, col)->setFlags(ui->tableUsers->item(row, col)->flags() & ~Qt::ItemIsEditable);
        }
    }

    updatePagination();
}

void UserManageWindow::updatePagination()
{
    // 更新页码信息
    ui->labelPageInfo->setText(QString("第 %1 页 / 共 %2 页 (%3 条)")
                                   .arg(m_currentPage)
                                   .arg(m_totalPages)
                                   .arg(m_totalCount));

    // 更新页码下拉框
    ui->comboPage->clear();
    for (int i = 1; i <= m_totalPages; ++i) {
        ui->comboPage->addItem(QString::number(i));
    }
    ui->comboPage->setCurrentIndex(m_currentPage - 1);

    // 禁用/启用分页按钮
    ui->btnFirst->setEnabled(m_currentPage > 1);
    ui->btnPrev->setEnabled(m_currentPage > 1);
    ui->btnNext->setEnabled(m_currentPage < m_totalPages);
    ui->btnLast->setEnabled(m_currentPage < m_totalPages);
}

QVector<QVariantMap> UserManageWindow::getUsers(int page, int pageSize, const QString &keyword)
{
    // 1. 参数合法性验证（核心修复）
    if (page < 1) page = 1; // 确保页码至少为1
    if (pageSize <= 0 || pageSize > 1000) pageSize = 10; // 限制每页条数为1-1000

    // 2. 计算偏移量（避免负数）
    qint64 offset = (page - 1) * pageSize;
    if (offset < 0) offset = 0; // 确保偏移量非负

    // 3. 构建查询SQL
    QString sql = "SELECT * FROM user WHERE 1=1 ";
    QVariantMap params;

    // 处理搜索关键词
    if (!keyword.isEmpty()) {
        sql += "AND (user_name LIKE :keyword OR real_name LIKE :keyword OR phone LIKE :keyword) ";
        params["keyword"] = "%" + keyword + "%";
    }

    // 4. 绑定LIMIT和OFFSET（确保类型为整数）
    sql += "ORDER BY user_id DESC LIMIT :limit OFFSET :offset";
    params["limit"] = pageSize;       // 绑定为整数类型
    params["offset"] = offset;        // 绑定为整数类型（使用qint64避免溢出）

    // 5. 执行查询
    QVector<QVariantMap> result = DBUtil::instance()->query(sql, params);
    if (DBUtil::instance()->lastError().isEmpty()) {
        qWarning() << "查询用户失败：" << DBUtil::instance()->lastError()
            << "SQL:" << sql << "Params:" << params;
    }
    return result;
}

int UserManageWindow::getUserCount(const QString &keyword)
{
    QString sql = "SELECT COUNT(*) AS count FROM user WHERE 1=1";
    QVariantMap params;

    if (!keyword.isEmpty()) {
        sql += " AND (user_name LIKE :keyword OR real_name LIKE :keyword)";
        params["keyword"] = "%" + keyword + "%";
    }

    QVariant result = DBUtil::instance()->querySingleValue(sql, params);
    return result.toInt();
}

QString UserManageWindow::getOrganizationName(int orgId)
{
    if (orgId <= 0) return "";

    QString sql = "SELECT org_name FROM organization WHERE org_id = :org_id";
    QVariantMap params;
    params["org_id"] = orgId;

    QVariant result = DBUtil::instance()->querySingleValue(sql, params);
    return result.toString();
}

QString UserManageWindow::getStatusText(int status)
{
    QString sql = "SELECT dict_value FROM data_dictionary WHERE dict_type = 'user_status' AND dict_key = :status";
    QVariantMap params;
    params["status"] = status;

    QVariant result = DBUtil::instance()->querySingleValue(sql, params);
    return result.toString();
}

QString UserManageWindow::getPermissionText(int userId)
{
    QString sql = "SELECT p.permission_name FROM permission p "
                  "JOIN user_permission up ON p.permission_id = up.permission_id "
                  "WHERE up.user_id = :user_id";
    QVariantMap params;
    params["user_id"] = userId;

    QVector<QVariantMap> permissions = DBUtil::instance()->query(sql, params);

    QStringList permissionNames;
    for (const auto &perm : permissions) {
        permissionNames << perm["permission_name"].toString();
    }

    return permissionNames.join("; ");
}

void UserManageWindow::onBtnAddClicked()
{
    // 创建新增用户对话框
    UserDialog dialog(this, UserDialog::NewUser);
    dialog.setWindowTitle("新增用户");

    // 显示对话框，等待用户输入
    if (dialog.exec() == QDialog::Accepted) {
        // 获取用户输入的数据
        UserDialog::UserData dialogData = dialog.getUserData();
        UserInfo user = getUserInfoFromDialog(dialogData);

        // 插入数据库
        if (addUserToDB(user)) {
            QMessageBox::information(this, "成功", "用户添加成功！");
            loadUserData(ui->lineSearch->text().trimmed());  // 刷新列表
            emit statusMessageRequested("新增用户成功", 2000);
        } else {
            QMessageBox::critical(this, "失败", "用户添加失败：" + DBUtil::instance()->lastError());
        }
    }
}

void UserManageWindow::onBtnEditClicked()
{
    // 获取选中的用户
    UserInfo user = getSelectedUserInfo();
    if (user.id == -1) {
        QMessageBox::warning(this, "提示", "请选择要编辑的用户");
        return;
    }

    // 转换为UserDialog需要的数据格式（仅保留数据库存在的字段）
    UserDialog::UserData dialogData;
    dialogData.username = user.username;
    dialogData.name = user.realName;
    dialogData.phone = user.phone;
    dialogData.password = "";  // 编辑模式初始密码为空（不修改密码）

    // 创建编辑模式的对话框
    UserDialog dialog(this, UserDialog::EditUser, dialogData);
    dialog.setWindowTitle("编辑用户");
    dialog.setOrgId(user.orgId);  // 设置当前所属机构（新增）

    // 显示对话框
    if (dialog.exec() == QDialog::Accepted) {
        // 更新用户数据
        UserDialog::UserData updatedData = dialog.getUserData();
        UserInfo updatedUser = getUserInfoFromDialog(updatedData, user.id);

        // 从对话框获取更新后的机构ID（替换原有逻辑）
        updatedUser.orgId = dialog.getOrgId();
        updatedUser.status = user.status;  // 保持原有状态（状态应通过单独功能修改）

        // 更新数据库
        if (updateUserInDB(updatedUser)) {
            QMessageBox::information(this, "成功", "用户更新成功！");
            loadUserData(ui->lineSearch->text().trimmed());  // 刷新列表
            emit statusMessageRequested("更新用户成功", 2000);
        } else {
            QMessageBox::critical(this, "失败", "用户更新失败：" + DBUtil::instance()->lastError());
        }
    }
}

// 辅助函数：将UserDialog数据转换为内部UserInfo
UserManageWindow::UserInfo UserManageWindow::getUserInfoFromDialog(const UserDialog::UserData &dialogData, int id)
{
    UserInfo user;
    user.id = id;
    user.username = dialogData.username;
    user.realName = dialogData.name;
    user.phone = dialogData.phone;
    user.password = dialogData.password; // 新增密码
    user.orgId = 1;  // 默认机构ID（实际应从界面选择）
    user.status = 1; // 默认状态为正常（1-正常，0-禁用）
    return user;
}

// 数据库操作：添加用户
bool UserManageWindow::addUserToDB(const UserInfo &user)
{
    QString sql = "INSERT INTO user ("
                  "user_name, password, real_name, org_id, phone, status, create_time, update_time"
                  ") VALUES ("
                  ":username, :password, :realName, :orgId, :phone, :status, NOW(), NOW()"
                  ")";

    QVariantMap params;
    params["username"] = user.username;
    params["password"] = user.password; // 新增密码字段
    params["realName"] = user.realName;
    params["orgId"] = user.orgId;
    params["phone"] = user.phone;
    params["status"] = user.status;

    return DBUtil::instance()->execute(sql, params) > 0;
}


// 数据库操作：更新用户
bool UserManageWindow::updateUserInDB(const UserInfo &user)
{
    QString sql = "UPDATE user SET "
                  "user_name = :username, "
                  "real_name = :realName, "
                  "phone = :phone, "
                  "org_id = :orgId, "
                  "update_time = NOW()";

    // 编辑模式下如果输入了新密码，则更新密码
    if (!user.password.isEmpty()) {
        sql += ", password = :password";
    }

    sql += " WHERE user_id = :id";

    QVariantMap params;
    params["username"] = user.username;
    params["realName"] = user.realName;
    params["phone"] = user.phone;
    params["orgId"] = user.orgId;
    params["id"] = user.id;
    if (!user.password.isEmpty()) {
        params["password"] = user.password;
    }

    return DBUtil::instance()->execute(sql, params) > 0;
}


// 获取选中行的用户信息
UserManageWindow::UserInfo UserManageWindow::getSelectedUserInfo()
{
    UserInfo emptyUser;
    emptyUser.id = -1;  // 标记为无效

    // 获取选中行（保持不变）
    int currentRow = -1;
    for (int i = 0; i < ui->tableUsers->rowCount(); ++i) {
        if (ui->tableUsers->item(i, 0)->checkState() == Qt::Checked) {
            if (currentRow != -1) {
                QMessageBox::warning(this, "警告", "只能选择一条记录进行编辑");
                return emptyUser;
            }
            currentRow = i;
        }
    }

    if (currentRow == -1) {
        return emptyUser;
    }

    // 从表格获取基础信息（完整信息建议从数据库查询）
      int userId = ui->tableUsers->item(currentRow, 0)->data(Qt::UserRole).toInt();

    // 从数据库查询完整用户信息
    QString sql = "SELECT * FROM user WHERE user_id = :id";
    QVariantMap params;
    params["id"] = userId;

    QVector<QVariantMap> result = DBUtil::instance()->query(sql, params);
    if (result.isEmpty()) {
        return emptyUser;
    }

    QVariantMap userData = result[0];
    UserInfo user;
    user.id = userData["user_id"].toInt();
    user.username = userData["user_name"].toString();
    user.realName = userData["real_name"].toString();
    user.phone = userData["phone"].toString();
    user.password = userData["password"].toString(); // 新增密码
    user.orgId = userData["org_id"].toInt();
    user.status = userData["status"].toInt();

    return user;
}


void UserManageWindow::onBtnDeleteClicked()
{
    // 获取选中的行
    QVector<int> selectedIds;
    for (int i = 0; i < ui->tableUsers->rowCount(); ++i) {
        if (ui->tableUsers->item(i, 0)->checkState() == Qt::Checked) {
            selectedIds.append(ui->tableUsers->item(i, 0)->data(Qt::UserRole).toInt());
        }
    }

    if (selectedIds.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择要删除的用户");
        return;
    }

    if (QMessageBox::question(this, "确认", QString("确定要删除选中的 %1 个用户吗?").arg(selectedIds.size()),
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    emit statusMessageRequested("删除用户功能待实现", 2000);
    QMessageBox::information(this, "提示", "删除用户功能待实现");
}

void UserManageWindow::onBtnSearchClicked()
{
    QString keyword = ui->lineSearch->text().trimmed();
    m_currentPage = 1; // 搜索时重置到第一页
    loadUserData(keyword);
    emit statusMessageRequested(QString("搜索用户: %1").arg(keyword), 2000);
}

void UserManageWindow::onBtnFirstClicked()
{
    if (m_currentPage != 1) {
        m_currentPage = 1;
        loadUserData(ui->lineSearch->text().trimmed());
    }
}

void UserManageWindow::onBtnPrevClicked()
{
    if (m_currentPage > 1) {
        m_currentPage--;
        loadUserData(ui->lineSearch->text().trimmed());
    }
}

void UserManageWindow::onBtnNextClicked()
{
    if (m_currentPage < m_totalPages) {
        m_currentPage++;
        loadUserData(ui->lineSearch->text().trimmed());
    }
}

void UserManageWindow::onBtnLastClicked()
{
    if (m_currentPage != m_totalPages) {
        m_currentPage = m_totalPages;
        loadUserData(ui->lineSearch->text().trimmed());
    }
}

void UserManageWindow::onComboPageSizeChanged(const QString &text)
{
    int newSize = text.split(" ")[0].toInt();
    if (newSize != m_pageSize) {
        m_pageSize = newSize;
        m_currentPage = 1; // 改变每页条数时重置到第一页
        loadUserData(ui->lineSearch->text().trimmed());
    }
}

void UserManageWindow::onComboPageChanged(int index)
{
    int newPage = index + 1;
    if (newPage != m_currentPage) {
        m_currentPage = newPage;
        loadUserData(ui->lineSearch->text().trimmed());
    }
}

void UserManageWindow::onBtnBackClicked()
{
    emit backToSystemManage();  // 发送返回信号
    this->hide();  // 隐藏当前窗口
    emit statusMessageRequested("返回系统管理界面", 2000);
}
