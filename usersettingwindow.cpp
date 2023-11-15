#include "usersettingwindow.h"
#include "ui_usersettingwindow.h"

UserSettingWindow::UserSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettingWindow)
{
    ui->setupUi(this);
}

UserSettingWindow::~UserSettingWindow()
{
    delete ui;
}
