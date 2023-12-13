#include "registrationwindow.h"
#include "ui_registrationwindow.h"

#include <QSqlRecord>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_pushButton_toLogin_clicked()
{
    this->close();
    emit toLoginWindow();
}


void RegistrationWindow::on_pushButton_register_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString passwordConfirm = ui->lineEdit_passwordConfirm->text();

    if(login !="" && password != "" && password == passwordConfirm)
    {
        QSqlQuery query;

        query.prepare("INSERT INTO UsersList (login, password) VALUES (:login, :password)");
        query.bindValue(":login", login);
        query.bindValue(":password", password);

        if(query.exec())
        {
            QMessageBox::about(this, "Регистрация", "Регистрация прошла успешно");
        }
        else
        {
            QMessageBox::about(this, "Регистрация", "Не удалось зарегистрироваться");
        }
    }
    else
    {
        QMessageBox::about(this, "Ошибка", "Неверные данные");
    }
}

