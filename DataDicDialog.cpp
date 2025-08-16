#include "DataDicDialog.h"
#include "ui_DataDicDialog.h"
#include <QPushButton>

DataDicDialog::DataDicDialog(QWidget *parent, Mode mode, const DictData &data)
    : QDialog(parent),
    ui(new Ui::DataDicDialog),
    m_mode(mode)
{
    ui->setupUi(this);
    setWindowTitle(mode == NewDict ? "新增数据字典" : "编辑数据字典");

    if (mode == EditDict) {
        setDictData(data);
    }

    setupConnections();
    validateInput();
}

DataDicDialog::~DataDicDialog()
{
    delete ui;
}

void DataDicDialog::setupConnections()
{
    connect(ui->lineType, &QLineEdit::textChanged, this, &DataDicDialog::validateInput);
    connect(ui->lineKey, &QLineEdit::textChanged, this, &DataDicDialog::validateInput);
    connect(ui->lineValue, &QLineEdit::textChanged, this, &DataDicDialog::validateInput);
}

DataDicDialog::DictData DataDicDialog::getDictData() const
{
    DictData data;
    data.type = ui->lineType->text().trimmed();
    data.key = ui->lineKey->text().trimmed();
    data.value = ui->lineValue->text().trimmed();
    data.sort = ui->spinSort->value();
    return data;
}

void DataDicDialog::setDictData(const DictData &data)
{
    ui->lineType->setText(data.type);
    ui->lineKey->setText(data.key);
    ui->lineValue->setText(data.value);
    ui->spinSort->setValue(data.sort);
}

void DataDicDialog::validateInput()
{
    bool valid = true;
    QString error;

    if (ui->lineType->text().trimmed().isEmpty()) {
        valid = false;
        error = "字典类型不能为空";
    } else if (ui->lineKey->text().trimmed().isEmpty()) {
        valid = false;
        error = "键不能为空";
    } else if (ui->lineValue->text().trimmed().isEmpty()) {
        valid = false;
        error = "值不能为空";
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(valid);
    ui->labelError->setText(error);
}
