/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sideBar;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelLogo;
    QPushButton *btnUnits;
    QPushButton *btnStations;
    QPushButton *btnProtocols;
    QPushButton *btnCommands;
    QPushButton *btnTests;
    QPushButton *btnAnalysis;
    QVBoxLayout *systemMenuLayout;
    QPushButton *btnSystem;
    QVBoxLayout *systemSubLayout;
    QPushButton *btnUserManage;
    QPushButton *btnPermissionManage;
    QPushButton *btnOrgManage;
    QPushButton *btnDictManage;
    QSpacerItem *verticalSpacer;
    QPushButton *btnLogout;
    QStackedWidget *stackedWidget;
    QWidget *pageHome;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelWelcome;
    QLabel *labelDescription;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageUnits;
    QWidget *pageStations;
    QWidget *pageProtocols;
    QWidget *pageCommands;
    QWidget *pageTests;
    QWidget *pageAnalysis;
    QWidget *pageSystem;
    QWidget *pageUserManage;
    QWidget *pagePermissionManage;
    QWidget *pageOrgManage;
    QWidget *pageDictManage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #f5f7fa;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sideBar = new QFrame(centralwidget);
        sideBar->setObjectName("sideBar");
        sideBar->setStyleSheet(QString::fromUtf8("background-color: #2c3e50;"));
        sideBar->setFrameShape(QFrame::Shape::StyledPanel);
        sideBar->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(sideBar);
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelLogo = new QLabel(sideBar);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setStyleSheet(QString::fromUtf8("color: white; font-size: 20px; font-weight: bold; padding: 20px;"));
        labelLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(labelLogo);

        btnUnits = new QPushButton(sideBar);
        btnUnits->setObjectName("btnUnits");
        btnUnits->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/units.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnUnits->setIcon(icon);
        btnUnits->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnUnits);

        btnStations = new QPushButton(sideBar);
        btnStations->setObjectName("btnStations");
        btnStations->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/stations.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnStations->setIcon(icon1);
        btnStations->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnStations);

        btnProtocols = new QPushButton(sideBar);
        btnProtocols->setObjectName("btnProtocols");
        btnProtocols->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/protocols.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnProtocols->setIcon(icon2);
        btnProtocols->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnProtocols);

        btnCommands = new QPushButton(sideBar);
        btnCommands->setObjectName("btnCommands");
        btnCommands->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/commands.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnCommands->setIcon(icon3);
        btnCommands->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnCommands);

        btnTests = new QPushButton(sideBar);
        btnTests->setObjectName("btnTests");
        btnTests->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/tests.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnTests->setIcon(icon4);
        btnTests->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnTests);

        btnAnalysis = new QPushButton(sideBar);
        btnAnalysis->setObjectName("btnAnalysis");
        btnAnalysis->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/analysis.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAnalysis->setIcon(icon5);
        btnAnalysis->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnAnalysis);

        systemMenuLayout = new QVBoxLayout();
        systemMenuLayout->setObjectName("systemMenuLayout");
        btnSystem = new QPushButton(sideBar);
        btnSystem->setObjectName("btnSystem");
        btnSystem->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}\n"
"QPushButton[active=\"true\"] {\n"
"    background-color: #34495e;\n"
"    border-left: 4px solid #3498db;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/system.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSystem->setIcon(icon6);
        btnSystem->setIconSize(QSize(24, 24));

        systemMenuLayout->addWidget(btnSystem);

        systemSubLayout = new QVBoxLayout();
        systemSubLayout->setObjectName("systemSubLayout");
        btnUserManage = new QPushButton(sideBar);
        btnUserManage->setObjectName("btnUserManage");
        btnUserManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #bdc3c7; /* \345\255\220\351\241\271\351\242\234\350\211\262\347\250\215\346\265\205\357\274\214\345\214\272\345\210\206\344\270\273\350\217\234\345\215\225 */\n"
"    text-align: left;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    background-color: #34495e;\n"
"}"));

        systemSubLayout->addWidget(btnUserManage);

        btnPermissionManage = new QPushButton(sideBar);
        btnPermissionManage->setObjectName("btnPermissionManage");
        btnPermissionManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #bdc3c7;\n"
"    text-align: left;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    background-color: #34495e;\n"
"}"));

        systemSubLayout->addWidget(btnPermissionManage);

        btnOrgManage = new QPushButton(sideBar);
        btnOrgManage->setObjectName("btnOrgManage");
        btnOrgManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #bdc3c7;\n"
"    text-align: left;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    background-color: #34495e;\n"
"}"));

        systemSubLayout->addWidget(btnOrgManage);

        btnDictManage = new QPushButton(sideBar);
        btnDictManage->setObjectName("btnDictManage");
        btnDictManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #bdc3c7;\n"
"    text-align: left;\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    color: white;\n"
"    background-color: #34495e;\n"
"}"));

        systemSubLayout->addWidget(btnDictManage);


        systemMenuLayout->addLayout(systemSubLayout);


        verticalLayout_2->addLayout(systemMenuLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        btnLogout = new QPushButton(sideBar);
        btnLogout->setObjectName("btnLogout");
        btnLogout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    text-align: left;\n"
"    padding: 12px 20px;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-left: 4px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/logout.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLogout->setIcon(icon7);
        btnLogout->setIconSize(QSize(24, 24));

        verticalLayout_2->addWidget(btnLogout);


        horizontalLayout->addWidget(sideBar);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #f5f7fa;"));
        pageHome = new QWidget();
        pageHome->setObjectName("pageHome");
        verticalLayout_3 = new QVBoxLayout(pageHome);
        verticalLayout_3->setObjectName("verticalLayout_3");
        labelWelcome = new QLabel(pageHome);
        labelWelcome->setObjectName("labelWelcome");
        labelWelcome->setStyleSheet(QString::fromUtf8("font-size: 24px; color: #2c3e50; padding: 20px;"));
        labelWelcome->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(labelWelcome);

        labelDescription = new QLabel(pageHome);
        labelDescription->setObjectName("labelDescription");
        labelDescription->setStyleSheet(QString::fromUtf8("font-size: 16px; color: #7f8c8d; padding: 10px 40px;"));
        labelDescription->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(labelDescription);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(pageHome);
        pageUnits = new QWidget();
        pageUnits->setObjectName("pageUnits");
        stackedWidget->addWidget(pageUnits);
        pageStations = new QWidget();
        pageStations->setObjectName("pageStations");
        stackedWidget->addWidget(pageStations);
        pageProtocols = new QWidget();
        pageProtocols->setObjectName("pageProtocols");
        stackedWidget->addWidget(pageProtocols);
        pageCommands = new QWidget();
        pageCommands->setObjectName("pageCommands");
        stackedWidget->addWidget(pageCommands);
        pageTests = new QWidget();
        pageTests->setObjectName("pageTests");
        stackedWidget->addWidget(pageTests);
        pageAnalysis = new QWidget();
        pageAnalysis->setObjectName("pageAnalysis");
        stackedWidget->addWidget(pageAnalysis);
        pageSystem = new QWidget();
        pageSystem->setObjectName("pageSystem");
        stackedWidget->addWidget(pageSystem);
        pageUserManage = new QWidget();
        pageUserManage->setObjectName("pageUserManage");
        stackedWidget->addWidget(pageUserManage);
        pagePermissionManage = new QWidget();
        pagePermissionManage->setObjectName("pagePermissionManage");
        stackedWidget->addWidget(pagePermissionManage);
        pageOrgManage = new QWidget();
        pageOrgManage->setObjectName("pageOrgManage");
        stackedWidget->addWidget(pageOrgManage);
        pageDictManage = new QWidget();
        pageDictManage->setObjectName("pageDictManage");
        stackedWidget->addWidget(pageDictManage);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(btnUserManage, &QPushButton::clicked, stackedWidget, &QStackedWidget::setCurrentWidget);
        QObject::connect(btnPermissionManage, &QPushButton::clicked, stackedWidget, &QStackedWidget::setCurrentWidget);
        QObject::connect(btnOrgManage, &QPushButton::clicked, stackedWidget, &QStackedWidget::setCurrentWidget);
        QObject::connect(btnDictManage, &QPushButton::clicked, stackedWidget, &QStackedWidget::setCurrentWidget);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\227\240\344\272\272\345\271\263\345\217\260\346\265\213\350\257\225\350\257\204\344\274\260\347\263\273\347\273\237", nullptr));
        labelLogo->setText(QCoreApplication::translate("MainWindow", "\346\227\240\344\272\272\345\271\263\345\217\260\346\265\213\350\257\225\350\257\204\344\274\260\347\263\273\347\273\237", nullptr));
        btnUnits->setText(QCoreApplication::translate("MainWindow", "\345\217\202\350\257\225\345\215\225\344\275\215\347\256\241\347\220\206", nullptr));
        btnStations->setText(QCoreApplication::translate("MainWindow", "\346\227\240\344\272\272\345\271\263\345\217\260\346\216\247\345\210\266\347\253\231\347\256\241\347\220\206", nullptr));
        btnProtocols->setText(QCoreApplication::translate("MainWindow", "\345\215\217\350\256\256\347\256\241\347\220\206", nullptr));
        btnCommands->setText(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\347\256\241\347\220\206", nullptr));
        btnTests->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\256\241\347\220\206", nullptr));
        btnAnalysis->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\204\347\273\223\346\236\234\345\210\206\346\236\220", nullptr));
        btnSystem->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        btnUserManage->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        btnPermissionManage->setText(QCoreApplication::translate("MainWindow", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        btnOrgManage->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\256\241\347\220\206", nullptr));
        btnDictManage->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\255\227\345\205\270", nullptr));
        btnLogout->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        labelWelcome->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\227\240\344\272\272\345\271\263\345\217\260\346\265\213\350\257\225\350\257\204\344\274\260\347\263\273\347\273\237", nullptr));
        labelDescription->setText(QCoreApplication::translate("MainWindow", "\350\257\267\344\273\216\345\267\246\344\276\247\350\217\234\345\215\225\351\200\211\346\213\251\345\212\237\350\203\275\346\250\241\345\235\227\345\274\200\345\247\213\345\267\245\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
