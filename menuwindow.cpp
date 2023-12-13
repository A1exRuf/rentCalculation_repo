#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    ui->pushButton_toUserSetting->setVisible(MainWindow::getIsAdmin());
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
    calculationMethodChoiceWindow = new CalculationMethodChoiceWindow();
    connect(calculationMethodChoiceWindow, &CalculationMethodChoiceWindow::toMenuWindow, this, &CalculationMethodChoiceWindow::show);
    hide();
    calculationMethodChoiceWindow->setWindowTitle("Способ расчета");
    calculationMethodChoiceWindow->show();
}


void MenuWindow::on_pushButton_toStandartSettings_clicked()
{
    normativeSettingWindow = new NormativeSettingWindow();
    connect(normativeSettingWindow, &NormativeSettingWindow::toMenuWindow, this, &NormativeSettingWindow::show);
    hide();
    normativeSettingWindow->setWindowTitle("Настройка нормативов потребления");
    normativeSettingWindow->show();
}


void MenuWindow::on_pushButton_toPaymentAccounting_clicked()
{
    paymentAccountingWindow = new PaymentAccountingWindow;
    connect(paymentAccountingWindow, &PaymentAccountingWindow::toMenuWindow, this, &NormativeSettingWindow::show);
    hide();
    paymentAccountingWindow->setWindowTitle("Учёт оплаты");
    paymentAccountingWindow->show();
}


void MenuWindow::on_pushButton_toUserSetting_clicked()
{
    userSettingWindow = new UserSettingWindow;
    connect(userSettingWindow, &UserSettingWindow::toMenuWindow, this, &NormativeSettingWindow::show);
    this->close();
    userSettingWindow->setWindowTitle("Контроль учётных записей");
    userSettingWindow->show();
}


void MenuWindow::on_pushButton_toBenefitSettings_clicked()
{
    benefitSettingWindow = new BenefitSettingWindow;
    connect(benefitSettingWindow, &BenefitSettingWindow::toMenuWindow, this, &BenefitSettingWindow::show);
    this->close();
    benefitSettingWindow->setWindowTitle("Настройка льгот");
    benefitSettingWindow->show();
}

