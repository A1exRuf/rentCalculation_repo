#ifndef USERSETTINGWINDOW_H
#define USERSETTINGWINDOW_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>

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

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_idSort_clicked();

    void on_pushButton_loginSort_clicked();

    void on_pushButton_roleSort_clicked();

    void on_pushButton_setAdmin_clicked();

    void on_pushButton_setUser_clicked();

    void on_pushButton_toMenu_clicked();

private:
    Ui::UserSettingWindow *ui;

    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
};

#endif // USERSETTINGWINDOW_H
