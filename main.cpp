#include "MainWindow.h"
#include "DBUtil.h"

#include <QApplication>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置全局样式，确保 QMessageBox 文本为黑色
    a.setStyleSheet(
        "QMessageBox { background-color: white; }"
        "QMessageBox QLabel { color: black; }"
        "QMessageBox QPushButton { color: black; }"
        );

    // 1. 设置相对配置文件路径
    QString currentSourceFile = __FILE__;
    QFileInfo fileInfo(currentSourceFile);
    QString sourceDir = fileInfo.absolutePath();
    QString configPath = QDir::cleanPath(sourceDir + "/config.ini");

    qDebug() << "配置文件路径:" << configPath;

    // 检查配置文件是否存在
    if (!QFileInfo::exists(configPath)) {
        QMessageBox::critical(
            nullptr,
            "配置文件错误",
            QString("<span style='color: black;'>"
                    "未找到配置文件！<br><br>"
                    "路径: <b>%1</b><br><br>"
                    "请确保：<br>"
                    "1. 配置文件存在于指定位置<br>"
                    "2. 程序有读取权限</span>")
                .arg(configPath)
            );
        return -1;
    }

    // 2. 初始化数据库
    DBUtil* dbUtil = DBUtil::instance();
    if (!dbUtil->initFromConfig(configPath)) {
        qDebug() << "可用数据库驱动:" << QSqlDatabase::drivers();
        qDebug() << "最后执行的SQL:" << dbUtil->lastExecutedQuery();

        QMessageBox::critical(
            nullptr,
            "数据库初始化失败",
            QString("<span style='color: black;'>"
                    "数据库连接失败！<br><br>"
                    "错误信息: <b>%1</b><br><br>"
                    "请检查：<br>"
                    "1. 数据库服务是否运行<br>"
                    "2. 配置文件的用户名/密码是否正确</span>")
                .arg(dbUtil->lastError())
            );
        return -1;
    }

    // 3. 验证连接
    if (!dbUtil->isConnectionValid()) {
        QMessageBox::critical(
            nullptr,
            "连接测试失败",
            QString("<span style='color: black;'>"
                    "数据库连接不稳定！<br>"
                    "最后错误: <b>%1</b><br><br>"
                    "请检查网络连接或数据库状态</span>")
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
