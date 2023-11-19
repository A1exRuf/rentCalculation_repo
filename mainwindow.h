#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "registrationwindow.h"
#include "menuwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool getIsAdmin();

private slots:
    void on_pushButton_signIn_clicked();
    void on_pushButton_toRegistration_clicked();

private:
    Ui::MainWindow *ui;
    static bool isAdmin;
    RegistrationWindow *registrationWindow;
    MenuWindow *menuWindow;
};
#endif // MAINWINDOW_H
