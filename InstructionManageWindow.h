#ifndef INSTRUCTIONMANAGEWINDOW_H
#define INSTRUCTIONMANAGEWINDOW_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class InstructionManageWindow;
}

class InstructionManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionManageWindow(QWidget *parent = nullptr);
    ~InstructionManageWindow();

signals:
    void statusMessageRequested(const QString &message, int timeout = 0);

private slots:
    void onAdd();
    void onEdit();
    void onDelete();
    void onSearch();
    void onProtocolFilterChanged(int index);
    void onPageChanged(int index);
    void onPageSizeChanged(int index);
    void gotoFirstPage();
    void gotoPrevPage();
    void gotoNextPage();
    void gotoLastPage();

private:
    void refreshData();
    void scrollToNewestRow();
    void initUI();
    void initProtocolFilter();
    void initPagination();
    void setupConnections();
    void updatePagination();
    void updateTable();
    void updateTableWithResults(const QVector<QStringList> &results);
    QList<int> getSelectedRows() const;
    bool validateInstructionContent(const QString &content, int protocolId);

    // 数据库操作方法
    QVector<QStringList> getAllInstructions();
    QVector<QStringList> getInstructionsByProtocol(int protocolId);
    bool addInstruction(const QStringList &instructionData);
    bool updateInstruction(int instructionId, const QStringList &instructionData);
    bool deleteInstructions(const QList<int> &instructionIds);
    QVector<QStringList> searchInstructions(const QString &keyword);
    QMap<int, QString> getProtocolMap();

    Ui::InstructionManageWindow *ui;
    int currentPage;
    int pageSize;
    int totalPages;
    QMap<int, QString> protocolMap; // 存储协议ID和名称的映射
};

#endif // INSTRUCTIONMANAGEWINDOW_H
