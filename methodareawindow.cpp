#include "methodareawindow.h"
#include "ui_methodareawindow.h"

MethodAreaWindow::MethodAreaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodAreaWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("TenantsData");
}

MethodAreaWindow::~MethodAreaWindow()
{
    delete ui;
}

void MethodAreaWindow::on_pushButton_clicked()
{
    hide();
    emit toChoiceWindow();
}

void MethodAreaWindow::on_pushButton_2_clicked()
{
    QString account = ui->lineEdit_selectRow->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM TenantsData WHERE PersonalAccount = ?");
    query.bindValue(0, account);
    if (!query.exec()) {
        qDebug() << "Failed to execute query";
        return;
    }

    if (query.next()) {
        QSqlRecord record = query.record();
        double areaCosts = Calculations::calculateAreaCosts(record);
        Calculations::pushToTable(this, query, account, areaCosts);
    } else {
        qDebug() << "Счёт не существует";
    }
}

