#ifndef USERSETTINGWINDOW_H
#define USERSETTINGWINDOW_H

#include <QDialog>

namespace Ui {
class UserSettingWindow;
}

class UserSettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettingWindow(QWidget *parent = nullptr);
    ~UserSettingWindow();

signals:
    void toMenuWindow();

private:
    Ui::UserSettingWindow *ui;
};

#endif // USERSETTINGWINDOW_H
