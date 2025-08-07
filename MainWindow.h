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
    void onBtnSystemClicked();
    void onBtnLogoutClicked();

private:
    void setupConnections();
    void setActiveButton(QPushButton *btn);
    void resetAllButtons();

    Ui::MainWindow *ui;
    UnitManageWindow *unitManageWindow;          // 参试单位管理窗口
    ControlStationManageWindow *stationManageWindow; // 控制站管理窗口
    ProtocolManageWindow *protocolManageWindow;  // 协议管理窗口
    InstructionManageWindow *instructionManageWindow;  // 新增指令管理窗口指针
    TestManageWindow *testManageWindow;

};

#endif // MAINWINDOW_H
