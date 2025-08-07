#include "TestManageWindow.h"
#include "ui_TestManageWindow.h"
#include "TaskDetailWindow.h"
#include "NewTaskWithItemsDialog.h"
#include "DBUtil.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QPushButton>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

TestManageWindow::TestManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestManageWindow),
    currentPage(1),
    pageSize(10),
    totalCount(0),
    totalPages(0)
{
    ui->setupUi(this);

    // 检查数据库连接状态
    if (!DBUtil::instance()->isInitialized()) {
        QMessageBox::critical(this, "数据库错误", "数据库未初始化，请检查配置");
        return;
    }

    if (!DBUtil::instance()->isConnectionValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效: " + DBUtil::instance()->lastError());
        return;
    }

    initTable();
    loadTestTasks();
}

TestManageWindow::~TestManageWindow()
{
    delete ui;
}

// 初始化表格
void TestManageWindow::initTable()
{
    // 设置表格属性
    ui->tableTasks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableTasks->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableTasks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableTasks->setSelectionBehavior(QAbstractItemView::SelectRows);

}

// 加载测试任务数据
void TestManageWindow::loadTestTasks()
{
    // 清空表格
    while (ui->tableTasks->rowCount() > 0) {
        ui->tableTasks->removeRow(0);
    }

    // 获取总记录数
    QString countSql = "SELECT COUNT(*) FROM test_task";
    QVector<QVariantMap> countResult = DBUtil::instance()->query(countSql);
    if (!countResult.isEmpty()) {
        totalCount = countResult.first()["COUNT(*)"].toInt();
    }
    calculateTotalPages();

    // 构建查询SQL（带分页）
    currentPage = qMax(1, currentPage);
    currentPage = qMin(currentPage, totalPages);
    int offset = (currentPage - 1) * pageSize;
    offset = qMax(0, offset);
    QString sql = QString("SELECT t.task_id, t.task_name, pu.unit_name, "
                          "cs.station_name, p.protocol_name, t.start_time, "
                          "CASE t.status WHEN 0 THEN '未开始' WHEN 1 THEN '进行中' "
                          "WHEN 2 THEN '已完成' WHEN 3 THEN '失败' END as status "
                          "FROM test_task t "
                          "JOIN participate_unit pu ON t.unit_id = pu.unit_id "
                          "JOIN control_station cs ON t.station_id = cs.station_id "
                          "JOIN protocol p ON t.protocol_id = p.protocol_id "
                          "LIMIT %1 OFFSET %2").arg(pageSize).arg(offset);

    // 执行查询
    QVector<QVariantMap> results = DBUtil::instance()->query(sql);
    if (!DBUtil::instance()->lastError().isEmpty()) {
        QMessageBox::warning(this, "查询错误", "加载测试任务失败: " + DBUtil::instance()->lastError());
        return;
    }

    // 填充表格
    int row = 0;
    for (const auto& task : results)  {
        ui->tableTasks->insertRow(row);

        // 任务ID
        ui->tableTasks->setItem(row, 0, new QTableWidgetItem(task["task_id"].toString()));
        // 任务名称
        ui->tableTasks->setItem(row, 1, new QTableWidgetItem(task["task_name"].toString()));
        // 参试单位
        ui->tableTasks->setItem(row, 2, new QTableWidgetItem(task["unit_name"].toString()));
        // 控制站
        ui->tableTasks->setItem(row, 3, new QTableWidgetItem(task["station_name"].toString()));
        // 测试协议
        ui->tableTasks->setItem(row, 4, new QTableWidgetItem(task["protocol_name"].toString()));
        // 开始时间
        ui->tableTasks->setItem(row, 5, new QTableWidgetItem(task["start_time"].toString()));
        // 状态
        QTableWidgetItem* statusItem = new QTableWidgetItem(task["status"].toString());

        QString status = task["status"].toString();
        if (status == "未开始") statusItem->setBackground(QColor(230, 230, 230));
        else if (status == "进行中") statusItem->setBackground(QColor(255, 230, 180));
        else if (status == "已完成") statusItem->setBackground(QColor(180, 255, 180));
        else if (status == "失败") statusItem->setBackground(QColor(255, 180, 180));
        ui->tableTasks->setItem(row, 6, statusItem);

        // 操作列 - 添加详情按钮
        QPushButton* detailBtn = createDetailButton(task["task_id"].toString());
        ui->tableTasks->setCellWidget(row, 7, detailBtn);

        row++;
    }

    // 更新分页信息
    updatePaginationInfo();
}

// 计算总页数
void TestManageWindow::calculateTotalPages()
{
    if (totalCount <= 0) {
        totalPages = 1;
        return;
    }
    totalPages = totalCount / pageSize;
    if (totalCount % pageSize != 0) {
        totalPages++;
    }
}

// 更新分页信息
void TestManageWindow::updatePaginationInfo()
{
    // 更新页码信息标签
    ui->labelPageInfo->setText(QString("第 %1 页 / 共 %2 页 (%3 条)")
                                   .arg(currentPage).arg(totalPages).arg(totalCount));

    // 禁用/启用分页按钮
    ui->btnFirst->setEnabled(currentPage > 1);
    ui->btnPrev->setEnabled(currentPage > 1);
    ui->btnNext->setEnabled(currentPage < totalPages);
    ui->btnLast->setEnabled(currentPage < totalPages);
}

// 创建详情按钮
QPushButton* TestManageWindow::createDetailButton(const QString& taskId)
{
    QPushButton* btn = new QPushButton("查看详情", this);

    btn->setStyleSheet("background-color: #165DFF; color: white; border-radius: 4px; padding: 2px 8px;");
    btn->setProperty("taskId", taskId);

    btn->setObjectName("detailButton");

    connect(btn, &QPushButton::clicked, this, &TestManageWindow::ondetailButtonclicked);
    return btn;
}


// 获取选中的任务ID
QString TestManageWindow::getSelectedTaskId()
{
    QModelIndexList selectedRows = ui->tableTasks->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "提示", "请选择一个测试任务");
        return "";
    }
    return ui->tableTasks->item(selectedRows.first().row(), 0)->text();
}

// 新增任务按钮
void TestManageWindow::on_btnAddTask_clicked()
{
    NewTaskWithItemsDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        saveNewTaskToDB(dialog);
        QMessageBox::information(this, "成功", "任务及测试项目新增成功！");
    } else {
        QMessageBox::information(this, "取消", "任务新增已取消");
    }
}

bool TestManageWindow::saveNewTaskToDB(const NewTaskWithItemsDialog &dialog)
{
    // 1. 验证任务基本信息
    QString taskName = dialog.getTaskName();
    if (taskName.isEmpty()) {
        QMessageBox::warning(this, "错误", "任务名称不能为空");
        return false;
    }

    // 2. 开启数据库事务
    if (!DBUtil::instance()->beginTransaction()) {
        QMessageBox::critical(this, "错误", "开启事务事务失败: " + DBUtil::instance()->lastError());
        return false;
    }

    // 3. 插入任务主表（test_task）
    QString sql = "INSERT INTO test_task ("
                  "task_name, unit_id, station_id, protocol_id, start_time, status"
                  ") values ("
                  ":task_name, :unit_id, :station_id, :protocol_id, :start_time, :status"
                  ")";

    QVariantMap params;
    params["task_name"] = taskName;
    params["unit_id"] = dialog.getUnitId();       // 获取单位ID（外键）
    params["station_id"] = dialog.getStationId(); // 获取控制站ID（外键）
    params["protocol_id"] = dialog.getProtocolId(); // 获取协议ID（外键）
    params["start_time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    params["status"] = 0; // 0表示"未开始"（与数据库状态定义一致）

    int affected = DBUtil::instance()->execute(sql, params);
    if (affected <= 0) {
        DBUtil::instance()->rollbackTransaction();
        QMessageBox::critical(this, "错误", "保存任务失败: " + DBUtil::instance()->lastError());
        return false;
    }

    // 4. 获取新插入的任务ID
    QVariant taskId = DBUtil::instance()->querySingleValue("SELECT LAST_INSERT_ID()");
    if (!taskId.isValid()) {
        DBUtil::instance()->rollbackTransaction();
        QMessageBox::critical(this, "错误", "无法获取任务ID");
        return false;
    }

    // 5. 保存测试项（关键修改：通过getTestItems()获取数据，独立保存）
    QVector<QVariantMap> testItems = dialog.getTestItems(); // 从对话框获取获取测试项列表
    foreach (const auto& item, testItems) {
        QString itemSql = "INSERT into test_item ("
                          "task_id, item_name, standard_requirement, result"
                          ") values ("
                          ":task_id, :item_name, :standard_requirement, 2" // result=2表示"未测试"
                          ")";

        QVariantMap itemParams;
        itemParams["task_id"] = taskId.toInt(); // 关联当前任务ID
        itemParams["item_name"] = item["item_name"]; // 测试项名称
        itemParams["standard_requirement"] = item["standard_requirement"]; // 标准要求

        int itemAffected = DBUtil::instance()->execute(itemSql, itemParams);
        if (itemAffected <= 0) {
            DBUtil::instance()->rollbackTransaction(); // 测试项保存失败，回滚整个事务
            QMessageBox::critical(this, "错误", "保存测试项失败，任务已回滚: " + DBUtil::instance()->lastError());
            return false;
        }
    }

    // 6. 提交事务
    if (!DBUtil::instance()->commitTransaction()) {
        DBUtil::instance()->rollbackTransaction();
        QMessageBox::critical(this, "错误", "提交事务失败: " + DBUtil::instance()->lastError());
        return false;
    }

    return true;

}


// 编辑任务按钮
void TestManageWindow::on_btnEditTask_clicked()
{
    QString taskId = getSelectedTaskId();
    if (!taskId.isEmpty()) {
        QMessageBox::information(this, "提示", QString("编辑测试任务 %1 功能待实现").arg(taskId));
    }
}

// 删除任务按钮
void TestManageWindow::on_btnDeleteTask_clicked()
{
    QString taskId = getSelectedTaskId();
    if (!taskId.isEmpty()) {
        if (QMessageBox::question(this, "确认", QString("确定要删除任务 %1 吗？").arg(taskId))
            == QMessageBox::Yes) {
            QString sql = "DELETE FROM test_task WHERE task_id = :taskId";
            QVariantMap params;
            params["taskId"] = taskId;

            int result = DBUtil::instance()->execute(sql, params);
            if (result > 0) {
                QMessageBox::information(this, "成功", "任务删除成功");
                loadTestTasks(); // 重新加载数据
            } else {
                QMessageBox::warning(this, "失败", "任务删除失败: " + DBUtil::instance()->lastError());
            }
        }
    }
}

// 执行任务按钮
void TestManageWindow::on_btnExecuteTask_clicked()
{
    QString taskId = getSelectedTaskId();
    if (!taskId.isEmpty()) {
        QMessageBox::information(this, "提示", QString("执行测试任务 %1 功能待实现").arg(taskId));
    }
}


// 搜索按钮
void TestManageWindow::on_btnSearch_clicked()
{
    QString keyword = ui->lineSearch->text().trimmed();
    if (keyword.isEmpty()) {
        // 无关键词时加载全部数据
        loadTestTasks();
        return;
    }

    // 构建带条件的查询
    QString sql = QString("SELECT t.task_id, t.task_name, pu.unit_name, "
                          "cs.station_name, p.protocol_name, t.start_time, "
                          "CASE t.status WHEN 0 THEN '未开始' WHEN 1 THEN '进行中' "
                          "WHEN 2 THEN '已完成' WHEN 3 THEN '失败' END as status "
                          "FROM test_task t "
                          "JOIN participate_unit pu ON t.unit_id = pu.unit_id "
                          "JOIN control_station cs ON t.station_id = cs.station_id "
                          "JOIN protocol p ON t.protocol_id = p.protocol_id "
                          "WHERE t.task_name LIKE :keyword OR pu.unit_name LIKE :keyword");
    QVariantMap params;
    params["keyword"] = "%" + keyword + "%";

    QVector<QVariantMap> results = DBUtil::instance()->query(sql, params);
    if (!DBUtil::instance()->lastError().isEmpty()) {
        QMessageBox::warning(this, "查询错误", "搜索失败: " + DBUtil::instance()->lastError());
        return;
    }

    // 清空表格
    while (ui->tableTasks->rowCount() > 0) {
        ui->tableTasks->removeRow(0);
    }

    // 填充搜索结果
    int row = 0;
    for (const auto& task : results) {
        ui->tableTasks->insertRow(row);

        // 任务ID
        ui->tableTasks->setItem(row, 0, new QTableWidgetItem(task["task_id"].toString()));
        // 任务名称
        ui->tableTasks->setItem(row, 1, new QTableWidgetItem(task["task_name"].toString()));
        // 参试单位
        ui->tableTasks->setItem(row, 2, new QTableWidgetItem(task["unit_name"].toString()));
        // 控制站
        ui->tableTasks->setItem(row, 3, new QTableWidgetItem(task["station_name"].toString()));
        // 测试协议
        ui->tableTasks->setItem(row, 4, new QTableWidgetItem(task["protocol_name"].toString()));
        // 开始时间
        ui->tableTasks->setItem(row, 5, new QTableWidgetItem(task["start_time"].toString()));
        // 状态
        QTableWidgetItem* statusItem = new QTableWidgetItem(task["status"].toString());
        QString status = task["status"].toString();
        if (status == "未开始") statusItem->setBackground(QColor(230, 230, 230));
        else if (status == "进行中") statusItem->setBackground(QColor(255, 230, 180));
        else if (status == "已完成") statusItem->setBackground(QColor(180, 255, 180));
        else if (status == "失败") statusItem->setBackground(QColor(255, 180, 180));
        ui->tableTasks->setItem(row, 6, statusItem);

        // 操作列 - 添加详情按钮
        QPushButton* detailBtn = createDetailButton(task["task_id"].toString());
        ui->tableTasks->setCellWidget(row, 7, detailBtn);

        row++;
    }

    // 更新分页信息为搜索结果
    totalCount = results.size();
    calculateTotalPages();
    currentPage = 1; // 重置到第一页
    updatePaginationInfo();
}

// 首页按钮
void TestManageWindow::on_btnFirst_clicked()
{
    if (currentPage != 1) {
        currentPage = 1;
        loadTestTasks();
    }
}

// 上一页按钮
void TestManageWindow::on_btnPrev_clicked()
{
    if (currentPage > 1) {
        currentPage--;
        loadTestTasks();
    }
}

// 下一页按钮
void TestManageWindow::on_btnNext_clicked()
{
    if (currentPage < totalPages) {
        currentPage++;
        loadTestTasks();
    }
}

// 末页按钮
void TestManageWindow::on_btnLast_clicked()
{
    if (currentPage != totalPages) {
        currentPage = totalPages;
        loadTestTasks();
    }
}


// 详情按钮点击事件
void TestManageWindow::ondetailButtonclicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        QString taskId = btn->property("taskId").toString();
        if (!taskId.isEmpty()) {
            // 创建任务详情窗口实例，传入当前任务ID
            TaskDetailWindow detailWindow(taskId, this);
            // 以模态方式显示窗口（用户关闭详情窗口后才返回当前界面）
            detailWindow.exec();
        }
    }
}
