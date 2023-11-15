#include "paymenttablewindow.h"
#include "ui_paymenttablewindow.h"

PaymentTableWindow::PaymentTableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentTableWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("TenantsData");
    model->select();
    ui->tableView->setModel(model);
}

PaymentTableWindow::~PaymentTableWindow()
{
    delete ui;
}

void PaymentTableWindow::on_pushButton_add_clicked()
{
    model->insertRow(model->rowCount());
}


void PaymentTableWindow::on_pushButton_delete_clicked()
{
    model->removeRow(currentRow);
    model->select();
}

void PaymentTableWindow::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

void PaymentTableWindow::on_pushButton_sortByPayment_clicked()
{
    model->setSort(12, Qt::AscendingOrder);
    model->select();
}


void PaymentTableWindow::on_pushButton_sortByAccount_clicked()
{
    model->setSort(0, Qt::AscendingOrder);
    model->select();
}

void PaymentTableWindow::on_pushButton_toPaymentAccounting_clicked()
{
    this->close();
    emit toPaymentAccounting();
}

