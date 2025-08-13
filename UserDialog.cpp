#include "UserDialog.h"
#include "ui_UserDialog.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPushButton>
#include "DBUtil.h"

UserDialog::UserDialog(QWidget *parent, Mode mode, const UserData &data)
    : QDialog(parent),
    ui(new Ui::UserDialog),
    m_mode(mode)
{
    ui->setupUi(this);

    // 修改按钮文本
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确认");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("关闭");

    // 动态加载机构数据（关联organization表）
    QString sql = "SELECT org_id, org_name FROM organization ORDER BY org_id";
    QVector<QVariantMap> orgs = DBUtil::instance()->query(sql);
    for (const auto &org : orgs) {
        ui->comboOrg->addItem(org["org_name"].toString(), org["org_id"]);
    }

    // 根据模式设置窗口标题
    setWindowTitle(m_mode == NewUser ? "新增用户" : "编辑用户");
    setFixedSize(500, 300); // 调整窗口大小

    // 设置样式（保持不变）
    setStyleSheet(R"(
    QDialog {
        background-color: #f8f9fa;
        font-family: 'Microsoft YaHei', 'Segoe UI';
    }
    QLabel {
        color: #333333;
        font-size: 13px;
    }
    QLineEdit {
        border: 1px solid #d0d0d0;
        border-radius: 4px;
        padding: 8px;
        font-size: 13px;
        background-color: white;
        color: #000000;
    }
    QLineEdit:focus {
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

    // 设置数据
    if (mode == EditUser) {
        setUserData(data);
    }

    // 连接信号槽（移除邮箱、性别等相关信号）
    connect(ui->lineUsername, &QLineEdit::textChanged, this, &UserDialog::validateInput);
    connect(ui->lineName, &QLineEdit::textChanged, this, &UserDialog::validateInput);
    connect(ui->linePhone, &QLineEdit::textChanged, this, &UserDialog::validateInput);
    connect(ui->linePassword, &QLineEdit::textChanged, this, &UserDialog::validateInput); // 新增密码验证

    // 初始验证
    validateInput();
}

UserDialog::~UserDialog()
{
    delete ui;
}

UserDialog::UserData UserDialog::getUserData() const
{
    UserData data;
    data.username = ui->lineUsername->text().trimmed();
    data.name = ui->lineName->text().trimmed();
    data.phone = ui->linePhone->text().trimmed();
    data.password = ui->linePassword->text().trimmed(); // 新增密码
    return data;
}

void UserDialog::setUserData(const UserData &data)
{
    ui->lineUsername->setText(data.username);
    ui->lineName->setText(data.name);
    ui->linePhone->setText(data.phone);
    // 编辑模式下密码可以为空（保持原密码）
    if (m_mode == NewUser) {
        ui->linePassword->setText(data.password);
    }
}

void UserDialog::validateInput()
{
    bool valid = true;
    QString error;

    // 验证用户名
    if (ui->lineUsername->text().trimmed().isEmpty()) {
        valid = false;
        error = "用户名不能为空";
    }
    // 验证姓名
    else if (ui->lineName->text().trimmed().isEmpty()) {
        valid = false;
        error = "姓名不能为空";
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
        // 验证密码（新增）
        else if (m_mode == NewUser && ui->linePassword->text().trimmed().isEmpty()) {
            valid = false;
            error = "密码不能为空";
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

void UserDialog::setOrgId(int orgId)
{
    // 查找机构ID对应的索引并选中
    for (int i = 0; i < ui->comboOrg->count(); ++i) {
        if (ui->comboOrg->itemData(i).toInt() == orgId) {
            ui->comboOrg->setCurrentIndex(i);
            break;
        }
    }
}

int UserDialog::getOrgId() const
{
    // 返回选中的机构ID（从itemData中获取）
    return ui->comboOrg->currentData().toInt();
}
