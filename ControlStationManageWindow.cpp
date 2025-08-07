#include "ControlStationManageWindow.h"
#include "ui_ControlStationManageWindow.h"
#include "ControlStationDialog.h"
#include "DBUtil.h"

#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>
#include <QStyledItemDelegate>
#include <algorithm>

// 复选框委托类实现
class CheckBoxDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);

        if (opt.state & QStyle::State_MouseOver) {
            painter->fillRect(opt.rect.adjusted(1,1,-1,-1), QColor(220, 230, 240));
        }

        QRect checkRect = QRect(opt.rect.x() + opt.rect.width()/2 - 8,
                                opt.rect.y() + opt.rect.height()/2 - 8,
                                16, 16);

        bool checked = index.data(Qt::CheckStateRole) == Qt::Checked;
        QColor checkColor = checked ? QColor(58, 110, 165) : QColor(200, 200, 200);

        painter->setPen(QPen(checkColor, 1.5));
        painter->setBrush(checked ? QBrush(checkColor) : QBrush(Qt::white));
        painter->drawRoundedRect(checkRect, 3, 3);

        if (checked) {
            painter->setPen(QPen(Qt::white, 2));
            painter->drawLine(checkRect.x()+4, checkRect.y()+8,
                              checkRect.x()+6, checkRect.y()+12);
            painter->drawLine(checkRect.x()+6, checkRect.y()+12,
                              checkRect.x()+12, checkRect.y()+4);
        }

        painter->restore();
    }
};

ControlStationManageWindow::ControlStationManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlStationManageWindow),
    currentPage(1),
    pageSize(10),
    totalPages(1)
{
    ui->setupUi(this);
    initUI();
    initPagination();
    setupConnections();

    if (!DBUtil::instance()->isInitialized()) {
        QMessageBox::critical(this, "错误", "数据库未初始化，无法加载数据");
        return;
    }

    updateTable();
}

ControlStationManageWindow::~ControlStationManageWindow()
{
    delete ui;
}

void ControlStationManageWindow::initUI()
{
    QStringList headers;
    headers << "" << "控制站名称" << "所属单位" << "控制站类型" << "IP地址" << "通信端口" << "状态" << "更新时间";
    ui->tableStations->setColumnCount(headers.size());
    ui->tableStations->setHorizontalHeaderLabels(headers);

    auto header = ui->tableStations->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableStations->setColumnWidth(0, 40);
    header->setDefaultAlignment(Qt::AlignCenter);

    ui->tableStations->setAlternatingRowColors(true);
    ui->tableStations->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableStations->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStations->verticalHeader()->setVisible(false);
    ui->tableStations->setShowGrid(false);
    ui->tableStations->setSortingEnabled(true);
    ui->tableStations->setItemDelegateForColumn(0, new CheckBoxDelegate(this));
}

void ControlStationManageWindow::initPagination()
{
    ui->comboPageSize->setCurrentIndex(0);
    ui->comboPage->clear();
    ui->comboPage->addItem("第1页");
}

void ControlStationManageWindow::setupConnections()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &ControlStationManageWindow::onAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &ControlStationManageWindow::onEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &ControlStationManageWindow::onDelete);
    connect(ui->btnSearch, &QPushButton::clicked, this, &ControlStationManageWindow::onSearch);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ControlStationManageWindow::onPageChanged);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ControlStationManageWindow::onPageSizeChanged);
    connect(ui->btnFirst, &QPushButton::clicked, this, &ControlStationManageWindow::gotoFirstPage);
    connect(ui->btnPrev, &QPushButton::clicked, this, &ControlStationManageWindow::gotoPrevPage);
    connect(ui->btnNext, &QPushButton::clicked, this, &ControlStationManageWindow::gotoNextPage);
    connect(ui->btnLast, &QPushButton::clicked, this, &ControlStationManageWindow::gotoLastPage);
}

QVector<QStringList> ControlStationManageWindow::getAllStations()
{
    QString sql = "SELECT s.station_id, s.station_name, COALESCE(u.unit_name, '未知单位') as unit_name, "
                  "s.station_type, s.ip_address, s.port, s.status, s.update_time "
                  "FROM control_station s "
                  "LEFT JOIN participate_unit u ON s.unit_id = u.unit_id AND u.is_delete = 0 "
                  "WHERE s.is_delete = 0 "
                  "ORDER BY s.update_time DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QStringList> stations;

    for (const auto& row : results) {
        QStringList station;
        station << row["station_id"].toString()
                << row["station_name"].toString()
                << row["unit_name"].toString()
                << row["station_type"].toString()
                << row["ip_address"].toString()
                << row["port"].toString()
                << (row["status"].toInt() == 1 ? "在线" : "离线")
                << row["update_time"].toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        stations.append(station);
    }

    return stations;
}

bool ControlStationManageWindow::addStation(const QStringList &stationData)
{
    if (stationData.size() < 6) return false;

    QString sql = "INSERT INTO control_station "
                  "(station_name, unit_id, station_type, ip_address, port, status, "
                  "create_time, update_time, is_delete) "
                  "VALUES (:name, :unit_id, :type, :ip, :port, :status, "
                  "NOW(), NOW(), 0)";

    QVariantMap params;
    params["name"] = stationData[0];
    params["unit_id"] = stationData[1].toInt();
    params["type"] = stationData[2];
    params["ip"] = stationData[3];
    params["port"] = stationData[4].toInt();
    params["status"] = stationData[5].toInt();

    int affectedRows = DBUtil::instance()->execute(sql, params);
    return affectedRows > 0;
}

bool ControlStationManageWindow::updateStation(int stationId, const QStringList &stationData) {
    if (stationData.size() < 6) return false;

    // 执行更新
    QString updateSql = "UPDATE control_station SET "
                        "station_name = :name, "
                        "unit_id = (SELECT unit_id FROM participate_unit WHERE unit_name = :unit_name LIMIT 1), "
                        "station_type = :type, "
                        "ip_address = :ip, "
                        "port = :port, "
                        "status = :status, "
                        "update_time = NOW() "
                        "WHERE station_id = :id";

    QVariantMap params;
    params["id"] = stationId;
    params["name"] = stationData[0];
    params["unit_name"] = stationData[1]; // 现在使用单位名称而不是ID
    params["type"] = stationData[2];
    params["ip"] = stationData[3];
    params["port"] = stationData[4].toInt();
    params["status"] = stationData[5].toInt();

    return DBUtil::instance()->execute(updateSql, params) > 0;
}

bool ControlStationManageWindow::deleteStations(const QList<int> &stationIds)
{
    if (stationIds.isEmpty()) return false;

    QString idList;
    for (int id : stationIds) {
        if (!idList.isEmpty()) idList += ",";
        idList += QString::number(id);
    }

    QString sql = QString("UPDATE control_station SET is_delete = 1 WHERE station_id IN (%1)").arg(idList);
    return DBUtil::instance()->execute(sql) > 0;
}

QVector<QStringList> ControlStationManageWindow::searchStations(const QString &keyword)
{
    QString sql = "SELECT s.station_id, s.station_name, COALESCE(u.unit_name, '未知单位') as unit_name, "
                  "s.station_type, s.ip_address, s.port, s.status, s.update_time "
                  "FROM control_station s "
                  "LEFT JOIN participate_unit u ON s.unit_id = u.unit_id AND u.is_delete = 0 "
                  "WHERE s.is_delete = 0 AND "
                  "(s.station_name LIKE :keyword OR "
                  "u.unit_name LIKE :keyword OR "
                  "s.station_type LIKE :keyword OR "
                  "s.ip_address LIKE :keyword) "
                  "ORDER BY s.update_time DESC";

    QVariantMap params;
    params["keyword"] = QString("%%1%").arg(keyword);

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> stations;

    for (const auto& row : results) {
        QStringList station;
        station << row["station_id"].toString()
                << row["station_name"].toString()
                << row["unit_name"].toString()
                << row["station_type"].toString()
                << row["ip_address"].toString()
                << row["port"].toString()
                << (row["status"].toInt() == 1 ? "在线" : "离线")
                << row["update_time"].toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        stations.append(station);
    }

    return stations;
}



void ControlStationManageWindow::updatePagination()
{
    QVector<QStringList> stations = getAllStations();
    int totalItems = stations.size();
    totalPages = (totalItems + pageSize - 1) / pageSize;
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
        QString("第 %1 页 / 共 %2 页 (%3 条)").arg(currentPage).arg(totalPages).arg(totalItems));

    ui->btnFirst->setEnabled(currentPage > 1);
    ui->btnPrev->setEnabled(currentPage > 1);
    ui->btnNext->setEnabled(currentPage < totalPages);
    ui->btnLast->setEnabled(currentPage < totalPages);
}

void ControlStationManageWindow::updateTable()
{
    ui->tableStations->blockSignals(true);
    ui->tableStations->clearContents();
    ui->tableStations->setRowCount(0);
    ui->tableStations->blockSignals(false);

    QVector<QStringList> stations = getAllStations();
    ui->tableStations->setRowCount(stations.size());

    for (int i = 0; i < stations.size(); ++i) {
        const QStringList &station = stations[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableStations->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(station[1]);
        nameItem->setData(Qt::UserRole, station[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 1, nameItem);

        QTableWidgetItem *unitItem = new QTableWidgetItem(station[2]);
        unitItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 2, unitItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(station[3]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 3, typeItem);

        QTableWidgetItem *ipItem = new QTableWidgetItem(station[4]);
        ipItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 4, ipItem);

        QTableWidgetItem *portItem = new QTableWidgetItem(station[5]);
        portItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 5, portItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(station[6]);
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setForeground(station[6] == "在线" ? QColor(0, 128, 0) : QColor(255, 0, 0));
        ui->tableStations->setItem(i, 6, statusItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(station[7]);
        timeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 7, timeItem);
    }

    updatePagination();
    emit statusMessageRequested(QString("共 %1 条记录").arg(stations.size()));
    qApp->processEvents();
}

void ControlStationManageWindow::updateTableWithResults(const QVector<QStringList> &results)
{
    ui->tableStations->clearContents();
    ui->tableStations->setRowCount(results.size());

    for (int i = 0; i < results.size(); ++i) {
        const QStringList &station = results[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableStations->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(station[1]);
        nameItem->setData(Qt::UserRole, station[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 1, nameItem);

        QTableWidgetItem *unitItem = new QTableWidgetItem(station[2]);
        unitItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 2, unitItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(station[3]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 3, typeItem);

        QTableWidgetItem *ipItem = new QTableWidgetItem(station[4]);
        ipItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 4, ipItem);

        QTableWidgetItem *portItem = new QTableWidgetItem(station[5]);
        portItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 5, portItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(station[6]);
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setForeground(station[6] == "在线" ? QColor(0, 128, 0) : QColor(255, 0, 0));
        ui->tableStations->setItem(i, 6, statusItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(station[7]);
        timeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableStations->setItem(i, 7, timeItem);
    }

    updatePagination();
}

QList<int> ControlStationManageWindow::getSelectedRows() const
{
    QList<int> selectedRows;
    for(int i = 0; i < ui->tableStations->rowCount(); ++i) {
        if(ui->tableStations->item(i, 0)->checkState() == Qt::Checked) {
            selectedRows.append(i);
        }
    }
    return selectedRows;
}

void ControlStationManageWindow::onAdd()
{
    ControlStationDialog dialog(this, ControlStationDialog::NewStation);
    if (dialog.exec() == QDialog::Accepted) {
        auto stationData = dialog.getStationData();
        if (stationData.isValid()) {
            DBUtil::instance()->beginTransaction();

            if (addStation(stationData.toStringList())) {
                DBUtil::instance()->commitTransaction();
                updateTable();
                emit statusMessageRequested("新增控制站成功", 3000);
            } else {
                DBUtil::instance()->rollbackTransaction();
                emit statusMessageRequested("新增控制站失败: " + DBUtil::instance()->lastError(), 5000);
            }
        }
    }
}

void ControlStationManageWindow::onEdit()
{
    QList<int> selectedRows = getSelectedRows();
    if (selectedRows.size() != 1) {
        QMessageBox::warning(
            this,
            "警告",
            "<span style='color: black;'>请勾选一条记录进行编辑</span>"
            );
        return;
    }

    int row = selectedRows.first();
    int stationId = ui->tableStations->item(row, 1)->data(Qt::UserRole).toInt();

    ControlStationDialog::StationData currentData;
    currentData.name = ui->tableStations->item(row, 1)->text();
    currentData.unitName = ui->tableStations->item(row, 2)->text();
    currentData.type = ui->tableStations->item(row, 3)->text();
    currentData.ip = ui->tableStations->item(row, 4)->text();
    currentData.port = ui->tableStations->item(row, 5)->text().toInt();
    currentData.status = ui->tableStations->item(row, 6)->text() == "在线" ? 1 : 0;

    ControlStationDialog dialog(this, ControlStationDialog::EditStation, currentData);
    if (dialog.exec() == QDialog::Accepted) {
        auto stationData = dialog.getStationData();
        if (updateStation(stationId, stationData.toStringList())) {
            updateTable();
            emit statusMessageRequested("编辑控制站成功", 3000);
        } else {
            emit statusMessageRequested("编辑控制站失败: " + DBUtil::instance()->lastError(), 5000);
        }
    }
}

void ControlStationManageWindow::onDelete()
{
    QList<int> selectedRows = getSelectedRows();
    if(selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "<span style='color: black;'>请勾选要删除的记录</span>");
        return;
    }

    if(QMessageBox::question(this, "确认删除",
                              QString("确定要删除选中的 %1 条记录吗？").arg(selectedRows.size()),
                              QMessageBox::Yes|QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    QList<int> stationIds;
    for (int row : selectedRows) {
        int stationId = ui->tableStations->item(row, 1)->data(Qt::UserRole).toInt();
        stationIds.append(stationId);
    }

    if (deleteStations(stationIds)) {
        updateTable();
        emit statusMessageRequested(QString("已删除 %1 条记录").arg(selectedRows.size()), 3000);
    } else {
        emit statusMessageRequested("删除失败: " + DBUtil::instance()->lastError(), 5000);
    }
}



void ControlStationManageWindow::onSearch()
{
    QString keyword = ui->lineSearch->text().trimmed();
    if (keyword.isEmpty()) {
        updateTable();
        return;
    }

    QVector<QStringList> results = searchStations(keyword);
    updateTableWithResults(results);
    emit statusMessageRequested(QString("搜索到 %1 条匹配记录").arg(results.size()), 3000);
}

void ControlStationManageWindow::onPageChanged(int index)
{
    currentPage = index + 1;
    updateTable();
    ui->comboPage->setCurrentText(QString("第%1页").arg(currentPage));
}

void ControlStationManageWindow::onPageSizeChanged(int index)
{
    static const int pageSizes[] = {10, 20, 50, 100};
    pageSize = pageSizes[index];
    currentPage = 1;
    updateTable();
}

void ControlStationManageWindow::gotoFirstPage()
{
    currentPage = 1;
    updateTable();
}

void ControlStationManageWindow::gotoPrevPage()
{
    if (currentPage > 1) {
        currentPage--;
        updateTable();
    }
}

void ControlStationManageWindow::gotoNextPage()
{
    if (currentPage < totalPages) {
        currentPage++;
        updateTable();
    }
}

void ControlStationManageWindow::gotoLastPage()
{
    currentPage = totalPages;
    updateTable();
}
