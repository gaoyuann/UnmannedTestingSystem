#include "UnitManageWindow.h"
#include "ui_UnitManageWindow.h"
#include "UnitDialog.h"
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

UnitManageWindow::UnitManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitManageWindow),
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

UnitManageWindow::~UnitManageWindow()
{
    delete ui;
}

void UnitManageWindow::initUI()
{
    QString buttonStyle = R"(
        QPushButton {
            background-color: #3a6ea5;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-size: 13px;
            min-width: 80px;
        }
        QPushButton:hover {
            background-color: #4a90e2;
        }
        QPushButton:pressed {
            background-color: #2a5685;
        }
        QPushButton:disabled {
            background-color: #cccccc;
        }
    )";

    ui->btnAdd->setStyleSheet(buttonStyle);
    ui->btnEdit->setStyleSheet(buttonStyle);
    ui->btnDelete->setStyleSheet(buttonStyle);
    ui->btnSearch->setStyleSheet(buttonStyle);

    ui->lineSearch->setStyleSheet(R"(
        QLineEdit {
            padding: 8px 12px;
            border: 1px solid #d0d0d0;
            border-radius: 4px;
            font-size: 13px;
            min-width: 250px;
            background-color: white;
            color: #333333;
        }
        QLineEdit:focus {
            border: 1px solid #4a90e2;
            box-shadow: 0 0 0 2px rgba(74,144,226,0.2);
        }
    )");

    QStringList headers;
    headers << "" << "名称" << "地址" << "联系人" << "电话" << "类型";
    ui->tableUnits->setColumnCount(headers.size());
    ui->tableUnits->setHorizontalHeaderLabels(headers);

    ui->tableUnits->setStyleSheet(R"(
        QTableWidget {
            gridline-color: #e0e0e0;
            font-size: 13px;
            background-color: white;
            alternate-background-color: #f8f9fa;
            border: 1px solid #e0e0e0;
            border-radius: 4px;
            outline: 0;
        }
        QTableWidget::item {
            padding: 8px;
            border-bottom: 1px solid #f0f0f0;
            color: #333333;
        }
        QTableWidget::item:hover {
            background-color: #f0f7ff;
        }
        QHeaderView::section {
            background-color: #3a6ea5;
            color: white;
            padding: 8px;
            border: none;
            font-weight: 500;
        }
        QHeaderView {
            border-top-left-radius: 4px;
            border-top-right-radius: 4px;
        }
    )");

    auto header = ui->tableUnits->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableUnits->setColumnWidth(0, 40);
    header->setDefaultAlignment(Qt::AlignCenter);

    ui->tableUnits->setAlternatingRowColors(true);
    ui->tableUnits->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableUnits->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableUnits->verticalHeader()->setVisible(false);
    ui->tableUnits->setShowGrid(false);
    ui->tableUnits->setSortingEnabled(true);
    ui->tableUnits->setItemDelegateForColumn(0, new CheckBoxDelegate(this));
}

void UnitManageWindow::initPagination()
{
    QString paginationStyle = R"(
        QPushButton {
            min-width: 60px;
            padding: 4px 8px;
            background-color: #f0f0f0;
            border: 1px solid #d0d0d0;
            border-radius: 3px;
        }
        QPushButton:hover {
            background-color: #e0e0e0;
        }
        QPushButton:pressed {
            background-color: #d0d0d0;
        }
        QComboBox {
            padding: 4px;
            border: 1px solid #d0d0d0;
            border-radius: 3px;
            min-width: 60px;
        }
        QLabel {
            color: #666666;
        }
    )";

    ui->paginationWidget->setStyleSheet(paginationStyle);
    ui->comboPageSize->addItems({"10", "20", "50", "100"});
    ui->comboPageSize->setCurrentIndex(0);
    ui->comboPage->clear();
    ui->comboPage->addItem("1");
}

void UnitManageWindow::setupConnections()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &UnitManageWindow::onAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &UnitManageWindow::onEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &UnitManageWindow::onDelete);
    connect(ui->btnSearch, &QPushButton::clicked, this, &UnitManageWindow::onSearch);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &UnitManageWindow::onPageChanged);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &UnitManageWindow::onPageSizeChanged);
    connect(ui->btnFirst, &QPushButton::clicked, this, &UnitManageWindow::gotoFirstPage);
    connect(ui->btnPrev, &QPushButton::clicked, this, &UnitManageWindow::gotoPrevPage);
    connect(ui->btnNext, &QPushButton::clicked, this, &UnitManageWindow::gotoNextPage);
    connect(ui->btnLast, &QPushButton::clicked, this, &UnitManageWindow::gotoLastPage);
}

QVector<QStringList> UnitManageWindow::getAllUnits()
{
    QString sql = "SELECT unit_id, unit_name, contact_person, contact_phone, "
                  "unit_type, address "
                  "FROM participate_unit WHERE is_delete = 0 "
                  "ORDER BY update_time DESC";

    auto results = DBUtil::instance()->query(sql);
    QVector<QStringList> units;

    for (const auto& row : results) {
        QStringList unit;
        unit << row["unit_id"].toString()
             << row["unit_name"].toString()
             << row["address"].toString()
             << row["contact_person"].toString()
             << row["contact_phone"].toString()
             << row["unit_type"].toString();
        units.append(unit);
    }

    return units;
}

bool UnitManageWindow::addUnit(const QStringList &unitData)
{
    if (unitData.size() < 5) return false;

    QString sql = "INSERT INTO participate_unit "
                  "(unit_name, contact_person, contact_phone, unit_type, address, "
                  "create_time, update_time, is_delete) "
                  "VALUES (:name, :contact, :phone, :type, :address, "
                  "NOW(), NOW(), 0)";  // 明确设置 is_delete = 0

    QVariantMap params;
    params["name"] = unitData[0];
    params["contact"] = unitData[1];
    params["phone"] = unitData[2];
    params["type"] = unitData[3];
    params["address"] = unitData[4];

    int affectedRows = DBUtil::instance()->execute(sql, params);
    qDebug() << "Insert affected rows:" << affectedRows;

    return affectedRows > 0;
}

bool UnitManageWindow::updateUnit(int unitId, const QStringList &unitData)
{
    if (unitData.size() < 5) return false;

    QString sql = "UPDATE participate_unit SET "
                  "unit_name = :name, "
                  "contact_person = :contact, "
                  "contact_phone = :phone, "
                  "unit_type = :type, "
                  "address = :address, "
                  "update_time = NOW() "
                  "WHERE unit_id = :id";

    QVariantMap params;
    params["id"] = unitId;
    params["name"] = unitData[0];
    params["contact"] = unitData[1];
    params["phone"] = unitData[2];
    params["type"] = unitData[3];
    params["address"] = unitData[4];

    return DBUtil::instance()->execute(sql, params) > 0;
}

bool UnitManageWindow::deleteUnits(const QList<int> &unitIds)
{
    if (unitIds.isEmpty()) return false;

    QString idList;
    for (int id : unitIds) {
        if (!idList.isEmpty()) idList += ",";
        idList += QString::number(id);
    }

    QString sql = QString("UPDATE participate_unit SET is_delete = 1 WHERE unit_id IN (%1)").arg(idList);
    return DBUtil::instance()->execute(sql) > 0;
}

QVector<QStringList> UnitManageWindow::searchUnits(const QString &keyword)
{
    QString sql = "SELECT unit_id, unit_name, contact_person, contact_phone, "
                  "unit_type, address "
                  "FROM participate_unit "
                  "WHERE is_delete = 0 AND "
                  "(unit_name LIKE :keyword OR "
                  "contact_person LIKE :keyword OR "
                  "contact_phone LIKE :keyword OR "
                  "address LIKE :keyword) "
                  "ORDER BY update_time DESC";

    QVariantMap params;
    params["keyword"] = QString("%%1%").arg(keyword);

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> units;

    for (const auto& row : results) {
        QStringList unit;
        unit << row["unit_id"].toString()
             << row["unit_name"].toString()
             << row["address"].toString()
             << row["contact_person"].toString()
             << row["contact_phone"].toString()
             << row["unit_type"].toString();
        units.append(unit);
    }

    return units;
}

void UnitManageWindow::updatePagination()
{
    QVector<QStringList> units = getAllUnits();
    int totalItems = units.size();
    totalPages = (totalItems + pageSize - 1) / pageSize;
    if (totalPages == 0) totalPages = 1;

    currentPage = std::clamp(currentPage, 1, totalPages);

    ui->comboPage->blockSignals(true);
    ui->comboPage->clear();
    for (int i = 1; i <= totalPages; ++i) {
        ui->comboPage->addItem(QString::number(i));
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


void UnitManageWindow::updateTable()
{
    // 清空表格前先断开所有信号连接
    ui->tableUnits->blockSignals(true);
    ui->tableUnits->clearContents();
    ui->tableUnits->setRowCount(0);
    ui->tableUnits->blockSignals(false);

    // 获取最新数据
    QVector<QStringList> units = getAllUnits();

    // 设置行数
    ui->tableUnits->setRowCount(units.size());

    for (int i = 0; i < units.size(); ++i) {
        const QStringList &unit = units[i];

        // 复选框列
        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableUnits->setItem(i, 0, checkItem);

        // 名称列（包含ID）
        QTableWidgetItem *nameItem = new QTableWidgetItem(unit[1]);
        nameItem->setData(Qt::UserRole, unit[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 1, nameItem);

        // 地址列
        QTableWidgetItem *addressItem = new QTableWidgetItem(unit[2]);
        addressItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 2, addressItem);

        // 联系人列
        QTableWidgetItem *contactItem = new QTableWidgetItem(unit[3]);
        contactItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 3, contactItem);

        // 电话列
        QTableWidgetItem *phoneItem = new QTableWidgetItem(unit[4]);
        phoneItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 4, phoneItem);

        // 类型列
        QTableWidgetItem *typeItem = new QTableWidgetItem(unit[5]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 5, typeItem);
    }

    // 更新分页信息
    updatePagination();
    emit statusMessageRequested(QString("共 %1 条记录").arg(units.size()));

    // 确保UI刷新
    qApp->processEvents();
}


void UnitManageWindow::updateTableWithResults(const QVector<QStringList> &results)
{
    ui->tableUnits->clearContents();
    ui->tableUnits->setRowCount(results.size());

    for (int i = 0; i < results.size(); ++i) {
        const QStringList &unit = results[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableUnits->setItem(i, 0, checkItem);

        QTableWidgetItem *nameItem = new QTableWidgetItem(unit[1]);
        nameItem->setData(Qt::UserRole, unit[0].toInt());
        nameItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 1, nameItem);

        QTableWidgetItem *addressItem = new QTableWidgetItem(unit[2]);
        addressItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 2, addressItem);

        QTableWidgetItem *contactItem = new QTableWidgetItem(unit[3]);
        contactItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 3, contactItem);

        QTableWidgetItem *phoneItem = new QTableWidgetItem(unit[4]);
        phoneItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 4, phoneItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(unit[5]);
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableUnits->setItem(i, 5, typeItem);
    }

    updatePagination();
}

QList<int> UnitManageWindow::getSelectedRows() const
{
    QList<int> selectedRows;
    for(int i = 0; i < ui->tableUnits->rowCount(); ++i) {
        if(ui->tableUnits->item(i, 0)->checkState() == Qt::Checked) {
            selectedRows.append(i);
        }
    }
    return selectedRows;
}


void UnitManageWindow::onAdd()
{
    UnitDialog dialog(this, UnitDialog::NewUnit);
    if (dialog.exec() == QDialog::Accepted) {
        auto unitData = dialog.getUnitData();
        if (unitData.isValid()) {
            DBUtil::instance()->beginTransaction();

            if (addUnit(unitData.toStringList())) {
                DBUtil::instance()->commitTransaction();

                // 验证插入的数据
                QVariantMap verify = DBUtil::instance()->query(
                                                           "SELECT unit_id, is_delete FROM participate_unit ORDER BY unit_id DESC LIMIT 1"
                                                           ).first();

                qDebug() << "Newly added unit - ID:" << verify["unit_id"]
                         << "is_delete:" << verify["is_delete"];

                // 刷新表格
                updateTable();

                emit statusMessageRequested("新增单位成功", 3000);
            } else {
                DBUtil::instance()->rollbackTransaction();
                emit statusMessageRequested("新增单位失败: " + DBUtil::instance()->lastError(), 5000);
            }
        }
    }
}


void UnitManageWindow::onEdit()
{
    QList<int> selectedRows = getSelectedRows();
    if (selectedRows.size() != 1) {
        QMessageBox::warning(this, "警告", "请勾选一条记录进行编辑");
        return;
    }

    int row = selectedRows.first();
    int unitId = ui->tableUnits->item(row, 1)->data(Qt::UserRole).toInt();

    // 准备当前数据
    UnitDialog::UnitData currentData;
    currentData.name = ui->tableUnits->item(row, 1)->text();
    currentData.address = ui->tableUnits->item(row, 2)->text();
    currentData.contact = ui->tableUnits->item(row, 3)->text();
    currentData.phone = ui->tableUnits->item(row, 4)->text();
    currentData.type = ui->tableUnits->item(row, 5)->text();

    UnitDialog dialog(this, UnitDialog::EditUnit, currentData);
    if (dialog.exec() == QDialog::Accepted) {
        auto unitData = dialog.getUnitData();
        if (updateUnit(unitId, unitData.toStringList())) {
            updateTable();
            emit statusMessageRequested("编辑单位成功", 3000);
        } else {
            emit statusMessageRequested("编辑单位失败: " + DBUtil::instance()->lastError(), 5000);
        }
    }
}




void UnitManageWindow::onDelete()
{
    QList<int> selectedRows = getSelectedRows();
    if(selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请勾选要删除的记录");
        return;
    }

    if(QMessageBox::question(this, "确认删除",
                              QString("确定要删除选中的 %1 条记录吗？").arg(selectedRows.size()),
                              QMessageBox::Yes|QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    QList<int> unitIds;
    for (int row : selectedRows) {
        int unitId = ui->tableUnits->item(row, 1)->data(Qt::UserRole).toInt();
        unitIds.append(unitId);
    }

    if (deleteUnits(unitIds)) {
        updateTable();
        emit statusMessageRequested(QString("已删除 %1 条记录").arg(selectedRows.size()), 3000);
    } else {
        emit statusMessageRequested("删除失败: " + DBUtil::instance()->lastError(), 5000);
    }
}

void UnitManageWindow::onSearch()
{
    QString keyword = ui->lineSearch->text().trimmed();
    if (keyword.isEmpty()) {
        updateTable();
        return;
    }

    QVector<QStringList> results = searchUnits(keyword);
    updateTableWithResults(results);
    emit statusMessageRequested(QString("搜索到 %1 条匹配记录").arg(results.size()), 3000);
}

void UnitManageWindow::onPageChanged(int index)
{
    currentPage = index + 1;
    updateTable();
}

void UnitManageWindow::onPageSizeChanged(int index)
{
    static const int pageSizes[] = {10, 20, 50, 100};
    pageSize = pageSizes[index];
    currentPage = 1;
    updateTable();
}

void UnitManageWindow::gotoFirstPage()
{
    currentPage = 1;
    updateTable();
}

void UnitManageWindow::gotoPrevPage()
{
    if (currentPage > 1) {
        currentPage--;
        updateTable();
    }
}

void UnitManageWindow::gotoNextPage()
{
    if (currentPage < totalPages) {
        currentPage++;
        updateTable();
    }
}

void UnitManageWindow::gotoLastPage()
{
    currentPage = totalPages;
    updateTable();
}
