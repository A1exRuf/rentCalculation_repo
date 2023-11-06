#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./usersDB.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("not open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE UsersList(Login TEXT, Password TEXT, isAdmin BOOL);");

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

    }
    else{
        QMessageBox::information(this, "Login", "Incorrect");
    }
}

