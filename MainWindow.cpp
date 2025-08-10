#include "MainWindow.h"
#include "ui_MainWindow.h"

// 包含具体的窗口头文件
#include "UnitManageWindow.h"
#include "ControlStationManageWindow.h"
#include "ProtocolManageWindow.h"
#include "InstructionManageWindow.h"  // 新增指令管理窗口头文件
#include "TestManageWindow.h"

#include "UserManageWindow.h"


#include <QStyle>
#include <QList>
#include <QPushButton>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    unitManageWindow(nullptr),
    testManageWindow(nullptr),
    stationManageWindow(nullptr),
    protocolManageWindow(nullptr),
    instructionManageWindow(nullptr),
    userManageWindow(nullptr)
    , permissionManageWindow(nullptr)
    , orgManageWindow(nullptr)
    , dictManageWindow(nullptr)// 初始化指令管理窗口指针
{
    ui->setupUi(this);

    // 设置初始状态
    ui->stackedWidget->setCurrentIndex(0);
    resetAllButtons();

    // 设置信号槽连接
    setupConnections();
    initSystemMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete unitManageWindow;
    delete stationManageWindow;
    delete protocolManageWindow;
    delete instructionManageWindow;  // 安全删除指令管理窗口
    delete testManageWindow;
    delete userManageWindow;
    delete permissionManageWindow;
    delete orgManageWindow;
    delete dictManageWindow;
}

void MainWindow::setupConnections()
{
    connect(ui->btnUnits, &QPushButton::clicked, this, &MainWindow::onBtnUnitsClicked);
    connect(ui->btnStations, &QPushButton::clicked, this, &MainWindow::onBtnStationsClicked);
    connect(ui->btnProtocols, &QPushButton::clicked, this, &MainWindow::onBtnProtocolsClicked);
    connect(ui->btnCommands, &QPushButton::clicked, this, &MainWindow::onBtnCommandsClicked);
    connect(ui->btnTests, &QPushButton::clicked, this, &MainWindow::onbtnTestsclicked);
    connect(ui->btnAnalysis, &QPushButton::clicked, this, &MainWindow::onBtnAnalysisClicked);
    connect(ui->btnSystem, &QPushButton::clicked, this, &MainWindow::on_btnSystem_clicked);
    connect(ui->btnLogout, &QPushButton::clicked, this, &MainWindow::onBtnLogoutClicked);
    connect(ui->btnUserManage, &QPushButton::clicked, this, &MainWindow::on_btnUserManage_clicked);
    connect(ui->btnPermissionManage, &QPushButton::clicked, this, &MainWindow::on_btnPermissionManage_clicked);
    connect(ui->btnOrgManage, &QPushButton::clicked, this, &MainWindow::on_btnOrgManage_clicked);
    connect(ui->btnDictManage, &QPushButton::clicked, this, &MainWindow::on_btnDictManage_clicked);
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

// 新增系统菜单初始化
void MainWindow::initSystemMenu()
{
    // 默认隐藏系统管理子菜单
    ui->systemSubLayout->parentWidget()->setVisible(false);
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

void MainWindow::onbtnTestsclicked()
{
    setActiveButton(ui->btnTests);
    if (!testManageWindow) {
        testManageWindow = new TestManageWindow(this);
        ui->stackedWidget->addWidget(testManageWindow);
    }
    ui->stackedWidget->setCurrentWidget(testManageWindow);
}

void MainWindow::onBtnAnalysisClicked()
{
    setActiveButton(ui->btnAnalysis);
    ui->stackedWidget->setCurrentWidget(ui->pageAnalysis);
}

void MainWindow::onBtnLogoutClicked()
{
    close();
}

// 新增系统管理菜单槽函数
void MainWindow::on_btnSystem_clicked()
{
    // 切换子菜单可见性
    QWidget *subMenu = ui->systemSubLayout->parentWidget();
    subMenu->setVisible(!subMenu->isVisible());

    // 激活系统管理主按钮
    setActiveButton(ui->btnSystem);

    // 切换到系统管理主页面
    ui->stackedWidget->setCurrentWidget(ui->pageSystem);
}

void MainWindow::on_btnUserManage_clicked()
{
    setActiveButton(ui->btnUserManage);
    if (!userManageWindow) {
        userManageWindow = new UserManageWindow(this);
        ui->stackedWidget->addWidget(userManageWindow);
    }
    ui->stackedWidget->setCurrentWidget(userManageWindow);
}

void MainWindow::on_btnPermissionManage_clicked()
{
    setActiveButton(ui->btnAnalysis);
    ui->stackedWidget->setCurrentWidget(ui->pageAnalysis);
}

void MainWindow::on_btnOrgManage_clicked()
{
    setActiveButton(ui->btnAnalysis);
    ui->stackedWidget->setCurrentWidget(ui->pageAnalysis);
}

void MainWindow::on_btnDictManage_clicked()
{
    setActiveButton(ui->btnAnalysis);
    ui->stackedWidget->setCurrentWidget(ui->pageAnalysis);
}

void MainWindow::onButtonClicked() {
    // 手动指定要切换到的页面（例如第0页）
    ui->stackedWidget->setCurrentIndex(0);
    // 或通过Widget指针切换：
    // ui->stackedWidget->setCurrentWidget(ui->page1);
}
