#include "InstructionDialog.h"
#include "ui_InstructionDialog.h"

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QPushButton>

InstructionDialog::InstructionDialog(QWidget *parent, DialogMode mode,
                                     const QMap<int, QString> &protocolMap,
                                     const InstructionData &data) :
    QDialog(parent),
    ui(new Ui::InstructionDialog),
    m_mode(mode),
    m_protocolMap(protocolMap)
{
    ui->setupUi(this);
    initUI();
    setupConnections();

    if (m_mode == EditInstruction) {
        setWindowTitle("编辑指令");
        ui->editName->setText(data.name);
        ui->editCode->setText(data.code);
        ui->comboType->setCurrentText(data.type);

        // 设置协议
        int protocolIndex = ui->comboProtocol->findData(data.protocolId);
        if (protocolIndex != -1) {
            ui->comboProtocol->setCurrentIndex(protocolIndex);
        }

        // 设置内容
        QJsonDocument doc = QJsonDocument::fromJson(data.content.toUtf8());
        ui->textContent->setPlainText(doc.toJson(QJsonDocument::Indented));
    } else {
        setWindowTitle("新增指令");
    }

    validateInputs();
}

InstructionDialog::~InstructionDialog()
{
    delete ui;
}

void InstructionDialog::initUI()
{
    ui->comboProtocol->clear();
    for (auto it = m_protocolMap.begin(); it != m_protocolMap.end(); ++it) {
        ui->comboProtocol->addItem(it.value(), it.key());
    }

    // 初始化指令类型
    ui->comboType->addItems({"控制指令", "查询指令", "配置指令", "状态指令", "测试指令"});

    // 设置JSON高亮
    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(10);
    ui->textContent->setFont(font);
}

void InstructionDialog::setupConnections()
{
    connect(ui->comboProtocol, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &InstructionDialog::onProtocolChanged);
    connect(ui->editName, &QLineEdit::textChanged, this, &InstructionDialog::validateInputs);
    connect(ui->editCode, &QLineEdit::textChanged, this, &InstructionDialog::validateInputs);
    connect(ui->textContent, &QPlainTextEdit::textChanged, this, &InstructionDialog::validateInputs);
}

InstructionDialog::InstructionData InstructionDialog::getInstructionData() const
{
    InstructionData data;
    data.name = ui->editName->text().trimmed();
    data.protocolId = ui->comboProtocol->currentData().toInt();
    data.protocolName = ui->comboProtocol->currentText();
    data.code = ui->editCode->text().trimmed();
    data.content = ui->textContent->toPlainText();
    data.type = ui->comboType->currentText();

    return data;
}

void InstructionDialog::onProtocolChanged(int index)
{
    Q_UNUSED(index);
    // 这里可以添加根据协议变化更新UI的逻辑
    // 例如加载协议模板或验证规则
}

void InstructionDialog::validateInputs()
{
    bool valid = !ui->editName->text().trimmed().isEmpty() &&
                 !ui->editCode->text().trimmed().isEmpty() &&
                 ui->comboProtocol->currentIndex() >= 0;

    // 验证JSON格式
    QJsonParseError error;
    QJsonDocument::fromJson(ui->textContent->toPlainText().toUtf8(), &error);
    valid = valid && (error.error == QJsonParseError::NoError);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(valid);

    // 设置JSON格式错误提示
    if (error.error != QJsonParseError::NoError && !ui->textContent->toPlainText().isEmpty()) {
        ui->labelJsonError->setText(QString("JSON格式错误: %1 (位置: %2)")
                                        .arg(error.errorString())
                                        .arg(error.offset));
    } else {
        ui->labelJsonError->clear();
    }
}
