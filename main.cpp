#include "MainWindow.h"
#include "DBUtil.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. 设置相对配置文件路径
    // 获取当前源文件的绝对路径（如 D:/study/UnmannedTestingSystem/main.cpp）
    QString currentSourceFile = __FILE__;

    // 获取所在目录（D:/study/UnmannedTestingSystem/）
    QFileInfo fileInfo(currentSourceFile);
    QString sourceDir = fileInfo.absolutePath();

    // 计算 config.ini 路径
    QString configPath = QDir::cleanPath(sourceDir + "/config.ini");

    qDebug() << "配置文件路径:" << configPath;

    // 检查配置文件是否存在
    if (!QFileInfo::exists(configPath)) {
        QMessageBox::critical(
            nullptr,
            "配置文件错误",
            QString("未找到配置文件！\n\n"
                    "路径: %1\n\n"
                    "请确保：\n"
                    "1. 配置文件存在于指定位置\n"
                    "2. 程序有读取权限")
                .arg(configPath)
            );
        return -1;
    }

    // 2. 初始化数据库
    DBUtil* dbUtil = DBUtil::instance();
    if (!dbUtil->initFromConfig(configPath)) {
        // 调试输出
        qDebug() << "可用数据库驱动:" << QSqlDatabase::drivers();
        qDebug() << "最后执行的SQL:" << dbUtil->lastExecutedQuery();
        return -1;
    }

    // 3. 验证连接
    if (!dbUtil->isConnectionValid()) {
        QMessageBox::critical(
            nullptr,
            "连接测试失败",
            QString("数据库连接不稳定！\n"
                    "最后错误: %1\n\n"
                    "请检查网络连接或数据库状态")
                .arg(dbUtil->lastError())
            );
        return -1;
    }

    // 4. 启动主窗口
    qDebug() << "数据库连接成功，启动主界面...";
    MainWindow w;
    w.show();

    return a.exec();
}
