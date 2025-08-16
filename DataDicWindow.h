#ifndef DATADICWINDOW_H
#define DATADICWINDOW_H

#include <QWidget>
#include <QVector>
#include <QStringList>
#include <QStyledItemDelegate>
#include "DBUtil.h"

class CheckBoxDelegate;
class QTableWidgetItem;

namespace Ui {
class DataDicWindow;
}

class DataDicWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DataDicWindow(QWidget *parent = nullptr);
    ~DataDicWindow();

signals:
    void backToSystemManage();
    void statusMessageRequested(const QString &message, int timeout = 3000);

private slots:
    void onBtnAddClicked();
    void onBtnEditClicked();
    void onBtnDeleteClicked();
    void onBtnSearchClicked();
    void onBtnBackClicked();
    void onPageChanged(int index);
    void onPageSizeChanged(int index);
    void gotoFirstPage();
    void gotoPrevPage();
    void gotoNextPage();
    void gotoLastPage();

private:
    Ui::DataDicWindow *ui;
    CheckBoxDelegate *checkBoxDelegate;
    int currentPage;
    int pageSize;
    int totalPages;

    void initUI();
    void initPagination();
    void setupConnections();
    void updateTable();
    void updateTableWithResults(const QVector<QStringList> &results);
    void updatePagination();
    QList<int> getSelectedRows() const;

    // 数据库操作
    QVector<QStringList> getAllDicts();
    bool addDict(const QStringList &dictData);
    bool updateDict(int dictId, const QStringList &dictData);
    bool deleteDicts(const QList<int> &dictIds);
    QVector<QStringList> searchDicts(const QString &keyword);
};

#endif // DATADICWINDOW_H
