/********************************************************************************
** Form generated from reading UI file 'UserDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

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

class Ui_UserDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineUsername;
    QLabel *label_2;
    QLineEdit *lineName;
    QLabel *label_3;
    QLineEdit *linePassword;
    QLabel *label_4;
    QLineEdit *linePhone;
    QLabel *label_5;
    QComboBox *comboOrg;
    QLabel *labelError;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(500, 320);
        verticalLayout = new QVBoxLayout(UserDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(UserDialog);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineUsername = new QLineEdit(groupBox);
        lineUsername->setObjectName("lineUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineUsername);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        lineName = new QLineEdit(groupBox);
        lineName->setObjectName("lineName");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineName);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        linePassword = new QLineEdit(groupBox);
        linePassword->setObjectName("linePassword");
        linePassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, linePassword);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        linePhone = new QLineEdit(groupBox);
        linePhone->setObjectName("linePhone");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, linePhone);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        comboOrg = new QComboBox(groupBox);
        comboOrg->setObjectName("comboOrg");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, comboOrg);


        verticalLayout->addWidget(groupBox);

        labelError = new QLabel(UserDialog);
        labelError->setObjectName("labelError");
        labelError->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelError->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px;"));

        verticalLayout->addWidget(labelError);

        buttonBox = new QDialogButtonBox(UserDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(UserDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, UserDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, UserDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UserDialog", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("UserDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("UserDialog", "\347\234\237\345\256\236\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("UserDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        linePassword->setPlaceholderText(QCoreApplication::translate("UserDialog", "\346\226\260\345\242\236\347\224\250\346\210\267\345\277\205\345\241\253\357\274\214\347\274\226\350\276\221\345\217\257\347\225\231\347\251\272\357\274\210\344\270\215\344\277\256\346\224\271\345\257\206\347\240\201\357\274\211", nullptr));
        label_4->setText(QCoreApplication::translate("UserDialog", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("UserDialog", "\346\211\200\345\261\236\346\234\272\346\236\204\357\274\232", nullptr));
        labelError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
