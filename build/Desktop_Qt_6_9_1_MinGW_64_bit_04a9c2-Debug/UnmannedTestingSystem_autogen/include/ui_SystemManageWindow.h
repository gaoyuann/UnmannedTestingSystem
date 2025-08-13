/********************************************************************************
** Form generated from reading UI file 'SystemManageWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGEWINDOW_H
#define UI_SYSTEMMANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemManageWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *btnUserManage;
    QPushButton *btnOrgManage;
    QPushButton *btnPermissionManage;
    QPushButton *btnDictManage;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SystemManageWindow)
    {
        if (SystemManageWindow->objectName().isEmpty())
            SystemManageWindow->setObjectName("SystemManageWindow");
        SystemManageWindow->resize(900, 700);
        SystemManageWindow->setStyleSheet(QString::fromUtf8("background-color: #f5f7fa;"));
        verticalLayout = new QVBoxLayout(SystemManageWindow);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(SystemManageWindow);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("font-size: 24px; color: #2c3e50; padding: 20px; font-weight: bold;"));

        verticalLayout->addWidget(labelTitle);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(60);
        gridLayout->setVerticalSpacing(40);
        gridLayout->setContentsMargins(80, 20, 80, 20);
        btnUserManage = new QPushButton(SystemManageWindow);
        btnUserManage->setObjectName("btnUserManage");
        btnUserManage->setMinimumSize(QSize(220, 160));
        btnUserManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2980b9;\n"
"    border-radius: 6px;\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #3498db;\n"
"}"));

        gridLayout->addWidget(btnUserManage, 0, 0, 1, 1);

        btnOrgManage = new QPushButton(SystemManageWindow);
        btnOrgManage->setObjectName("btnOrgManage");
        btnOrgManage->setMinimumSize(QSize(220, 160));
        btnOrgManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2980b9;\n"
"    border-radius: 6px;\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #3498db;\n"
"}"));

        gridLayout->addWidget(btnOrgManage, 0, 1, 1, 1);

        btnPermissionManage = new QPushButton(SystemManageWindow);
        btnPermissionManage->setObjectName("btnPermissionManage");
        btnPermissionManage->setMinimumSize(QSize(220, 160));
        btnPermissionManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2980b9;\n"
"    border-radius: 6px;\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #3498db;\n"
"}"));

        gridLayout->addWidget(btnPermissionManage, 1, 0, 1, 1);

        btnDictManage = new QPushButton(SystemManageWindow);
        btnDictManage->setObjectName("btnDictManage");
        btnDictManage->setMinimumSize(QSize(220, 160));
        btnDictManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2980b9;\n"
"    border-radius: 6px;\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #3498db;\n"
"}"));

        gridLayout->addWidget(btnDictManage, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(SystemManageWindow);

        QMetaObject::connectSlotsByName(SystemManageWindow);
    } // setupUi

    void retranslateUi(QWidget *SystemManageWindow)
    {
        SystemManageWindow->setWindowTitle(QCoreApplication::translate("SystemManageWindow", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        labelTitle->setText(QCoreApplication::translate("SystemManageWindow", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        btnUserManage->setText(QCoreApplication::translate("SystemManageWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        btnOrgManage->setText(QCoreApplication::translate("SystemManageWindow", "\347\273\204\347\273\207\346\234\272\346\236\204\347\256\241\347\220\206", nullptr));
        btnPermissionManage->setText(QCoreApplication::translate("SystemManageWindow", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        btnDictManage->setText(QCoreApplication::translate("SystemManageWindow", "\346\225\260\346\215\256\345\255\227\345\205\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemManageWindow: public Ui_SystemManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGEWINDOW_H
