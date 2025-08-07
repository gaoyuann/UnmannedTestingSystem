#include "ControlStationDialog.h"
#include "ui_ControlStationDialog.h"
#include "DBUtil.h"
#include <QPushButton>
#include <QMessageBox>
#include <QIntValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QToolTip>

ControlStationDialog::ControlStationDialog(QWidget *parent, DialogMode mode, const StationData &data)
    : QDialog(parent),
    ui(new Ui::ControlStationDialog),
    m_mode(mode)
{
    ui->setupUi(this);
    initUI();
    loadUnitList();
    setupConnections();

    // 初始化样式
    setErrorStyle(""); // 清除所有错误样式

    if (m_mode == EditStation && data.isValid()) {
        setWindowTitle("编辑控制站");
        ui->editName->setText(data.name);

        int unitIndex = ui->comboUnit->findText(data.unitName);
        if (unitIndex != -1) {
            ui->comboUnit->setCurrentIndex(unitIndex);
        }

        ui->comboType->setCurrentText(data.type);
        ui->editIP->setText(data.ip);
        ui->editPort->setText(QString::number(data.port));
        ui->comboStatus->setCurrentIndex(data.status);
    } else {
        setWindowTitle("新增控制站");
    }
}

ControlStationDialog::~ControlStationDialog()
{
    delete ui;
}

void ControlStationDialog::initUI()
{
    // 设置IP地址输入验证
    QRegularExpression ipRegex("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionValidator *ipValidator = new QRegularExpressionValidator(ipRegex, this);
    ui->editIP->setValidator(ipValidator);

    // 设置端口输入验证
    QIntValidator *portValidator = new QIntValidator(1, 65535, this);
    ui->editPort->setValidator(portValidator);

    // 初始化控制站类型下拉框
    ui->comboType->addItems({"无人机控制站", "无人艇控制站", "无人车控制站", "综合控制站"});

    // 初始化状态下拉框
    ui->comboStatus->addItems({"离线", "在线"});

    // 设置对话框按钮
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确定");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");

    // 初始禁用确定按钮
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    // 设置输入框提示
    ui->editName->setPlaceholderText("请输入控制站名称");
    ui->editIP->setPlaceholderText("例如: 192.168.1.1");
    ui->editPort->setPlaceholderText("1-65535");
}

void ControlStationDialog::setupConnections()
{
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ControlStationDialog::onAccept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // 输入验证
    connect(ui->editName, &QLineEdit::textChanged, this, &ControlStationDialog::validateInput);
    connect(ui->editIP, &QLineEdit::textChanged, this, &ControlStationDialog::validateInput);
    connect(ui->editPort, &QLineEdit::textChanged, this, &ControlStationDialog::validateInput);
    connect(ui->comboUnit, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ControlStationDialog::validateInput);
}

void ControlStationDialog::onAccept()
{
    QString errorMsg;
    if (!validateAll(errorMsg)) {
        QMessageBox::warning(this, "输入错误", errorMsg);
        return;
    }

    accept();
}

bool ControlStationDialog::validateAll(QString &errorMsg)
{
    errorMsg.clear();

    // 验证控制站名称
    if (ui->editName->text().trimmed().isEmpty()) {
        errorMsg += "• 控制站名称不能为空\n";
        setErrorStyle("name");
    }

    // 验证所属单位
    if (ui->comboUnit->currentIndex() < 0) {
        errorMsg += "• 请选择所属单位\n";
        setErrorStyle("unit");
    }

    // 验证IP地址
    QString ip = ui->editIP->text().trimmed();
    QRegularExpression ipRegex("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    if (ip.isEmpty()) {
        errorMsg += "• IP地址不能为空\n";
        setErrorStyle("ip");
    } else if (!ipRegex.match(ip).hasMatch()) {
        errorMsg += "• IP地址格式不正确\n";
        setErrorStyle("ip");
    }

    // 验证端口
    bool portOk;
    int port = ui->editPort->text().toInt(&portOk);
    if (ui->editPort->text().trimmed().isEmpty()) {
        errorMsg += "• 端口不能为空\n";
        setErrorStyle("port");
    } else if (!portOk || port <= 0 || port > 65535) {
        errorMsg += "• 端口必须是1-65535之间的整数\n";
        setErrorStyle("port");
    }

    return errorMsg.isEmpty();
}

void ControlStationDialog::validateInput()
{
    QString errorMsg;
    bool isValid = validateAll(errorMsg);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isValid);

    // 实时显示错误提示
    QLineEdit *senderEdit = qobject_cast<QLineEdit*>(sender());
    if (senderEdit) {
        if (!isValid && !senderEdit->text().isEmpty()) {
            if (senderEdit == ui->editIP && !errorMsg.contains("IP地址格式不正确")) {
                return;
            }
            if (senderEdit == ui->editPort && !errorMsg.contains("端口必须是")) {
                return;
            }
            QToolTip::showText(senderEdit->mapToGlobal(QPoint(0, senderEdit->height())),
                               errorMsg, senderEdit, QRect(), 3000);
        } else {
            QToolTip::hideText();
        }
    }
}

void ControlStationDialog::setErrorStyle(const QString &field)
{
    // 清除所有错误样式
    ui->editName->setStyleSheet("");
    ui->comboUnit->setStyleSheet("");
    ui->editIP->setStyleSheet("");
    ui->editPort->setStyleSheet("");

    // 设置指定字段的错误样式
    QString errorStyle = "border: 1px solid red; background-color: #FFF0F0;";
    if (field == "name") {
        ui->editName->setStyleSheet(errorStyle);
    } else if (field == "unit") {
        ui->comboUnit->setStyleSheet(errorStyle);
    } else if (field == "ip") {
        ui->editIP->setStyleSheet(errorStyle);
    } else if (field == "port") {
        ui->editPort->setStyleSheet(errorStyle);
    }
}

ControlStationDialog::StationData ControlStationDialog::getStationData() const
{
    StationData data;
    data.name = ui->editName->text().trimmed();
    data.unitName = ui->comboUnit->currentText();
    data.type = ui->comboType->currentText();
    data.ip = ui->editIP->text().trimmed();
    data.port = ui->editPort->text().toInt();
    data.status = ui->comboStatus->currentIndex();
    return data;
}

void ControlStationDialog::loadUnitList()
{
    QString sql = "SELECT unit_id, unit_name FROM participate_unit WHERE is_delete = 0 ORDER BY unit_name";
    auto results = DBUtil::instance()->query(sql);

    ui->comboUnit->clear();
    ui->comboUnit->addItem("请选择所属单位", -1); // 添加默认选项

    for (const auto& row : results) {
        ui->comboUnit->addItem(row["unit_name"].toString(), row["unit_id"].toInt());
    }

    ui->comboUnit->setCurrentIndex(0);
}
