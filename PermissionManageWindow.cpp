#include "PermissionManageWindow.h"
#include "ui_PermissionManageWindow.h"

PermissionManageWindow::PermissionManageWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PermissionManageWindow)
{
    ui->setupUi(this);
}

PermissionManageWindow::~PermissionManageWindow()
{
    delete ui;
}
