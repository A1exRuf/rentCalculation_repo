#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    calculationMethodChoiceWindow = new CalculationMethodChoiceWindow();
    connect(calculationMethodChoiceWindow, &CalculationMethodChoiceWindow::toMenuWindow, this, &CalculationMethodChoiceWindow::show);
    normativeSettingWindow = new NormativeSettingWindow();
    connect(normativeSettingWindow, &NormativeSettingWindow::toMenuWindow, this, &NormativeSettingWindow::show);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}


void MenuWindow::on_pushButton_toLogin_clicked()
{
    this->close();
    emit toLoginWindow();
}


void MenuWindow::on_pushButton_toRenctCalculation_clicked()
{
    hide();
    calculationMethodChoiceWindow->show();
}


void MenuWindow::on_pushButton_toStandartSettings_clicked()
{
    hide();
    normativeSettingWindow->show();
}

