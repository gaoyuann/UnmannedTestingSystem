/********************************************************************************
** Form generated from reading UI file 'DataDicWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADICWINDOW_H
#define UI_DATADICWINDOW_H

#include <QtCore/QVariant>
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

class Ui_DataDicWindow
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
    QTableWidget *tableDicts;
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

    void setupUi(QWidget *DataDicWindow)
    {
        if (DataDicWindow->objectName().isEmpty())
            DataDicWindow->setObjectName("DataDicWindow");
        DataDicWindow->resize(1000, 650);
        DataDicWindow->setStyleSheet(QString::fromUtf8("\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"   "));
        verticalLayout = new QVBoxLayout(DataDicWindow);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        buttonContainer = new QWidget(DataDicWindow);
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
"         "));

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
"         "));

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
"         "));

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
"         "));

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
"              background-color: white;\n"
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
"         "));

        buttonLayout->addWidget(btnSearch);


        verticalLayout->addWidget(buttonContainer);

        tableDicts = new QTableWidget(DataDicWindow);
        if (tableDicts->columnCount() < 6)
            tableDicts->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDicts->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDicts->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDicts->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableDicts->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableDicts->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableDicts->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableDicts->setObjectName("tableDicts");
        tableDicts->setStyleSheet(QString::fromUtf8("\n"
"       QTableWidget {\n"
"           font-size: 13px;\n"
"           background-color: white;\n"
"           alternate-background-color: #f8f9fa;\n"
"           border: 1px solid #e0e0e0;\n"
"           border-radius: 6px;\n"
"       }\n"
"       QHeaderView::section {\n"
"           background-color: #3a6ea5;\n"
"           color: white;\n"
"           padding: 8px;\n"
"           border: none;\n"
"       }\n"
"      "));
        tableDicts->setAlternatingRowColors(true);
        tableDicts->setSelectionMode(QAbstractItemView::NoSelection);
        tableDicts->setSortingEnabled(true);
        tableDicts->setColumnCount(6);

        verticalLayout->addWidget(tableDicts);

        paginationWidget = new QWidget(DataDicWindow);
        paginationWidget->setObjectName("paginationWidget");
        paginationWidget->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 8px;\n"
"      "));
        horizontalLayout = new QHBoxLayout(paginationWidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
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


        retranslateUi(DataDicWindow);

        QMetaObject::connectSlotsByName(DataDicWindow);
    } // setupUi

    void retranslateUi(QWidget *DataDicWindow)
    {
        DataDicWindow->setWindowTitle(QCoreApplication::translate("DataDicWindow", "\346\225\260\346\215\256\345\255\227\345\205\270\347\256\241\347\220\206\346\250\241\345\235\227", nullptr));
        btnBack->setText(QCoreApplication::translate("DataDicWindow", "\350\277\224\345\233\236", nullptr));
        btnAdd->setText(QCoreApplication::translate("DataDicWindow", "\346\226\260\345\242\236\345\255\227\345\205\270", nullptr));
        btnEdit->setText(QCoreApplication::translate("DataDicWindow", "\347\274\226\350\276\221", nullptr));
        btnDelete->setText(QCoreApplication::translate("DataDicWindow", "\345\210\240\351\231\244", nullptr));
        lineSearch->setPlaceholderText(QCoreApplication::translate("DataDicWindow", "\350\276\223\345\205\245\347\261\273\345\236\213\343\200\201\351\224\256\343\200\201\345\200\274\347\255\211\345\205\263\351\224\256\350\257\215...", nullptr));
        btnSearch->setText(QCoreApplication::translate("DataDicWindow", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableDicts->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DataDicWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDicts->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DataDicWindow", "\345\255\227\345\205\270\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDicts->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DataDicWindow", "\351\224\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableDicts->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DataDicWindow", "\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableDicts->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DataDicWindow", "\346\216\222\345\272\217", nullptr));
        labelPageInfo->setText(QCoreApplication::translate("DataDicWindow", "\347\254\254 1 \351\241\265 / \345\205\261 1 \351\241\265 (10 \346\235\241)", nullptr));
        btnFirst->setText(QCoreApplication::translate("DataDicWindow", "\351\246\226\351\241\265", nullptr));
        btnPrev->setText(QCoreApplication::translate("DataDicWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        btnNext->setText(QCoreApplication::translate("DataDicWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        btnLast->setText(QCoreApplication::translate("DataDicWindow", "\346\234\253\351\241\265", nullptr));
        comboPageSize->setItemText(0, QCoreApplication::translate("DataDicWindow", "10 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(1, QCoreApplication::translate("DataDicWindow", "20 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(2, QCoreApplication::translate("DataDicWindow", "50 \346\235\241/\351\241\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DataDicWindow: public Ui_DataDicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADICWINDOW_H
