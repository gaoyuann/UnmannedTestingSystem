#include "ProtocolManageWindow.h"
#include "ui_ProtocolManageWindow.h"
#include "ProtocolDialog.h"
#include "MessageFormatDialog.h"
#include "DBUtil.h"

#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>
#include <QStyledItemDelegate>
#include <algorithm>


ProtocolManageWindow::ProtocolManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProtocolManageWindow),
    currentPage(1),
    pageSize(10),
    totalPages(1),
    currentProtocolId(-1)
{
    ui->setupUi(this);
    initUI();
    initPagination();
    setupConnections();

    if (!DBUtil::instance()->isInitialized()) {
        QMessageBox::critical(this, "错误", "数据库未初始化，无法加载数据");
        return;
    }

    updateProtocolTable();
}

ProtocolManageWindow::~ProtocolManageWindow()
{
    delete ui;
}

void ProtocolManageWindow::initUI()
{
    // 协议表格初始化
    QStringList protocolHeaders;
    protocolHeaders << "" << "协议名称" << "协议类型" << "创建时间" << "更新时间";
    ui->tableProtocols->setColumnCount(protocolHeaders.size());
    ui->tableProtocols->setHorizontalHeaderLabels(protocolHeaders);

    auto protocolHeader = ui->tableProtocols->horizontalHeader();
    protocolHeader->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableProtocols->setColumnWidth(0, 40);
    protocolHeader->setDefaultAlignment(Qt::AlignCenter);

    ui->tableProtocols->setAlternatingRowColors(true);
    ui->tableProtocols->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableProtocols->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableProtocols->verticalHeader()->setVisible(false);
    ui->tableProtocols->setShowGrid(false);
    ui->tableProtocols->setSortingEnabled(true);
    ui->tableProtocols->setItemDelegateForColumn(0, new CheckBoxDelegate(this));
}

void ProtocolManageWindow::initPagination()
{
    ui->comboPageSize->setCurrentIndex(0);
    ui->comboPage->clear();
    ui->comboPage->addItem("第1页");
}

void ProtocolManageWindow::setupConnections()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &ProtocolManageWindow::onAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &ProtocolManageWindow::onEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &ProtocolManageWindow::onDelete);
    connect(ui->btnFormat, &QPushButton::clicked, this, &ProtocolManageWindow::onFormat);
    connect(ui->btnSearch, &QPushButton::clicked, this, &ProtocolManageWindow::onSearch);
    connect(ui->tableProtocols, &QTableWidget::cellClicked, this, &ProtocolManageWindow::onProtocolSelected);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ProtocolManageWindow::onPageChanged);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ProtocolManageWindow::onPageSizeChanged);
    connect(ui->btnFirst, &QPushButton::clicked, this, &ProtocolManageWindow::gotoFirstPage);
    connect(ui->btnPrev, &QPushButton::clicked, this, &ProtocolManageWindow::gotoPrevPage);
    connect(ui->btnNext, &QPushButton::clicked, this, &ProtocolManageWindow::gotoNextPage);
    connect(ui->btnLast, &QPushButton::clicked, this, &ProtocolManageWindow::gotoLastPage);
}

QVector<QStringList> ProtocolManageWindow::getAllProtocols()
{
    QString sql = "SELECT protocol_id, protocol_name, protocol_type, "
                  "DATE_FORMAT(create_time, '%Y-%m-%d %H:%i:%s') as create_time, "
                  "DATE_FORMAT(update_time, '%Y-%m-%d %H:%i:%s') as update_time "
                  "FROM protocol WHERE is_delete = 0 "
                  "ORDER BY update_time DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QStringList> protocols;

    for (const auto& row : results) {
        QStringList protocol;
        protocol << row["protocol_id"].toString()
                 << row["protocol_name"].toString()
                 << row["protocol_type"].toString()
                 << row["create_time"].toString()
                 << row["update_time"].toString();
        protocols.append(protocol);
    }

    return protocols;
}

bool ProtocolManageWindow::addProtocol(const QStringList &protocolData)
{
    if (protocolData.size() < 2) return false;

    QString sql = "INSERT INTO protocol "
                  "(protocol_name, protocol_type, description, "
                  "create_time, update_time, is_delete) "
                  "VALUES (:name, :type, :desc, NOW(), NOW(), 0)";

    QVariantMap params;
    params["name"] = protocolData[0];
    params["type"] = protocolData[1];
    params["desc"] = protocolData.size() > 2 ? protocolData[2] : "";

    return DBUtil::instance()->execute(sql, params) > 0;
}

bool ProtocolManageWindow::updateProtocol(int protocolId, const QStringList &protocolData)
{
    if (protocolData.size() < 2) return false;

    QString sql = "UPDATE protocol SET "
                  "protocol_name = :name, "
                  "protocol_type = :type, "
                  "description = :desc, "
                  "update_time = NOW() "
                  "WHERE protocol_id = :id";

    QVariantMap params;
    params["id"] = protocolId;
    params["name"] = protocolData[0];
    params["type"] = protocolData[1];
    params["desc"] = protocolData.size() > 2 ? protocolData[2] : "";

    return DBUtil::instance()->execute(sql, params) > 0;
}

bool ProtocolManageWindow::deleteProtocols(const QList<int> &protocolIds)
{
    if (protocolIds.isEmpty()) return false;

    QString idList;
    for (int id : protocolIds) {
        if (!idList.isEmpty()) idList += ",";
        idList += QString::number(id);
    }

    QString sql = QString("UPDATE protocol SET is_delete = 1 WHERE protocol_id IN (%1)").arg(idList);
    return DBUtil::instance()->execute(sql) > 0;
}

QVector<QStringList> ProtocolManageWindow::searchProtocols(const QString &keyword)
{
    QString sql = "SELECT protocol_id, protocol_name, protocol_type, "
                  "DATE_FORMAT(create_time, '%Y-%m-%d %H:%i:%s') as create_time, "
                  "DATE_FORMAT(update_time, '%Y-%m-%d %H:%i:%s') as update_time "
                  "FROM protocol "
                  "WHERE is_delete = 0 AND "
                  "(protocol_name LIKE :keyword OR "
                  "protocol_type LIKE :keyword OR "
                  "description LIKE :keyword) "
                  "ORDER BY update_time DESC";

    QVariantMap params;
    params["keyword"] = QString("%%1%").arg(keyword);

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> protocols;

    for (const auto& row : results) {
        QStringList protocol;
        protocol << row["protocol_id"].toString()
                 << row["protocol_name"].toString()
                 << row["protocol_type"].toString()
                 << row["create_time"].toString()
                 << row["update_time"].toString();
        protocols.append(protocol);
    }

    return protocols;
}

QVector<MessageFormat> ProtocolManageWindow::getMessageFormats(int protocolId)
{
    QString sql = "SELECT format_id, field_name, data_type, length, sort, description "
                  "FROM protocol_message_format "
                  "WHERE protocol_id = :protocol_id "
                  "ORDER BY sort";

    QVariantMap params;
    params["protocol_id"] = protocolId;

    auto results = DBUtil::instance()->query(sql, params);
    QVector<MessageFormat> formats;

    for (const auto& row : results) {
        MessageFormat format;
        format.formatId = row["format_id"].toInt();
        format.fieldName = row["field_name"].toString();
        format.dataType = row["data_type"].toString();
        format.length = row["length"].toInt();
        format.sort = row["sort"].toInt();
        format.description = row["description"].toString();
        formats.append(format);
    }

    return formats;
}

bool ProtocolManageWindow::saveMessageFormats(int protocolId, const QVector<MessageFormat> &formats)
{
    DBUtil::instance()->beginTransaction();

    try {
        // 先删除旧的格式
        QString deleteSql = "DELETE FROM protocol_message_format WHERE protocol_id = :protocol_id";
        QVariantMap deleteParams;
        deleteParams["protocol_id"] = protocolId;
        DBUtil::instance()->execute(deleteSql, deleteParams);

        // 插入新的格式
        QString insertSql = "INSERT INTO protocol_message_format "
                            "(format_id, protocol_id, field_name, data_type, length, sort, description) "
                            "VALUES (:format_id, :protocol_id, :field_name, :data_type, :length, :sort, :description)";

        // 获取当前最大ID
        int maxId = 0;
        QString maxIdSql = "SELECT MAX(format_id) as max_id FROM protocol_message_format";
        auto result = DBUtil::instance()->query(maxIdSql);
        if (!result.isEmpty()) {
            maxId = result.first()["max_id"].toInt();
        }

        for (const auto &format : formats) {
            QVariantMap params;
            params["format_id"] = ++maxId;  // 自增ID
            params["protocol_id"] = protocolId;
            params["field_name"] = format.fieldName;
            params["data_type"] = format.dataType;
            params["length"] = format.length;
            params["sort"] = format.sort;
            params["description"] = format.description;

            if (DBUtil::instance()->execute(insertSql, params) <= 0) {
                throw std::runtime_error("保存报文格式失败");
            }
        }

        DBUtil::instance()->commitTransaction();
        return true;
    } catch (...) {
        DBUtil::instance()->rollbackTransaction();
        return false;
    }
}

void ProtocolManageWindow::updatePagination()
{
    QVector<QStringList> protocols = getAllProtocols();
    int totalItems = protocols.size();
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

void ProtocolManageWindow::updateProtocolTable()
{
    ui->tableProtocols->blockSignals(true);
    ui->tableProtocols->clearContents();
    ui->tableProtocols->setRowCount(0);
    ui->tableProtocols->blockSignals(false);

    QVector<QStringList> protocols = getAllProtocols();
    ui->tableProtocols->setRowCount(protocols.size());

    for (int i = 0; i < protocols.size(); ++i) {
        const QStringList &protocol = protocols[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableProtocols->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(protocol[1]);
        nameItem->setData(Qt::UserRole, protocol[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 1, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(protocol[2]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 2, typeItem);

        QTableWidgetItem *createTimeItem = new QTableWidgetItem(protocol[3]);
        createTimeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 3, createTimeItem);

        QTableWidgetItem *updateTimeItem = new QTableWidgetItem(protocol[4]);
        updateTimeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 4, updateTimeItem);
    }

    updatePagination();
    emit statusMessageRequested(QString("共 %1 条记录").arg(protocols.size()));
    qApp->processEvents();
}

void ProtocolManageWindow::updateTableWithResults(const QVector<QStringList> &results)
{
    ui->tableProtocols->clearContents();
    ui->tableProtocols->setRowCount(results.size());

    for (int i = 0; i < results.size(); ++i) {
        const QStringList &protocol = results[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableProtocols->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(protocol[1]);
        nameItem->setData(Qt::UserRole, protocol[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 1, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(protocol[2]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 2, typeItem);

        QTableWidgetItem *createTimeItem = new QTableWidgetItem(protocol[3]);
        createTimeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 3, createTimeItem);

        QTableWidgetItem *updateTimeItem = new QTableWidgetItem(protocol[4]);
        updateTimeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableProtocols->setItem(i, 4, updateTimeItem);
    }

    updatePagination();
}

QList<int> ProtocolManageWindow::getSelectedRows() const
{
    QList<int> selectedRows;
    for(int i = 0; i < ui->tableProtocols->rowCount(); ++i) {
        if(ui->tableProtocols->item(i, 0)->checkState() == Qt::Checked) {
            selectedRows.append(i);
        }
    }
    return selectedRows;
}

void ProtocolManageWindow::onAdd()
{
    ProtocolDialog dialog(this, ProtocolDialog::NewProtocol);
    if (dialog.exec() == QDialog::Accepted) {
        auto protocolData = dialog.getProtocolData();
        if (protocolData.isValid()) {
            DBUtil::instance()->beginTransaction();

            if (addProtocol(protocolData.toStringList())) {
                DBUtil::instance()->commitTransaction();
                updateProtocolTable();
                emit statusMessageRequested("新增协议成功", 3000);
            } else {
                DBUtil::instance()->rollbackTransaction();
                emit statusMessageRequested("新增协议失败: " + DBUtil::instance()->lastError(), 5000);
            }
        }
    }
}

void ProtocolManageWindow::onEdit()
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
    int protocolId = ui->tableProtocols->item(row, 1)->data(Qt::UserRole).toInt();

    ProtocolDialog::ProtocolData currentData;
    currentData.name = ui->tableProtocols->item(row, 1)->text();
    currentData.type = ui->tableProtocols->item(row, 2)->text();
    currentData.description = ""; // 需要从数据库获取完整数据

    ProtocolDialog dialog(this, ProtocolDialog::EditProtocol, currentData);
    if (dialog.exec() == QDialog::Accepted) {
        auto protocolData = dialog.getProtocolData();
        if (updateProtocol(protocolId, protocolData.toStringList())) {
            updateProtocolTable();
            emit statusMessageRequested("编辑协议成功", 3000);
        } else {
            emit statusMessageRequested("编辑协议失败: " + DBUtil::instance()->lastError(), 5000);
        }
    }
}

void ProtocolManageWindow::onDelete()
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

    QList<int> protocolIds;
    for (int row : selectedRows) {
        int protocolId = ui->tableProtocols->item(row, 1)->data(Qt::UserRole).toInt();
        protocolIds.append(protocolId);
    }

    if (deleteProtocols(protocolIds)) {
        updateProtocolTable();
        emit statusMessageRequested(QString("已删除 %1 条记录").arg(selectedRows.size()), 3000);
    } else {
        emit statusMessageRequested("删除失败: " + DBUtil::instance()->lastError(), 5000);
    }
}

MessageFormatDialog::~MessageFormatDialog()
{
    delete ui;
}

void ProtocolManageWindow::onFormat()
{
    // 获取选中的行
    QList<int> selectedRows = getSelectedRows();
    if (selectedRows.size() != 1) {
        QMessageBox::warning(
            this,
            "警告",
            "<span style='color: black;'>请勾选一条记录配置报文格式</span>"
            );
        return;
    }

    // 获取协议ID和名称
    int row = selectedRows.first();
    QTableWidgetItem* protocolItem = ui->tableProtocols->item(row, 1);
    if (!protocolItem) {
        QMessageBox::critical(this, "错误", "获取协议信息失败");
        return;
    }

    bool ok = false;
    int protocolId = protocolItem->data(Qt::UserRole).toInt(&ok);
    if (!ok || protocolId <= 0) {
        QMessageBox::critical(this, "错误", "无效的协议ID");
        return;
    }

    QString protocolName = protocolItem->text();
    if (protocolName.isEmpty()) {
        QMessageBox::critical(this, "错误", "协议名称为空");
        return;
    }

    // 获取现有报文格式
    QVector<MessageFormat> formats;
    try {
        formats = getMessageFormats(protocolId);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "错误", QString("获取报文格式失败: %1").arg(e.what()));
        return;
    }

    // 创建并显示配置对话框
    MessageFormatDialog dialog(this, protocolName, formats);
    if (dialog.exec() == QDialog::Accepted) {
        // 获取新格式并保存
        QVector<MessageFormat> newFormats = dialog.getMessageFormats();

        // 验证数据
        if (newFormats.isEmpty()) {
            QMessageBox::warning(this, "警告", "报文格式不能为空");
            return;
        }

        // 保存到数据库
        bool saveSuccess = false;
        QString errorMsg;
        try {
            saveSuccess = saveMessageFormats(protocolId, newFormats);
            if (!saveSuccess) {
                errorMsg = DBUtil::instance()->lastError();
            }
        } catch (const std::exception& e) {
            errorMsg = e.what();
            saveSuccess = false;
        }

        // 处理保存结果
        if (saveSuccess) {
            emit statusMessageRequested("保存报文格式成功", 3000);

            // 可选：刷新界面显示
            // updateMessageFormatTable(protocolId);
        } else {
            emit statusMessageRequested(
                QString("保存报文格式失败: %1").arg(errorMsg),
                5000
                );
        }
    }
}

void ProtocolManageWindow::onSearch()
{
    QString keyword = ui->lineSearch->text().trimmed();
    if (keyword.isEmpty()) {
        updateProtocolTable();
        return;
    }

    QVector<QStringList> results = searchProtocols(keyword);
    updateTableWithResults(results);
    emit statusMessageRequested(QString("搜索到 %1 条匹配记录").arg(results.size()), 3000);
}

void ProtocolManageWindow::onProtocolSelected(int row)
{
    if (row < 0 || row >= ui->tableProtocols->rowCount()) return;

    int protocolId = ui->tableProtocols->item(row, 1)->data(Qt::UserRole).toInt();
    currentProtocolId = protocolId;
}

void ProtocolManageWindow::onPageChanged(int index)
{
    currentPage = index + 1;
    updateProtocolTable();
    ui->comboPage->setCurrentText(QString("第%1页").arg(currentPage));
}

void ProtocolManageWindow::onPageSizeChanged(int index)
{
    static const int pageSizes[] = {10, 20, 50, 100};
    pageSize = pageSizes[index];
    currentPage = 1;
    updateProtocolTable();
}

void ProtocolManageWindow::gotoFirstPage()
{
    currentPage = 1;
    updateProtocolTable();
}

void ProtocolManageWindow::gotoPrevPage()
{
    if (currentPage > 1) {
        currentPage--;
        updateProtocolTable();
    }
}

void ProtocolManageWindow::gotoNextPage()
{
    if (currentPage < totalPages) {
        currentPage++;
        updateProtocolTable();
    }
}

void ProtocolManageWindow::gotoLastPage()
{
    currentPage = totalPages;
    updateProtocolTable();
}
