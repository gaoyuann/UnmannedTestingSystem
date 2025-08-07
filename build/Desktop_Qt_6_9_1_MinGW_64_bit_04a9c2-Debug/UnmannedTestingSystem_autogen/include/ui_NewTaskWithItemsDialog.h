/********************************************************************************
** Form generated from reading UI file 'NewTaskWithItemsDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTASKWITHITEMSDIALOG_H
#define UI_NEWTASKWITHITEMSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewTaskWithItemsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBasic;
    QFormLayout *formLayoutBasic;
    QLabel *labelTaskName;
    QLineEdit *editTaskName;
    QLabel *labelUnit;
    QComboBox *comboUnit;
    QLabel *labelStation;
    QComboBox *comboStation;
    QLabel *labelProtocol;
    QComboBox *comboProtocol;
    QGroupBox *groupTestItems;
    QVBoxLayout *verticalLayoutItems;
    QTableWidget *tableTestItems;
    QHBoxLayout *horizontalLayoutItemButtons;
    QPushButton *btnAddItem;
    QPushButton *btnRemoveItem;
    QLabel *labelError;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewTaskWithItemsDialog)
    {
        if (NewTaskWithItemsDialog->objectName().isEmpty())
            NewTaskWithItemsDialog->setObjectName("NewTaskWithItemsDialog");
        NewTaskWithItemsDialog->resize(642, 666);
        verticalLayout = new QVBoxLayout(NewTaskWithItemsDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBasic = new QGroupBox(NewTaskWithItemsDialog);
        groupBasic->setObjectName("groupBasic");
        formLayoutBasic = new QFormLayout(groupBasic);
        formLayoutBasic->setObjectName("formLayoutBasic");
        labelTaskName = new QLabel(groupBasic);
        labelTaskName->setObjectName("labelTaskName");

        formLayoutBasic->setWidget(0, QFormLayout::ItemRole::LabelRole, labelTaskName);

        editTaskName = new QLineEdit(groupBasic);
        editTaskName->setObjectName("editTaskName");

        formLayoutBasic->setWidget(0, QFormLayout::ItemRole::FieldRole, editTaskName);

        labelUnit = new QLabel(groupBasic);
        labelUnit->setObjectName("labelUnit");

        formLayoutBasic->setWidget(1, QFormLayout::ItemRole::LabelRole, labelUnit);

        comboUnit = new QComboBox(groupBasic);
        comboUnit->setObjectName("comboUnit");

        formLayoutBasic->setWidget(1, QFormLayout::ItemRole::FieldRole, comboUnit);

        labelStation = new QLabel(groupBasic);
        labelStation->setObjectName("labelStation");

        formLayoutBasic->setWidget(2, QFormLayout::ItemRole::LabelRole, labelStation);

        comboStation = new QComboBox(groupBasic);
        comboStation->setObjectName("comboStation");

        formLayoutBasic->setWidget(2, QFormLayout::ItemRole::FieldRole, comboStation);

        labelProtocol = new QLabel(groupBasic);
        labelProtocol->setObjectName("labelProtocol");

        formLayoutBasic->setWidget(3, QFormLayout::ItemRole::LabelRole, labelProtocol);

        comboProtocol = new QComboBox(groupBasic);
        comboProtocol->setObjectName("comboProtocol");

        formLayoutBasic->setWidget(3, QFormLayout::ItemRole::FieldRole, comboProtocol);


        verticalLayout->addWidget(groupBasic);

        groupTestItems = new QGroupBox(NewTaskWithItemsDialog);
        groupTestItems->setObjectName("groupTestItems");
        verticalLayoutItems = new QVBoxLayout(groupTestItems);
        verticalLayoutItems->setObjectName("verticalLayoutItems");
        tableTestItems = new QTableWidget(groupTestItems);
        tableTestItems->setObjectName("tableTestItems");

        verticalLayoutItems->addWidget(tableTestItems);

        horizontalLayoutItemButtons = new QHBoxLayout();
        horizontalLayoutItemButtons->setObjectName("horizontalLayoutItemButtons");
        btnAddItem = new QPushButton(groupTestItems);
        btnAddItem->setObjectName("btnAddItem");

        horizontalLayoutItemButtons->addWidget(btnAddItem);

        btnRemoveItem = new QPushButton(groupTestItems);
        btnRemoveItem->setObjectName("btnRemoveItem");

        horizontalLayoutItemButtons->addWidget(btnRemoveItem);


        verticalLayoutItems->addLayout(horizontalLayoutItemButtons);


        verticalLayout->addWidget(groupTestItems);

        labelError = new QLabel(NewTaskWithItemsDialog);
        labelError->setObjectName("labelError");
        labelError->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelError);

        buttonBox = new QDialogButtonBox(NewTaskWithItemsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewTaskWithItemsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewTaskWithItemsDialog, SLOT(on_buttonBox_accepted()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewTaskWithItemsDialog, SLOT(on_buttonBox_rejected()));
        QObject::connect(btnAddItem, SIGNAL(clicked()), NewTaskWithItemsDialog, SLOT(on_btnAddItem_clicked()));
        QObject::connect(btnRemoveItem, SIGNAL(clicked()), NewTaskWithItemsDialog, SLOT(on_btnRemoveItem_clicked()));

        QMetaObject::connectSlotsByName(NewTaskWithItemsDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTaskWithItemsDialog)
    {
        NewTaskWithItemsDialog->setWindowTitle(QCoreApplication::translate("NewTaskWithItemsDialog", "\346\226\260\345\242\236\346\265\213\350\257\225\344\273\273\345\212\241\357\274\210\345\220\253\346\265\213\350\257\225\351\241\271\347\233\256\357\274\211", nullptr));
        groupBasic->setTitle(QCoreApplication::translate("NewTaskWithItemsDialog", "\344\273\273\345\212\241\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        labelTaskName->setText(QCoreApplication::translate("NewTaskWithItemsDialog", "\344\273\273\345\212\241\345\220\215\347\247\260:", nullptr));
        labelUnit->setText(QCoreApplication::translate("NewTaskWithItemsDialog", "\345\217\202\350\257\225\345\215\225\344\275\215:", nullptr));
        labelStation->setText(QCoreApplication::translate("NewTaskWithItemsDialog", "\346\216\247\345\210\266\347\253\231:", nullptr));
        labelProtocol->setText(QCoreApplication::translate("NewTaskWithItemsDialog", "\346\265\213\350\257\225\345\215\217\350\256\256:", nullptr));
        groupTestItems->setTitle(QCoreApplication::translate("NewTaskWithItemsDialog", "\346\265\213\350\257\225\351\241\271\347\233\256\357\274\210\345\217\257\346\226\260\345\242\236\345\244\232\350\241\214\357\274\211", nullptr));
        btnAddItem->setText(QCoreApplication::translate("NewTaskWithItemsDialog", "\346\226\260\345\242\236\346\265\213\350\257\225\351\241\271", nullptr));
        btnRemoveItem->setText(QCoreApplication::translate("NewTaskWithItemsDialog", "\345\210\240\351\231\244\351\200\211\344\270\255\351\241\271", nullptr));
        labelError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewTaskWithItemsDialog: public Ui_NewTaskWithItemsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTASKWITHITEMSDIALOG_H
