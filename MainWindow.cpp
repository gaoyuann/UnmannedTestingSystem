#include "MainWindow.h"
#include "ui_MainWindow.h"

// 包含具体的窗口头文件
#include "UnitManageWindow.h"
#include "ControlStationManageWindow.h"
#include "ProtocolManageWindow.h"
#include "InstructionManageWindow.h"  // 新增指令管理窗口头文件

#include <QStyle>
#include <QList>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    unitManageWindow(nullptr),
    stationManageWindow(nullptr),
    protocolManageWindow(nullptr),
    instructionManageWindow(nullptr)  // 初始化指令管理窗口指针
{
    ui->setupUi(this);

    // 设置初始状态
    ui->stackedWidget->setCurrentIndex(0);
    resetAllButtons();

    // 设置信号槽连接
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete unitManageWindow;
    delete stationManageWindow;
    delete protocolManageWindow;
    delete instructionManageWindow;  // 安全删除指令管理窗口
}

void MainWindow::setupConnections()
{
    connect(ui->btnUnits, &QPushButton::clicked, this, &MainWindow::onBtnUnitsClicked);
    connect(ui->btnStations, &QPushButton::clicked, this, &MainWindow::onBtnStationsClicked);
    connect(ui->btnProtocols, &QPushButton::clicked, this, &MainWindow::onBtnProtocolsClicked);
    connect(ui->btnCommands, &QPushButton::clicked, this, &MainWindow::onBtnCommandsClicked);
    connect(ui->btnTests, &QPushButton::clicked, this, &MainWindow::onBtnTestsClicked);
    connect(ui->btnAnalysis, &QPushButton::clicked, this, &MainWindow::onBtnAnalysisClicked);
    connect(ui->btnSystem, &QPushButton::clicked, this, &MainWindow::onBtnSystemClicked);
    connect(ui->btnLogout, &QPushButton::clicked, this, &MainWindow::onBtnLogoutClicked);
}

void MainWindow::setActiveButton(QPushButton *btn)
{
    resetAllButtons();
    btn->setProperty("active", true);
    btn->style()->unpolish(btn);
    btn->style()->polish(btn);
}

void MainWindow::resetAllButtons()
{
    QList<QPushButton*> buttons = ui->sideBar->findChildren<QPushButton*>();
    foreach (QPushButton *btn, buttons) {
        if (btn != ui->btnLogout) {
            btn->setProperty("active", false);
            btn->style()->unpolish(btn);
            btn->style()->polish(btn);
        }
    }
}

void MainWindow::onBtnUnitsClicked()
{
    setActiveButton(ui->btnUnits);
    if (!unitManageWindow) {
        unitManageWindow = new UnitManageWindow(this);
        ui->stackedWidget->addWidget(unitManageWindow);
    }
    ui->stackedWidget->setCurrentWidget(unitManageWindow);
}

void MainWindow::onBtnStationsClicked()
{
    setActiveButton(ui->btnStations);
    if (!stationManageWindow) {
        stationManageWindow = new ControlStationManageWindow(this);
        ui->stackedWidget->addWidget(stationManageWindow);
    }
    ui->stackedWidget->setCurrentWidget(stationManageWindow);
}

void MainWindow::onBtnProtocolsClicked()
{
    setActiveButton(ui->btnProtocols);
    if (!protocolManageWindow) {
        protocolManageWindow = new ProtocolManageWindow(this);
        ui->stackedWidget->addWidget(protocolManageWindow);
    }
    ui->stackedWidget->setCurrentWidget(protocolManageWindow);
}

void MainWindow::onBtnCommandsClicked()
{
    setActiveButton(ui->btnCommands);
    if (!instructionManageWindow) {
        instructionManageWindow = new InstructionManageWindow(this);
        ui->stackedWidget->addWidget(instructionManageWindow);

        // 连接状态消息信号到主窗口状态栏
        connect(instructionManageWindow, &InstructionManageWindow::statusMessageRequested,
                this, [this](const QString &message, int timeout) {
                    ui->statusbar->showMessage(message, timeout);
                });
    }
    ui->stackedWidget->setCurrentWidget(instructionManageWindow);
}

void MainWindow::onBtnTestsClicked()
{
    setActiveButton(ui->btnTests);
    ui->stackedWidget->setCurrentWidget(ui->pageTests);
}

void MainWindow::onBtnAnalysisClicked()
{
    setActiveButton(ui->btnAnalysis);
    ui->stackedWidget->setCurrentWidget(ui->pageAnalysis);
}

void MainWindow::onBtnSystemClicked()
{
    setActiveButton(ui->btnSystem);
    ui->stackedWidget->setCurrentWidget(ui->pageSystem);
}

void MainWindow::onBtnLogoutClicked()
{
    close();
}
