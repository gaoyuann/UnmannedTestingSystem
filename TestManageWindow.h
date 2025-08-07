#ifndef TESTMANAGEWINDOW_H
#define TESTMANAGEWINDOW_H

#include <QWidget>
#include <QSqlQuery>
#include <QVector>
#include <QVariantMap>
#include <QMainWindow>

#include "ui_TestManageWindow.h"
#include "NewTaskWithItemsDialog.h"
#include "TaskDetailWindow.h"
#include "DBUtil.h"

namespace Ui {
class TestManageWindow;
}

class TestManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestManageWindow(QWidget *parent = nullptr);
    ~TestManageWindow();

private slots:
    // 按钮点击事件
    void on_btnAddTask_clicked();
    void on_btnEditTask_clicked();
    void on_btnDeleteTask_clicked();
    void on_btnExecuteTask_clicked();
    void on_btnSearch_clicked();
    void on_btnFirst_clicked();
    void on_btnPrev_clicked();
    void on_btnNext_clicked();
    void on_btnLast_clicked();
    void ondetailButtonclicked();


private:
    Ui::TestManageWindow *ui;

    // 分页参数
    int currentPage;
    int totalPages;
    int totalCount;
    int pageSize;

    // 初始化表格
    void initTable();

    // 加载测试任务数据
    void loadTestTasks();

    // 计算总页数
    void calculateTotalPages();

    // 更新分页信息
    void updatePaginationInfo();

     // 保存任务及项目到数据库
    bool saveNewTaskToDB(const NewTaskWithItemsDialog &dialog);

    // 创建详情按钮
    QPushButton* createDetailButton(const QString& taskId);

    // 获取选中的任务ID
    QString getSelectedTaskId();
};

#endif // TESTMANAGEWINDOW_H
