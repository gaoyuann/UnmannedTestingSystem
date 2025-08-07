#ifndef UNITDIALOG_H
#define UNITDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class UnitDialog; }
QT_END_NAMESPACE

class UnitDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode { NewUnit, EditUnit };

    struct UnitData {
        QString name;
        QString address;
        QString contact;
        QString phone;
        QString type;
        QString notes;

        bool isValid() const {
            return !name.isEmpty() && !contact.isEmpty() && !phone.isEmpty();
        }

        QStringList toStringList() const {
            return {name, contact, phone, type, address, notes};
        }
    };

    explicit UnitDialog(QWidget *parent = nullptr,
                        Mode mode = NewUnit,
                        const UnitData &data = UnitData());
    ~UnitDialog();

    UnitData getUnitData() const;
    void setUnitData(const UnitData &data);

private slots:
    void validateInput();

private:
    Ui::UnitDialog *ui;
    Mode m_mode;
};

#endif // UNITDIALOG_H

