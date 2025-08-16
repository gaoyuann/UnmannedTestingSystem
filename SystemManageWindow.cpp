#include "SystemManageWindow.h"
#include "ui_SystemManageWindow.h"
#include <QMessageBox>

SystemManageWindow::SystemManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemManageWindow),
    userManageWindow(nullptr),
    orgManageWindow(nullptr),
    permissionManageWindow(nullptr),
    dataDicWindow(nullptr)
{
    ui->setupUi(this);
    setupConnections();
}

SystemManageWindow::~SystemManageWindow()
{
    delete ui;
    if (userManageWindow) delete userManageWindow;
    if (orgManageWindow) delete orgManageWindow;
    if (permissionManageWindow) delete permissionManageWindow;
    if (dataDicWindow) delete dataDicWindow;
}

void SystemManageWindow::setupConnections()
{
    connect(ui->btnUserManage, &QPushButton::clicked,
            this, &SystemManageWindow::onBtnUserManageClicked);
    connect(ui->btnOrgManage, &QPushButton::clicked,
            this, &SystemManageWindow::onBtnOrgManageClicked);
    connect(ui->btnPermissionManage, &QPushButton::clicked,
            this, &SystemManageWindow::onBtnPermissionManageClicked);
    connect(ui->btnDictManage, &QPushButton::clicked,
            this, &SystemManageWindow::onBtnDictManageClicked);
}

void SystemManageWindow::onBtnUserManageClicked()
{
    // 修改为打开用户管理窗口
    if (!userManageWindow) {
        userManageWindow = new UserManageWindow(this);
        // 连接状态消息信号
        connect(userManageWindow, &UserManageWindow::statusMessageRequested,
                this, &SystemManageWindow::statusMessageRequested);
        //处理用户管理窗口的返回信号
        connect(userManageWindow, &UserManageWindow::backToSystemManage,
                this, [=]() {
                    this->show();  // 显示系统管理窗口
                    this->raise();
                    this->activateWindow();
                });
    }
    this->show();
    userManageWindow->show();
    userManageWindow->raise();
    userManageWindow->activateWindow();
    emit statusMessageRequested("打开用户管理模块", 2000);
}

void SystemManageWindow::onBtnOrgManageClicked()
{
    if (!orgManageWindow) {
        orgManageWindow = new OrgManageWindow(this);
        // 连接机构管理窗口的返回信号
        connect(orgManageWindow, &OrgManageWindow::backToSystemManage,
                this, &SystemManageWindow::onOrgManageBack);
        // 连接状态提示信号
        connect(orgManageWindow, &OrgManageWindow::statusMessageRequested,
                this, &SystemManageWindow::statusMessageRequested);
    }
    this->hide();
    orgManageWindow->show();
    orgManageWindow->raise();
    orgManageWindow->activateWindow();
    emit statusMessageRequested("打开机构管理模块", 2000);

}

void SystemManageWindow::onOrgManageBack() {
    if (orgManageWindow) {
        orgManageWindow->hide();  // 隐藏机构管理窗口
    }
    this->show();  // 显示系统管理窗口
    this->raise();
    this->activateWindow();
    emit statusMessageRequested("已返回系统管理", 3000);
}

void SystemManageWindow::onBtnPermissionManageClicked()
{
    if (!permissionManageWindow) {
        permissionManageWindow = new PermissionManageWindow(this);
        connect(permissionManageWindow, &PermissionManageWindow::backToSystemManage,
                this, [=]() {
                    this->show();
                    this->raise();
                    permissionManageWindow->hide();
                });
        connect(permissionManageWindow, &PermissionManageWindow::statusMessageRequested,
                this, &SystemManageWindow::statusMessageRequested);
    }
    this->hide();
    permissionManageWindow->show();
    permissionManageWindow->raise();
    permissionManageWindow->refreshData();
    emit statusMessageRequested("打开权限管理模块", 2000);
}


void SystemManageWindow::onBtnDictManageClicked()
{
    if (!dataDicWindow) {
        dataDicWindow = new DataDicWindow(this);
        connect(dataDicWindow, &DataDicWindow::backToSystemManage,
                this, [=]() {
                    this->show();
                    this->raise();
                    dataDicWindow->hide();
                });
        connect(dataDicWindow, &DataDicWindow::statusMessageRequested,
                this, &SystemManageWindow::statusMessageRequested);
    }
    this->hide();
    dataDicWindow->show();
    dataDicWindow->raise();
    emit statusMessageRequested("打开数据字典管理模块", 2000);
}
