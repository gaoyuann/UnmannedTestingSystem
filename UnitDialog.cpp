#include "UnitDialog.h"
#include "ui_UnitDialog.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPushButton>

UnitDialog::UnitDialog(QWidget *parent, Mode mode, const UnitData &data)
    : QDialog(parent),
    ui(new Ui::UnitDialog),
    m_mode(mode)
{
    ui->setupUi(this);

    // 修改按钮文本
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确认");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("关闭");

    // 根据模式设置窗口标题
    setWindowTitle(m_mode == NewUnit ? "新增参试单位" : "编辑参试单位");
    setFixedSize(500, 350);  // 调整了高度

    // 设置样式
    setStyleSheet(R"(
    QDialog {
        background-color: #f8f9fa;
        font-family: 'Microsoft YaHei', 'Segoe UI';
    }
    QLabel {
        color: #333333;
        font-size: 13px;
    }
    QLineEdit, QComboBox {
        border: 1px solid #d0d0d0;
        border-radius: 4px;
        padding: 8px;
        font-size: 13px;
        background-color: white;
        color: #000000;  /* 确保字体颜色为黑色 */
    }
    QComboBox QAbstractItemView {
        color: #000000;  /* 下拉列表中项目的字体颜色 */
        background-color: white;  /* 下拉列表背景色 */
    }
    QLineEdit:focus, QComboBox:focus {
        border: 1px solid #4a90e2;
        box-shadow: 0 0 0 2px rgba(74,144,226,0.2);
    }
    QPushButton {
        background-color: #3a6ea5;
        color: white;
        border: none;
        padding: 8px 16px;
        border-radius: 4px;
        font-size: 13px;
        min-width: 80px;
    }
    QPushButton:hover {
        background-color: #4a90e2;
    }
    QPushButton:pressed {
        background-color: #2a5685;
    }
    QPushButton:disabled {
        background-color: #cccccc;
        color: #666666;
    }
)");

    // 初始化单位类型下拉框
    QStringList unitTypes = {"科研院所", "高等院校", "企业单位", "政府部门", "其他"};
    ui->comboType->addItems(unitTypes);

    // 设置数据
    if (mode == EditUnit) {
        setUnitData(data);
    }

    // 连接信号槽
    connect(ui->lineName, &QLineEdit::textChanged, this, &UnitDialog::validateInput);
    connect(ui->lineContact, &QLineEdit::textChanged, this, &UnitDialog::validateInput);
    connect(ui->linePhone, &QLineEdit::textChanged, this, &UnitDialog::validateInput);

    // 初始验证
    validateInput();
}

UnitDialog::~UnitDialog()
{
    delete ui;
}

UnitDialog::UnitData UnitDialog::getUnitData() const
{
    UnitData data;
    data.name = ui->lineName->text().trimmed();
    data.address = ui->lineAddress->text().trimmed();
    data.contact = ui->lineContact->text().trimmed();
    data.phone = ui->linePhone->text().trimmed();
    data.type = ui->comboType->currentText();
    return data;
}

void UnitDialog::setUnitData(const UnitData &data)
{
    ui->lineName->setText(data.name);
    ui->lineAddress->setText(data.address);
    ui->lineContact->setText(data.contact);
    ui->linePhone->setText(data.phone);
    ui->comboType->setCurrentText(data.type);
}

void UnitDialog::validateInput()
{
    bool valid = true;
    QString error;

    // 验证单位名称
    if (ui->lineName->text().trimmed().isEmpty()) {
        valid = false;
        error = "单位名称不能为空";
    }
    // 验证联系人
    else if (ui->lineContact->text().trimmed().isEmpty()) {
        valid = false;
        error = "联系人不能为空";
    }
    // 验证电话号码
    else if (ui->linePhone->text().trimmed().isEmpty()) {
        valid = false;
        error = "联系电话不能为空";
    }
    else {
        QRegularExpression phoneRegex(R"(^[\d\-\(\)\s\+]+$)");
        if (!phoneRegex.match(ui->linePhone->text()).hasMatch()) {
            valid = false;
            error = "请输入有效的电话号码";
        }
    }

    // 设置确定按钮状态
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(valid);

    // 显示错误提示
    if (!valid) {
        ui->labelError->setText(error);
        ui->labelError->setStyleSheet("color: red; font-size: 12px;");
    } else {
        ui->labelError->clear();
    }
}
