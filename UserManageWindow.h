#ifndef USERMANAGEWINDOW_H
#define USERMANAGEWINDOW_H

#include <QWidget>
#include <QVector>
#include <QVariantMap>
#include "UserDialog.h"

namespace Ui {
class UserManageWindow;
}

class UserManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserManageWindow(QWidget *parent = nullptr);
    ~UserManageWindow();

    // 定义用户数据结构（与UserDialog对应）
    struct UserInfo {
        int id;               // 用户ID（user_id）
        QString username;     // 用户名（user_name）
        QString realName;     // 真实姓名（real_name）
        QString phone;        // 电话（phone）
        QString password;     // 密码（password）
        int orgId;            // 所属机构ID（org_id）
        int status;           // 状态（status）
    };

signals:
    void statusMessageRequested(const QString &message, int timeout = 3000);
    void backToSystemManage();

private slots:
    void onBtnAddClicked();
    void onBtnEditClicked();
    void onBtnDeleteClicked();
    void onBtnSearchClicked();
    void onBtnFirstClicked();
    void onBtnPrevClicked();
    void onBtnNextClicked();
    void onBtnLastClicked();
    void onComboPageSizeChanged(const QString &text);
    void onComboPageChanged(int index);
    void onBtnBackClicked();

private:
    Ui::UserManageWindow *ui;
    int m_currentPage;
    int m_totalPages;
    int m_pageSize;
    int m_totalCount;

    void setupConnections();
    void initTable();
    void loadUserData(const QString &keyword = "");
    void updatePagination();
    void loadOrganizations();
    void loadPermissions();
    QVector<QVariantMap> getUsers(int page, int pageSize, const QString &keyword);
    int getUserCount(const QString &keyword = "");
    QString getOrganizationName(int orgId);
    QString getStatusText(int status);
    QString getPermissionText(int userId);

    // 新增函数声明
    UserInfo getUserInfoFromDialog(const UserDialog::UserData &dialogData, int id = -1);
    bool addUserToDB(const UserInfo &user);       // 添加用户到数据库
    bool updateUserInDB(const UserInfo &user);    // 更新数据库用户
    UserInfo getSelectedUserInfo();               // 获取选中行的用户信息
};

#endif // USERMANAGEWINDOW_H
