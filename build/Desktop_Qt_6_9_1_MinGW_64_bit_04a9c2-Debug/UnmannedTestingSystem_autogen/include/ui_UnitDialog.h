/********************************************************************************
** Form generated from reading UI file 'UnitDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITDIALOG_H
#define UI_UNITDIALOG_H

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

class Ui_UnitDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label_2;
    QComboBox *comboType;
    QLabel *label_3;
    QLineEdit *lineAddress;
    QLabel *label_4;
    QLineEdit *lineContact;
    QLabel *label_5;
    QLineEdit *linePhone;
    QLabel *labelError;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UnitDialog)
    {
        if (UnitDialog->objectName().isEmpty())
            UnitDialog->setObjectName("UnitDialog");
        UnitDialog->resize(500, 400);
        verticalLayout = new QVBoxLayout(UnitDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(UnitDialog);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineName = new QLineEdit(groupBox);
        lineName->setObjectName("lineName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineName);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        comboType = new QComboBox(groupBox);
        comboType->setObjectName("comboType");
        comboType->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboType);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        lineAddress = new QLineEdit(groupBox);
        lineAddress->setObjectName("lineAddress");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineAddress);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        lineContact = new QLineEdit(groupBox);
        lineContact->setObjectName("lineContact");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineContact);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        linePhone = new QLineEdit(groupBox);
        linePhone->setObjectName("linePhone");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, linePhone);


        verticalLayout->addWidget(groupBox);

        labelError = new QLabel(UnitDialog);
        labelError->setObjectName("labelError");
        labelError->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelError);

        buttonBox = new QDialogButtonBox(UnitDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(UnitDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, UnitDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, UnitDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(UnitDialog);
    } // setupUi

    void retranslateUi(QDialog *UnitDialog)
    {
        UnitDialog->setWindowTitle(QCoreApplication::translate("UnitDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UnitDialog", "\345\215\225\344\275\215\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("UnitDialog", "\345\215\225\344\275\215\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("UnitDialog", "\345\215\225\344\275\215\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("UnitDialog", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("UnitDialog", "\350\201\224\347\263\273\344\272\272\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("UnitDialog", "\347\224\265\350\257\235\357\274\232", nullptr));
        labelError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UnitDialog: public Ui_UnitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITDIALOG_H
