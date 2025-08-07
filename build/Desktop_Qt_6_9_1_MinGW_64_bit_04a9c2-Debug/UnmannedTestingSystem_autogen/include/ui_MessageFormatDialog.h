/********************************************************************************
** Form generated from reading UI file 'MessageFormatDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEFORMATDIALOG_H
#define UI_MESSAGEFORMATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageFormatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableFormats;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *MessageFormatDialog)
    {
        if (MessageFormatDialog->objectName().isEmpty())
            MessageFormatDialog->setObjectName("MessageFormatDialog");
        MessageFormatDialog->resize(800, 600);
        MessageFormatDialog->setStyleSheet(QString::fromUtf8("\n"
"    QDialog {\n"
"        background-color: #f5f7fa;\n"
"        font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"    }\n"
"    QTableWidget {\n"
"        font-size: 13px;\n"
"        color: black;\n"
"        background-color: white;\n"
"        alternate-background-color: #f8f9fa;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 6px;\n"
"        gridline-color: #e0e0e0;\n"
"    }\n"
"    QTableWidget::item {\n"
"        color: black;\n"
"        padding: 8px;\n"
"        border-bottom: 1px solid #f0f0f0;\n"
"    }\n"
"    QTableWidget QLineEdit {\n"
"        color: black;\n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: #9b59b6;\n"
"        color: white;\n"
"        padding: 8px;\n"
"        border: none;\n"
"        font-weight: 500;\n"
"        font-size: 13px;\n"
"    }\n"
"    QComboBox {\n"
"        color: black;\n"
"        background-color: white;\n"
"        border: 1px solid #d0d0d0;\n"
"        border-radius: 3px;\n"
"        padding: 0px 6"
                        "px;  /* \344\270\212\344\270\2130px\357\274\214\345\267\246\345\217\2636px */\n"
"        text-align: center;\n"
"        min-width: 100px;\n"
"        max-width: 200px;\n"
"        min-height: 24px;  /* \350\260\203\346\225\264\344\270\272\346\240\207\345\207\206\351\253\230\345\272\246 */\n"
"        max-height: 24px;\n"
"        line-height: 24px; /* \350\241\214\351\253\230\344\270\216\351\253\230\345\272\246\344\270\200\350\207\264\347\241\256\344\277\235\345\236\202\347\233\264\345\261\205\344\270\255 */\n"
"        margin: 0px;\n"
"    }\n"
"    QComboBox QAbstractItemView {\n"
"        color: black;\n"
"        text-align: center;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(MessageFormatDialog);
        verticalLayout->setObjectName("verticalLayout");
        tableFormats = new QTableWidget(MessageFormatDialog);
        if (tableFormats->columnCount() < 6)
            tableFormats->setColumnCount(6);
        tableFormats->setObjectName("tableFormats");
        tableFormats->setRowCount(0);
        tableFormats->setColumnCount(6);
        tableFormats->setStyleSheet(QString::fromUtf8("QTableWidget::item { text-align: center; }"));

        verticalLayout->addWidget(tableFormats);

        buttonWidget = new QWidget(MessageFormatDialog);
        buttonWidget->setObjectName("buttonWidget");
        buttonWidget->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 8px;\n"
"       box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"      "));
        horizontalLayout = new QHBoxLayout(buttonWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnAdd = new QPushButton(buttonWidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #3a6ea5;\n"
"              color: white;\n"
"              border: none;\n"
"              padding: 8px 16px;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              min-width: 80px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #4a90e2;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #2a5685;\n"
"          }\n"
"         "));

        horizontalLayout->addWidget(btnAdd);

        btnRemove = new QPushButton(buttonWidget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #e74c3c;\n"
"              color: white;\n"
"              border: none;\n"
"              padding: 8px 16px;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              min-width: 80px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #c0392b;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #992d22;\n"
"          }\n"
"         "));

        horizontalLayout->addWidget(btnRemove);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(buttonWidget);
        btnSave->setObjectName("btnSave");
        btnSave->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(buttonWidget);
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

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addWidget(buttonWidget);


        retranslateUi(MessageFormatDialog);

        QMetaObject::connectSlotsByName(MessageFormatDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageFormatDialog)
    {
        MessageFormatDialog->setWindowTitle(QCoreApplication::translate("MessageFormatDialog", "\346\212\245\346\226\207\346\240\274\345\274\217\351\205\215\347\275\256", nullptr));
        btnAdd->setText(QCoreApplication::translate("MessageFormatDialog", "\346\267\273\345\212\240", nullptr));
        btnRemove->setText(QCoreApplication::translate("MessageFormatDialog", "\345\210\240\351\231\244", nullptr));
        btnSave->setText(QCoreApplication::translate("MessageFormatDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("MessageFormatDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageFormatDialog: public Ui_MessageFormatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEFORMATDIALOG_H
