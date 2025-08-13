#include "SystemManageWindow.h"
#include "ui_SystemManageWindow.h"
#include <QMessageBox>

SystemManageWindow::SystemManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemManageWindow),
    userManageWindow(nullptr),
    orgManageWindow(nullptr)
{
    ui->setupUi(this);
    setupConnections();
}

SystemManageWindow::~SystemManageWindow()
{
    delete ui;
    if (userManageWindow) {
        delete userManageWindow;
        userManageWindow = nullptr;
    }
    if (orgManageWindow) {
        delete orgManageWindow;
        orgManageWindow = nullptr;
    }
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
    emit statusMessageRequested("权限管理功能待实现", 2000);
    QMessageBox::information(this, "提示", "权限管理功能待实现");
}


void SystemManageWindow::onBtnDictManageClicked()
{
    emit statusMessageRequested("数据字典功能待实现", 2000);
    QMessageBox::information(this, "提示", "数据字典功能待实现");
}
