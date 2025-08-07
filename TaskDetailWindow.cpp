#include "TaskDetailWindow.h"
#include "ui_TaskDetailWindow.h"
#include "DBUtil.h"
#include <QMessageBox>
#include <QColor>
#include <QTableWidgetItem>

TaskDetailWindow::TaskDetailWindow(const QString &taskId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDetailWindow),
    m_taskId(taskId)
{
    qDebug() << "开始加载UI";
    ui->setupUi(this);
    qDebug() << "UI加载完成";
    loadAllData(); // 加载所有任务详情数据
}

TaskDetailWindow::~TaskDetailWindow()
{
    delete ui;
}

// 加载所有数据
void TaskDetailWindow::loadAllData()
{
    qDebug() << "开始加载数据";
    loadBasicInfo();   // 加载基本信息
    loadTestItems();   // 加载测试项目
    loadTestReport();  // 加载测试报告
}

// 加载任务基本信息
void TaskDetailWindow::loadBasicInfo()
{
    QString sql = "SELECT t.*, pu.unit_name, cs.station_name, p.protocol_name "
                  "FROM test_task t "
                  "JOIN participate_unit pu ON t.unit_id = pu.unit_id "
                  "JOIN control_station cs ON t.station_id = cs.station_id "
                  "JOIN protocol p ON t.protocol_id = p.protocol_id "
                  "WHERE t.task_id = :taskId";

    QVariantMap params;
    params["taskId"] = m_taskId;

    QVector<QVariantMap> results = DBUtil::instance()->query(sql, params);
    if (results.isEmpty()) {
        QMessageBox::warning(this, "数据错误", "未找到任务基本信息");
        return;
    }

    QVariantMap taskInfo = results.first();

    // 填充基本信息到UI控件
    ui->labelTitle->setText(taskInfo["task_name"].toString());
    ui->labelTaskIdValue->setText(taskInfo["task_id"].toString());
    ui->labelStatusValue->setText(getStatusText(taskInfo["status"].toInt()));
    ui->labelUnitValue->setText(taskInfo["unit_name"].toString());
    ui->labelStationValue->setText(taskInfo["station_name"].toString());
    ui->labelProtocolValue->setText(taskInfo["protocol_name"].toString());
    ui->labelStartTimeValue->setText(taskInfo["start_time"].toString());
}

// 加载测试项目数据
void TaskDetailWindow::loadTestItems()
{
    QString sql = "SELECT item_id, item_name, standard_requirement, "
                  "CASE result WHEN 0 THEN '未通过' WHEN 1 THEN '通过' ELSE '未测试' END as result, "
                  "test_time "
                  "FROM test_item "
                  "WHERE task_id = :taskId "
                  "ORDER BY test_time DESC";

    QVariantMap params;
    params["taskId"] = m_taskId;

    QVector<QVariantMap> items = DBUtil::instance()->query(sql, params);
    if (!DBUtil::instance()->lastError().isEmpty()) {
        QMessageBox::warning(this, "查询错误", "加载测试项目失败: " + DBUtil::instance()->lastError());
        return;
    }


    // 清空表格并设置行数
    ui->tableTestItems->setRowCount(0);

    // 填充测试项目数据
    for (int i = 0; i < items.size(); ++i) {
        const QVariantMap &item = items[i];
        ui->tableTestItems->insertRow(i);

        // 项目ID
        ui->tableTestItems->setItem(i, 0, new QTableWidgetItem(item["item_id"].toString()));
        // 项目名称
        ui->tableTestItems->setItem(i, 1, new QTableWidgetItem(item["item_name"].toString()));
        // 测试标准
        ui->tableTestItems->setItem(i, 2, new QTableWidgetItem(item["standard_requirement"].toString()));
        // 测试结果（带颜色标识）
        QTableWidgetItem *resultItem = new QTableWidgetItem(item["result"].toString());
        if (item["result"].toString() == "通过") {
            resultItem->setBackground(QColor(180, 255, 180)); // 绿色
        } else if (item["result"].toString() == "未通过") {
            resultItem->setBackground(QColor(255, 180, 180)); // 红色
        } else {
            resultItem->setBackground(QColor(230, 230, 230)); // 灰色
        }
        ui->tableTestItems->setItem(i, 3, resultItem);
        // 测试时间
        ui->tableTestItems->setItem(i, 4, new QTableWidgetItem(item["test_time"].toString()));
    }
}

// 加载测试报告数据
void TaskDetailWindow::loadTestReport()
{
    QString sql = "SELECT tr.report_id, tr.pass_rate, tr.generate_user, tr.content, "
                  "tt.status "
                  "FROM test_report tr "
                  "JOIN test_task tt ON tr.task_id = tt.task_id  "
                  "WHERE tr.task_id = :taskId";

    QVariantMap params;
    params["taskId"] = m_taskId;

    QVector<QVariantMap> reports = DBUtil::instance()->query(sql, params);
    if (!DBUtil::instance()->lastError().isEmpty()) {
        QMessageBox::warning(this, "查询错误", "加载测试报告失败: " + DBUtil::instance()->lastError());
        return;
    }

    if (reports.isEmpty()) {
        // 无报告数据时显示默认信息
        ui->labelReportIdValue->setText("");
        ui->labelTestResultValue->setText("");
        ui->labelPassRateValue->setText("");
        ui->labelGenerateUserValue->setText("");
        ui->textSummaryContent->setText("暂无测试报告数据");
        return;
    }

    QVariantMap report = reports.first();

    // 填充测试报告数据到UI控件
    ui->labelReportIdValue->setText(report["report_id"].toString());
    ui->labelTestResultValue->setText(getStatusText(report["status"].toInt()));
    ui->labelPassRateValue->setText(QString("%1%").arg(report["pass_rate"].toDouble() * 100)); // 显示为百分比
    ui->labelGenerateUserValue->setText(report["generate_user"].toString());
    ui->textSummaryContent->setText(report["content"].toString());
}

// 将状态码转换为文本描述
QString TaskDetailWindow::getStatusText(int statusCode)
{
    switch (statusCode) {
    case 0: return "未开始";
    case 1: return "进行中";
    case 2: return "已完成";
    case 3: return "失败";
    default: return "未知状态";
    }
}

// 导出报告按钮点击事件
void TaskDetailWindow::on_btnExport_clicked()
{
    QMessageBox::information(this, "提示", "报告导出功能待实现");
    // 实际实现时可导出为PDF、Excel等格式
}

// 关闭按钮点击事件
void TaskDetailWindow::on_btnClose_clicked()
{
    this->close(); // 关闭窗口
}
