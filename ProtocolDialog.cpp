#include "ProtocolDialog.h"
#include "ui_ProtocolDialog.h"

ProtocolDialog::ProtocolDialog(QWidget *parent, Mode mode, const ProtocolData &data) :
    QDialog(parent),
    ui(new Ui::ProtocolDialog),
    m_mode(mode)
{
    ui->setupUi(this);
    setWindowTitle(mode == NewProtocol ? "新增协议" : "编辑协议");

    // 初始化数据
    ui->lineName->setText(data.name);
    ui->comboType->setCurrentText(data.type);
    ui->textDescription->setPlainText(data.description);

    // 设置协议类型下拉选项
    QStringList types = {"GJB7102-2010", "自定义协议", "GJB289A", "GJB1188A"};
    ui->comboType->addItems(types);
}

ProtocolDialog::~ProtocolDialog()
{
    delete ui;
}

ProtocolDialog::ProtocolData ProtocolDialog::getProtocolData() const
{
    ProtocolData data;
    data.name = ui->lineName->text().trimmed();
    data.type = ui->comboType->currentText();
    data.description = ui->textDescription->toPlainText().trimmed();
    return data;
}
