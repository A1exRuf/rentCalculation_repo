#include "calculationmethodchoicewindow.h"
#include "ui_calculationmethodchoicewindow.h"

CalculationMethodChoiceWindow::CalculationMethodChoiceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculationMethodChoiceWindow)
{
    ui->setupUi(this);

    methodAreaWindow = new MethodAreaWindow();
    connect(methodAreaWindow, &MethodAreaWindow::toChoiceWindow, this, &CalculationMethodChoiceWindow::show);
    methodTenantCount = new MethodTenantCount();
    connect(methodTenantCount, &MethodTenantCount::toChoiceWindow, this, &MethodTenantCount::show);
    methodFixedTariffs = new MethodFixedTariffs();
    connect(methodFixedTariffs, &MethodFixedTariffs::toChoiceWindow, this, &MethodFixedTariffs::show);
    methodNormatives = new MethodNormatives();
    connect(methodNormatives, &MethodNormatives::toChoiceWindow, this, &MethodNormatives::show);
}

CalculationMethodChoiceWindow::~CalculationMethodChoiceWindow()
{
    delete ui;
}

void CalculationMethodChoiceWindow::on_pushButton_toMenu_clicked()
{
    this->hide();
    emit toMenuWindow();
}


void CalculationMethodChoiceWindow::on_pushButton_clicked()
{
    this->hide();
    methodAreaWindow->show();
}


void CalculationMethodChoiceWindow::on_pushButton_2_clicked()
{
    this->hide();
    methodTenantCount->show();
}


void CalculationMethodChoiceWindow::on_pushButton_3_clicked()
{
    this->hide();
    methodFixedTariffs->show();
}


void CalculationMethodChoiceWindow::on_pushButton_4_clicked()
{
    this->hide();
    methodNormatives->show();
}

