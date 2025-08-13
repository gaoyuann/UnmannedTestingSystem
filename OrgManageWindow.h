#ifndef ORGMANAGEWINDOW_H
#define ORGMANAGEWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QVariantMap>

namespace Ui {
class OrgManageWindow;
}

class OrgManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OrgManageWindow(QWidget *parent = nullptr);
    ~OrgManageWindow();

signals:
    // 返回系统管理窗口信号
    void backToSystemManage();
    // 状态消息信号
    void statusMessageRequested(const QString &message, int timeout = 3000);

private slots:
    // 按钮点击事件
    void onBtnBackClicked();
    void onBtnAddClicked();
    void onBtnEditClicked();
    void onBtnDeleteClicked();
    void onBtnSearchClicked();

    // 分页相关
    void onBtnFirstClicked();
    void onBtnPrevClicked();
    void onBtnNextClicked();
    void onBtnLastClicked();
    void onComboPageSizeChanged(int index);
    void onComboPageChanged(int index);

private:
    Ui::OrgManageWindow *ui;

    // 分页参数
    int m_currentPage;
    int m_totalPages;
    int m_pageSize;
    int m_totalCount;

    // 初始化UI
    void initUI();
    // 初始化信号槽连接
    void setupConnections();
    // 加载组织数据
    void loadOrgData(const QString &keyword = "");
    // 刷新表格数据
    void refreshTable(const QVector<QVariantMap> &orgs);
    // 更新分页信息
    void updatePaginationInfo();
    // 获取当前页数据
    QVector<QVariantMap> getCurrentPageData(const QVector<QVariantMap> &allData);
    // 验证选中行
    bool validateSelectedRow();
    // 获取选中的组织ID
    int getSelectedOrgId();
};

#endif // ORGMANAGEWINDOW_H
