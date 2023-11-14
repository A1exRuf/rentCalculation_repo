#include "methodtenantcount.h"
#include "ui_methodtenantcount.h"

MethodTenantCount::MethodTenantCount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodTenantCount)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("TenantsData");
}

MethodTenantCount::~MethodTenantCount()
{
    delete ui;
}

void MethodTenantCount::on_pushButton_calculate_clicked()
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
        double tenantsCosts = Calculations::calculateTenantsCosts(record);
        Calculations::pushToTable(this, query, account, tenantsCosts);
    } else {
        qDebug() << "Счёт не существует";
    }
}


void MethodTenantCount::on_pushButton_toChoiceWin_clicked()
{
    hide();
    emit toChoiceWindow();
}

