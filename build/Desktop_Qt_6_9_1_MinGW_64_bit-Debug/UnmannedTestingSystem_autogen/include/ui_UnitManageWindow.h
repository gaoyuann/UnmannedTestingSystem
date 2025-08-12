/********************************************************************************
** Form generated from reading UI file 'UnitManageWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITMANAGEWINDOW_H
#define UI_UNITMANAGEWINDOW_H

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

class Ui_UnitManageWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *buttonContainer;
    QHBoxLayout *buttonLayout;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QTableWidget *tableUnits;
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

    void setupUi(QWidget *UnitManageWindow)
    {
        if (UnitManageWindow->objectName().isEmpty())
            UnitManageWindow->setObjectName("UnitManageWindow");
        UnitManageWindow->resize(1000, 650);
        UnitManageWindow->setStyleSheet(QString::fromUtf8("\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"   "));
        verticalLayout = new QVBoxLayout(UnitManageWindow);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        buttonContainer = new QWidget(UnitManageWindow);
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
"              transition: background-color 0.2s;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #4a90e2;\n"
"              box-shadow: 0 2px 4px rgba(0,0,0,0.1);\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #2a5685;\n"
"          }\n"
"          QPushButton:disabled {\n"
"              background-color: #cccccc;\n"
"          }\n"
"         "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAdd->setIcon(icon);

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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEdit->setIcon(icon1);

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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnDelete->setIcon(icon2);

        buttonLayout->addWidget(btnDelete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        lineSearch = new QLineEdit(buttonContainer);
        lineSearch->setObjectName("lineSearch");
        lineSearch->setMinimumSize(QSize(250, 0));
        lineSearch->setStyleSheet(QString::fromUtf8("\n"
"          QLineEdit {\n"
"              padding: 8px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 13px;\n"
"              min-width: 250px;\n"
"              background-color: white;\n"
"              color: #333333;\n"
"          }\n"
"          QLineEdit:focus {\n"
"              border: 1px solid #4a90e2;\n"
"              box-shadow: 0 0 0 2px rgba(74,144,226,0.2);\n"
"          }\n"
"          QLineEdit::placeholder {\n"
"              color: #999999;\n"
"              font-style: italic;\n"
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
"          QPushButton:pressed {\n"
"              background-color: #219955;\n"
"          }\n"
"         "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSearch->setIcon(icon3);

        buttonLayout->addWidget(btnSearch);


        verticalLayout->addWidget(buttonContainer);

        tableUnits = new QTableWidget(UnitManageWindow);
        if (tableUnits->columnCount() < 6)
            tableUnits->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableUnits->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableUnits->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableUnits->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableUnits->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableUnits->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableUnits->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableUnits->setObjectName("tableUnits");
        tableUnits->setStyleSheet(QString::fromUtf8("\n"
"       QTableWidget {\n"
"           font-size: 13px;\n"
"           background-color: white;\n"
"           alternate-background-color: #f8f9fa;\n"
"           border: 1px solid #e0e0e0;\n"
"           border-radius: 6px;\n"
"           gridline-color: #e0e0e0;\n"
"           outline: 0;\n"
"       }\n"
"       QTableWidget::item {\n"
"           padding: 8px;\n"
"           border-bottom: 1px solid #f0f0f0;\n"
"           color: #333333;\n"
"       }\n"
"       QTableWidget::item:hover {\n"
"           background-color: #f0f7ff;\n"
"       }\n"
"       QHeaderView::section {\n"
"           background-color: #3a6ea5;\n"
"           color: white;\n"
"           padding: 8px;\n"
"           border: none;\n"
"           font-weight: 500;\n"
"           font-size: 13px;\n"
"       }\n"
"       QHeaderView {\n"
"           border-top-left-radius: 6px;\n"
"           border-top-right-radius: 6px;\n"
"       }\n"
"      "));
        tableUnits->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableUnits->setAlternatingRowColors(true);
        tableUnits->setSelectionMode(QAbstractItemView::NoSelection);
        tableUnits->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableUnits->setShowGrid(false);
        tableUnits->setSortingEnabled(true);
        tableUnits->setRowCount(0);
        tableUnits->setColumnCount(6);

        verticalLayout->addWidget(tableUnits);

        paginationWidget = new QWidget(UnitManageWindow);
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
        labelPageInfo->setStyleSheet(QString::fromUtf8("\n"
"         color: #333333;  /* \346\224\271\344\270\272\346\233\264\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"         font-size: 13px;\n"
"         font-weight: 500;\n"
"         background-color: transparent;  /* \347\241\256\344\277\235\350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"         "));

        horizontalLayout->addWidget(labelPageInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnFirst = new QPushButton(paginationWidget);
        btnFirst->setObjectName("btnFirst");
        btnFirst->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              min-width: 60px;\n"
"              padding: 6px 8px;\n"
"              background-color: #f8f9fa;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e9ecef;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #dee2e6;\n"
"          }\n"
"         "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/first.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnFirst->setIcon(icon4);

        horizontalLayout->addWidget(btnFirst);

        btnPrev = new QPushButton(paginationWidget);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              min-width: 60px;\n"
"              padding: 6px 8px;\n"
"              background-color: #f8f9fa;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e9ecef;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #dee2e6;\n"
"          }\n"
"         "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/prev.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPrev->setIcon(icon5);

        horizontalLayout->addWidget(btnPrev);

        comboPage = new QComboBox(paginationWidget);
        comboPage->setObjectName("comboPage");
        comboPage->setStyleSheet(QString::fromUtf8("\n"
"          QComboBox {\n"
"              padding: 4px 8px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              min-width: 60px;\n"
"              font-size: 12px;\n"
"              padding: 4px 8px;\n"
"              color: #333333;  /* \346\267\273\345\212\240\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"              background-color: white;  /* \347\241\256\344\277\235\350\203\214\346\231\257\346\230\257\347\231\275\350\211\262 */\n"
"          }\n"
"          QComboBox::drop-down {\n"
"              width: 20px;\n"
"              border: none;\n"
"          }\n"
"          QComboBox QAbstractItemView {\n"
"              background-color: white;  /* \344\270\213\346\213\211\350\217\234\345\215\225\350\203\214\346\231\257 */\n"
"              color: #333333;  /* \344\270\213\346\213\211\350\217\234\345\215\225\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"              selection-background-color: #3a6ea5;  /* \351\200\211\344\270\255\351"
                        "\241\271\350\203\214\346\231\257 */\n"
"              selection-color: white;  /* \351\200\211\344\270\255\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"          }\n"
"         "));

        horizontalLayout->addWidget(comboPage);

        btnNext = new QPushButton(paginationWidget);
        btnNext->setObjectName("btnNext");
        btnNext->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              min-width: 60px;\n"
"              padding: 6px 8px;\n"
"              background-color: #f8f9fa;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e9ecef;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #dee2e6;\n"
"          }\n"
"         "));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNext->setIcon(icon6);

        horizontalLayout->addWidget(btnNext);

        btnLast = new QPushButton(paginationWidget);
        btnLast->setObjectName("btnLast");
        btnLast->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              min-width: 60px;\n"
"              padding: 6px 8px;\n"
"              background-color: #f8f9fa;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              font-size: 12px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e9ecef;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #dee2e6;\n"
"          }\n"
"         "));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/last.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLast->setIcon(icon7);

        horizontalLayout->addWidget(btnLast);

        comboPageSize = new QComboBox(paginationWidget);
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->setObjectName("comboPageSize");
        comboPageSize->setStyleSheet(QString::fromUtf8("\n"
"          QComboBox {\n"
"              padding: 4px 8px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              min-width: 80px;\n"
"              font-size: 12px;\n"
"              color: black;\n"
"          }\n"
"          QComboBox::drop-down {\n"
"              width: 20px;\n"
"              border: none;\n"
"          }\n"
"          QComboBox QAbstractItemView {\n"
"              color: black;  /* \344\270\213\346\213\211\351\200\211\351\241\271\345\255\227\344\275\223\351\273\221\350\211\262 */\n"
"              background-color: white;  /* \344\270\213\346\213\211\351\200\211\351\241\271\350\203\214\346\231\257\347\231\275\350\211\262 */\n"
"                      }\n"
"         "));

        horizontalLayout->addWidget(comboPageSize);


        verticalLayout->addWidget(paginationWidget);


        retranslateUi(UnitManageWindow);

        QMetaObject::connectSlotsByName(UnitManageWindow);
    } // setupUi

    void retranslateUi(QWidget *UnitManageWindow)
    {
        UnitManageWindow->setWindowTitle(QCoreApplication::translate("UnitManageWindow", "\345\217\202\350\257\225\345\215\225\344\275\215\347\256\241\347\220\206\346\250\241\345\235\227", nullptr));
        btnAdd->setText(QCoreApplication::translate("UnitManageWindow", "\346\226\260\345\242\236\345\215\225\344\275\215", nullptr));
        btnEdit->setText(QCoreApplication::translate("UnitManageWindow", "\347\274\226\350\276\221", nullptr));
        btnDelete->setText(QCoreApplication::translate("UnitManageWindow", "\345\210\240\351\231\244", nullptr));
        lineSearch->setPlaceholderText(QCoreApplication::translate("UnitManageWindow", "\350\276\223\345\205\245\345\215\225\344\275\215\345\220\215\347\247\260\343\200\201\350\201\224\347\263\273\344\272\272\347\255\211\345\205\263\351\224\256\350\257\215...", nullptr));
        btnSearch->setText(QCoreApplication::translate("UnitManageWindow", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableUnits->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UnitManageWindow", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableUnits->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UnitManageWindow", "\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableUnits->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UnitManageWindow", "\350\201\224\347\263\273\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableUnits->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("UnitManageWindow", "\347\224\265\350\257\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableUnits->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("UnitManageWindow", "\345\215\225\344\275\215\347\261\273\345\236\213", nullptr));
        labelPageInfo->setText(QCoreApplication::translate("UnitManageWindow", "\347\254\254 1 \351\241\265 / \345\205\261 1 \351\241\265 (10 \346\235\241)", nullptr));
        btnFirst->setText(QCoreApplication::translate("UnitManageWindow", "\351\246\226\351\241\265", nullptr));
        btnPrev->setText(QCoreApplication::translate("UnitManageWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        comboPage->setCurrentText(QString());
        btnNext->setText(QCoreApplication::translate("UnitManageWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        btnLast->setText(QCoreApplication::translate("UnitManageWindow", "\346\234\253\351\241\265", nullptr));
        comboPageSize->setItemText(0, QCoreApplication::translate("UnitManageWindow", "10 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(1, QCoreApplication::translate("UnitManageWindow", "20 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(2, QCoreApplication::translate("UnitManageWindow", "50 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(3, QCoreApplication::translate("UnitManageWindow", "100 \346\235\241/\351\241\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class UnitManageWindow: public Ui_UnitManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITMANAGEWINDOW_H
