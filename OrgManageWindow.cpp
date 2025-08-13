#include "OrgManageWindow.h"
#include "ui_OrgManageWindow.h"
#include "DBUtil.h"
#include <QMessageBox>
#include <QDebug>

OrgManageWindow::OrgManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrgManageWindow),
    m_currentPage(1),
    m_pageSize(10),
    m_totalCount(0),
    m_totalPages(1)
{
    ui->setupUi(this);
    initUI();
    setupConnections();

    qDebug() << "OrgManageWindow initialized, loading data...";
    loadOrgData();
}

OrgManageWindow::~OrgManageWindow()
{
    delete ui;
}

void OrgManageWindow::initUI()
{
    // 设置表格属性
    ui->tableOrgs->horizontalHeader()->setStretchLastSection(true);
    ui->tableOrgs->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置分页默认值
    ui->comboPageSize->setCurrentText("10 条/页");
}

void OrgManageWindow::setupConnections()
{
    // 按钮连接
    connect(ui->btnBack, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnBackClicked);
    connect(ui->btnAdd, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnAddClicked);
    connect(ui->btnEdit, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnDeleteClicked);
    connect(ui->btnSearch, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnSearchClicked);

    // 分页按钮连接
    connect(ui->btnFirst, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnFirstClicked);
    connect(ui->btnPrev, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnPrevClicked);
    connect(ui->btnNext, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnNextClicked);
    connect(ui->btnLast, &QPushButton::clicked,
            this, &OrgManageWindow::onBtnLastClicked);
    connect(ui->comboPageSize, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &OrgManageWindow::onComboPageSizeChanged);
    connect(ui->comboPage, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &OrgManageWindow::onComboPageChanged);
}

void OrgManageWindow::loadOrgData(const QString &keyword)
{
    // 检查数据库连接
    if (!DBUtil::instance()->isInitialized() || !DBUtil::instance()->isConnectionValid()) {
        emit statusMessageRequested("数据库连接失败", 3000);
        return;
    }

    QString sql = "SELECT org_id, org_name, description FROM organization";
    QVariantMap params;

    // 如果有搜索关键词，添加条件
    if (!keyword.isEmpty()) {
        sql += " WHERE org_name LIKE :keyword OR description LIKE :keyword";
        params.insert("keyword", "%" + keyword + "%");
    }

    // 执行查询
    QVector<QVariantMap> orgs = DBUtil::instance()->query(sql, params);

    if (DBUtil::instance()->lastError().isEmpty()) {
        m_totalCount = orgs.size();
        m_totalPages = (m_totalCount + m_pageSize - 1) / m_pageSize;
        m_currentPage = qMin(m_currentPage, m_totalPages);
        m_currentPage = qMax(m_currentPage, 1);

        // 刷新表格
        refreshTable(getCurrentPageData(orgs));
        // 更新分页信息
        updatePaginationInfo();

        emit statusMessageRequested(QString("加载成功，共 %1 条记录").arg(m_totalCount), 2000);
    } else {
        emit statusMessageRequested("加载数据失败: " + DBUtil::instance()->lastError(), 3000);
        qCritical() << "加载组织数据失败: " << DBUtil::instance()->lastError();
    }
}

void OrgManageWindow::refreshTable(const QVector<QVariantMap> &orgs)
{
    // 清空表格
    ui->tableOrgs->setRowCount(0);

    // 添加数据到表格
    for (const auto &org : orgs) {
        int row = ui->tableOrgs->rowCount();
        ui->tableOrgs->insertRow(row);

        // 设置单元格数据
        ui->tableOrgs->setItem(row, 0, new QTableWidgetItem(org["org_id"].toString()));
        ui->tableOrgs->setItem(row, 1, new QTableWidgetItem(org["org_name"].toString()));
        ui->tableOrgs->setItem(row, 2, new QTableWidgetItem(org["description"].toString()));
    }
}

void OrgManageWindow::updatePaginationInfo()
{
    // 更新页码组合框
    ui->comboPage->clear();
    for (int i = 1; i <= m_totalPages; ++i) {
        ui->comboPage->addItem(QString::number(i));
    }
    ui->comboPage->setCurrentIndex(m_currentPage - 1);

    // 更新分页信息标签
    ui->labelPageInfo->setText(QString("第 %1 页 / 共 %2 页 (%3 条)")
                                   .arg(m_currentPage)
                                   .arg(m_totalPages)
                                   .arg(m_totalCount));

    // 控制分页按钮状态
    ui->btnFirst->setEnabled(m_currentPage > 1);
    ui->btnPrev->setEnabled(m_currentPage > 1);
    ui->btnNext->setEnabled(m_currentPage < m_totalPages);
    ui->btnLast->setEnabled(m_currentPage < m_totalPages);
}

QVector<QVariantMap> OrgManageWindow::getCurrentPageData(const QVector<QVariantMap> &allData)
{
    QVector<QVariantMap> pageData;
    int startIndex = (m_currentPage - 1) * m_pageSize;
    int endIndex = qMin(startIndex + m_pageSize, allData.size());

    for (int i = startIndex; i < endIndex; ++i) {
        pageData.append(allData[i]);
    }

    return pageData;
}

bool OrgManageWindow::validateSelectedRow()
{
    QModelIndexList selectedRows = ui->tableOrgs->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先选择一条记录");
        return false;
    }
    return true;
}

int OrgManageWindow::getSelectedOrgId()
{
    QModelIndexList selectedRows = ui->tableOrgs->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        return -1;
    }

    int row = selectedRows.first().row();
    return ui->tableOrgs->item(row, 0)->text().toInt();
}

void OrgManageWindow::onBtnBackClicked()
{
    emit backToSystemManage();
}

void OrgManageWindow::onBtnAddClicked()
{
    // 这里应该弹出添加组织的对话框
    // 为简化，这里只做演示
    emit statusMessageRequested("新增机构功能待实现", 2000);
    QMessageBox::information(this, "提示", "新增机构功能待实现");
}

void OrgManageWindow::onBtnEditClicked()
{
    if (!validateSelectedRow()) {
        return;
    }

    int orgId = getSelectedOrgId();
    if (orgId <= 0) {
        QMessageBox::warning(this, "错误", "获取机构ID失败");
        return;
    }

    // 这里应该弹出编辑组织的对话框
    // 为简化，这里只做演示
    emit statusMessageRequested("编辑机构功能待实现", 2000);
    QMessageBox::information(this, "提示", "编辑机构功能待实现");
}

void OrgManageWindow::onBtnDeleteClicked()
{
    if (!validateSelectedRow()) {
        return;
    }

    int orgId = getSelectedOrgId();
    if (orgId <= 0) {
        QMessageBox::warning(this, "错误", "获取机构ID失败");
        return;
    }

    // 确认删除
    if (QMessageBox::question(this, "确认", "确定要删除选中的机构吗？",
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    // 执行删除操作
    QString sql = "DELETE FROM organization WHERE org_id = :org_id";
    QVariantMap params;
    params.insert("org_id", orgId);

    int affected = DBUtil::instance()->execute(sql, params);
    if (affected > 0) {
        emit statusMessageRequested("删除成功", 2000);
        loadOrgData(ui->lineSearch->text());
    } else {
        emit statusMessageRequested("删除失败: " + DBUtil::instance()->lastError(), 3000);
        QMessageBox::warning(this, "错误", "删除失败: " + DBUtil::instance()->lastError());
    }
}

void OrgManageWindow::onBtnSearchClicked()
{
    m_currentPage = 1; // 搜索时重置到第一页
    loadOrgData(ui->lineSearch->text());
}

void OrgManageWindow::onBtnFirstClicked()
{
    if (m_currentPage != 1) {
        m_currentPage = 1;
        loadOrgData(ui->lineSearch->text());
    }
}

void OrgManageWindow::onBtnPrevClicked()
{
    if (m_currentPage > 1) {
        m_currentPage--;
        loadOrgData(ui->lineSearch->text());
    }
}

void OrgManageWindow::onBtnNextClicked()
{
    if (m_currentPage < m_totalPages) {
        m_currentPage++;
        loadOrgData(ui->lineSearch->text());
    }
}

void OrgManageWindow::onBtnLastClicked()
{
    if (m_currentPage != m_totalPages) {
        m_currentPage = m_totalPages;
        loadOrgData(ui->lineSearch->text());
    }
}

void OrgManageWindow::onComboPageSizeChanged(int index)
{
    Q_UNUSED(index);
    QString text = ui->comboPageSize->currentText();
    m_pageSize = text.split(" ")[0].toInt();
    m_currentPage = 1; // 改变页大小时重置到第一页
    loadOrgData(ui->lineSearch->text());
}

void OrgManageWindow::onComboPageChanged(int index)
{
    int page = index + 1;
    if (page != m_currentPage) {
        m_currentPage = page;
        loadOrgData(ui->lineSearch->text());
    }
}
