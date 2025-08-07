#ifndef UNITMANAGEWINDOW_H
#define UNITMANAGEWINDOW_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class UnitManageWindow;
}

class UnitManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UnitManageWindow(QWidget *parent = nullptr);
    ~UnitManageWindow();

signals:
    void statusMessageRequested(const QString &message, int timeout = 0);

private slots:
    void onAdd();
    void onEdit();
    void onDelete();
    void onSearch();
    void onPageChanged(int index);
    void onPageSizeChanged(int index);
    void gotoFirstPage();
    void gotoPrevPage();
    void gotoNextPage();
    void gotoLastPage();

private:
    void initUI();
    void initPagination();
    void setupConnections();
    void updatePagination();
    void updateTable();
    void updateTableWithResults(const QVector<QStringList> &results);
    QList<int> getSelectedRows() const;

    // 数据库操作方法
    QVector<QStringList> getAllUnits();
    bool addUnit(const QStringList &unitData);
    bool updateUnit(int unitId, const QStringList &unitData);
    bool deleteUnits(const QList<int> &unitIds);
    QVector<QStringList> searchUnits(const QString &keyword);

    Ui::UnitManageWindow *ui;
    int currentPage;
    int pageSize;
    int totalPages;
};

#endif // UNITMANAGEWINDOW_H
