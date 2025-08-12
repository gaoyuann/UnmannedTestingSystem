/********************************************************************************
** Form generated from reading UI file 'TestResultsAnalysisWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTRESULTSANALYSISWINDOW_H
#define UI_TESTRESULTSANALYSISWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestResultsAnalysisWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *filterWidget;
    QHBoxLayout *filterLayout;
    QLabel *labelTask;
    QComboBox *comboTask;
    QLabel *labelUnit;
    QComboBox *comboUnit;
    QLabel *labelTime;
    QDateEdit *dateStart;
    QLabel *labelTo;
    QDateEdit *dateEnd;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnQuery;
    QPushButton *btnExport;
    QTabWidget *tabWidget;
    QWidget *tabSummary;
    QGridLayout *gridLayout;
    QWidget *widgetPassRate;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelPassRate;
    QChartView *chartViewPassRate;
    QWidget *widgetItemDistribution;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelItemDistribution;
    QChartView *chartViewItemDistribution;
    QWidget *widgetUnitPerformance;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelUnitPerformance;
    QChartView *chartViewUnitPerformance;
    QWidget *widgetTimeTrend;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelTimeTrend;
    QChartView *chartViewTimeTrend;
    QWidget *tabDetails;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableResults;
    QWidget *paginationWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPageInfo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnFirst;
    QPushButton *btnPrev;
    QComboBox *comboPage;
    QPushButton *btnNext;
    QPushButton *btnLast;
    QComboBox *comboPageSize;

    void setupUi(QWidget *TestResultsAnalysisWindow)
    {
        if (TestResultsAnalysisWindow->objectName().isEmpty())
            TestResultsAnalysisWindow->setObjectName("TestResultsAnalysisWindow");
        TestResultsAnalysisWindow->resize(1350, 800);
        TestResultsAnalysisWindow->setStyleSheet(QString::fromUtf8("\n"
"    background-color: #f5f7fa;\n"
"    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"   "));
        verticalLayout = new QVBoxLayout(TestResultsAnalysisWindow);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        filterWidget = new QWidget(TestResultsAnalysisWindow);
        filterWidget->setObjectName("filterWidget");
        filterWidget->setStyleSheet(QString::fromUtf8("\n"
"       background-color: white;\n"
"       border-radius: 6px;\n"
"       padding: 8px;\n"
"       box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"      "));
        filterLayout = new QHBoxLayout(filterWidget);
        filterLayout->setSpacing(10);
        filterLayout->setObjectName("filterLayout");
        filterLayout->setContentsMargins(4, 4, 4, 4);
        labelTask = new QLabel(filterWidget);
        labelTask->setObjectName("labelTask");
        labelTask->setStyleSheet(QString::fromUtf8("color: #000000; font-size: 13px;"));

        filterLayout->addWidget(labelTask);

        comboTask = new QComboBox(filterWidget);
        comboTask->setObjectName("comboTask");
        comboTask->setStyleSheet(QString::fromUtf8("\n"
"          QComboBox {\n"
"              padding: 6px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              min-width: 150px;\n"
"              font-size: 13px;\n"
"              color: #000000;\n"
"          }\n"
"          QComboBox::drop-down {\n"
"              width: 20px;\n"
"              border: none;\n"
"              color: #000000;\n"
"          }\n"
"          QComboBox QAbstractItemView {\n"
"              color: #000000;  /* \344\270\213\346\213\211\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"              background-color: white;  /* \344\270\213\346\213\211\351\241\271\350\203\214\346\231\257\350\211\262 */\n"
"              selection-color: white;  /* \351\200\211\344\270\255\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"              selection-background-color: #3a6ea5;  /* \351\200\211\344\270\255\351\241\271\350\203\214\346\231\257\350\211\262 */\n"
"              outline: 0;\n"
"           "
                        "   border: 1px solid #d0d0d0;\n"
"              font-size: 13px;\n"
"          }\n"
"         "));

        filterLayout->addWidget(comboTask);

        labelUnit = new QLabel(filterWidget);
        labelUnit->setObjectName("labelUnit");
        labelUnit->setStyleSheet(QString::fromUtf8("color: #000000; font-size: 13px;"));

        filterLayout->addWidget(labelUnit);

        comboUnit = new QComboBox(filterWidget);
        comboUnit->setObjectName("comboUnit");
        comboUnit->setStyleSheet(QString::fromUtf8("\n"
"         QComboBox {\n"
"             padding: 6px 12px;\n"
"             border: 1px solid #d0d0d0;\n"
"             border-radius: 4px;\n"
"             min-width: 140px;\n"
"             font-size: 13px;\n"
"             color: #000000;\n"
"         }\n"
"         QComboBox::drop-down {\n"
"             width: 20px;\n"
"             border: none;\n"
"             color: #000000;\n"
"         }\n"
"         QComboBox QAbstractItemView {\n"
"             color: #000000;  /* \344\270\213\346\213\211\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"             background-color: white;  /* \344\270\213\346\213\211\351\241\271\350\203\214\346\231\257\350\211\262 */\n"
"             selection-color: white;  /* \351\200\211\344\270\255\351\241\271\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"             selection-background-color: #3a6ea5;  /* \351\200\211\344\270\255\351\241\271\350\203\214\346\231\257\350\211\262 */\n"
"             outline: 0;\n"
"             border: 1px solid"
                        " #d0d0d0;\n"
"             font-size: 13px;\n"
"         }\n"
"         "));

        filterLayout->addWidget(comboUnit);

        labelTime = new QLabel(filterWidget);
        labelTime->setObjectName("labelTime");
        labelTime->setStyleSheet(QString::fromUtf8("color: #333333; font-size: 13px;"));

        filterLayout->addWidget(labelTime);

        dateStart = new QDateEdit(filterWidget);
        dateStart->setObjectName("dateStart");
        dateStart->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"          QDateEdit {\n"
"              padding: 6px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              min-width: 120px;\n"
"              font-size: 13px;\n"
"          }\n"
"         "));
        dateStart->setCalendarPopup(true);

        filterLayout->addWidget(dateStart);

        labelTo = new QLabel(filterWidget);
        labelTo->setObjectName("labelTo");
        labelTo->setStyleSheet(QString::fromUtf8("color: #333333; font-size: 13px;"));

        filterLayout->addWidget(labelTo);

        dateEnd = new QDateEdit(filterWidget);
        dateEnd->setObjectName("dateEnd");
        dateEnd->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"          QDateEdit {\n"
"              padding: 6px 12px;\n"
"              border: 1px solid #d0d0d0;\n"
"              border-radius: 4px;\n"
"              min-width: 120px;\n"
"              font-size: 13px;\n"
"          }\n"
"         "));
        dateEnd->setCalendarPopup(true);

        filterLayout->addWidget(dateEnd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        filterLayout->addItem(horizontalSpacer);

        btnQuery = new QPushButton(filterWidget);
        btnQuery->setObjectName("btnQuery");
        btnQuery->setStyleSheet(QString::fromUtf8("\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnQuery->setIcon(icon);

        filterLayout->addWidget(btnQuery);

        btnExport = new QPushButton(filterWidget);
        btnExport->setObjectName("btnExport");
        btnExport->setStyleSheet(QString::fromUtf8("\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/export.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExport->setIcon(icon1);

        filterLayout->addWidget(btnExport);


        verticalLayout->addWidget(filterWidget);

        tabWidget = new QTabWidget(TestResultsAnalysisWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"       QTabWidget::pane {\n"
"           border: 1px solid #e0e0e0;\n"
"           border-radius: 6px;\n"
"           background: white;\n"
"       }\n"
"       QTabBar::tab {\n"
"           background: #f0f0f0;\n"
"           border: 1px solid #e0e0e0;\n"
"           border-bottom: none;\n"
"           border-top-left-radius: 4px;\n"
"           border-top-right-radius: 4px;\n"
"           padding: 8px 16px;\n"
"           font-size: 13px;\n"
"           color: #333333;\n"
"       }\n"
"       QTabBar::tab:selected {\n"
"           background: white;\n"
"           border-bottom: 2px solid #3a6ea5;\n"
"           color: #3a6ea5;\n"
"           font-weight: 500;\n"
"       }\n"
"       QTabBar::tab:hover {\n"
"           background: #e9ecef;\n"
"       }\n"
"      "));
        tabSummary = new QWidget();
        tabSummary->setObjectName("tabSummary");
        gridLayout = new QGridLayout(tabSummary);
        gridLayout->setObjectName("gridLayout");
        widgetPassRate = new QWidget(tabSummary);
        widgetPassRate->setObjectName("widgetPassRate");
        widgetPassRate->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-radius: 6px;\n"
"           box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"          "));
        verticalLayout_2 = new QVBoxLayout(widgetPassRate);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(8, 8, 8, 8);
        labelPassRate = new QLabel(widgetPassRate);
        labelPassRate->setObjectName("labelPassRate");
        labelPassRate->setStyleSheet(QString::fromUtf8("color: #333333; font-size: 14px; font-weight: 500;"));

        verticalLayout_2->addWidget(labelPassRate);

        chartViewPassRate = new QChartView(widgetPassRate);
        chartViewPassRate->setObjectName("chartViewPassRate");
        chartViewPassRate->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout_2->addWidget(chartViewPassRate);


        gridLayout->addWidget(widgetPassRate, 0, 0, 1, 1);

        widgetItemDistribution = new QWidget(tabSummary);
        widgetItemDistribution->setObjectName("widgetItemDistribution");
        widgetItemDistribution->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-radius: 6px;\n"
"           box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"          "));
        verticalLayout_3 = new QVBoxLayout(widgetItemDistribution);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(8, 8, 8, 8);
        labelItemDistribution = new QLabel(widgetItemDistribution);
        labelItemDistribution->setObjectName("labelItemDistribution");
        labelItemDistribution->setStyleSheet(QString::fromUtf8("color: #333333; font-size: 14px; font-weight: 500;"));

        verticalLayout_3->addWidget(labelItemDistribution);

        chartViewItemDistribution = new QChartView(widgetItemDistribution);
        chartViewItemDistribution->setObjectName("chartViewItemDistribution");
        chartViewItemDistribution->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout_3->addWidget(chartViewItemDistribution);


        gridLayout->addWidget(widgetItemDistribution, 0, 1, 1, 1);

        widgetUnitPerformance = new QWidget(tabSummary);
        widgetUnitPerformance->setObjectName("widgetUnitPerformance");
        widgetUnitPerformance->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-radius: 6px;\n"
"           box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"          "));
        verticalLayout_4 = new QVBoxLayout(widgetUnitPerformance);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(8, 8, 8, 8);
        labelUnitPerformance = new QLabel(widgetUnitPerformance);
        labelUnitPerformance->setObjectName("labelUnitPerformance");
        labelUnitPerformance->setStyleSheet(QString::fromUtf8("color: #333333; font-size: 14px; font-weight: 500;"));

        verticalLayout_4->addWidget(labelUnitPerformance);

        chartViewUnitPerformance = new QChartView(widgetUnitPerformance);
        chartViewUnitPerformance->setObjectName("chartViewUnitPerformance");
        chartViewUnitPerformance->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout_4->addWidget(chartViewUnitPerformance);


        gridLayout->addWidget(widgetUnitPerformance, 1, 0, 1, 1);

        widgetTimeTrend = new QWidget(tabSummary);
        widgetTimeTrend->setObjectName("widgetTimeTrend");
        widgetTimeTrend->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-radius: 6px;\n"
"           box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"          "));
        verticalLayout_5 = new QVBoxLayout(widgetTimeTrend);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(8, 8, 8, 8);
        labelTimeTrend = new QLabel(widgetTimeTrend);
        labelTimeTrend->setObjectName("labelTimeTrend");
        labelTimeTrend->setStyleSheet(QString::fromUtf8("color: #333333; font-size: 14px; font-weight: 500;"));

        verticalLayout_5->addWidget(labelTimeTrend);

        chartViewTimeTrend = new QChartView(widgetTimeTrend);
        chartViewTimeTrend->setObjectName("chartViewTimeTrend");
        chartViewTimeTrend->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout_5->addWidget(chartViewTimeTrend);


        gridLayout->addWidget(widgetTimeTrend, 1, 1, 1, 1);

        tabWidget->addTab(tabSummary, QString());
        tabDetails = new QWidget();
        tabDetails->setObjectName("tabDetails");
        verticalLayout_6 = new QVBoxLayout(tabDetails);
        verticalLayout_6->setSpacing(8);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(8, 8, 8, 8);
        tableResults = new QTableWidget(tabDetails);
        if (tableResults->columnCount() < 7)
            tableResults->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableResults->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableResults->setObjectName("tableResults");
        tableResults->setStyleSheet(QString::fromUtf8("\n"
"           QTableWidget {\n"
"               font-size: 13px;\n"
"               background-color: white;\n"
"               alternate-background-color: #f8f9fa;\n"
"               border: 1px solid #e0e0e0;\n"
"               border-radius: 6px;\n"
"               gridline-color: #e0e0e0;\n"
"               outline: 0;\n"
"           }\n"
"           QTableWidget::item {\n"
"               padding: 8px;\n"
"               border-bottom: 1px solid #f0f0f0;\n"
"               color: #333333;\n"
"           }\n"
"           QTableWidget::item:hover {\n"
"               background-color: #f0f7ff;\n"
"           }\n"
"           QHeaderView::section {\n"
"               background-color: #3a6ea5;\n"
"               color: white;\n"
"               padding: 8px;\n"
"               border: none;\n"
"               font-weight: 500;\n"
"               font-size: 13px;\n"
"           }\n"
"           QHeaderView {\n"
"               border-top-left-radius: 6px;\n"
"               border-top-right-radius: 6px;\n"
""
                        "           }\n"
"          "));
        tableResults->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        tableResults->setAlternatingRowColors(true);
        tableResults->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        tableResults->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableResults->setShowGrid(false);
        tableResults->setSortingEnabled(true);
        tableResults->setRowCount(0);
        tableResults->setColumnCount(7);

        verticalLayout_6->addWidget(tableResults);

        paginationWidget = new QWidget(tabDetails);
        paginationWidget->setObjectName("paginationWidget");
        paginationWidget->setStyleSheet(QString::fromUtf8("\n"
"           background-color: white;\n"
"           border-radius: 6px;\n"
"           padding: 8px;\n"
"           box-shadow: 0 1px 4px rgba(0,0,0,0.05);\n"
"          "));
        horizontalLayout_2 = new QHBoxLayout(paginationWidget);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(8, 4, 8, 4);
        labelPageInfo = new QLabel(paginationWidget);
        labelPageInfo->setObjectName("labelPageInfo");
        labelPageInfo->setStyleSheet(QString::fromUtf8("\n"
"             color: #333333;\n"
"             font-size: 13px;\n"
"             font-weight: 500;\n"
"             "));

        horizontalLayout_2->addWidget(labelPageInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnFirst = new QPushButton(paginationWidget);
        btnFirst->setObjectName("btnFirst");
        btnFirst->setStyleSheet(QString::fromUtf8("\n"
"              QPushButton {\n"
"                  min-width: 60px;\n"
"                  padding: 6px 8px;\n"
"                  background-color: #f8f9fa;\n"
"                  border: 1px solid #d0d0d0;\n"
"                  border-radius: 4px;\n"
"                  font-size: 12px;\n"
"              }\n"
"              QPushButton:hover {\n"
"                  background-color: #e9ecef;\n"
"              }\n"
"              QPushButton:pressed {\n"
"                  background-color: #dee2e6;\n"
"              }\n"
"             "));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/first.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnFirst->setIcon(icon2);

        horizontalLayout_2->addWidget(btnFirst);

        btnPrev = new QPushButton(paginationWidget);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setStyleSheet(QString::fromUtf8("\n"
"              QPushButton {\n"
"                  min-width: 60px;\n"
"                  padding: 6px 8px;\n"
"                  background-color: #f8f9fa;\n"
"                  border: 1px solid #d0d0d0;\n"
"                  border-radius: 4px;\n"
"                  font-size: 12px;\n"
"              }\n"
"              QPushButton:hover {\n"
"                  background-color: #e9ecef;\n"
"              }\n"
"              QPushButton:pressed {\n"
"                  background-color: #dee2e6;\n"
"              }\n"
"             "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/prev.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPrev->setIcon(icon3);

        horizontalLayout_2->addWidget(btnPrev);

        comboPage = new QComboBox(paginationWidget);
        comboPage->setObjectName("comboPage");
        comboPage->setStyleSheet(QString::fromUtf8("\n"
"              QComboBox {\n"
"                  padding: 4px 8px;\n"
"                  border: 1px solid #d0d0d0;\n"
"                  border-radius: 4px;\n"
"                  min-width: 60px;\n"
"                  font-size: 12px;\n"
"              }\n"
"              QComboBox::drop-down {\n"
"                  width: 20px;\n"
"                  border: none;\n"
"              }\n"
"             "));

        horizontalLayout_2->addWidget(comboPage);

        btnNext = new QPushButton(paginationWidget);
        btnNext->setObjectName("btnNext");
        btnNext->setStyleSheet(QString::fromUtf8("\n"
"              QPushButton {\n"
"                  min-width: 60px;\n"
"                  padding: 6px 8px;\n"
"                  background-color: #f8f9fa;\n"
"                  border: 1px solid #d0d0d0;\n"
"                  border-radius: 4px;\n"
"                  font-size: 12px;\n"
"              }\n"
"              QPushButton:hover {\n"
"                  background-color: #e9ecef;\n"
"              }\n"
"              QPushButton:pressed {\n"
"                  background-color: #dee2e6;\n"
"              }\n"
"             "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNext->setIcon(icon4);

        horizontalLayout_2->addWidget(btnNext);

        btnLast = new QPushButton(paginationWidget);
        btnLast->setObjectName("btnLast");
        btnLast->setStyleSheet(QString::fromUtf8("\n"
"              QPushButton {\n"
"                  min-width: 60px;\n"
"                  padding: 6px 8px;\n"
"                  background-color: #f8f9fa;\n"
"                  border: 1px solid #d0d0d0;\n"
"                  border-radius: 4px;\n"
"                  font-size: 12px;\n"
"              }\n"
"              QPushButton:hover {\n"
"                  background-color: #e9ecef;\n"
"              }\n"
"              QPushButton:pressed {\n"
"                  background-color: #dee2e6;\n"
"              }\n"
"             "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/last.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLast->setIcon(icon5);

        horizontalLayout_2->addWidget(btnLast);

        comboPageSize = new QComboBox(paginationWidget);
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->addItem(QString());
        comboPageSize->setObjectName("comboPageSize");
        comboPageSize->setStyleSheet(QString::fromUtf8("\n"
"              QComboBox {\n"
"                  padding: 4px 8px;\n"
"                  border: 1px solid #d0d0d0;\n"
"                  border-radius: 4px;\n"
"                  min-width: 80px;\n"
"                  font-size: 12px;\n"
"              }\n"
"              QComboBox::drop-down {\n"
"                  width: 20px;\n"
"                  border: none;\n"
"              }\n"
"             "));

        horizontalLayout_2->addWidget(comboPageSize);


        verticalLayout_6->addWidget(paginationWidget);

        tabWidget->addTab(tabDetails, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(TestResultsAnalysisWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TestResultsAnalysisWindow);
    } // setupUi

    void retranslateUi(QWidget *TestResultsAnalysisWindow)
    {
        TestResultsAnalysisWindow->setWindowTitle(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\204\347\273\223\346\236\234\345\210\206\346\236\220\346\250\241\345\235\227", nullptr));
        labelTask->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\344\273\273\345\212\241:", nullptr));
        labelUnit->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\345\217\202\350\257\225\345\215\225\344\275\215:", nullptr));
        labelTime->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\227\266\351\227\264\350\214\203\345\233\264:", nullptr));
        labelTo->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\350\207\263", nullptr));
        btnQuery->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\237\245\350\257\242", nullptr));
        btnExport->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\345\257\274\345\207\272", nullptr));
        labelPassRate->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\351\200\232\350\277\207\347\216\207\347\273\237\350\256\241", nullptr));
        labelItemDistribution->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\351\241\271\345\210\206\345\270\203", nullptr));
        labelUnitPerformance->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\345\217\202\350\257\225\345\215\225\344\275\215\350\241\250\347\216\260", nullptr));
        labelTimeTrend->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\227\266\351\227\264\350\266\213\345\212\277\345\210\206\346\236\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSummary), QCoreApplication::translate("TestResultsAnalysisWindow", "\346\200\273\344\275\223\345\210\206\346\236\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableResults->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\344\273\273\345\212\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableResults->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\345\217\202\350\257\225\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableResults->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\351\241\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableResults->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\240\207\345\207\206\350\246\201\346\261\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableResults->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableResults->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\347\273\223\346\236\234\346\217\217\350\277\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableResults->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\265\213\350\257\225\346\227\266\351\227\264", nullptr));
        labelPageInfo->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\347\254\254 1 \351\241\265 / \345\205\261 1 \351\241\265 (10 \346\235\241)", nullptr));
        btnFirst->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\351\246\226\351\241\265", nullptr));
        btnPrev->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        comboPage->setCurrentText(QString());
        btnNext->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
        btnLast->setText(QCoreApplication::translate("TestResultsAnalysisWindow", "\346\234\253\351\241\265", nullptr));
        comboPageSize->setItemText(0, QCoreApplication::translate("TestResultsAnalysisWindow", "10 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(1, QCoreApplication::translate("TestResultsAnalysisWindow", "20 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(2, QCoreApplication::translate("TestResultsAnalysisWindow", "50 \346\235\241/\351\241\265", nullptr));
        comboPageSize->setItemText(3, QCoreApplication::translate("TestResultsAnalysisWindow", "100 \346\235\241/\351\241\265", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QCoreApplication::translate("TestResultsAnalysisWindow", "\350\257\246\347\273\206\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestResultsAnalysisWindow: public Ui_TestResultsAnalysisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTRESULTSANALYSISWINDOW_H
