#include "normativesettingwindow.h"
#include "ui_normativesettingwindow.h"

NormativeSettingWindow::NormativeSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormativeSettingWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("Normatives");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 320);
    ui->tableView->setColumnWidth(1, 80);
    ui->tableView->setColumnWidth(2, 130);
}

NormativeSettingWindow::~NormativeSettingWindow()
{
    delete ui;
}

void NormativeSettingWindow::on_pushButton_toMenu_clicked()
{
    this->hide();
    emit toMenuWindow();
}
