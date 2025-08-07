#ifndef INSTRUCTIONDIALOG_H
#define INSTRUCTIONDIALOG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class InstructionDialog;
}

class InstructionDialog : public QDialog
{
    Q_OBJECT

public:
    struct InstructionData {
        QString name;
        int protocolId;
        QString protocolName;
        QString code;
        QString content;
        QString type;

        bool isValid() const {
            return !name.isEmpty() && protocolId > 0 && !code.isEmpty() && !type.isEmpty();
        }

        QStringList toStringList() const {
            return {name, QString::number(protocolId), code, content, type};
        }
    };

    enum DialogMode {
        NewInstruction,
        EditInstruction
    };

    explicit InstructionDialog(QWidget *parent, DialogMode mode,
                               const QMap<int, QString> &protocolMap,
                               const InstructionData &data = InstructionData());
    ~InstructionDialog();

    InstructionData getInstructionData() const;

private slots:
    void onProtocolChanged(int index);
    void validateInputs();

private:
    void initUI();
    void setupConnections();

    Ui::InstructionDialog *ui;
    DialogMode m_mode;
    QMap<int, QString> m_protocolMap;
};

#endif // INSTRUCTIONDIALOG_H
