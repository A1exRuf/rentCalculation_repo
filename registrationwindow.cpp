#include "registrationwindow.h"
#include "ui_registrationwindow.h"

#include <QSqlRecord>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/alexe/Documents/GitHub/rentCalculation_repo/DB/db.sqlite");

    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("not open");
    }

    model = new QSqlTableModel(this, db);
    model->setTable("UsersList");
    model->select();

    ui->tableView->setModel(model);
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

    if(password == passwordConfirm)
    {
        QSqlRecord newRecord = model->record();

        newRecord.setValue("login", login);
        newRecord.setValue("password", password);

        model->insertRecord(-1, newRecord);
        model->select();

        QMessageBox::information(this, "Registration", "User added successfully!");
    }
    else{
        QMessageBox::information(this, "Login", "Incorrect");
    }
}

