#ifndef CONTROLSTATIONMANAGEWINDOW_H
#define CONTROLSTATIONMANAGEWINDOW_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class ControlStationManageWindow;
}

class ControlStationManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControlStationManageWindow(QWidget *parent = nullptr);
    ~ControlStationManageWindow();

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
    QVector<QStringList> getAllStations();
    bool addStation(const QStringList &stationData);
    bool updateStation(int stationId, const QStringList &stationData);
    bool deleteStations(const QList<int> &stationIds);
    QVector<QStringList> searchStations(const QString &keyword);
    bool refreshStationStatus();

    Ui::ControlStationManageWindow *ui;
    int currentPage;
    int pageSize;
    int totalPages;
};

#endif // CONTROLSTATIONMANAGEWINDOW_H
