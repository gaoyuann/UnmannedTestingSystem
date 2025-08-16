#include "DataDicWindow.h"
#include "ui_DataDicWindow.h"
#include "DataDicDialog.h"
#include "DBUtil.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <algorithm>


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

DataDicWindow::DataDicWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataDicWindow),
    currentPage(1),
    pageSize(10),
    totalPages(1),
    checkBoxDelegate(nullptr)
{
    ui->setupUi(this);
    initUI();
    initPagination();
    setupConnections();

    this->hide();

    if (!DBUtil::instance()->isInitialized()) {
        QMessageBox::critical(this, "错误", "数据库未初始化，无法加载数据");
        this->show();
        return;
    }
    updateTable();
    this->show();
}

DataDicWindow::~DataDicWindow()
{
    delete ui;
    delete checkBoxDelegate;
}

void DataDicWindow::initUI()
{
    ui->tableDicts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableDicts->setColumnWidth(0, 40);
    ui->tableDicts->verticalHeader()->setVisible(false);
    ui->tableDicts->setShowGrid(false);

    checkBoxDelegate = new CheckBoxDelegate(this);
    ui->tableDicts->setItemDelegateForColumn(0, checkBoxDelegate);
}

void DataDicWindow::initPagination()
{
    ui->comboPageSize->setCurrentIndex(0);
    ui->comboPage->clear();
    ui->comboPage->addItem("第1页");
}

void DataDicWindow::setupConnections()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &DataDicWindow::onBtnAddClicked);
    connect(ui->btnEdit, &QPushButton::clicked, this, &DataDicWindow::onBtnEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &DataDicWindow::onBtnDeleteClicked);
    connect(ui->btnSearch, &QPushButton::clicked, this, &DataDicWindow::onBtnSearchClicked);
    connect(ui->btnBack, &QPushButton::clicked, this, &DataDicWindow::onBtnBackClicked);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &DataDicWindow::onPageChanged);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &DataDicWindow::onPageSizeChanged);
    connect(ui->btnFirst, &QPushButton::clicked, this, &DataDicWindow::gotoFirstPage);
    connect(ui->btnPrev, &QPushButton::clicked, this, &DataDicWindow::gotoPrevPage);
    connect(ui->btnNext, &QPushButton::clicked, this, &DataDicWindow::gotoNextPage);
    connect(ui->btnLast, &QPushButton::clicked, this, &DataDicWindow::gotoLastPage);
}


void DataDicWindow::updateTable()
{
    ui->tableDicts->clearContents();
    ui->tableDicts->setRowCount(0);

    QVector<QStringList> dicts = getAllDicts();
    updateTableWithResults(dicts);
    updatePagination();
}

void DataDicWindow::updateTableWithResults(const QVector<QStringList> &results)
{
    ui->tableDicts->setRowCount(results.size());

    // 当没有数据时显示空状态
    if (results.isEmpty()) {
        // 可以添加一行提示信息
        ui->tableDicts->setRowCount(1);
        QTableWidgetItem *item = new QTableWidgetItem("没有找到匹配的数据");
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableDicts->setItem(0, 1, item);
        ui->tableDicts->setSpan(0, 1, 1, 5); // 合并单元格
        return;
    }

    for (int i = 0; i < results.size(); ++i) {
        const QStringList &dict = results[i];

        QTableWidgetItem *checkItem = new QTableWidgetItem();
        checkItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        checkItem->setCheckState(Qt::Unchecked);
        ui->tableDicts->setItem(i, 0, checkItem);

        for (int j = 0; j < 5; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(dict[j]);
            item->setTextAlignment(Qt::AlignCenter);
            if (j == 0) { // ID列存储原始数据
                item->setData(Qt::UserRole, dict[j].toInt());
            }
            ui->tableDicts->setItem(i, j+1, item);
        }
    }
}

void DataDicWindow::updatePagination()
{
    int totalItems = getAllDicts().size();
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

    ui->labelPageInfo->setText(QString("第 %1 页 / 共 %2 页 (%3 条)")
                                   .arg(currentPage).arg(totalPages).arg(totalItems));

    ui->btnFirst->setEnabled(currentPage > 1);
    ui->btnPrev->setEnabled(currentPage > 1);
    ui->btnNext->setEnabled(currentPage < totalPages);
    ui->btnLast->setEnabled(currentPage < totalPages);
}

QList<int> DataDicWindow::getSelectedRows() const
{
    QList<int> selectedRows;
    for (int i = 0; i < ui->tableDicts->rowCount(); ++i) {
        if (ui->tableDicts->item(i, 0)->checkState() == Qt::Checked) {
            selectedRows.append(i);
        }
    }
    return selectedRows;
}

// 数据库操作
QVector<QStringList> DataDicWindow::getAllDicts()
{
    QString sql = "SELECT dict_id, dict_type, dict_key, dict_value, sort "
                  "FROM data_dictionary "
                  "ORDER BY dict_type, sort";

    auto results = DBUtil::instance()->query(sql);
    QVector<QStringList> dicts;

    for (const auto& row : results) {
        QStringList dict;
        dict << row["dict_id"].toString()
             << row["dict_type"].toString()
             << row["dict_key"].toString()
             << row["dict_value"].toString()
             << row["sort"].toString();
        dicts.append(dict);
    }
    return dicts;
}

bool DataDicWindow::addDict(const QStringList &dictData)
{
    if (dictData.size() < 4) return false;

    QString sql = "INSERT INTO data_dictionary "
                  "(dict_type, dict_key, dict_value, sort) "
                  "VALUES (:type, :key, :value, :sort)";

    QVariantMap params;
    params["type"] = dictData[0];
    params["key"] = dictData[1];
    params["value"] = dictData[2];
    params["sort"] = dictData[3].toInt();

    return DBUtil::instance()->execute(sql, params) > 0;
}

bool DataDicWindow::updateDict(int dictId, const QStringList &dictData)
{
    if (dictData.size() < 4) return false;

    QString sql = "UPDATE data_dictionary SET "
                  "dict_type = :type, "
                  "dict_key = :key, "
                  "dict_value = :value, "
                  "sort = :sort "
                  "WHERE dict_id = :id";

    QVariantMap params;
    params["id"] = dictId;
    params["type"] = dictData[0];
    params["key"] = dictData[1];
    params["value"] = dictData[2];
    params["sort"] = dictData[3].toInt();

    return DBUtil::instance()->execute(sql, params) > 0;
}

bool DataDicWindow::deleteDicts(const QList<int> &dictIds)
{
    if (dictIds.isEmpty()) return false;

    QString idList;
    for (int id : dictIds) {
        idList += (idList.isEmpty() ? "" : ",") + QString::number(id);
    }

    QString sql = QString("DELETE FROM data_dictionary WHERE dict_id IN (%1)").arg(idList);
    return DBUtil::instance()->execute(sql) > 0;
}

QVector<QStringList> DataDicWindow::searchDicts(const QString &keyword)
{
    QString sql = "SELECT dict_id, dict_type, dict_key, dict_value, sort "
                  "FROM data_dictionary "
                  "WHERE dict_type LIKE :keyword OR "
                  "dict_key LIKE :keyword OR "
                  "dict_value LIKE :keyword "
                  "ORDER BY dict_type, sort";

    QVariantMap params;
    params["keyword"] = QString("%%1%").arg(keyword);

    auto results = DBUtil::instance()->query(sql, params);
    QVector<QStringList> dicts;

    for (const auto& row : results) {
        QStringList dict;
        dict << row["dict_id"].toString()
             << row["dict_type"].toString()
             << row["dict_key"].toString()
             << row["dict_value"].toString()
             << row["sort"].toString();
        dicts.append(dict);
    }
    return dicts;
}

// 槽函数实现
void DataDicWindow::onBtnAddClicked()
{
    DataDicDialog dialog(this, DataDicDialog::NewDict);
    if (dialog.exec() == QDialog::Accepted) {
        auto dictData = dialog.getDictData();
        if (dictData.isValid()) {
            if (addDict(dictData.toStringList())) {
                updateTable();
                emit statusMessageRequested("新增字典成功");
            } else {
                emit statusMessageRequested("新增字典失败: " + DBUtil::instance()->lastError());
            }
        }
    }
}

void DataDicWindow::onBtnEditClicked()
{
    QList<int> selectedRows = getSelectedRows();
    if (selectedRows.size() != 1) {
        QMessageBox::warning(this, "警告", "请勾选一条记录进行编辑");
        return;
    }

    int row = selectedRows.first();
    int dictId = ui->tableDicts->item(row, 1)->data(Qt::UserRole).toInt();

    DataDicDialog::DictData currentData;
    currentData.type = ui->tableDicts->item(row, 2)->text();
    currentData.key = ui->tableDicts->item(row, 3)->text();
    currentData.value = ui->tableDicts->item(row, 4)->text();
    currentData.sort = ui->tableDicts->item(row, 5)->text().toInt();

    DataDicDialog dialog(this, DataDicDialog::EditDict, currentData);
    if (dialog.exec() == QDialog::Accepted) {
        auto dictData = dialog.getDictData();
        if (updateDict(dictId, dictData.toStringList())) {
            updateTable();
            emit statusMessageRequested("编辑字典成功");
        } else {
            emit statusMessageRequested("编辑字典失败: " + DBUtil::instance()->lastError());
        }
    }
}

void DataDicWindow::onBtnDeleteClicked()
{
    QList<int> selectedRows = getSelectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请勾选要删除的记录");
        return;
    }

    if (QMessageBox::question(this, "确认删除",
                              QString("确定要删除选中的 %1 条记录吗？").arg(selectedRows.size()),
                              QMessageBox::Yes|QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    QList<int> dictIds;
    for (int row : selectedRows) {
        dictIds.append(ui->tableDicts->item(row, 1)->data(Qt::UserRole).toInt());
    }

    if (deleteDicts(dictIds)) {
        updateTable();
        emit statusMessageRequested(QString("已删除 %1 条记录").arg(selectedRows.size()));
    } else {
        emit statusMessageRequested("删除失败: " + DBUtil::instance()->lastError());
    }
}

void DataDicWindow::onBtnSearchClicked()
{
    QString keyword = ui->lineSearch->text().trimmed();
    if (keyword.isEmpty()) {
        updateTable();
        return;
    }

    QVector<QStringList> results = searchDicts(keyword);
    updateTableWithResults(results);
    emit statusMessageRequested(QString("搜索到 %1 条匹配记录").arg(results.size()));
}

void DataDicWindow::onBtnBackClicked()
{
    emit backToSystemManage();
}

void DataDicWindow::onPageChanged(int index)
{
    currentPage = index + 1;
    updateTable();
}

void DataDicWindow::onPageSizeChanged(int index)
{
    static const int pageSizes[] = {10, 20, 50};
    pageSize = pageSizes[index];
    currentPage = 1;
    updateTable();
}

void DataDicWindow::gotoFirstPage()
{
    currentPage = 1;
    updateTable();
}

void DataDicWindow::gotoPrevPage()
{
    if (currentPage > 1) {
        currentPage--;
        updateTable();
    }
}

void DataDicWindow::gotoNextPage()
{
    if (currentPage < totalPages) {
        currentPage++;
        updateTable();
    }
}

void DataDicWindow::gotoLastPage()
{
    currentPage = totalPages;
    updateTable();
}
