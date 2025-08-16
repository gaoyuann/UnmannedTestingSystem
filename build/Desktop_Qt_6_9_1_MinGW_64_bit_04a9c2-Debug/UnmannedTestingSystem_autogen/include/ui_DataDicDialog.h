/********************************************************************************
** Form generated from reading UI file 'DataDicDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADICDIALOG_H
#define UI_DATADICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DataDicDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *labelType;
    QLineEdit *lineType;
    QLabel *labelKey;
    QLineEdit *lineKey;
    QLabel *labelValue;
    QLineEdit *lineValue;
    QLabel *labelSort;
    QSpinBox *spinSort;
    QLabel *labelError;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DataDicDialog)
    {
        if (DataDicDialog->objectName().isEmpty())
            DataDicDialog->setObjectName("DataDicDialog");
        DataDicDialog->resize(500, 358);
        verticalLayout = new QVBoxLayout(DataDicDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DataDicDialog);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        labelType = new QLabel(groupBox);
        labelType->setObjectName("labelType");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelType);

        lineType = new QLineEdit(groupBox);
        lineType->setObjectName("lineType");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineType);

        labelKey = new QLabel(groupBox);
        labelKey->setObjectName("labelKey");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelKey);

        lineKey = new QLineEdit(groupBox);
        lineKey->setObjectName("lineKey");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineKey);

        labelValue = new QLabel(groupBox);
        labelValue->setObjectName("labelValue");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelValue);

        lineValue = new QLineEdit(groupBox);
        lineValue->setObjectName("lineValue");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineValue);

        labelSort = new QLabel(groupBox);
        labelSort->setObjectName("labelSort");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelSort);

        spinSort = new QSpinBox(groupBox);
        spinSort->setObjectName("spinSort");
        spinSort->setMinimum(0);
        spinSort->setMaximum(999);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, spinSort);


        verticalLayout->addWidget(groupBox);

        labelError = new QLabel(DataDicDialog);
        labelError->setObjectName("labelError");
        labelError->setStyleSheet(QString::fromUtf8("color: red;"));
        labelError->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelError);

        buttonBox = new QDialogButtonBox(DataDicDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DataDicDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DataDicDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DataDicDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DataDicDialog);
    } // setupUi

    void retranslateUi(QDialog *DataDicDialog)
    {
        DataDicDialog->setWindowTitle(QCoreApplication::translate("DataDicDialog", "\346\225\260\346\215\256\345\255\227\345\205\270\347\274\226\350\276\221", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DataDicDialog", "\345\255\227\345\205\270\344\277\241\346\201\257", nullptr));
        labelType->setText(QCoreApplication::translate("DataDicDialog", "\345\255\227\345\205\270\347\261\273\345\236\213\357\274\232", nullptr));
        labelKey->setText(QCoreApplication::translate("DataDicDialog", "\351\224\256\357\274\232", nullptr));
        labelValue->setText(QCoreApplication::translate("DataDicDialog", "\345\200\274\357\274\232", nullptr));
        labelSort->setText(QCoreApplication::translate("DataDicDialog", "\346\216\222\345\272\217\357\274\232", nullptr));
        labelError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataDicDialog: public Ui_DataDicDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADICDIALOG_H
