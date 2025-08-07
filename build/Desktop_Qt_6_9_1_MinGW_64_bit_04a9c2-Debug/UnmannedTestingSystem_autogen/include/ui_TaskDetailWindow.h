/********************************************************************************
** Form generated from reading UI file 'TaskDetailWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDETAILWINDOW_H
#define UI_TASKDETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TaskDetailWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QGroupBox *groupBasic;
    QGridLayout *gridLayoutBasic;
    QLabel *labelTaskIdKey;
    QLabel *labelTaskIdValue;
    QLabel *labelStatusKey;
    QLabel *labelStatusValue;
    QLabel *labelUnitKey;
    QLabel *labelUnitValue;
    QLabel *labelStationKey;
    QLabel *labelStationValue;
    QLabel *labelProtocolKey;
    QLabel *labelProtocolValue;
    QLabel *labelStartTimeKey;
    QLabel *labelStartTimeValue;
    QGroupBox *groupTestItems;
    QVBoxLayout *verticalLayoutItems;
    QTableWidget *tableTestItems;
    QGroupBox *groupReport;
    QVBoxLayout *verticalLayoutReport;
    QGridLayout *gridLayoutReport;
    QLabel *labelReportIdKey;
    QLabel *labelReportIdValue;
    QLabel *labelTestResultKey;
    QLabel *labelTestResultValue;
    QLabel *labelPassRateKey;
    QLabel *labelPassRateValue;
    QLabel *labelGenerateUserKey;
    QLabel *labelGenerateUserValue;
    QLabel *labelSummaryKey;
    QTextEdit *textSummaryContent;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnExport;
    QPushButton *btnClose;

    void setupUi(QDialog *TaskDetailWindow)
    {
        if (TaskDetailWindow->objectName().isEmpty())
            TaskDetailWindow->setObjectName("TaskDetailWindow");
        TaskDetailWindow->resize(950, 900);
        verticalLayout = new QVBoxLayout(TaskDetailWindow);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 25, 30, 25);
        labelTitle = new QLabel(TaskDetailWindow);
        labelTitle->setObjectName("labelTitle");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelTitle->setFont(font);

        verticalLayout->addWidget(labelTitle);

        groupBasic = new QGroupBox(TaskDetailWindow);
        groupBasic->setObjectName("groupBasic");
        gridLayoutBasic = new QGridLayout(groupBasic);
        gridLayoutBasic->setSpacing(20);
        gridLayoutBasic->setObjectName("gridLayoutBasic");
        labelTaskIdKey = new QLabel(groupBasic);
        labelTaskIdKey->setObjectName("labelTaskIdKey");

        gridLayoutBasic->addWidget(labelTaskIdKey, 0, 0, 1, 1);

        labelTaskIdValue = new QLabel(groupBasic);
        labelTaskIdValue->setObjectName("labelTaskIdValue");

        gridLayoutBasic->addWidget(labelTaskIdValue, 0, 1, 1, 1);

        labelStatusKey = new QLabel(groupBasic);
        labelStatusKey->setObjectName("labelStatusKey");

        gridLayoutBasic->addWidget(labelStatusKey, 0, 2, 1, 1);

        labelStatusValue = new QLabel(groupBasic);
        labelStatusValue->setObjectName("labelStatusValue");

        gridLayoutBasic->addWidget(labelStatusValue, 0, 3, 1, 1);

        labelUnitKey = new QLabel(groupBasic);
        labelUnitKey->setObjectName("labelUnitKey");

        gridLayoutBasic->addWidget(labelUnitKey, 1, 0, 1, 1);

        labelUnitValue = new QLabel(groupBasic);
        labelUnitValue->setObjectName("labelUnitValue");

        gridLayoutBasic->addWidget(labelUnitValue, 1, 1, 1, 1);

        labelStationKey = new QLabel(groupBasic);
        labelStationKey->setObjectName("labelStationKey");

        gridLayoutBasic->addWidget(labelStationKey, 1, 2, 1, 1);

        labelStationValue = new QLabel(groupBasic);
        labelStationValue->setObjectName("labelStationValue");

        gridLayoutBasic->addWidget(labelStationValue, 1, 3, 1, 1);

        labelProtocolKey = new QLabel(groupBasic);
        labelProtocolKey->setObjectName("labelProtocolKey");

        gridLayoutBasic->addWidget(labelProtocolKey, 2, 0, 1, 1);

        labelProtocolValue = new QLabel(groupBasic);
        labelProtocolValue->setObjectName("labelProtocolValue");

        gridLayoutBasic->addWidget(labelProtocolValue, 2, 1, 1, 1);

        labelStartTimeKey = new QLabel(groupBasic);
        labelStartTimeKey->setObjectName("labelStartTimeKey");

        gridLayoutBasic->addWidget(labelStartTimeKey, 2, 2, 1, 1);

        labelStartTimeValue = new QLabel(groupBasic);
        labelStartTimeValue->setObjectName("labelStartTimeValue");

        gridLayoutBasic->addWidget(labelStartTimeValue, 2, 3, 1, 1);


        verticalLayout->addWidget(groupBasic);

        groupTestItems = new QGroupBox(TaskDetailWindow);
        groupTestItems->setObjectName("groupTestItems");
        verticalLayoutItems = new QVBoxLayout(groupTestItems);
        verticalLayoutItems->setObjectName("verticalLayoutItems");
        tableTestItems = new QTableWidget(groupTestItems);
        if (tableTestItems->columnCount() < 5)
            tableTestItems->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTestItems->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTestItems->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableTestItems->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableTestItems->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableTestItems->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableTestItems->setObjectName("tableTestItems");
        tableTestItems->setColumnCount(5);

        verticalLayoutItems->addWidget(tableTestItems);


        verticalLayout->addWidget(groupTestItems);

        groupReport = new QGroupBox(TaskDetailWindow);
        groupReport->setObjectName("groupReport");
        verticalLayoutReport = new QVBoxLayout(groupReport);
        verticalLayoutReport->setObjectName("verticalLayoutReport");
        gridLayoutReport = new QGridLayout();
        gridLayoutReport->setSpacing(20);
        gridLayoutReport->setObjectName("gridLayoutReport");
        labelReportIdKey = new QLabel(groupReport);
        labelReportIdKey->setObjectName("labelReportIdKey");

        gridLayoutReport->addWidget(labelReportIdKey, 0, 0, 1, 1);

        labelReportIdValue = new QLabel(groupReport);
        labelReportIdValue->setObjectName("labelReportIdValue");

        gridLayoutReport->addWidget(labelReportIdValue, 0, 1, 1, 1);

        labelTestResultKey = new QLabel(groupReport);
        labelTestResultKey->setObjectName("labelTestResultKey");

        gridLayoutReport->addWidget(labelTestResultKey, 0, 2, 1, 1);

        labelTestResultValue = new QLabel(groupReport);
        labelTestResultValue->setObjectName("labelTestResultValue");

        gridLayoutReport->addWidget(labelTestResultValue, 0, 3, 1, 1);

        labelPassRateKey = new QLabel(groupReport);
        labelPassRateKey->setObjectName("labelPassRateKey");

        gridLayoutReport->addWidget(labelPassRateKey, 1, 0, 1, 1);

        labelPassRateValue = new QLabel(groupReport);
        labelPassRateValue->setObjectName("labelPassRateValue");

        gridLayoutReport->addWidget(labelPassRateValue, 1, 1, 1, 1);

        labelGenerateUserKey = new QLabel(groupReport);
        labelGenerateUserKey->setObjectName("labelGenerateUserKey");

        gridLayoutReport->addWidget(labelGenerateUserKey, 1, 2, 1, 1);

        labelGenerateUserValue = new QLabel(groupReport);
        labelGenerateUserValue->setObjectName("labelGenerateUserValue");

        gridLayoutReport->addWidget(labelGenerateUserValue, 1, 3, 1, 1);


        verticalLayoutReport->addLayout(gridLayoutReport);

        labelSummaryKey = new QLabel(groupReport);
        labelSummaryKey->setObjectName("labelSummaryKey");

        verticalLayoutReport->addWidget(labelSummaryKey);

        textSummaryContent = new QTextEdit(groupReport);
        textSummaryContent->setObjectName("textSummaryContent");
        textSummaryContent->setReadOnly(true);

        verticalLayoutReport->addWidget(textSummaryContent);


        verticalLayout->addWidget(groupReport);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnExport = new QPushButton(TaskDetailWindow);
        btnExport->setObjectName("btnExport");

        horizontalLayoutButtons->addWidget(btnExport);

        btnClose = new QPushButton(TaskDetailWindow);
        btnClose->setObjectName("btnClose");
        btnClose->setMouseTracking(false);

        horizontalLayoutButtons->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayoutButtons);


        retranslateUi(TaskDetailWindow);
        QObject::connect(btnClose, &QPushButton::clicked, TaskDetailWindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(TaskDetailWindow);
    } // setupUi

    void retranslateUi(QDialog *TaskDetailWindow)
    {
        TaskDetailWindow->setWindowTitle(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\344\273\273\345\212\241\350\257\246\346\203\205", nullptr));
        labelTitle->setText(QCoreApplication::translate("TaskDetailWindow", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        groupBasic->setTitle(QCoreApplication::translate("TaskDetailWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        labelTaskIdKey->setText(QCoreApplication::translate("TaskDetailWindow", "\344\273\273\345\212\241ID:", nullptr));
        labelTaskIdValue->setText(QString());
        labelStatusKey->setText(QCoreApplication::translate("TaskDetailWindow", "\344\273\273\345\212\241\347\212\266\346\200\201:", nullptr));
        labelStatusValue->setText(QString());
        labelUnitKey->setText(QCoreApplication::translate("TaskDetailWindow", "\345\217\202\350\257\225\345\215\225\344\275\215:", nullptr));
        labelUnitValue->setText(QString());
        labelStationKey->setText(QCoreApplication::translate("TaskDetailWindow", "\346\216\247\345\210\266\347\253\231:", nullptr));
        labelStationValue->setText(QString());
        labelProtocolKey->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\345\215\217\350\256\256:", nullptr));
        labelProtocolValue->setText(QString());
        labelStartTimeKey->setText(QCoreApplication::translate("TaskDetailWindow", "\345\274\200\345\247\213\346\227\266\351\227\264:", nullptr));
        labelStartTimeValue->setText(QString());
        groupTestItems->setTitle(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\351\241\271\347\233\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTestItems->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TaskDetailWindow", "\351\241\271\347\233\256ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTestItems->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TaskDetailWindow", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableTestItems->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\346\240\207\345\207\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableTestItems->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableTestItems->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\346\227\266\351\227\264", nullptr));
        groupReport->setTitle(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\346\212\245\345\221\212", nullptr));
        labelReportIdKey->setText(QCoreApplication::translate("TaskDetailWindow", "\346\212\245\345\221\212ID:", nullptr));
        labelReportIdValue->setText(QString());
        labelTestResultKey->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\347\273\223\346\236\234:", nullptr));
        labelTestResultValue->setText(QString());
        labelPassRateKey->setText(QCoreApplication::translate("TaskDetailWindow", "\351\200\232\350\277\207\347\216\207:", nullptr));
        labelPassRateValue->setText(QString());
        labelGenerateUserKey->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\344\272\272\345\221\230:", nullptr));
        labelGenerateUserValue->setText(QString());
        labelSummaryKey->setText(QCoreApplication::translate("TaskDetailWindow", "\346\265\213\350\257\225\346\200\273\347\273\223:", nullptr));
        btnExport->setText(QCoreApplication::translate("TaskDetailWindow", "\345\257\274\345\207\272\346\212\245\345\221\212", nullptr));
        btnClose->setText(QCoreApplication::translate("TaskDetailWindow", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDetailWindow: public Ui_TaskDetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDETAILWINDOW_H
