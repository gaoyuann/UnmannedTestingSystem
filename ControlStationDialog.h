#ifndef CONTROLSTATIONDIALOG_H
#define CONTROLSTATIONDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class ControlStationDialog;
}

class ControlStationDialog : public QDialog
{
    Q_OBJECT

public:
    enum DialogMode { NewStation, EditStation };

    struct StationData {
        QString name;
        QString unitName;
        QString type;
        QString ip;
        int port;
        int status;
        bool isValid() const {
            return !name.isEmpty() && !ip.isEmpty() && port > 0;
        }
        QStringList toStringList() const {
            return {name, unitName, type, ip, QString::number(port), QString::number(status)};
        }
    };

    explicit ControlStationDialog(QWidget *parent = nullptr,
                                  DialogMode mode = NewStation,
                                  const StationData &data = StationData());
    ~ControlStationDialog();

    StationData getStationData() const;

private slots:
    void onAccept();
    void validateInput();

private:
    void initUI();
    void loadUnitList();
    void setupConnections();
    void setErrorStyle(const QString &field);

    bool validateAll(QString &errorMsg);


    Ui::ControlStationDialog *ui;
    DialogMode m_mode;
};

#endif // CONTROLSTATIONDIALOG_H
