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
    this->hide();
    emit toMenuWindow();
}

