#include "InstructionManageWindow.h"
#include "ui_InstructionManageWindow.h"
#include "InstructionDialog.h"
#include "DBUtil.h"

#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <algorithm>

// 复选框委托类实现（与UnitManageWindow相同）
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

InstructionManageWindow::InstructionManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionManageWindow),
    currentPage(1),
    pageSize(10),
    totalPages(1)
{
    ui->setupUi(this);
    initUI();
    initProtocolFilter();
    initPagination();
    setupConnections();

    if (!DBUtil::instance()->isInitialized()) {
        QMessageBox::critical(this, "错误", "数据库未初始化，无法加载数据");
        return;
    }

    updateTable();
}

InstructionManageWindow::~InstructionManageWindow()
{
    delete ui;
}

void InstructionManageWindow::initUI()
{
    QStringList headers;
    headers << "" << "指令名称" << "所属协议" << "指令编码" << "指令类型" << "更新时间";
    ui->tableInstructions->setColumnCount(headers.size());
    ui->tableInstructions->setHorizontalHeaderLabels(headers);

    auto header = ui->tableInstructions->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableInstructions->setColumnWidth(0, 40);
    header->setDefaultAlignment(Qt::AlignCenter);

    ui->tableInstructions->setAlternatingRowColors(true);
    ui->tableInstructions->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableInstructions->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableInstructions->verticalHeader()->setVisible(false);
    ui->tableInstructions->setShowGrid(false);
    ui->tableInstructions->setSortingEnabled(true);
    ui->tableInstructions->setItemDelegateForColumn(0, new CheckBoxDelegate(this));
}

void InstructionManageWindow::initProtocolFilter()
{
    protocolMap = getProtocolMap();
    ui->comboProtocolFilter->clear();
    ui->comboProtocolFilter->addItem("所有协议", -1);

    for (auto it = protocolMap.begin(); it != protocolMap.end(); ++it) {
        ui->comboProtocolFilter->addItem(it.value(), it.key());
    }
}

void InstructionManageWindow::initPagination()
{
    ui->comboPageSize->setCurrentIndex(0);
    ui->comboPage->clear();
    ui->comboPage->addItem("第1页");
}

void InstructionManageWindow::setupConnections()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &InstructionManageWindow::onAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &InstructionManageWindow::onEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &InstructionManageWindow::onDelete);
    connect(ui->btnSearch, &QPushButton::clicked, this, &InstructionManageWindow::onSearch);
    connect(ui->comboProtocolFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &InstructionManageWindow::onProtocolFilterChanged);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &InstructionManageWindow::onPageChanged);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &InstructionManageWindow::onPageSizeChanged);
    connect(ui->btnFirst, &QPushButton::clicked, this, &InstructionManageWindow::gotoFirstPage);
    connect(ui->btnPrev, &QPushButton::clicked, this, &InstructionManageWindow::gotoPrevPage);
    connect(ui->btnNext, &QPushButton::clicked, this, &InstructionManageWindow::gotoNextPage);
    connect(ui->btnLast, &QPushButton::clicked, this, &InstructionManageWindow::gotoLastPage);
}

QMap<int, QString> InstructionManageWindow::getProtocolMap()
{
    QMap<int, QString> map;
    QString sql = "SELECT protocol_id, protocol_name FROM protocol WHERE is_delete = 0";
    auto results = DBUtil::instance()->query(sql);

    for (const auto& row : results) {
        map.insert(row["protocol_id"].toInt(), row["protocol_name"].toString());
    }

    return map;
}

QVector<QStringList> InstructionManageWindow::getAllInstructions()
{
    QString sql = "SELECT i.instruction_id, i.instruction_name, p.protocol_name, "
                  "i.instruction_code, i.instruction_type, i.update_time "
                  "FROM instruction i "
                  "LEFT JOIN protocol p ON i.protocol_id = p.protocol_id "
                  "WHERE i.is_delete = 0 "
                  "ORDER BY i.update_time DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QStringList> instructions;

    for (const auto& row : results) {
        QStringList instruction;
        instruction << row["instruction_id"].toString()
                    << row["instruction_name"].toString()
                    << row["protocol_name"].toString()
                    << row["instruction_code"].toString()
                    << row["instruction_type"].toString()
                    << row["update_time"].toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        instructions.append(instruction);
    }

    return instructions;
}

QVector<QStringList> InstructionManageWindow::getInstructionsByProtocol(int protocolId)
{
    QString sql = "SELECT i.instruction_id, i.instruction_name, p.protocol_name, "
                  "i.instruction_code, i.instruction_type, i.update_time "
                  "FROM instruction i "
                  "LEFT JOIN protocol p ON i.protocol_id = p.protocol_id "
                  "WHERE i.is_delete = 0 AND i.protocol_id = :protocolId "
                  "ORDER BY i.update_time DESC";

    QVariantMap params;
    params["protocolId"] = protocolId;

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> instructions;

    for (const auto& row : results) {
        QStringList instruction;
        instruction << row["instruction_id"].toString()
                    << row["instruction_name"].toString()
                    << row["protocol_name"].toString()
                    << row["instruction_code"].toString()
                    << row["instruction_type"].toString()
                    << row["update_time"].toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        instructions.append(instruction);
    }

    return instructions;
}

bool InstructionManageWindow::addInstruction(const QStringList &instructionData)
{
    if (instructionData.size() < 5) {
        qDebug() << "数据不完整，无法新增指令";
        return false;
    }

    QString sql = R"(
        INSERT INTO instruction
        (instruction_name, protocol_id, instruction_code,
         content, instruction_type, is_delete, create_time, update_time)
        VALUES (:name, :protocolId, :code, :content, :type, 0, NOW(), NOW())
    )";

    QVariantMap params;
    params["name"] = instructionData[0];
    params["protocolId"] = instructionData[1].toInt();
    params["code"] = instructionData[2];
    params["content"] = instructionData[3];
    params["type"] = instructionData[4];

    qDebug() << "执行新增指令SQL:" << sql;
    qDebug() << "参数:" << params;

    bool success = DBUtil::instance()->execute(sql, params) > 0;

    if(!success) {
        qDebug() << "新增指令失败:" << DBUtil::instance()->lastError();
    }
    return success;
}

bool InstructionManageWindow::updateInstruction(int instructionId, const QStringList &instructionData)
{
    if (instructionData.size() < 5) {
        qDebug() << "数据不完整，无法更新指令";
        return false;
    }

    QString sql = R"(
        UPDATE instruction SET
            instruction_name = :name,
            protocol_id = :protocolId,
            instruction_code = :code,
            content = :content,
            instruction_type = :type,
            update_time = NOW()
        WHERE instruction_id = :id
    )";

    QVariantMap params;
    params["id"] = instructionId;
    params["name"] = instructionData[0];
    params["protocolId"] = instructionData[1].toInt();
    params["code"] = instructionData[2];
    params["content"] = instructionData[3];
    params["type"] = instructionData[4];

    qDebug() << "执行更新指令SQL:" << sql;
    qDebug() << "参数:" << params;

    bool success = DBUtil::instance()->execute(sql, params) > 0;

    if(!success) {
        qDebug() << "更新指令失败:" << DBUtil::instance()->lastError();
    }
    return success;
}

bool InstructionManageWindow::deleteInstructions(const QList<int> &instructionIds)
{
    if (instructionIds.isEmpty()) return false;

    QString idList;
    for (int id : instructionIds) {
        if (!idList.isEmpty()) idList += ",";
        idList += QString::number(id);
    }

    QString sql = QString("UPDATE instruction SET is_delete = 1 WHERE instruction_id IN (%1)").arg(idList);
    return DBUtil::instance()->execute(sql) > 0;
}

QVector<QStringList> InstructionManageWindow::searchInstructions(const QString &keyword)
{
    QString sql = "SELECT i.instruction_id, i.instruction_name, p.protocol_name, "
                  "i.instruction_code, i.instruction_type, i.update_time "
                  "FROM instruction i "
                  "LEFT JOIN protocol p ON i.protocol_id = p.protocol_id "
                  "WHERE i.is_delete = 0 AND "
                  "(i.instruction_name LIKE :keyword OR "
                  "i.instruction_code LIKE :keyword OR "
                  "p.protocol_name LIKE :keyword) "
                  "ORDER BY i.update_time DESC";

    QVariantMap params;
    params["keyword"] = QString("%%1%").arg(keyword);

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> instructions;

    for (const auto& row : results) {
        QStringList instruction;
        instruction << row["instruction_id"].toString()
                    << row["instruction_name"].toString()
                    << row["protocol_name"].toString()
                    << row["instruction_code"].toString()
                    << row["instruction_type"].toString()
                    << row["update_time"].toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        instructions.append(instruction);
    }

    return instructions;
}

bool InstructionManageWindow::validateInstructionContent(const QString &content, int protocolId)
{
    // 这里应该实现验证指令内容是否符合协议定义的规范
    // 可能需要查询协议表获取协议定义，然后验证JSON内容
    // 这是一个简化版本，实际实现需要根据业务需求

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(content.toUtf8(), &error);

    if (error.error != QJsonParseError::NoError) {
        return false;
    }

    if (!doc.isObject()) {
        return false;
    }

    // 这里可以添加更多针对特定协议的验证逻辑
    return true;
}

void InstructionManageWindow::updatePagination()
{
    QVector<QStringList> instructions = getAllInstructions();
    int totalItems = instructions.size();
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

void InstructionManageWindow::updateTable()
{
    ui->tableInstructions->blockSignals(true);
    ui->tableInstructions->clearContents();
    ui->tableInstructions->setRowCount(0);
    ui->tableInstructions->blockSignals(false);

    QVector<QStringList> instructions;
    int protocolId = ui->comboProtocolFilter->currentData().toInt();

    if (protocolId == -1) {
        instructions = getAllInstructions();
    } else {
        instructions = getInstructionsByProtocol(protocolId);
    }

    ui->tableInstructions->setRowCount(instructions.size());

    for (int i = 0; i < instructions.size(); ++i) {
        const QStringList &instruction = instructions[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableInstructions->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(instruction[1]);
        nameItem->setData(Qt::UserRole, instruction[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 1, nameItem);

        QTableWidgetItem *protocolItem = new QTableWidgetItem(instruction[2]);
        protocolItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 2, protocolItem);

        QTableWidgetItem *codeItem = new QTableWidgetItem(instruction[3]);
        codeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 3, codeItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(instruction[4]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 4, typeItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(instruction[5]);
        timeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 5, timeItem);
    }

    updatePagination();
    emit statusMessageRequested(QString("共 %1 条记录").arg(instructions.size()));
    qApp->processEvents();
}

void InstructionManageWindow::updateTableWithResults(const QVector<QStringList> &results)
{
    ui->tableInstructions->clearContents();
    ui->tableInstructions->setRowCount(results.size());

    for (int i = 0; i < results.size(); ++i) {
        const QStringList &instruction = results[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableInstructions->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(instruction[1]);
        nameItem->setData(Qt::UserRole, instruction[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 1, nameItem);

        QTableWidgetItem *protocolItem = new QTableWidgetItem(instruction[2]);
        protocolItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 2, protocolItem);

        QTableWidgetItem *codeItem = new QTableWidgetItem(instruction[3]);
        codeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 3, codeItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(instruction[4]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 4, typeItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(instruction[5]);
        timeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableInstructions->setItem(i, 5, timeItem);
    }

    updatePagination();
}

QList<int> InstructionManageWindow::getSelectedRows() const
{
    QList<int> selectedRows;
    for(int i = 0; i < ui->tableInstructions->rowCount(); ++i) {
        if(ui->tableInstructions->item(i, 0)->checkState() == Qt::Checked) {
            selectedRows.append(i);
        }
    }
    return selectedRows;
}

void InstructionManageWindow::onAdd()
{
    InstructionDialog dialog(this, InstructionDialog::NewInstruction, protocolMap);
    if (dialog.exec() == QDialog::Accepted) {
        auto instructionData = dialog.getInstructionData();

        if (instructionData.isValid()) {
            DBUtil::instance()->beginTransaction();

            if (addInstruction(instructionData.toStringList())) {
                DBUtil::instance()->commitTransaction();

                // 强制重新加载数据
                refreshData();

                // 滚动到新增的行
                scrollToNewestRow();

                emit statusMessageRequested("新增指令成功", 3000);
            } else {
                DBUtil::instance()->rollbackTransaction();
                emit statusMessageRequested("新增失败: " + DBUtil::instance()->lastError(), 5000);
            }
        }
    }
}

void InstructionManageWindow::refreshData()
{
    // 重置分页到第一页
    currentPage = 1;
    updateTable();

    qDebug() << "数据已强制刷新";
}

void InstructionManageWindow::scrollToNewestRow()
{
    if (ui->tableInstructions->rowCount() > 0) {
        // 滚动到最后一行
        ui->tableInstructions->scrollToBottom();

        // 选中新增的行
        int newRow = ui->tableInstructions->rowCount() - 1;
        ui->tableInstructions->selectRow(newRow);

        qDebug() << "已滚动到新增行:" << newRow;
    }
}

void InstructionManageWindow::onEdit()
{
    QList<int> selectedRows = getSelectedRows();
    if (selectedRows.size() != 1) {
        QMessageBox::warning(this, "警告", "请选择一条要编辑的指令");
        return;
    }

    int row = selectedRows.first();
    int instructionId = ui->tableInstructions->item(row, 1)->data(Qt::UserRole).toInt();

    // 从数据库获取完整指令数据
    QString sql = "SELECT * FROM instruction WHERE instruction_id = :id";
    QVariantMap params;
    params["id"] = instructionId;
    auto result = DBUtil::instance()->query(sql, params).first();

    InstructionDialog::InstructionData currentData;
    currentData.name = result["instruction_name"].toString();
    currentData.protocolId = result["protocol_id"].toInt();
    currentData.protocolName = protocolMap.value(currentData.protocolId, "未知协议");
    currentData.code = result["instruction_code"].toString();
    currentData.content = result["content"].toString();
    currentData.type = result["instruction_type"].toString();

    InstructionDialog dialog(this, InstructionDialog::EditInstruction, protocolMap, currentData);
    if (dialog.exec() == QDialog::Accepted) {
        auto instructionData = dialog.getInstructionData();

        if (updateInstruction(instructionId, instructionData.toStringList())) {
            updateTable();
            emit statusMessageRequested("指令更新成功", 3000);
        } else {
            QString error = DBUtil::instance()->lastError();
            qDebug() << "更新指令失败:" << error;
            emit statusMessageRequested("更新指令失败: " + error, 5000);
        }
    }
}

void InstructionManageWindow::onDelete()
{
    QList<int> selectedRows = getSelectedRows();
    if(selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "<span style='color: black;'>请勾选要删除的记录</span>");
        return;
    }

    if(QMessageBox::question(this, "确认删除",
                              QString("确定要删除选中的 %1 条指令吗？").arg(selectedRows.size()),
                              QMessageBox::Yes|QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    QList<int> instructionIds;
    for (int row : selectedRows) {
        int instructionId = ui->tableInstructions->item(row, 1)->data(Qt::UserRole).toInt();
        instructionIds.append(instructionId);
    }

    if (deleteInstructions(instructionIds)) {
        updateTable();
        emit statusMessageRequested(QString("已删除 %1 条指令").arg(selectedRows.size()), 3000);
    } else {
        emit statusMessageRequested("删除失败: " + DBUtil::instance()->lastError(), 5000);
    }
}

void InstructionManageWindow::onSearch()
{
    QString keyword = ui->lineSearch->text().trimmed();
    if (keyword.isEmpty()) {
        updateTable();
        return;
    }

    QVector<QStringList> results = searchInstructions(keyword);
    updateTableWithResults(results);
    emit statusMessageRequested(QString("搜索到 %1 条匹配记录").arg(results.size()), 3000);
}

void InstructionManageWindow::onProtocolFilterChanged(int index)
{
    Q_UNUSED(index);
    currentPage = 1;
    updateTable();
}

void InstructionManageWindow::onPageChanged(int index)
{
    currentPage = index + 1;
    updateTable();
    ui->comboPage->setCurrentText(QString("第%1页").arg(currentPage));
}

void InstructionManageWindow::onPageSizeChanged(int index)
{
    static const int pageSizes[] = {10, 20, 50, 100};
    pageSize = pageSizes[index];
    currentPage = 1;
    updateTable();
}

void InstructionManageWindow::gotoFirstPage()
{
    currentPage = 1;
    updateTable();
}

void InstructionManageWindow::gotoPrevPage()
{
    if (currentPage > 1) {
        currentPage--;
        updateTable();
    }
}

void InstructionManageWindow::gotoNextPage()
{
    if (currentPage < totalPages) {
        currentPage++;
        updateTable();
    }
}

void InstructionManageWindow::gotoLastPage()
{
    currentPage = totalPages;
    updateTable();
}
