/********************************************************************************
** Form generated from reading UI file 'ControlStationDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLSTATIONDIALOG_H
#define UI_CONTROLSTATIONDIALOG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ControlStationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *editName;
    QLabel *labelUnit;
    QComboBox *comboUnit;
    QLabel *labelType;
    QComboBox *comboType;
    QLabel *labelIP;
    QLineEdit *editIP;
    QLabel *labelPort;
    QLineEdit *editPort;
    QLabel *labelStatus;
    QComboBox *comboStatus;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ControlStationDialog)
    {
        if (ControlStationDialog->objectName().isEmpty())
            ControlStationDialog->setObjectName("ControlStationDialog");
        ControlStationDialog->resize(400, 365);
        ControlStationDialog->setStyleSheet(QString::fromUtf8("background-color: #f5f7fa;"));
        verticalLayout = new QVBoxLayout(ControlStationDialog);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        groupBox = new QGroupBox(ControlStationDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"      QGroupBox {\n"
"          border: 1px solid #d0d0d0;\n"
"          border-radius: 4px;\n"
"          margin-top: 10px;\n"
"          padding-top: 15px;\n"
"          font-weight: bold;\n"
"      }\n"
"      QGroupBox::title {\n"
"          subcontrol-origin: margin;\n"
"          left: 10px;\n"
"          padding: 0 3px;\n"
"      }\n"
"      "));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(8);
        formLayout->setVerticalSpacing(8);
        formLayout->setContentsMargins(8, 16, 8, 8);
        labelName = new QLabel(groupBox);
        labelName->setObjectName("labelName");
        labelName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        editName = new QLineEdit(groupBox);
        editName->setObjectName("editName");
        editName->setStyleSheet(QString::fromUtf8("\n"
"         QLineEdit {\n"
"             padding: 6px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 3px;\n"
"         }\n"
"         QLineEdit:focus {\n"
"             border: 1px solid #4a90e2;\n"
"         }\n"
"         "));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editName);

        labelUnit = new QLabel(groupBox);
        labelUnit->setObjectName("labelUnit");
        labelUnit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelUnit);

        comboUnit = new QComboBox(groupBox);
        comboUnit->setObjectName("comboUnit");
        comboUnit->setStyleSheet(QString::fromUtf8("\n"
"         QComboBox {\n"
"             padding: 6px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 3px;\n"
"         }\n"
"         QComboBox::drop-down {\n"
"             width: 20px;\n"
"             border: none;\n"
"         }\n"
"         "));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboUnit);

        labelType = new QLabel(groupBox);
        labelType->setObjectName("labelType");
        labelType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelType);

        comboType = new QComboBox(groupBox);
        comboType->setObjectName("comboType");
        comboType->setStyleSheet(QString::fromUtf8("\n"
"         QComboBox {\n"
"             padding: 6px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 3px;\n"
"         }\n"
"         QComboBox::drop-down {\n"
"             width: 20px;\n"
"             border: none;\n"
"         }\n"
"         "));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboType);

        labelIP = new QLabel(groupBox);
        labelIP->setObjectName("labelIP");
        labelIP->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelIP);

        editIP = new QLineEdit(groupBox);
        editIP->setObjectName("editIP");
        editIP->setStyleSheet(QString::fromUtf8("\n"
"         QLineEdit {\n"
"             padding: 6px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 3px;\n"
"         }\n"
"         QLineEdit:focus {\n"
"             border: 1px solid #4a90e2;\n"
"         }\n"
"         "));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, editIP);

        labelPort = new QLabel(groupBox);
        labelPort->setObjectName("labelPort");
        labelPort->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelPort);

        editPort = new QLineEdit(groupBox);
        editPort->setObjectName("editPort");
        editPort->setStyleSheet(QString::fromUtf8("\n"
"         QLineEdit {\n"
"             padding: 6px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 3px;\n"
"         }\n"
"         QLineEdit:focus {\n"
"             border: 1px solid #4a90e2;\n"
"         }\n"
"         "));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, editPort);

        labelStatus = new QLabel(groupBox);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelStatus);

        comboStatus = new QComboBox(groupBox);
        comboStatus->setObjectName("comboStatus");
        comboStatus->setStyleSheet(QString::fromUtf8("\n"
"         QComboBox {\n"
"             padding: 6px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 3px;\n"
"         }\n"
"         QComboBox::drop-down {\n"
"             width: 20px;\n"
"             border: none;\n"
"         }\n"
"         "));

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, comboStatus);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(ControlStationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ControlStationDialog);

        QMetaObject::connectSlotsByName(ControlStationDialog);
    } // setupUi

    void retranslateUi(QDialog *ControlStationDialog)
    {
        ControlStationDialog->setWindowTitle(QCoreApplication::translate("ControlStationDialog", "\346\216\247\345\210\266\347\253\231\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ControlStationDialog", "\346\216\247\345\210\266\347\253\231\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        labelName->setText(QCoreApplication::translate("ControlStationDialog", "\346\216\247\345\210\266\347\253\231\345\220\215\347\247\260\357\274\232", nullptr));
        editName->setPlaceholderText(QCoreApplication::translate("ControlStationDialog", "\350\257\267\350\276\223\345\205\245\346\216\247\345\210\266\347\253\231\345\220\215\347\247\260", nullptr));
        labelUnit->setText(QCoreApplication::translate("ControlStationDialog", "\346\211\200\345\261\236\345\215\225\344\275\215\357\274\232", nullptr));
        labelType->setText(QCoreApplication::translate("ControlStationDialog", "\346\216\247\345\210\266\347\253\231\347\261\273\345\236\213\357\274\232", nullptr));
        labelIP->setText(QCoreApplication::translate("ControlStationDialog", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        editIP->setPlaceholderText(QCoreApplication::translate("ControlStationDialog", "\344\276\213\345\246\202\357\274\232192.168.1.100", nullptr));
        labelPort->setText(QCoreApplication::translate("ControlStationDialog", "\351\200\232\344\277\241\347\253\257\345\217\243\357\274\232", nullptr));
        editPort->setPlaceholderText(QCoreApplication::translate("ControlStationDialog", "1-65535", nullptr));
        labelStatus->setText(QCoreApplication::translate("ControlStationDialog", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlStationDialog: public Ui_ControlStationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLSTATIONDIALOG_H
