#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    registrationWindow = new RegistrationWindow();
    connect(registrationWindow, &RegistrationWindow::toLoginWindow, this, &MainWindow::show);

    menuWindow = new MenuWindow(this);
    connect(menuWindow, &MenuWindow::toLoginWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_signIn_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if(login == "text" && password == "text")
    {
        hide();
        menuWindow->show();
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

