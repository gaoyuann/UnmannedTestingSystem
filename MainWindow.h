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
class InstructionManageWindow;
class TestManageWindow;
class TestResultsAnalysisWindow;  // 新增分析窗口前置声明

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
    void onBtnCommandsClicked();
    void onbtnTestsclicked();
    void onBtnAnalysisClicked();
    void onBtnSystemClicked();
    void onBtnLogoutClicked();

private:
    void setupConnections();
    void setActiveButton(QPushButton *btn);
    void resetAllButtons();

    Ui::MainWindow *ui;
    UnitManageWindow *unitManageWindow;
    ControlStationManageWindow *stationManageWindow;
    ProtocolManageWindow *protocolManageWindow;
    InstructionManageWindow *instructionManageWindow;
    TestManageWindow *testManageWindow;
    TestResultsAnalysisWindow *testResultsAnalysisWindow;  // 新增分析窗口指针
};

#endif // MAINWINDOW_H
