#ifndef TESTRESULTSANALYSISWINDOW_H
#define TESTRESULTSANALYSISWINDOW_H

#include <QWidget>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QDate>

namespace Ui {
class TestResultsAnalysisWindow;
}

class TestResultsAnalysisWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestResultsAnalysisWindow(QWidget *parent = nullptr);
    ~TestResultsAnalysisWindow();

signals:
    void statusMessageRequested(const QString &message, int timeout = 0);

private slots:
    void onQuery();
    void onExport();
    void onPageChanged(int index);
    void onPageSizeChanged(int index);
    void gotoFirstPage();
    void gotoPrevPage();
    void gotoNextPage();
    void gotoLastPage();

private:
    void initUI();
    void initCharts();
    void setupConnections();
    void updateCharts();
    void updateTable();
    void updatePagination();
    void loadFilterOptions();

    // 数据库操作方法
    QVector<QStringList> getTestResults(int taskId = -1, int unitId = -1,
                                        const QDate &startDate = QDate(),
                                        const QDate &endDate = QDate());
    QVector<QPair<QString, double>> getPassRateByItem();
    QVector<QPair<QString, int>> getItemDistribution();
    QVector<QPair<QString, double>> getUnitPerformance();
    QVector<QPair<QDate, double>> getTimeTrend();

    Ui::TestResultsAnalysisWindow *ui;
    int currentPage;
    int pageSize;
    int totalPages;
    QChart *chartPassRate;
    QChart *chartItemDistribution;
    QChart *chartUnitPerformance;
    QChart *chartTimeTrend;
};

#endif // TESTRESULTSANALYSISWINDOW_H
