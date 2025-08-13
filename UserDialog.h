#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class UserDialog; }
QT_END_NAMESPACE

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode { NewUser, EditUser };

    void setOrgId(int orgId);  // 设置选中的机构ID
    int getOrgId() const;

    struct UserData {
        QString username;   // 用户名（对应user_name）
        QString name;       // 真实姓名（对应real_name）
        QString phone;      // 电话（对应phone）
        QString password;   // 密码（对应password）

        bool isValid() const {
            return !username.isEmpty() && !name.isEmpty() &&
                   !phone.isEmpty() && !password.isEmpty(); // 新增密码验证
        }

        QStringList toStringList() const {
            return {username, name, phone, password};
        }
    };

    explicit UserDialog(QWidget *parent = nullptr,
                        Mode mode = NewUser,
                        const UserData &data = UserData());
    ~UserDialog();

    UserData getUserData() const;
    void setUserData(const UserData &data);

private slots:
    void validateInput();

private:
    Ui::UserDialog *ui;
    Mode m_mode;
};

#endif // USERDIALOG_H
