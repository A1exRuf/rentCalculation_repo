#include "methodtenantcount.h"
#include "ui_methodtenantcount.h"
#include "calculations.h"

MethodTenantCount::MethodTenantCount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodTenantCount)
{
    ui->setupUi(this);

    QSqlQueryModel *comboBoxModel = new QSqlQueryModel(this);
    comboBoxModel->setQuery("SELECT PersonalAccount FROM TenantsData", db);
    ui->comboBox_selectRow->setModel(comboBoxModel);
}

MethodTenantCount::~MethodTenantCount()
{
    delete ui;
}

void MethodTenantCount::on_pushButton_calculate_clicked()
{
    QString account = ui->comboBox_selectRow->currentText();

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
    }
}


void MethodTenantCount::on_pushButton_toChoiceWin_clicked()
{
    hide();
    emit toChoiceWindow();
}

