#include "calculationmethodchoicewindow.h"
#include "ui_calculationmethodchoicewindow.h"

CalculationMethodChoiceWindow::CalculationMethodChoiceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculationMethodChoiceWindow)
{
    ui->setupUi(this);
}

CalculationMethodChoiceWindow::~CalculationMethodChoiceWindow()
{
    delete ui;
}

void CalculationMethodChoiceWindow::on_pushButton_toMenu_clicked()
{
    this->close();
    emit toMenuWindow();
}


void CalculationMethodChoiceWindow::on_pushButton_clicked()
{
    methodAreaWindow = new MethodAreaWindow();
    connect(methodAreaWindow, &MethodAreaWindow::toChoiceWindow, this, &CalculationMethodChoiceWindow::show);
    this->close();
    methodAreaWindow->show();
}


void CalculationMethodChoiceWindow::on_pushButton_2_clicked()
{
    methodTenantCount = new MethodTenantCount();
    connect(methodTenantCount, &MethodTenantCount::toChoiceWindow, this, &MethodTenantCount::show);
    this->close();
    methodTenantCount->show();
}


void CalculationMethodChoiceWindow::on_pushButton_3_clicked()
{
    methodFixedTariffs = new MethodFixedTariffs();
    connect(methodFixedTariffs, &MethodFixedTariffs::toChoiceWindow, this, &MethodFixedTariffs::show);
    this->close();
    methodFixedTariffs->show();
}


void CalculationMethodChoiceWindow::on_pushButton_4_clicked()
{
    methodNormatives = new MethodNormatives();
    connect(methodNormatives, &MethodNormatives::toChoiceWindow, this, &MethodNormatives::show);
    this->close();
    methodNormatives->show();
}


void CalculationMethodChoiceWindow::on_pushButton_meteringDevices_clicked()
{
    methodMeteringDevices = new MethodMeteringDevices();
    connect(methodMeteringDevices, &MethodMeteringDevices::toChoiceWindow, this, &MethodMeteringDevices::show);
    this->close();
    methodMeteringDevices->show();

}

