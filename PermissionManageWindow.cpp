#include "PermissionManageWindow.h"
#include "ui_PermissionManageWindow.h"
#include "DBUtil.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QTimer>

PermissionManageWindow::PermissionManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PermissionManageWindow)
{
    ui->setupUi(this);
    initTable();
    setupConnections();
}

PermissionManageWindow::~PermissionManageWindow()
{
    delete ui;
}

void PermissionManageWindow::setupConnections()
{
    connect(ui->btnBack, &QPushButton::clicked, this, &PermissionManageWindow::onBtnBackClicked);
    connect(ui->btnAdd, &QPushButton::clicked, this, &PermissionManageWindow::onBtnAddClicked);
    connect(ui->btnEdit, &QPushButton::clicked, this, &PermissionManageWindow::onBtnEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &PermissionManageWindow::onBtnDeleteClicked);
    connect(ui->btnSearch, &QPushButton::clicked, this, &PermissionManageWindow::onBtnSearchClicked);
}

void PermissionManageWindow::initTable()
{
    ui->tablePermissions->setColumnCount(6);
    ui->tablePermissions->horizontalHeader()->setStretchLastSection(true);
    ui->tablePermissions->setColumnWidth(0, 60);
    ui->tablePermissions->horizontalHeader()->setStretchLastSection(true);
    ui->tablePermissions->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tablePermissions->setColumnWidth(0, 40);  // 选择框列
    ui->tablePermissions->setColumnWidth(1, 120); // 用户名
    ui->tablePermissions->setColumnWidth(2, 120); // 真实姓名
    ui->tablePermissions->setColumnWidth(3, 150); // 所属机构
    ui->tablePermissions->setColumnWidth(4, 120); // 联系电话
    ui->tablePermissions->setColumnWidth(5, 80);  // 状态
    ui->tablePermissions->setColumnWidth(6, 150); // 权限
}

void PermissionManageWindow::loadPermissionData()
{
    ui->tablePermissions->setRowCount(0);

    QString sql = "SELECT * FROM permission";
    QVector<QVariantMap> results = DBUtil::instance()->query(sql);

    if (DBUtil::instance()->lastError().isEmpty()) {
        for (int i = 0; i < results.size(); ++i) {
            QVariantMap rowData = results[i];
            ui->tablePermissions->insertRow(i);

            // 添加勾选框
            QCheckBox *checkBox = new QCheckBox();
            checkBox->setStyleSheet("margin-left:50%; margin-right:50%;");
            ui->tablePermissions->setCellWidget(i, 0, checkBox);

            // 填充数据
            ui->tablePermissions->setItem(i, 1, new QTableWidgetItem(rowData["permission_id"].toString()));
            ui->tablePermissions->setItem(i, 2, new QTableWidgetItem(rowData["permission_name"].toString()));
            ui->tablePermissions->setItem(i, 3, new QTableWidgetItem(rowData["permission_code"].toString()));
            ui->tablePermissions->setItem(i, 4, new QTableWidgetItem(rowData["parent_id"].toString()));
            ui->tablePermissions->setItem(i, 5, new QTableWidgetItem(rowData["description"].toString()));
        }
        emit statusMessageRequested(QString("加载完成，共 %1 条记录").arg(results.size()), 2000);
    } else {
        emit statusMessageRequested("加载失败: " + DBUtil::instance()->lastError(), 3000);
    }
}

QVector<int> PermissionManageWindow::getSelectedIds()
{
    QVector<int> ids;
    for (int i = 0; i < ui->tablePermissions->rowCount(); ++i) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->tablePermissions->cellWidget(i, 0));
        if (checkBox && checkBox->isChecked()) {
            int id = ui->tablePermissions->item(i, 1)->text().toInt();
            ids.append(id);
        }
    }
    return ids;
}

void PermissionManageWindow::onBtnBackClicked()
{
    emit backToSystemManage();
}

void PermissionManageWindow::onBtnAddClicked()
{
    emit statusMessageRequested("新增权限功能待实现", 2000);
}

void PermissionManageWindow::onBtnEditClicked()
{
    QVector<int> selected = getSelectedIds();
    if (selected.size() != 1) {
        emit statusMessageRequested("请选择一条记录进行编辑", 2000);
        return;
    }
    emit statusMessageRequested("编辑权限功能待实现", 2000);
}

void PermissionManageWindow::onBtnDeleteClicked()
{
    QVector<int> selected = getSelectedIds();
    if (selected.isEmpty()) {
        emit statusMessageRequested("请选择需要删除的记录", 2000);
        return;
    }
    emit statusMessageRequested("删除权限功能待实现", 2000);
}

void PermissionManageWindow::onBtnSearchClicked()
{
    QString keyword = ui->lineSearch->text();
    if (keyword.isEmpty()) {
        loadPermissionData();
        return;
    }

    QString sql = QString("SELECT * FROM permission WHERE permission_name LIKE '%%1%' OR permission_code LIKE '%%1%'")
                      .arg(keyword);
    QVector<QVariantMap> results = DBUtil::instance()->query(sql);
    ui->tablePermissions->setRowCount(0);

    for (int i = 0; i < results.size(); ++i) {
        // 填充数据逻辑同loadPermissionData
    }
}

void PermissionManageWindow::refreshData()
{
    loadPermissionData();  // 调用私有数据加载函数
}
