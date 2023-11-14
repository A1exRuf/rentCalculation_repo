#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registrationwindow.h"
#include "menuwindow.h"

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_signIn_clicked();

    void on_pushButton_toRegistration_clicked();

private:
    Ui::MainWindow *ui;

    RegistrationWindow *registrationWindow;
    MenuWindow *menuWindow;
};
#endif // MAINWINDOW_H
