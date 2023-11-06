#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

signals:
    void toLoginWindow();

private slots:
    void on_pushButton_toLogin_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::RegistrationWindow *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // REGISTRATIONWINDOW_H
