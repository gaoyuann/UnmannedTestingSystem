/********************************************************************************
** Form generated from reading UI file 'ProtocolDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOCOLDIALOG_H
#define UI_PROTOCOLDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProtocolDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QWidget *formContainer;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *lineName;
    QLabel *labelType;
    QComboBox *comboType;
    QLabel *labelDesc;
    QTextEdit *textDescription;
    QWidget *buttonContainer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *ProtocolDialog)
    {
        if (ProtocolDialog->objectName().isEmpty())
            ProtocolDialog->setObjectName("ProtocolDialog");
        ProtocolDialog->resize(500, 400);
        ProtocolDialog->setStyleSheet(QString::fromUtf8("background-color: #f5f7fa;"));
        verticalLayout = new QVBoxLayout(ProtocolDialog);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        labelTitle = new QLabel(ProtocolDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("\n"
"      font-size: 16px;\n"
"      font-weight: bold;\n"
"      color: #333333;\n"
"      "));

        verticalLayout->addWidget(labelTitle);

        formContainer = new QWidget(ProtocolDialog);
        formContainer->setObjectName("formContainer");
        formContainer->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 12px;\n"
"       box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"      "));
        formLayout = new QFormLayout(formContainer);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(6, 6, 6, 6);
        labelName = new QLabel(formContainer);
        labelName->setObjectName("labelName");
        labelName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        lineName = new QLineEdit(formContainer);
        lineName->setObjectName("lineName");
        lineName->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              padding: 8px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              background-color: white;\n"
"              color: #333333;\n"
"          }\n"
"          QLineEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"              box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"          }\n"
"         "));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineName);

        labelType = new QLabel(formContainer);
        labelType->setObjectName("labelType");
        labelType->setStyleSheet(QString::fromUtf8("color: black;"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelType);

        comboType = new QComboBox(formContainer);
        comboType->setObjectName("comboType");
        comboType->setStyleSheet(QString::fromUtf8("\n"
"         QComboBox {\n"
"             padding: 8px 12px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 4px;\n"
"             font-size: 13px;\n"
"             background-color: white;\n"
"             color: black;  /* \344\270\273\346\226\207\346\234\254\351\242\234\350\211\262\346\224\271\344\270\272\351\273\221\350\211\262 */\n"
"         }\n"
"         QComboBox::drop-down {\n"
"             width: 20px;\n"
"             border: none;\n"
"         }\n"
"         QComboBox QAbstractItemView {\n"
"             color: black;  /* \344\270\213\346\213\211\345\210\227\350\241\250\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"             background-color: white;  /* \344\270\213\346\213\211\345\210\227\350\241\250\350\203\214\346\231\257 */\n"
"             selection-background-color: #3a6ea5;  /* \351\200\211\344\270\255\351\241\271\350\203\214\346\231\257 */\n"
"             selection-color: white;  /* \351\200\211\344\270\255\351\241\271\346\226\207\345\255\227\351\242"
                        "\234\350\211\262 */\n"
"         }\n"
"         "));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboType);

        labelDesc = new QLabel(formContainer);
        labelDesc->setObjectName("labelDesc");
        labelDesc->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelDesc);

        textDescription = new QTextEdit(formContainer);
        textDescription->setObjectName("textDescription");
        textDescription->setStyleSheet(QString::fromUtf8("\n"
"          QTextEdit {\n"
"              padding: 8px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              background-color: white;\n"
"              color: #333333;\n"
"          }\n"
"          QTextEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"              box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"          }\n"
"         "));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, textDescription);


        verticalLayout->addWidget(formContainer);

        buttonContainer = new QWidget(ProtocolDialog);
        buttonContainer->setObjectName("buttonContainer");
        buttonContainer->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 8px;\n"
"       box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"      "));
        horizontalLayout = new QHBoxLayout(buttonContainer);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(buttonContainer);
        btnOK->setObjectName("btnOK");
        btnOK->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #27ae60;\n"
"              color: white;\n"
"              border: none;\n"
"              padding: 8px 16px;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              min-width: 80px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #2ecc71;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #219955;\n"
"          }\n"
"         "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/ok.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnOK->setIcon(icon);

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(buttonContainer);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #95a5a6;\n"
"              color: white;\n"
"              border: none;\n"
"              padding: 8px 16px;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              min-width: 80px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #7f8c8d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #6c7a7d;\n"
"          }\n"
"         "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cancel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnCancel->setIcon(icon1);

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addWidget(buttonContainer);


        retranslateUi(ProtocolDialog);
        QObject::connect(btnOK, &QPushButton::clicked, ProtocolDialog, qOverload<>(&QDialog::accept));
        QObject::connect(btnCancel, &QPushButton::clicked, ProtocolDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ProtocolDialog);
    } // setupUi

    void retranslateUi(QDialog *ProtocolDialog)
    {
        ProtocolDialog->setWindowTitle(QCoreApplication::translate("ProtocolDialog", "\345\215\217\350\256\256\344\277\241\346\201\257", nullptr));
        labelTitle->setText(QCoreApplication::translate("ProtocolDialog", "\345\215\217\350\256\256\344\277\241\346\201\257", nullptr));
        labelName->setText(QCoreApplication::translate("ProtocolDialog", "\345\215\217\350\256\256\345\220\215\347\247\260\357\274\232", nullptr));
        labelType->setText(QCoreApplication::translate("ProtocolDialog", "\345\215\217\350\256\256\347\261\273\345\236\213\357\274\232", nullptr));
        labelDesc->setText(QCoreApplication::translate("ProtocolDialog", "\345\215\217\350\256\256\346\217\217\350\277\260\357\274\232", nullptr));
        btnOK->setText(QCoreApplication::translate("ProtocolDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("ProtocolDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProtocolDialog: public Ui_ProtocolDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOCOLDIALOG_H
