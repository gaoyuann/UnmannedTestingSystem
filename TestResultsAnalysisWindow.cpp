#include "TestResultsAnalysisWindow.h"
#include "ui_TestResultsAnalysisWindow.h"
#include "DBUtil.h"
#include <QtCharts>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QPainter>
#include <QStyledItemDelegate>
#include <algorithm>
#include <QTextStream>


TestResultsAnalysisWindow::TestResultsAnalysisWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestResultsAnalysisWindow),
    currentPage(1),
    pageSize(10),
    totalPages(1),
    chartPassRate(new QChart),
    chartItemDistribution(new QChart),
    chartUnitPerformance(new QChart),
    chartTimeTrend(new QChart)
{
    ui->setupUi(this);
    initUI();
    initCharts();
    setupConnections();
    loadFilterOptions();

    if (!DBUtil::instance()->isInitialized()) {
        QMessageBox::critical(this, "错误", "数据库未初始化，无法加载数据");
        return;
    }

    updateTable();
    updateCharts();
}

TestResultsAnalysisWindow::~TestResultsAnalysisWindow()
{
    delete ui;
    delete chartPassRate;
    delete chartItemDistribution;
    delete chartUnitPerformance;
    delete chartTimeTrend;
}

void TestResultsAnalysisWindow::initUI()
{
    // 设置日期范围默认为最近3个月
    QDate today = QDate::currentDate();
    ui->dateStart->setDate(today.addMonths(-3));
    ui->dateEnd->setDate(today);

    // 初始化表格
    QStringList headers;
    headers << "测试任务" << "参试单位" << "测试项" << "标准要求" << "测试结果" << "结果描述" << "测试时间";
    ui->tableResults->setColumnCount(headers.size());
    ui->tableResults->setHorizontalHeaderLabels(headers);

    auto header = ui->tableResults->horizontalHeader();
    header->setDefaultAlignment(Qt::AlignCenter);
    ui->tableResults->verticalHeader()->setVisible(false);
    ui->tableResults->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableResults->setAlternatingRowColors(true);
    ui->tableResults->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableResults->setShowGrid(false);
    ui->tableResults->setSortingEnabled(true);
}

void TestResultsAnalysisWindow::initCharts()
{
    // 通过率统计图表
    chartPassRate->setTitle("测试项通过率统计");
    chartPassRate->setAnimationOptions(QChart::SeriesAnimations);
    chartPassRate->legend()->setVisible(true);
    chartPassRate->legend()->setAlignment(Qt::AlignBottom);
    ui->chartViewPassRate->setChart(chartPassRate);
    ui->chartViewPassRate->setRenderHint(QPainter::Antialiasing);

    // 测试项分布图表
    chartItemDistribution->setTitle("测试项分布");
    chartItemDistribution->setAnimationOptions(QChart::SeriesAnimations);
    chartItemDistribution->legend()->setVisible(true);
    chartItemDistribution->legend()->setAlignment(Qt::AlignRight);
    ui->chartViewItemDistribution->setChart(chartItemDistribution);
    ui->chartViewItemDistribution->setRenderHint(QPainter::Antialiasing);

    // 参试单位表现图表
    chartUnitPerformance->setTitle("参试单位表现");
    chartUnitPerformance->setAnimationOptions(QChart::SeriesAnimations);
    chartUnitPerformance->legend()->setVisible(true);
    chartUnitPerformance->legend()->setAlignment(Qt::AlignBottom);
    ui->chartViewUnitPerformance->setChart(chartUnitPerformance);
    ui->chartViewUnitPerformance->setRenderHint(QPainter::Antialiasing);

    // 时间趋势图表
    chartTimeTrend->setTitle("通过率时间趋势");
    chartTimeTrend->setAnimationOptions(QChart::SeriesAnimations);
    chartTimeTrend->legend()->setVisible(true);
    chartTimeTrend->legend()->setAlignment(Qt::AlignBottom);
    ui->chartViewTimeTrend->setChart(chartTimeTrend);
    ui->chartViewTimeTrend->setRenderHint(QPainter::Antialiasing);
}

void TestResultsAnalysisWindow::setupConnections()
{
    connect(ui->btnQuery, &QPushButton::clicked, this, &TestResultsAnalysisWindow::onQuery);
    connect(ui->btnExport, &QPushButton::clicked, this, &TestResultsAnalysisWindow::onExport);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TestResultsAnalysisWindow::onPageChanged);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TestResultsAnalysisWindow::onPageSizeChanged);
    connect(ui->btnFirst, &QPushButton::clicked, this, &TestResultsAnalysisWindow::gotoFirstPage);
    connect(ui->btnPrev, &QPushButton::clicked, this, &TestResultsAnalysisWindow::gotoPrevPage);
    connect(ui->btnNext, &QPushButton::clicked, this, &TestResultsAnalysisWindow::gotoNextPage);
    connect(ui->btnLast, &QPushButton::clicked, this, &TestResultsAnalysisWindow::gotoLastPage);
}

void TestResultsAnalysisWindow::loadFilterOptions()
{
    // 加载测试任务选项
    auto tasks = DBUtil::instance()->query("SELECT task_id, task_name FROM test_task ORDER BY create_time DESC");
    ui->comboTask->addItem("全部任务", -1);
    for (const auto &task : tasks) {
        ui->comboTask->addItem(task["task_name"].toString(), task["task_id"].toInt());
    }

    // 加载参试单位选项
    auto units = DBUtil::instance()->query("SELECT unit_id, unit_name FROM participate_unit WHERE is_delete = 0 ORDER BY unit_name");
    ui->comboUnit->addItem("全部单位", -1);
    for (const auto &unit : units) {
        ui->comboUnit->addItem(unit["unit_name"].toString(), unit["unit_id"].toInt());
    }
}

QVector<QStringList> TestResultsAnalysisWindow::getTestResults(int taskId, int unitId,
                                                               const QDate &startDate,
                                                               const QDate &endDate)
{
    QString sql = "SELECT t.task_name, u.unit_name, i.item_name, i.standard_requirement, "
                  "i.result, i.result_desc, i.test_time "
                  "FROM test_item i "
                  "JOIN test_task t ON i.task_id = t.task_id "
                  "JOIN participate_unit u ON t.unit_id = u.unit_id "
                  "WHERE i.result != 2 "; // 排除未测试项

    QVariantMap params;

    if (taskId != -1) {
        sql += " AND t.task_id = :taskId";
        params["taskId"] = taskId;
    }

    if (unitId != -1) {
        sql += " AND t.unit_id = :unitId";
        params["unitId"] = unitId;
    }

    if (startDate.isValid()) {
        sql += " AND i.test_time >= :startDate";
        params["startDate"] = startDate.toString("yyyy-MM-dd");
    }

    if (endDate.isValid()) {
        sql += " AND i.test_time <= :endDate";
        params["endDate"] = endDate.addDays(1).toString("yyyy-MM-dd"); // 包含当天
    }

    sql += " ORDER BY i.test_time DESC";

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> testResults;

    for (const auto& row : results) {
        QStringList result;
        result << row["task_name"].toString()
               << row["unit_name"].toString()
               << row["item_name"].toString()
               << row["standard_requirement"].toString()
               << (row["result"].toInt() == 1 ? "通过" : "不通过")
               << row["result_desc"].toString()
               << row["test_time"].toDateTime().toString("yyyy-MM-dd hh:mm");
        testResults.append(result);
    }

    return testResults;
}

QVector<QPair<QString, double>> TestResultsAnalysisWindow::getPassRateByItem()
{
    QString sql = "SELECT i.item_name, "
                  "SUM(CASE WHEN i.result = 1 THEN 1 ELSE 0 END) * 100.0 / COUNT(*) as pass_rate "
                  "FROM test_item i "
                  "WHERE i.result != 2 " // 排除未测试项
                  "GROUP BY i.item_name "
                  "ORDER BY pass_rate DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QPair<QString, double>> passRates;

    for (const auto& row : results) {
        passRates.append(qMakePair(row["item_name"].toString(), row["pass_rate"].toDouble()));
    }

    return passRates;
}

QVector<QPair<QString, int>> TestResultsAnalysisWindow::getItemDistribution()
{
    QString sql = "SELECT i.item_name, COUNT(*) as count "
                  "FROM test_item i "
                  "WHERE i.result != 2 " // 排除未测试项
                  "GROUP BY i.item_name "
                  "ORDER BY count DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QPair<QString, int>> itemDistribution;

    for (const auto& row : results) {
        itemDistribution.append(qMakePair(row["item_name"].toString(), row["count"].toInt()));
    }

    return itemDistribution;
}

QVector<QPair<QString, double>> TestResultsAnalysisWindow::getUnitPerformance()
{
    QString sql = "SELECT u.unit_name, "
                  "SUM(CASE WHEN i.result = 1 THEN 1 ELSE 0 END) * 100.0 / COUNT(*) as pass_rate "
                  "FROM test_item i "
                  "JOIN test_task t ON i.task_id = t.task_id "
                  "JOIN participate_unit u ON t.unit_id = u.unit_id "
                  "WHERE i.result != 2 " // 排除未测试项
                  "GROUP BY u.unit_name "
                  "ORDER BY pass_rate DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QPair<QString, double>> unitPerformance;

    for (const auto& row : results) {
        unitPerformance.append(qMakePair(row["unit_name"].toString(), row["pass_rate"].toDouble()));
    }

    return unitPerformance;
}

QVector<QPair<QDate, double>> TestResultsAnalysisWindow::getTimeTrend()
{
    QString sql = "SELECT DATE(i.test_time) as test_date, "
                  "SUM(CASE WHEN i.result = 1 THEN 1 ELSE 0 END) * 100.0 / COUNT(*) as pass_rate "
                  "FROM test_item i "
                  "WHERE i.result != 2 AND i.test_time IS NOT NULL " // 排除未测试项和未记录时间的
                  "GROUP BY DATE(i.test_time) "
                  "ORDER BY test_date";

    auto results = DBUtil::instance()->query(sql);
    QVector<QPair<QDate, double>> timeTrend;

    for (const auto& row : results) {
        timeTrend.append(qMakePair(row["test_date"].toDate(), row["pass_rate"].toDouble()));
    }

    return timeTrend;
}

void TestResultsAnalysisWindow::updateCharts()
{
    // 更新通过率统计图表
    chartPassRate->removeAllSeries();
    auto passRates = getPassRateByItem();

    QBarSeries *passRateSeries = new QBarSeries();
    QBarSet *passRateSet = new QBarSet("通过率(%)");

    QStringList categories;
    for (const auto &item : passRates) {
        *passRateSet << item.second;
        categories << item.first;
    }

    passRateSeries->append(passRateSet);
    chartPassRate->addSeries(passRateSeries);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chartPassRate->addAxis(axisX, Qt::AlignBottom);
    passRateSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100);
    axisY->setTitleText("通过率(%)");
    chartPassRate->addAxis(axisY, Qt::AlignLeft);
    passRateSeries->attachAxis(axisY);

    // 更新测试项分布图表
    chartItemDistribution->removeAllSeries();
    auto itemDistribution = getItemDistribution();

    QPieSeries *pieSeries = new QPieSeries();
    for (const auto &item : itemDistribution) {
        pieSeries->append(item.first, item.second);
    }

    pieSeries->setLabelsVisible(true);
    chartItemDistribution->addSeries(pieSeries);

    // 更新参试单位表现图表
    chartUnitPerformance->removeAllSeries();
    auto unitPerformance = getUnitPerformance();

    QBarSeries *unitSeries = new QBarSeries();
    QBarSet *unitSet = new QBarSet("通过率(%)");

    QStringList unitCategories;
    for (const auto &item : unitPerformance) {
        *unitSet << item.second;
        unitCategories << item.first;
    }

    unitSeries->append(unitSet);
    chartUnitPerformance->addSeries(unitSeries);

    QBarCategoryAxis *unitAxisX = new QBarCategoryAxis();
    unitAxisX->append(unitCategories);
    chartUnitPerformance->addAxis(unitAxisX, Qt::AlignBottom);
    unitSeries->attachAxis(unitAxisX);

    QValueAxis *unitAxisY = new QValueAxis();
    unitAxisY->setRange(0, 100);
    unitAxisY->setTitleText("通过率(%)");
    chartUnitPerformance->addAxis(unitAxisY, Qt::AlignLeft);
    unitSeries->attachAxis(unitAxisY);

    // 更新时间趋势图表
    chartTimeTrend->removeAllSeries();
    auto timeTrend = getTimeTrend();

    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->setName("通过率趋势");

    QDate minDate = QDate::currentDate();
    QDate maxDate = QDate::currentDate().addYears(-1);

    for (const auto &item : timeTrend) {
        lineSeries->append(item.first.startOfDay().toMSecsSinceEpoch(), item.second);
        if (item.first < minDate) minDate = item.first;
        if (item.first > maxDate) maxDate = item.first;
    }

    chartTimeTrend->addSeries(lineSeries);

    QDateTimeAxis *dateAxis = new QDateTimeAxis();
    dateAxis->setFormat("yyyy-MM-dd");
    dateAxis->setRange(minDate.startOfDay(), maxDate.addDays(1).startOfDay());
    chartTimeTrend->addAxis(dateAxis, Qt::AlignBottom);
    lineSeries->attachAxis(dateAxis);

    QValueAxis *trendAxisY = new QValueAxis();
    trendAxisY->setRange(0, 100);
    trendAxisY->setTitleText("通过率(%)");
    chartTimeTrend->addAxis(trendAxisY, Qt::AlignLeft);
    lineSeries->attachAxis(trendAxisY);
}

void TestResultsAnalysisWindow::updateTable()
{
    ui->tableResults->blockSignals(true);
    ui->tableResults->clearContents();
    ui->tableResults->setRowCount(0);
    ui->tableResults->blockSignals(false);

    int taskId = ui->comboTask->currentData().toInt();
    int unitId = ui->comboUnit->currentData().toInt();
    QDate startDate = ui->dateStart->date();
    QDate endDate = ui->dateEnd->date();

    QVector<QStringList> results = getTestResults(taskId, unitId, startDate, endDate);
    ui->tableResults->setRowCount(results.size());

    for (int i = 0; i < results.size(); ++i) {
        const QStringList &result = results[i];

        for (int j = 0; j < result.size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(result[j]);
            item->setTextAlignment(Qt::AlignCenter);

            // 设置结果列的文本颜色
            if (j == 4) {
                item->setForeground(result[j] == "通过" ? QColor(0, 128, 0) : QColor(255, 0, 0));
            }

            ui->tableResults->setItem(i, j, item);
        }
    }

    updatePagination();
    emit statusMessageRequested(QString("共 %1 条记录").arg(results.size()));
}

void TestResultsAnalysisWindow::updatePagination()
{
    int rowCount = ui->tableResults->rowCount();
    totalPages = (rowCount + pageSize - 1) / pageSize;
    if (totalPages == 0) totalPages = 1;

    currentPage = std::clamp(currentPage, 1, totalPages);

    ui->comboPage->blockSignals(true);
    ui->comboPage->clear();
    for (int i = 1; i <= totalPages; ++i) {
        ui->comboPage->addItem(QString("第%1页").arg(i));
    }
    ui->comboPage->setCurrentIndex(currentPage - 1);
    ui->comboPage->blockSignals(false);

    ui->labelPageInfo->setText(
        QString("第 %1 页 / 共 %2 页 (%3 条)").arg(currentPage).arg(totalPages).arg(rowCount));

    ui->btnFirst->setEnabled(currentPage > 1);
    ui->btnPrev->setEnabled(currentPage > 1);
    ui->btnNext->setEnabled(currentPage < totalPages);
    ui->btnLast->setEnabled(currentPage < totalPages);
}

void TestResultsAnalysisWindow::onQuery()
{
    updateTable();
    updateCharts();
}

void TestResultsAnalysisWindow::onExport()
{
    // 打开文件对话框让用户选择保存路径和文件名
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("导出数据"),
        "",
        tr("CSV文件 (*.csv);;所有文件 (*)")
        );

    // 如果用户取消选择，则直接返回
    if (fileName.isEmpty()) {
        return;
    }

    // 确保文件以.csv扩展名结尾
    if (!fileName.endsWith(".csv", Qt::CaseInsensitive)) {
        fileName += ".csv";
    }

    QFile file(fileName);
    // 尝试以只写和文本模式打开文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(
            this,
            tr("警告"),
            tr("无法创建文件：%1").arg(file.errorString())
            );
        return;
    }

    // 创建文本流并设置UTF-8编码（Qt 6 正确方式）
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);  // 这里是修改的地方

    // 写入表头
    QStringList headers;
    for (int i = 0; i < ui->tableResults->columnCount(); ++i) {
        QTableWidgetItem *headerItem = ui->tableResults->horizontalHeaderItem(i);
        headers << (headerItem ? headerItem->text() : tr("未命名列"));
    }
    out << headers.join(",") << "\n";

    // 写入表格数据
    for (int i = 0; i < ui->tableResults->rowCount(); ++i) {
        QStringList rowData;
        for (int j = 0; j < ui->tableResults->columnCount(); ++j) {
            // 处理可能的空单元格，避免空指针异常
            QTableWidgetItem *item = ui->tableResults->item(i, j);
            QString cellText = item ? item->text() : "";
            // 替换文本中的逗号，避免破坏CSV格式
            rowData << cellText.replace(",", ";");
        }
        out << rowData.join(",") << "\n";
    }

    // 关闭文件
    file.close();

    // 发送状态消息通知用户导出完成
    emit statusMessageRequested(tr("数据已导出到: %1").arg(fileName), 3000);
}



void TestResultsAnalysisWindow::onPageChanged(int index)
{
    currentPage = index + 1;
    updateTable();
}

void TestResultsAnalysisWindow::onPageSizeChanged(int index)
{
    static const int pageSizes[] = {10, 20, 50, 100};
    pageSize = pageSizes[index];
    currentPage = 1;
    updateTable();
}

void TestResultsAnalysisWindow::gotoFirstPage()
{
    currentPage = 1;
    updateTable();
}

void TestResultsAnalysisWindow::gotoPrevPage()
{
    if (currentPage > 1) {
        currentPage--;
        updateTable();
    }
}

void TestResultsAnalysisWindow::gotoNextPage()
{
    if (currentPage < totalPages) {
        currentPage++;
        updateTable();
    }
}

void TestResultsAnalysisWindow::gotoLastPage()
{
    currentPage = totalPages;
    updateTable();
}
