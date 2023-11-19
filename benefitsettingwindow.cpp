#include "benefitsettingwindow.h"
#include "ui_benefitsettingwindow.h"

BenefitSettingWindow::BenefitSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BenefitSettingWindow)
{
    ui->setupUi(this);

    QSqlQueryModel *comboBoxModel1 = new QSqlQueryModel(this);
    comboBoxModel1->setQuery("SELECT PersonalAccount FROM TenantsData", db);
    ui->comboBox_PersonalAccount->setModel(comboBoxModel1);

    QSqlQueryModel *comboBoxModel2 = new QSqlQueryModel(this);
    comboBoxModel2->setQuery("SELECT Individual FROM TenantsData", db);
    ui->comboBox_Individual->setModel(comboBoxModel2);
}

BenefitSettingWindow::~BenefitSettingWindow()
{
    delete ui;
}

void BenefitSettingWindow::on_pushButton_accountComplite_clicked()
{
    QString selectedValue = ui->comboBox_PersonalAccount->currentText();
    QSqlQuery query;
    query.prepare("UPDATE TenantsData SET Benefits = 'Полная' WHERE PersonalAccount = :selectedValue");
    query.bindValue(":selectedValue", selectedValue);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_accountPartial_clicked()
{
    QString selectedValue = ui->comboBox_PersonalAccount->currentText();
    QSqlQuery query;
    query.prepare("UPDATE TenantsData SET Benefits = 'Частичная' WHERE PersonalAccount = :selectedValue");
    query.bindValue(":selectedValue", selectedValue);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_accountDelete_clicked()
{
    QString selectedValue = ui->comboBox_PersonalAccount->currentText();
    QSqlQuery query;
    query.prepare("UPDATE TenantsData SET Benefits = 'Нет' WHERE PersonalAccount = :selectedValue");
    query.bindValue(":selectedValue", selectedValue);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_individualComplite_clicked()
{
    QString selectedValue = ui->comboBox_Individual->currentText();
    QSqlQuery query;
    query.prepare("UPDATE TenantsData SET Benefits = 'Полная' WHERE Individual = :selectedValue");
    query.bindValue(":selectedValue", selectedValue);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_individualPartial_clicked()
{
    QString selectedValue = ui->comboBox_Individual->currentText();
    QSqlQuery query;
    query.prepare("UPDATE TenantsData SET Benefits = 'Частичная' WHERE Individual = :selectedValue");
    query.bindValue(":selectedValue", selectedValue);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_individualDelete_clicked()
{
    QString selectedValue = ui->comboBox_Individual->currentText();
    QSqlQuery query;
    query.prepare("UPDATE TenantsData SET Benefits = 'Нет' WHERE Individual = :selectedValue");
    query.bindValue(":selectedValue", selectedValue);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_discountChange_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE Benefits SET discount = :newDiscount WHERE type = 'partial'");
    int newDiscount = ui->lineEdit_discount->text().toInt();
    query.bindValue(":newDiscount", newDiscount);
    query.exec();
}


void BenefitSettingWindow::on_pushButton_toMenu_clicked()
{
    this->close();
    emit toMenuWindow();
}

