#include "NewTaskWithItemsDialog.h"
#include "ui_NewTaskWithItemsDialog.h"
#include "DBUtil.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDateTime>

NewTaskWithItemsDialog::NewTaskWithItemsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTaskWithItemsDialog)
{
    ui->setupUi(this);
    setWindowTitle("新增测试任务（含测试项目）");  // 设置窗口标题

    // 初始化表格（设置列宽自适应）
    ui->tableTestItems->horizontalHeader()->setStretchLastSection(true);
    ui->tableTestItems->setColumnCount(2);
    ui->tableTestItems->setHorizontalHeaderLabels({"测试项名称", "标准要求"});

    // 加载下拉框数据
    loadComboBoxData();

    // 初始化错误提示标签（参考UnitDialog的labelError）
    ui->labelError->setStyleSheet("color: red;");
}

NewTaskWithItemsDialog::~NewTaskWithItemsDialog()
{
    delete ui;
}

// 获取任务名称
QString NewTaskWithItemsDialog::getTaskName() const
{
    return ui->editTaskName->text().trimmed();
}

// 获取参试单位ID
int NewTaskWithItemsDialog::getUnitId() const
{
    return ui->comboUnit->currentData().toInt();
}

// 获取控制站ID
int NewTaskWithItemsDialog::getStationId() const
{
    return ui->comboStation->currentData().toInt();
}

// 获取测试协议ID
int NewTaskWithItemsDialog::getProtocolId() const
{
    return ui->comboProtocol->currentData().toInt();
}

// 获取测试项列表（供外部保存）
QVector<QVariantMap> NewTaskWithItemsDialog::getTestItems() const
{
    QVector<QVariantMap> items;
    for (int i = 0; i < ui->tableTestItems->rowCount(); ++i) {
        QTableWidgetItem *nameItem = ui->tableTestItems->item(i, 0);
        QTableWidgetItem *stdItem = ui->tableTestItems->item(i, 1);

        if (!nameItem || nameItem->text().trimmed().isEmpty()) continue;

        QVariantMap item;
        item["item_name"] = nameItem->text().trimmed();
        item["standard_requirement"] = stdItem ? stdItem->text().trimmed() : "";
        items.append(item);
    }
    return items;
}

// 从数据库加载下拉框数据
void NewTaskWithItemsDialog::loadComboBoxData()
{
    // 1. 加载参试单位（participate_unit表）
    QVector<QVariantMap> units = DBUtil::instance()->query(
        "SELECT unit_id, unit_name FROM participate_unit WHERE is_delete = 0 ORDER BY unit_name"
        );
    for (const auto &unit : units) {
        ui->comboUnit->addItem(unit["unit_name"].toString(), unit["unit_id"].toInt());
    }

    // 2. 加载控制站（control_station表）
    QVector<QVariantMap> stations = DBUtil::instance()->query(
        "SELECT station_id, station_name FROM control_station WHERE is_delete = 0 ORDER BY station_name"
        );
    for (const auto &station : stations) {
        ui->comboStation->addItem(station["station_name"].toString(), station["station_id"].toInt());
    }

    // 3. 加载测试协议（protocol表）
    QVector<QVariantMap> protocols = DBUtil::instance()->query(
        "SELECT protocol_id, protocol_name FROM protocol WHERE is_delete = 0 ORDER BY protocol_name"
        );
    for (const auto &protocol : protocols) {
        ui->comboProtocol->addItem(protocol["protocol_name"].toString(), protocol["protocol_id"].toInt());
    }
}

// 新增测试项
void NewTaskWithItemsDialog::on_btnAddItem_clicked()
{
    int row = ui->tableTestItems->rowCount();
    ui->tableTestItems->insertRow(row);
    ui->tableTestItems->setItem(row, 0, new QTableWidgetItem(""));
    ui->tableTestItems->setItem(row, 1, new QTableWidgetItem(""));
    ui->tableTestItems->selectRow(row);  // 自动选中新行
}

// 删除选中测试项
void NewTaskWithItemsDialog::on_btnRemoveItem_clicked()
{
    int currentRow = ui->tableTestItems->currentRow();
    if (currentRow >= 0) {
        ui->tableTestItems->removeRow(currentRow);
    } else {
        showError("请先选中要删除的测试项行");
    }
}

// 确认按钮（替代原btnSave）
void NewTaskWithItemsDialog::on_buttonBox_accepted()
{
    if (validateInput()) {
        accept();  // 验证通过，关闭对话框
    }
}

// 取消按钮
void NewTaskWithItemsDialog::on_buttonBox_rejected()
{
    reject();  // 直接关闭对话框
}

// 验证输入合法性
bool NewTaskWithItemsDialog::validateInput()
{
    // 清空之前的错误提示
    showError("");

    // 1. 验证任务名称
    if (getTaskName().isEmpty()) {
        showError("任务名称不能为空");
        ui->editTaskName->setFocus();
        return false;
    }

    // 2. 验证参试单位选择
    if (ui->comboUnit->currentIndex() < 0) {
        showError("请选择参试单位");
        ui->comboUnit->setFocus();
        return false;
    }

    // 3. 验证控制站选择
    if (ui->comboStation->currentIndex() < 0) {
        showError("请选择控制站");
        ui->comboStation->setFocus();
        return false;
    }

    // 4. 验证测试协议选择
    if (ui->comboProtocol->currentIndex() < 0) {
        showError("请选择测试协议");
        ui->comboProtocol->setFocus();
        return false;
    }

    // 5. 验证测试项
    if (ui->tableTestItems->rowCount() == 0) {
        showError("至少需要添加一个测试项");
        return false;
    }

    // 6. 验证测试项名称
    for (int i = 0; i < ui->tableTestItems->rowCount(); ++i) {
        QTableWidgetItem *item = ui->tableTestItems->item(i, 0);
        if (!item || item->text().trimmed().isEmpty()) {
            showError(QString("第%1行测试项名称不能为空").arg(i + 1));
            ui->tableTestItems->selectRow(i);
            return false;
        }
    }

    return true;
}

// 显示错误信息（参考UnitDialog的labelError）
void NewTaskWithItemsDialog::showError(const QString &message)
{
    ui->labelError->setText(message);
}
