/********************************************************************************
** Form generated from reading UI file 'PermissionManageWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERMISSIONMANAGEWINDOW_H
#define UI_PERMISSIONMANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PermissionManageWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *buttonContainer;
    QHBoxLayout *buttonLayout;
    QPushButton *btnBack;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QTableWidget *tablePermissions;
    QWidget *paginationWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPageInfo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnFirst;
    QPushButton *btnPrev;
    QComboBox *comboPage;
    QPushButton *btnNext;
    QPushButton *btnLast;
    QComboBox *comboPageSize;

    void setupUi(QWidget *PermissionManageWindow)
    {
        if (PermissionManageWindow->objectName().isEmpty())
            PermissionManageWindow->setObjectName("PermissionManageWindow");
        PermissionManageWindow->resize(1000, 650);
        PermissionManageWindow->setStyleSheet(QString::fromUtf8("\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"   "));
        verticalLayout = new QVBoxLayout(PermissionManageWindow);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        buttonContainer = new QWidget(PermissionManageWindow);
        buttonContainer->setObjectName("buttonContainer");
        buttonContainer->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 8px;\n"
"       box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"      "));
        buttonLayout = new QHBoxLayout(buttonContainer);
        buttonLayout->setSpacing(10);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(4, 4, 4, 4);
        btnBack = new QPushButton(buttonContainer);
        btnBack->setObjectName("btnBack");
        btnBack->setStyleSheet(QString::fromUtf8("\n"
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
"              background-color: #607d8b;\n"
"          }\n"
"         "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/back.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnBack->setIcon(icon);

        buttonLayout->addWidget(btnBack);

        btnAdd = new QPushButton(buttonContainer);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAdd->setIcon(icon1);

        buttonLayout->addWidget(btnAdd);

        btnEdit = new QPushButton(buttonContainer);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setStyleSheet(QString::fromUtf8("\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEdit->setIcon(icon2);

        buttonLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(buttonContainer);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setStyleSheet(QString::fromUtf8("\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDelete->setIcon(icon3);

        buttonLayout->addWidget(btnDelete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        lineSearch = new QLineEdit(buttonContainer);
        lineSearch->setObjectName("lineSearch");
        lineSearch->setMinimumSize(QSize(276, 0));
        lineSearch->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              padding: 8px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              min-width: 250px;\n"
"              background-color: white;\n"
"          }\n"
"          QLineEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"          }\n"
"         "));

        buttonLayout->addWidget(lineSearch);

        btnSearch = new QPushButton(buttonContainer);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setStyleSheet(QString::fromUtf8("\n"
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
"         "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSearch->setIcon(icon4);

        buttonLayout->addWidget(btnSearch);


        verticalLayout->addWidget(buttonContainer);

        tablePermissions = new QTableWidget(PermissionManageWindow);
        if (tablePermissions->columnCount() < 6)
            tablePermissions->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablePermissions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablePermissions->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablePermissions->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablePermissions->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablePermissions->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablePermissions->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tablePermissions->setObjectName("tablePermissions");
        tablePermissions->setStyleSheet(QString::fromUtf8("\n"
"       QTableWidget {\n"
"           font-size: 13px;\n"
"           background-color: white;\n"
"           alternate-background-color: #f8f9fa;\n"
"           border: 1px solid #e0e0e0;\n"
"           border-radius: 6px;\n"
"           gridline-color: #e0e0e0;\n"
"       }\n"
"       QTableWidget::item {\n"
"           padding: 8px;\n"
"           border-bottom: 1px solid #f0f0f0;\n"
"       }\n"
"       QHeaderView::section {\n"
"           background-color: #3a6ea5;\n"
"           color: white;\n"
"           padding: 8px;\n"
"           border: none;\n"
"           font-size: 13px;\n"
"       }\n"
"      "));
        tablePermissions->setAlternatingRowColors(true);
        tablePermissions->setSelectionBehavior(QAbstractItemView::SelectRows);
        tablePermissions->setShowGrid(false);
        tablePermissions->setSortingEnabled(true);
        tablePermissions->setRowCount(0);
        tablePermissions->setColumnCount(6);

        verticalLayout->addWidget(tablePermissions);

        paginationWidget = new QWidget(PermissionManageWindow);
        paginationWidget->setObjectName("paginationWidget");
        paginationWidget->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 8px;\n"
"       box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"      "));
        horizontalLayout = new QHBoxLayout(paginationWidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(8, 4, 8, 4);
        labelPageInfo = new QLabel(paginationWidget);
        labelPageInfo->setObjectName("labelPageInfo");

        horizontalLayout->addWidget(labelPageInfo);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnFirst = new QPushButton(paginationWidget);
        btnFirst->setObjectName("btnFirst");

        horizontalLayout->addWidget(btnFirst);

        btnPrev = new QPushButton(paginationWidget);
        btnPrev->setObjectName("btnPrev");

        horizontalLayout->addWidget(btnPrev);

        comboPage = new QComboBox(paginationWidget);
        comboPage->setObjectName("comboPage");

        horizontalLayout->addWidget(comboPage);

        btnNext = new QPushButton(paginationWidget);
        btnNext->setObjectName("btnNext");

        horizontalLayout->addWidget(btnNext);

        btnLast = new QPushButton(paginationWidget);
        btnLast->setObjectName("btnLast");

        horizontalLayout->addWidget(btnLast);

        comboPageSize = new QComboBox(paginationWidget);
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->setObjectName("comboPageSize");

        horizontalLayout->addWidget(comboPageSize);


        verticalLayout->addWidget(paginationWidget);


        retranslateUi(PermissionManageWindow);

        QMetaObject::connectSlotsByName(PermissionManageWindow);
    } // setupUi

    void retranslateUi(QWidget *PermissionManageWindow)
    {
        PermissionManageWindow->setWindowTitle(QCoreApplication::translate("PermissionManageWindow", "\346\235\203\351\231\220\347\256\241\347\220\206\346\250\241\345\235\227", nullptr));
        btnBack->setText(QCoreApplication::translate("PermissionManageWindow", "\350\277\224\345\233\236", nullptr));
        btnAdd->setText(QCoreApplication::translate("PermissionManageWindow", "\346\226\260\345\242\236\346\235\203\351\231\220", nullptr));
        btnEdit->setText(QCoreApplication::translate("PermissionManageWindow", "\347\274\226\350\276\221", nullptr));
        btnDelete->setText(QCoreApplication::translate("PermissionManageWindow", "\345\210\240\351\231\244", nullptr));
        lineSearch->setPlaceholderText(QCoreApplication::translate("PermissionManageWindow", "\350\276\223\345\205\245\346\235\203\351\231\220\345\220\215\347\247\260\343\200\201\347\274\226\347\240\201\347\255\211\345\205\263\351\224\256\350\257\215...", nullptr));
        btnSearch->setText(QCoreApplication::translate("PermissionManageWindow", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablePermissions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PermissionManageWindow", "\351\200\211\346\213\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablePermissions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PermissionManageWindow", "\346\235\203\351\231\220ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablePermissions->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PermissionManageWindow", "\346\235\203\351\231\220\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tablePermissions->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PermissionManageWindow", "\346\235\203\351\231\220\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tablePermissions->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("PermissionManageWindow", "\347\210\266\346\235\203\351\231\220ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tablePermissions->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("PermissionManageWindow", "\346\217\217\350\277\260", nullptr));
        labelPageInfo->setText(QCoreApplication::translate("PermissionManageWindow", "\347\254\254 1 \351\241\265 / \345\205\261 1 \351\241\265 (10 \346\235\241)", nullptr));
        btnFirst->setText(QCoreApplication::translate("PermissionManageWindow", "\351\246\226\351\241\265", nullptr));
        btnPrev->setText(QCoreApplication::translate("PermissionManageWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        btnNext->setText(QCoreApplication::translate("PermissionManageWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        btnLast->setText(QCoreApplication::translate("PermissionManageWindow", "\346\234\253\351\241\265", nullptr));
        comboPageSize->setItemText(0, QCoreApplication::translate("PermissionManageWindow", "10 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(1, QCoreApplication::translate("PermissionManageWindow", "20 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(2, QCoreApplication::translate("PermissionManageWindow", "50 \346\235\241/\351\241\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PermissionManageWindow: public Ui_PermissionManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERMISSIONMANAGEWINDOW_H
