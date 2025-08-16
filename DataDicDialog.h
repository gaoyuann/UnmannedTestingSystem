#ifndef DATADICDIALOG_H
#define DATADICDIALOG_H

#include <QDialog>

namespace Ui {
class DataDicDialog;
}

class DataDicDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode { NewDict, EditDict };

    struct DictData {
        QString type;
        QString key;
        QString value;
        int sort;

        bool isValid() const {
            return !type.isEmpty() && !key.isEmpty() && !value.isEmpty();
        }

        QStringList toStringList() const {
            return {type, key, value, QString::number(sort)};
        }
    };

    explicit DataDicDialog(QWidget *parent = nullptr, Mode mode = NewDict,
                           const DictData &data = DictData());
    ~DataDicDialog();

    DictData getDictData() const;
    void setDictData(const DictData &data);

private slots:
    void validateInput();

private:
    Ui::DataDicDialog *ui;
    Mode m_mode;

    void setupConnections();
};

#endif // DATADICDIALOG_H
