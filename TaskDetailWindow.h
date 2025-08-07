#ifndef TASKDETAILWINDOW_H
#define TASKDETAILWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class TaskDetailWindow;
}

class TaskDetailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDetailWindow(const QString &taskId, QWidget *parent = nullptr);
    ~TaskDetailWindow();

private slots:
    void on_btnExport_clicked();
    void on_btnClose_clicked();

private:
    Ui::TaskDetailWindow *ui;
    QString m_taskId; // 任务ID

    // 数据加载函数
    void loadAllData();
    void loadBasicInfo();
    void loadTestItems();
    void loadTestReport();

    // 辅助函数
    QString getStatusText(int statusCode);
};

#endif // TASKDETAILWINDOW_H
