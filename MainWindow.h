#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>

// 前置声明
namespace Ui {
class MainWindow;
}
class UnitManageWindow;
class ControlStationManageWindow;
class ProtocolManageWindow;
class InstructionManageWindow;  // 新增指令管理窗口前置声明
class TestManageWindow;

class UserManageWindow;
class PermissionManageWindow;
class OrgManageWindow;
class DictManageWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBtnUnitsClicked();
    void onBtnStationsClicked();
    void onBtnProtocolsClicked();
    void onBtnCommandsClicked();  // 修改为指令管理功能
    void onbtnTestsclicked();
    void onBtnAnalysisClicked();
    void onBtnLogoutClicked();
    // 系统管理折叠菜单相关槽函数
    void on_btnSystem_clicked();
    void on_btnUserManage_clicked();
    void on_btnPermissionManage_clicked();
    void on_btnOrgManage_clicked();
    void on_btnDictManage_clicked();


private:
    Ui::MainWindow *ui;

    UnitManageWindow *unitManageWindow;          // 参试单位管理窗口
    ControlStationManageWindow *stationManageWindow; // 控制站管理窗口
    ProtocolManageWindow *protocolManageWindow;  // 协议管理窗口
    InstructionManageWindow *instructionManageWindow;  // 新增指令管理窗口指针
    TestManageWindow *testManageWindow;

    UserManageWindow *userManageWindow;        //系统管理子窗口
    PermissionManageWindow *permissionManageWindow;
    OrgManageWindow *orgManageWindow;
    DictManageWindow *dictManageWindow;

    void setupConnections();
    void setActiveButton(QPushButton *btn);
    void resetAllButtons();
    void onButtonClicked();
    void initSystemMenu();

};

#endif // MAINWINDOW_H
