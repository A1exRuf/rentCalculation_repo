#include "methodnormatives.h"
#include "ui_methodnormatives.h"

MethodNormatives::MethodNormatives(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodNormatives)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("TenantsData");
}

MethodNormatives::~MethodNormatives()
{
    delete ui;
}

void MethodNormatives::on_pushButton_calculate_clicked()
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
        double normativesCosts = Calculations::calculateByNormatives(record, query);
        Calculations::pushToTable(this, query, account, normativesCosts);
    } else {
        qDebug() << "Счёт не существует";
    }
}


void MethodNormatives::on_pushButton_toChoice_clicked()
{
    hide();
    emit toChoiceWindow();
}

