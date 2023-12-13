#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::isAdmin = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

            menuWindow = new MenuWindow(this);
            connect(menuWindow, &MenuWindow::toLoginWindow, this, &MainWindow::show);

            hide();
            menuWindow->setWindowTitle("Главное меню");
            menuWindow->show();
        }
        else
        {
            QMessageBox::about(this, "Ошибка", "Неверные данные");
        }
    }
}

void MainWindow::on_pushButton_toRegistration_clicked()
{
    registrationWindow = new RegistrationWindow();
    connect(registrationWindow, &RegistrationWindow::toLoginWindow, this, &MainWindow::show);
    registrationWindow->setWindowTitle("Регистрация");
    registrationWindow->show();
    this->close();
}

