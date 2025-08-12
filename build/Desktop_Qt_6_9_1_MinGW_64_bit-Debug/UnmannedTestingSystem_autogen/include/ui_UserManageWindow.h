/********************************************************************************
** Form generated from reading UI file 'UserManageWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEWINDOW_H
#define UI_USERMANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManageWindow
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *UserManageWindow)
    {
        if (UserManageWindow->objectName().isEmpty())
            UserManageWindow->setObjectName("UserManageWindow");
        UserManageWindow->resize(1000, 650);
        tableWidget = new QTableWidget(UserManageWindow);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 110, 971, 511));
        tableWidget->horizontalHeader()->setDefaultSectionSize(122);
        label = new QLabel(UserManageWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 171, 71));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        widget = new QWidget(UserManageWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(653, 60, 321, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        retranslateUi(UserManageWindow);

        QMetaObject::connectSlotsByName(UserManageWindow);
    } // setupUi

    void retranslateUi(QWidget *UserManageWindow)
    {
        UserManageWindow->setWindowTitle(QCoreApplication::translate("UserManageWindow", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UserManageWindow", "\347\224\250\346\210\267id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UserManageWindow", "\350\264\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UserManageWindow", "\345\257\206\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("UserManageWindow", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("UserManageWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("UserManageWindow", "\346\211\200\345\261\236\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("UserManageWindow", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("UserManageWindow", "\346\237\245\347\234\213\350\257\246\346\203\205", nullptr));
        label->setText(QCoreApplication::translate("UserManageWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("UserManageWindow", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManageWindow: public Ui_UserManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEWINDOW_H
