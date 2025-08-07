#ifndef PROTOCOLDIALOG_H
#define PROTOCOLDIALOG_H

#include <QDialog>

namespace Ui {
class ProtocolDialog;
}

class ProtocolDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode { NewProtocol, EditProtocol };

    struct ProtocolData {
        QString name;
        QString type;
        QString description;

        bool isValid() const { return !name.isEmpty() && !type.isEmpty(); }
        QStringList toStringList() const { return {name, type, description}; }
    };

    explicit ProtocolDialog(QWidget *parent = nullptr, Mode mode = NewProtocol,
                            const ProtocolData &data = ProtocolData());
    ~ProtocolDialog();

    ProtocolData getProtocolData() const;

private:
    Ui::ProtocolDialog *ui;
    Mode m_mode;
};

#endif // PROTOCOLDIALOG_H
