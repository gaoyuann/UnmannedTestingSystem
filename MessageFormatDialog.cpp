#include "MessageFormatDialog.h"
#include "ui_MessageFormatDialog.h"
#include <QComboBox>
#include <QHeaderView>
#include <QMessageBox>
#include <QCheckBox>
#include <QLineEdit>

MessageFormatDialog::MessageFormatDialog(QWidget *parent, const QString &protocolName,
                                         const QVector<MessageFormat> &formats) :
    QDialog(parent),
    ui(new Ui::MessageFormatDialog),
    protocolName(protocolName),
    formats(formats)
{
    ui->setupUi(this);
    setWindowTitle(QString("报文格式配置 - %1").arg(protocolName));
    initUI();
    setupConnections();
    updateTable();
}



void MessageFormatDialog::initUI()
{
    // 设置表格样式
    ui->tableFormats->setStyleSheet(
        "QTableWidget {"
        "   font-size: 13px;"
        "   background-color: white;"
        "   alternate-background-color: #f8f9fa;"
        "   border: 1px solid #e0e0e0;"
        "   border-radius: 6px;"
        "   gridline-color: #e0e0e0;"
        "}"
        "QTableWidget::item {"
        "   color: black;"
        "   padding: 8px;"
        "   border-bottom: 1px solid #f0f0f0;"
        "}"
        "QHeaderView::section {"
        "   background-color: #9b59b6;"
        "   color: white;"
        "   padding: 8px;"
        "   border: none;"
        "   font-weight: 500;"
        "   font-size: 13px;"
        "}"
        "QTableWidget QLineEdit {"
        "   color: black;"
        "   text-align: center;"
        "}"
        );

    // 设置表格列
    QStringList headers;
    headers << "" << "字段名称" << "数据类型" << "长度(字节)" << "排序" << "描述";
    ui->tableFormats->setColumnCount(headers.size());
    ui->tableFormats->setHorizontalHeaderLabels(headers);

    // 设置列宽和行高
    ui->tableFormats->setColumnWidth(0, 40);   // 复选框列
    ui->tableFormats->setColumnWidth(2, 150);  // 数据类型列
    ui->tableFormats->setColumnWidth(3, 100);  // 长度列
    ui->tableFormats->setColumnWidth(4, 80);   // 排序列
    ui->tableFormats->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableFormats->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
    ui->tableFormats->verticalHeader()->setDefaultSectionSize(36);
    ui->tableFormats->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void MessageFormatDialog::setupDataTypeComboBox(QComboBox *combo)
{
    combo->clear();
    combo->addItems(dataTypes);
    combo->setStyleSheet(
        "QComboBox {"
        "   color: black;"
        "   background-color: white;"
        "   border: 1px solid #d0d0d0;"
        "   border-radius: 3px;"
        "   padding: 0px 6px;"
        "   min-height: 20px;"
        "   min-width: 80px;"
        "   text-align: center;"
        "}"
        );
    combo->setSizeAdjustPolicy(QComboBox::AdjustToContents);
}

void MessageFormatDialog::updateTable()
{
    ui->tableFormats->setRowCount(formats.size());

    for (int i = 0; i < formats.size(); ++i) {
        const MessageFormat &format = formats[i];

        // 复选框
        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableFormats->setItem(i, 0, checkItem);

        // 字段名称
        QTableWidgetItem *nameItem = new QTableWidgetItem(format.fieldName);
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableFormats->setItem(i, 1, nameItem);

        // 数据类型下拉框
        QComboBox *typeCombo = new QComboBox();
        setupDataTypeComboBox(typeCombo);
        typeCombo->setCurrentText(format.dataType);
        ui->tableFormats->setCellWidget(i, 2, typeCombo);

        // 长度
        QTableWidgetItem *lengthItem = new QTableWidgetItem(QString::number(format.length));
        lengthItem->setTextAlignment(Qt::AlignCenter);
        ui->tableFormats->setItem(i, 3, lengthItem);

        // 排序
        QTableWidgetItem *sortItem = new QTableWidgetItem(QString::number(format.sort));
        sortItem->setTextAlignment(Qt::AlignCenter);
        ui->tableFormats->setItem(i, 4, sortItem);

        // 描述
        QTableWidgetItem *descItem = new QTableWidgetItem(format.description);
        descItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->tableFormats->setItem(i, 5, descItem);
    }
}

void MessageFormatDialog::setupConnections()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &MessageFormatDialog::onAddField);
    connect(ui->btnRemove, &QPushButton::clicked, this, &MessageFormatDialog::onRemoveField);
    connect(ui->btnSave, &QPushButton::clicked, this, &MessageFormatDialog::onSave);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}

void MessageFormatDialog::onAddField()
{
    int newRow = ui->tableFormats->rowCount();
    ui->tableFormats->insertRow(newRow);

    // 复选框
    QTableWidgetItem *checkItem = new QTableWidgetItem();
    checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    checkItem->setCheckState(Qt::Unchecked);
    ui->tableFormats->setItem(newRow, 0, checkItem);

    // 字段名称
    QTableWidgetItem *nameItem = new QTableWidgetItem("新字段");
    nameItem->setTextAlignment(Qt::AlignCenter);
    ui->tableFormats->setItem(newRow, 1, nameItem);

    // 数据类型
    QComboBox *typeCombo = new QComboBox();
    setupDataTypeComboBox(typeCombo);
    typeCombo->setCurrentText("string");
    ui->tableFormats->setCellWidget(newRow, 2, typeCombo);

    // 长度
    QTableWidgetItem *lengthItem = new QTableWidgetItem("0");
    lengthItem->setTextAlignment(Qt::AlignCenter);
    ui->tableFormats->setItem(newRow, 3, lengthItem);

    // 排序
    QTableWidgetItem *sortItem = new QTableWidgetItem(QString::number(newRow + 1));
    sortItem->setTextAlignment(Qt::AlignCenter);
    ui->tableFormats->setItem(newRow, 4, sortItem);

    // 描述
    QTableWidgetItem *descItem = new QTableWidgetItem("");
    descItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableFormats->setItem(newRow, 5, descItem);

    ui->tableFormats->setCurrentCell(newRow, 1);
}

void MessageFormatDialog::onRemoveField()
{
    QList<int> rowsToRemove;
    for (int i = 0; i < ui->tableFormats->rowCount(); ++i) {
        if (ui->tableFormats->item(i, 0)->checkState() == Qt::Checked) {
            rowsToRemove.prepend(i);
        }
    }

    if (rowsToRemove.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先勾选要删除的字段");
        return;
    }

    foreach (int row, rowsToRemove) {
        ui->tableFormats->removeRow(row);
    }
}

QVector<MessageFormat> MessageFormatDialog::getMessageFormats() const
{
    QVector<MessageFormat> result;

    for (int i = 0; i < ui->tableFormats->rowCount(); ++i) {
        MessageFormat format;
        format.fieldName = ui->tableFormats->item(i, 1)->text();

        QComboBox *combo = qobject_cast<QComboBox*>(ui->tableFormats->cellWidget(i, 2));
        format.dataType = combo ? combo->currentText() : "string";

        format.length = ui->tableFormats->item(i, 3)->text().toInt();
        format.sort = ui->tableFormats->item(i, 4)->text().toInt();
        format.description = ui->tableFormats->item(i, 5)->text();

        result.append(format);
    }

    return result;
}

void MessageFormatDialog::onSave()
{
    accept();
}
