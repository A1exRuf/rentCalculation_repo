#include "methodnormatives.h"
#include "ui_methodnormatives.h"

MethodNormatives::MethodNormatives(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MethodNormatives)
{
    ui->setupUi(this);

    QSqlQueryModel *comboBoxModel = new QSqlQueryModel(this);
    comboBoxModel->setQuery("SELECT PersonalAccount FROM TenantsData", db);
    ui->comboBox_selectRow->setModel(comboBoxModel);
}

MethodNormatives::~MethodNormatives()
{
    delete ui;
}

void MethodNormatives::on_pushButton_calculate_clicked()
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
        double normativesCosts = Calculations::calculateByNormatives(record, query);
        if (normativesCosts != -1)
        {
            Calculations::pushToTable(this, query, account, normativesCosts);
        }
        else
        {
            QMessageBox::about(this, "Ошибка", "Данное лицо не имеет соответствущей льготы");
        }
    }
}


void MethodNormatives::on_pushButton_toChoice_clicked()
{
    hide();
    emit toChoiceWindow();
}

