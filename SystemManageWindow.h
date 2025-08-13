#ifndef SYSTEMMANAGEWINDOW_H
#define SYSTEMMANAGEWINDOW_H

#include <QWidget>

#include "UserManageWindow.h"
#include "OrgManageWindow.h"

namespace Ui {
class SystemManageWindow;
}

class SystemManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SystemManageWindow(QWidget *parent = nullptr);
    ~SystemManageWindow();

signals:
    // 状态消息信号，用于与主窗口状态栏通信
    void statusMessageRequested(const QString &message, int timeout = 3000);

private slots:
    void onBtnUserManageClicked();
    void onBtnOrgManageClicked();
    void onBtnPermissionManageClicked();
    void onBtnDictManageClicked();
    void onOrgManageBack();

private:
    Ui::SystemManageWindow *ui;
    UserManageWindow *userManageWindow;
    OrgManageWindow *orgManageWindow;
    void setupConnections();
};

#endif // SYSTEMMANAGEWINDOW_H
