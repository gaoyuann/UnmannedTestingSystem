#ifndef MESSAGEFORMATDIALOG_H
#define MESSAGEFORMATDIALOG_H

#include <QDialog>
#include "ProtocolManageWindow.h" // 获取CheckBoxDelegate
#include <QComboBox>

namespace Ui {
class MessageFormatDialog;
}

struct MessageFormat {
    int formatId;
    QString fieldName;
    QString dataType;
    int length;
    int sort;
    QString description;
};

class MessageFormatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageFormatDialog(QWidget *parent, const QString &protocolName,
                                 const QVector<MessageFormat> &formats);
    ~MessageFormatDialog();

    QVector<MessageFormat> getMessageFormats() const;

private slots:
    void onAddField();
    void onRemoveField();
    void onSave();

private:
    void initUI();
    void setupConnections();
    void updateTable();
    void setupDataTypeComboBox(QComboBox *combo);

    Ui::MessageFormatDialog *ui;
    QString protocolName;
    QVector<MessageFormat> formats;
    QStringList dataTypes = {"string", "int", "float", "bool", "byte", "short", "long", "double"};
};

#endif
