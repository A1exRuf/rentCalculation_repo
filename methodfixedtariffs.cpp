#include "methodfixedtariffs.h"
#include "ui_methodfixedtariffs.h"
#include "calculations.h"

MethodFixedTariffs::MethodFixedTariffs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodFixedTariffs)
{
    ui->setupUi(this);

    QSqlQueryModel *comboBoxModel = new QSqlQueryModel(this);
    comboBoxModel->setQuery("SELECT PersonalAccount FROM TenantsData", db);
    ui->comboBox_selectRow->setModel(comboBoxModel);
}

MethodFixedTariffs::~MethodFixedTariffs()
{
    delete ui;
}

void MethodFixedTariffs::on_pushButton_setTariff_clicked()
{
    QString account = ui->comboBox_selectRow->currentText();
    QString tariffText = ui->lineEdit_tariff->text();

    bool ok;
    double tariff = tariffText.toDouble(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Ошибка", "Введена неверная сумма");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM TenantsData WHERE PersonalAccount = ?");
    query.bindValue(0, account);
    if (!query.exec()) {
        qDebug() << "Failed to execute query";
        return;
    }

    if (query.next()) {
        QSqlRecord record = query.record();
        Calculations::pushToTable(this, query, account, tariff);
    }
}


void MethodFixedTariffs::on_pushButton_clicked()
{
    hide();
    emit toChoiceWindow();
}

