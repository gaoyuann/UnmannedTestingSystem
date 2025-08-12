/********************************************************************************
** Form generated from reading UI file 'TestManageWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMANAGEWINDOW_H
#define UI_TESTMANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_TestManageWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *buttonLayout;
    QPushButton *btnAddTask;
    QPushButton *btnEditTask;
    QPushButton *btnDeleteTask;
    QPushButton *btnExecuteTask;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QTableWidget *tableTasks;
    QWidget *paginationWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPageInfo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnFirst;
    QPushButton *btnPrev;
    QPushButton *btnNext;
    QPushButton *btnLast;

    void setupUi(QWidget *TestManageWindow)
    {
        if (TestManageWindow->objectName().isEmpty())
            TestManageWindow->setObjectName("TestManageWindow");
        TestManageWindow->resize(1016, 650);
        TestManageWindow->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        verticalLayout = new QVBoxLayout(TestManageWindow);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(10);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(12, 12, 12, 12);
        btnAddTask = new QPushButton(TestManageWindow);
        btnAddTask->setObjectName("btnAddTask");
        btnAddTask->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3a6ea5;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4a90e2;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #2a5685;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAddTask->setIcon(icon);

        buttonLayout->addWidget(btnAddTask);

        btnEditTask = new QPushButton(TestManageWindow);
        btnEditTask->setObjectName("btnEditTask");
        btnEditTask->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3a6ea5;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4a90e2;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #2a5685;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEditTask->setIcon(icon1);

        buttonLayout->addWidget(btnEditTask);

        btnDeleteTask = new QPushButton(TestManageWindow);
        btnDeleteTask->setObjectName("btnDeleteTask");
        btnDeleteTask->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #992d22;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDeleteTask->setIcon(icon2);

        buttonLayout->addWidget(btnDeleteTask);

        btnExecuteTask = new QPushButton(TestManageWindow);
        btnExecuteTask->setObjectName("btnExecuteTask");
        btnExecuteTask->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f39c12;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e67e22;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d35400;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/run.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExecuteTask->setIcon(icon3);

        buttonLayout->addWidget(btnExecuteTask);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        lineSearch = new QLineEdit(TestManageWindow);
        lineSearch->setObjectName("lineSearch");
        lineSearch->setMinimumSize(QSize(250, 0));
        lineSearch->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 8px 12px;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    background-color: white;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #4a90e2;\n"
"    box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"}"));

        buttonLayout->addWidget(lineSearch);

        btnSearch = new QPushButton(TestManageWindow);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2ecc71;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #219955;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSearch->setIcon(icon4);

        buttonLayout->addWidget(btnSearch);


        verticalLayout->addLayout(buttonLayout);

        tableTasks = new QTableWidget(TestManageWindow);
        if (tableTasks->columnCount() < 8)
            tableTasks->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableTasks->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableTasks->setObjectName("tableTasks");
        tableTasks->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    font-size: 13px;\n"
"    background-color: white;\n"
"    alternate-background-color: #f8f9fa;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 4px;\n"
"    gridline-color: #d0d0d0;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"    border-right: 1px solid #e0e0e0;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QTableWidget::item:hover {\n"
"    background-color: #f0f7ff;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #3a6ea5;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border-right: 1px solid #2a5685;\n"
"    border-bottom: none;\n"
"    font-weight: 500;\n"
"}\n"
"QHeaderView {\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}"));
        tableTasks->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        tableTasks->setAlternatingRowColors(true);
        tableTasks->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableTasks->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableTasks->setShowGrid(false);
        tableTasks->setSortingEnabled(true);
        tableTasks->setRowCount(0);
        tableTasks->setColumnCount(8);

        verticalLayout->addWidget(tableTasks);

        paginationWidget = new QWidget(TestManageWindow);
        paginationWidget->setObjectName("paginationWidget");
        paginationWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        horizontalLayout = new QHBoxLayout(paginationWidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(12, 6, 12, 6);
        labelPageInfo = new QLabel(paginationWidget);
        labelPageInfo->setObjectName("labelPageInfo");
        labelPageInfo->setStyleSheet(QString::fromUtf8("color: #666666;"));

        horizontalLayout->addWidget(labelPageInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnFirst = new QPushButton(paginationWidget);
        btnFirst->setObjectName("btnFirst");
        btnFirst->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        color: rgb(0, 0, 0);\n"
"    min-width: 60px;\n"
"    padding: 4px 8px;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 3px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/first.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnFirst->setIcon(icon5);

        horizontalLayout->addWidget(btnFirst);

        btnPrev = new QPushButton(paginationWidget);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        color: rgb(0, 0, 0);\n"
"    min-width: 60px;\n"
"    padding: 4px 8px;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 3px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/prev.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPrev->setIcon(icon6);

        horizontalLayout->addWidget(btnPrev);

        btnNext = new QPushButton(paginationWidget);
        btnNext->setObjectName("btnNext");
        btnNext->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        color: rgb(0, 0, 0);\n"
"    min-width: 60px;\n"
"    padding: 4px 8px;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 3px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNext->setIcon(icon7);

        horizontalLayout->addWidget(btnNext);

        btnLast = new QPushButton(paginationWidget);
        btnLast->setObjectName("btnLast");
        btnLast->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        color: rgb(0, 0, 0);\n"
"    min-width: 60px;\n"
"    padding: 4px 8px;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 3px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/last.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLast->setIcon(icon8);

        horizontalLayout->addWidget(btnLast);


        verticalLayout->addWidget(paginationWidget);


        retranslateUi(TestManageWindow);

        QMetaObject::connectSlotsByName(TestManageWindow);
    } // setupUi

    void retranslateUi(QWidget *TestManageWindow)
    {
        TestManageWindow->setWindowTitle(QCoreApplication::translate("TestManageWindow", "\346\265\213\350\257\225\347\256\241\347\220\206\346\250\241\345\235\227", nullptr));
        btnAddTask->setText(QCoreApplication::translate("TestManageWindow", "\346\226\260\345\242\236\344\273\273\345\212\241", nullptr));
        btnEditTask->setText(QCoreApplication::translate("TestManageWindow", "\347\274\226\350\276\221\344\273\273\345\212\241", nullptr));
        btnDeleteTask->setText(QCoreApplication::translate("TestManageWindow", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        btnExecuteTask->setText(QCoreApplication::translate("TestManageWindow", "\346\211\247\350\241\214\344\273\273\345\212\241", nullptr));
        lineSearch->setPlaceholderText(QCoreApplication::translate("TestManageWindow", "\350\276\223\345\205\245\344\273\273\345\212\241\345\220\215\347\247\260\343\200\201\345\217\202\350\257\225\345\215\225\344\275\215\347\255\211\345\205\263\351\224\256\350\257\215...", nullptr));
        btnSearch->setText(QCoreApplication::translate("TestManageWindow", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTasks->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TestManageWindow", "\344\273\273\345\212\241ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTasks->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TestManageWindow", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableTasks->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TestManageWindow", "\345\217\202\350\257\225\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableTasks->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TestManageWindow", "\346\216\247\345\210\266\347\253\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableTasks->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TestManageWindow", "\346\265\213\350\257\225\345\215\217\350\256\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableTasks->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TestManageWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableTasks->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TestManageWindow", "\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableTasks->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("TestManageWindow", "\346\223\215\344\275\234", nullptr));
        labelPageInfo->setText(QCoreApplication::translate("TestManageWindow", "\347\254\254 1 \351\241\265 / \345\205\261 1 \351\241\265 (10 \346\235\241)", nullptr));
        btnFirst->setText(QCoreApplication::translate("TestManageWindow", "\351\246\226\351\241\265", nullptr));
        btnPrev->setText(QCoreApplication::translate("TestManageWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        btnNext->setText(QCoreApplication::translate("TestManageWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        btnLast->setText(QCoreApplication::translate("TestManageWindow", "\346\234\253\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestManageWindow: public Ui_TestManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMANAGEWINDOW_H
