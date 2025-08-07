#ifndef USERMANAGEWINDOW_H
#define USERMANAGEWINDOW_H

#include <QWidget>

namespace Ui {
class UserManageWindow;
}

class UserManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserManageWindow(QWidget *parent = nullptr);
    ~UserManageWindow();

private:
    Ui::UserManageWindow *ui;
};

#endif // USERMANAGEWINDOW_H
