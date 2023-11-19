#include "methodmeteringdevices.h"
#include "ui_methodmeteringdevices.h"

MethodMeteringDevices::MethodMeteringDevices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodMeteringDevices)
{
    ui->setupUi(this);

    QSqlQueryModel *comboBoxModel = new QSqlQueryModel(this);
    comboBoxModel->setQuery("SELECT PersonalAccount FROM TenantsData", db);
    ui->comboBox_selectRow->setModel(comboBoxModel);
}

MethodMeteringDevices::~MethodMeteringDevices()
{
    delete ui;
}

void MethodMeteringDevices::on_pushButton_calculate_clicked()
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
        double fixedCosts = Calculations::calculateFixedRates(record);
        Calculations::pushToTable(this, query, account, fixedCosts);
    }
}

void MethodMeteringDevices::on_pushButton_toChoice_clicked()
{
    this->close();
    emit toChoiceWindow();
}

