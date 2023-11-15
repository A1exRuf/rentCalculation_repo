#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::isAdmin = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    registrationWindow = new RegistrationWindow();
    connect(registrationWindow, &RegistrationWindow::toLoginWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getIsAdmin()
{
    return isAdmin;
}

void MainWindow::on_pushButton_signIn_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery qry;

    if(qry.exec("SELECT Login, Password, Role FROM UsersList WHERE Login=\'" + login + "\' AND Password=\'" + password + "\'"))
    {
        if(qry.next())
        {
            isAdmin = qry.value(2) == "admin";

            qDebug() << isAdmin;

            menuWindow = new MenuWindow(this);
            connect(menuWindow, &MenuWindow::toLoginWindow, this, &MainWindow::show);

            hide();
            menuWindow->show();
        }
    }

    else {
        QMessageBox::information(this, "Login", "Incorrect");
    }
}

void MainWindow::on_pushButton_toRegistration_clicked()
{
    registrationWindow->show();
    this->close();
}

