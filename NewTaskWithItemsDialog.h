#ifndef NEWTASKWITHITEMSDIALOG_H
#define NEWTASKWITHITEMSDIALOG_H

#include <QDialog>
#include <QVector>
#include <QVariantMap>

namespace Ui {
class NewTaskWithItemsDialog;
}

class NewTaskWithItemsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTaskWithItemsDialog(QWidget *parent = nullptr);
    ~NewTaskWithItemsDialog();

    // 获取任务基本信息（供外部保存到数据库）
    QString getTaskName() const;       // 任务名称
    int getUnitId() const;             // 参试单位ID（外键）
    int getStationId() const;          // 控制站ID（外键）
    int getProtocolId() const;         // 测试协议ID（外键）

    // 获取测试项列表（任务名称+标准要求）
    QVector<QVariantMap> getTestItems() const;

private slots:
    void on_btnAddItem_clicked();      // 新增测试项
    void on_btnRemoveItem_clicked();   // 删除选中测试项
    void on_buttonBox_accepted();      // 确认按钮（替代原btnSave）
    void on_buttonBox_rejected();      // 取消按钮

private:
    Ui::NewTaskWithItemsDialog *ui;

    // 从数据库加载下拉框数据（参试单位、控制站、测试协议）
    void loadComboBoxData();

    // 验证输入合法性
    bool validateInput();

    // 显示错误信息
    void showError(const QString &message);
};

#endif // NEWTASKWITHITEMSDIALOG_H
