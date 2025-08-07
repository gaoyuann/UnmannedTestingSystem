#include "UserManageWindow.h"
#include "ui_UserManageWindow.h"

UserManageWindow::UserManageWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserManageWindow)
{
    ui->setupUi(this);
}

UserManageWindow::~UserManageWindow()
{
    delete ui;
}
