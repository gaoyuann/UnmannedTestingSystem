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
    QStringList headers;
    headers << "" << "名称" << "地址" << "联系人" << "电话" << "类型";
    ui->tableUnits->setColumnCount(headers.size());
    ui->tableUnits->setHorizontalHeaderLabels(headers);

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
    ui->comboPageSize->setCurrentIndex(0);
    ui->comboPage->clear();
    ui->comboPage->addItem("第1页");
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
                  "NOW(), NOW(), 0)";

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

void UnitManageWindow::updateTable()
{
    ui->tableUnits->blockSignals(true);
    ui->tableUnits->clearContents();
    ui->tableUnits->setRowCount(0);
    ui->tableUnits->blockSignals(false);

    QVector<QStringList> units = getAllUnits();
    ui->tableUnits->setRowCount(units.size());

    for (int i = 0; i < units.size(); ++i) {
        const QStringList &unit = units[i];

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
    emit statusMessageRequested(QString("共 %1 条记录").arg(units.size()));
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

                QVariantMap verify = DBUtil::instance()->query(
                                                           "SELECT unit_id, is_delete FROM participate_unit ORDER BY unit_id DESC LIMIT 1"
                                                           ).first();

                qDebug() << "Newly added unit - ID:" << verify["unit_id"]
                         << "is_delete:" << verify["is_delete"];

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
        QMessageBox::warning(
            this,
            "警告",
            "<span style='color: black;'>请勾选一条记录进行编辑</span>"
            );
        return;
    }

    int row = selectedRows.first();
    int unitId = ui->tableUnits->item(row, 1)->data(Qt::UserRole).toInt();

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
        QMessageBox::warning(this, "警告", "<span style='color: black;'>请勾选要删除的记录</span>");
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
    ui->comboPage->setCurrentText(QString("第%1页").arg(currentPage));
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
