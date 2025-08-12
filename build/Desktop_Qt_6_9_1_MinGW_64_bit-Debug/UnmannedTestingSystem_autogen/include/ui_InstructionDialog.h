/********************************************************************************
** Form generated from reading UI file 'InstructionDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONDIALOG_H
#define UI_INSTRUCTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InstructionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBasic;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *editName;
    QLabel *labelProtocol;
    QComboBox *comboProtocol;
    QLabel *labelCode;
    QLineEdit *editCode;
    QLabel *labelType;
    QComboBox *comboType;
    QGroupBox *groupContent;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *textContent;
    QLabel *labelJsonError;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InstructionDialog)
    {
        if (InstructionDialog->objectName().isEmpty())
            InstructionDialog->setObjectName("InstructionDialog");
        InstructionDialog->resize(600, 500);
        InstructionDialog->setStyleSheet(QString::fromUtf8("\n"
"    QDialog {\n"
"        background-color: #f5f7fa;\n"
"        font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"        color: black; /* \345\205\250\345\261\200\345\255\227\344\275\223\351\242\234\350\211\262\350\256\276\347\275\256\344\270\272\351\273\221\350\211\262 */\n"
"    }\n"
"    QGroupBox {\n"
"        border: 1px solid #d0d0d0;\n"
"        border-radius: 4px;\n"
"        margin-top: 10px;\n"
"        padding-top: 15px;\n"
"        padding-bottom: 10px;\n"
"        padding-left: 10px;\n"
"        padding-right: 10px;\n"
"        background-color: white;\n"
"        color: black; /* \345\210\206\347\273\204\346\241\206\346\240\207\351\242\230\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    }\n"
"    QLabel {\n"
"        color: black; /* \346\211\200\346\234\211\346\240\207\347\255\276\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(InstructionDialog);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        groupBasic = new QGroupBox(InstructionDialog);
        groupBasic->setObjectName("groupBasic");
        formLayout = new QFormLayout(groupBasic);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelName = new QLabel(groupBasic);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        editName = new QLineEdit(groupBasic);
        editName->setObjectName("editName");
        editName->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              padding: 6px 10px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              background-color: white;\n"
"              color: black; /* \350\276\223\345\205\245\346\241\206\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"          }\n"
"          QLineEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"              box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"          }\n"
"         "));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editName);

        labelProtocol = new QLabel(groupBasic);
        labelProtocol->setObjectName("labelProtocol");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelProtocol);

        comboProtocol = new QComboBox(groupBasic);
        comboProtocol->setObjectName("comboProtocol");
        comboProtocol->setStyleSheet(QString::fromUtf8("\n"
"          QComboBox {\n"
"              padding: 6px 10px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              background-color: white;\n"
"              color: black; /* \344\270\213\346\213\211\346\241\206\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"          }\n"
"          QComboBox::drop-down {\n"
"              width: 20px;\n"
"              border: none;\n"
"          }\n"
"          QComboBox QAbstractItemView {\n"
"              color: black; /* \344\270\213\346\213\211\351\200\211\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"              background-color: white;\n"
"          }\n"
"         "));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboProtocol);

        labelCode = new QLabel(groupBasic);
        labelCode->setObjectName("labelCode");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelCode);

        editCode = new QLineEdit(groupBasic);
        editCode->setObjectName("editCode");
        editCode->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              padding: 6px 10px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              background-color: white;\n"
"              color: black;\n"
"          }\n"
"          QLineEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"              box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"          }\n"
"         "));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, editCode);

        labelType = new QLabel(groupBasic);
        labelType->setObjectName("labelType");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelType);

        comboType = new QComboBox(groupBasic);
        comboType->setObjectName("comboType");
        comboType->setStyleSheet(QString::fromUtf8("\n"
"          QComboBox {\n"
"              padding: 6px 10px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              background-color: white;\n"
"              color: black;\n"
"          }\n"
"          QComboBox::drop-down {\n"
"              width: 20px;\n"
"              border: none;\n"
"          }\n"
"          QComboBox QAbstractItemView {\n"
"              color: black;\n"
"              background-color: white;\n"
"          }\n"
"         "));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, comboType);


        verticalLayout->addWidget(groupBasic);

        groupContent = new QGroupBox(InstructionDialog);
        groupContent->setObjectName("groupContent");
        verticalLayout_2 = new QVBoxLayout(groupContent);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        textContent = new QPlainTextEdit(groupContent);
        textContent->setObjectName("textContent");
        textContent->setStyleSheet(QString::fromUtf8("\n"
"          QPlainTextEdit {\n"
"              font-family: \"Consolas\", \"Courier New\", monospace;\n"
"              font-size: 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              padding: 4px;\n"
"              background-color: white;\n"
"              color: black; /* JSON\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"          }\n"
"          QPlainTextEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"              box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"          }\n"
"         "));

        verticalLayout_2->addWidget(textContent);

        labelJsonError = new QLabel(groupContent);
        labelJsonError->setObjectName("labelJsonError");
        labelJsonError->setStyleSheet(QString::fromUtf8("\n"
"          color: #e74c3c; /* \351\224\231\350\257\257\344\277\241\346\201\257\344\277\235\346\214\201\347\272\242\350\211\262 */\n"
"          font-size: 12px;\n"
"         "));

        verticalLayout_2->addWidget(labelJsonError);


        verticalLayout->addWidget(groupContent);

        buttonBox = new QDialogButtonBox(InstructionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("\n"
"       QPushButton {\n"
"           min-width: 80px;\n"
"           padding: 6px 12px;\n"
"           color: black; /* \346\214\211\351\222\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"       }\n"
"      "));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InstructionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, InstructionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, InstructionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(InstructionDialog);
    } // setupUi

    void retranslateUi(QDialog *InstructionDialog)
    {
        InstructionDialog->setWindowTitle(QCoreApplication::translate("InstructionDialog", "\346\214\207\344\273\244\347\274\226\350\276\221", nullptr));
        groupBasic->setTitle(QCoreApplication::translate("InstructionDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        labelName->setText(QCoreApplication::translate("InstructionDialog", "\346\214\207\344\273\244\345\220\215\347\247\260\357\274\232", nullptr));
        labelProtocol->setText(QCoreApplication::translate("InstructionDialog", "\346\211\200\345\261\236\345\215\217\350\256\256\357\274\232", nullptr));
        labelCode->setText(QCoreApplication::translate("InstructionDialog", "\346\214\207\344\273\244\347\274\226\347\240\201\357\274\232", nullptr));
        labelType->setText(QCoreApplication::translate("InstructionDialog", "\346\214\207\344\273\244\347\261\273\345\236\213\357\274\232", nullptr));
        groupContent->setTitle(QCoreApplication::translate("InstructionDialog", "\346\214\207\344\273\244\345\206\205\345\256\271 (JSON\346\240\274\345\274\217)", nullptr));
        labelJsonError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InstructionDialog: public Ui_InstructionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONDIALOG_H
