#include "paymentaccountingwindow.h"
#include "ui_paymentaccountingwindow.h"

PaymentAccountingWindow::PaymentAccountingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentAccountingWindow)
{
    ui->setupUi(this);

    QSqlQueryModel *comboBoxModel = new QSqlQueryModel(this);
    comboBoxModel->setQuery("SELECT PersonalAccount FROM TenantsData", db);
    ui->comboBox_selectRow->setModel(comboBoxModel);
}

PaymentAccountingWindow::~PaymentAccountingWindow()
{
    delete ui;
}

void PaymentAccountingWindow::on_pushButton_toMenu_clicked()
{
    this->close();
    emit toMenuWindow();
}


void PaymentAccountingWindow::on_pushButton_checkPayment_clicked()
{
    QString account = ui->comboBox_selectRow->currentText();
    qDebug("test");
    QSqlQuery query;
    query.exec("SELECT * FROM TenantsData WHERE PersonalAccount=\'" + account + "\'");
    if(query.next())
    {
        QString payment = query.value(12).toString();
        if(payment == "0")
        {
            QMessageBox::about(this, "Статус оплаты", "Оплачено");
        }
        else
        {
            QMessageBox::about(this, "Статус оплаты", "Требуется оплата в размере " + payment + " byn.");
        }
    }
}


void PaymentAccountingWindow::on_pushButton_toTable_clicked()
{
    paymentTableWindow = new PaymentTableWindow();
    connect(paymentTableWindow, &PaymentTableWindow::toPaymentAccounting, this, &PaymentAccountingWindow::show);
    this->close();
    paymentTableWindow->setWindowTitle("Учёт оплаты");
    paymentTableWindow->show();
}

