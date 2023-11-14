#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>

class Calculations
{
public:
    static double calculateAreaCosts(const QSqlRecord& record);
    static double calculateTenantsCosts(const QSqlRecord& record);
    static double calculateFixedRates(const QSqlRecord& record);
    static double calculateByNormatives(const QSqlRecord& record, QSqlQuery query);

    static void pushToTable(QWidget* parentWidget ,QSqlQuery query, QString account, double costs);
private:
    static double getNormativeValue(const QString& service, QSqlQuery query);
};

#endif // CALCULATIONS_H
