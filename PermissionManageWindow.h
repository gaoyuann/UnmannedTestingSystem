#ifndef PERMISSIONMANAGEWINDOW_H
#define PERMISSIONMANAGEWINDOW_H

#include <QWidget>
#include <QVector>
#include <QVariantMap>

namespace Ui {
class PermissionManageWindow;
}

class PermissionManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionManageWindow(QWidget *parent = nullptr);
    ~PermissionManageWindow();

signals:
    void backToSystemManage();
    void statusMessageRequested(const QString &message, int timeout = 3000);

private slots:
    void onBtnBackClicked();
    void onBtnAddClicked();
    void onBtnEditClicked();
    void onBtnDeleteClicked();
    void onBtnSearchClicked();
    void loadPermissionData();

private:
    Ui::PermissionManageWindow *ui;
    void initTable();
    void setupConnections();
    QVector<int> getSelectedIds();
};

#endif // PERMISSIONMANAGEWINDOW_H
