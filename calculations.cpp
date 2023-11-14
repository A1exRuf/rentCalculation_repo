#include "calculations.h"

double Calculations::calculateAreaCosts(const QSqlRecord& record)
{
    double totalAreaRate = 10;
    double livingAreaRate = 9;
    double heatingAreaRate = 4;
    double additionalAreaRate = 2;

    double totalArea = record.value("TotalArea").toDouble();
    double livingArea = record.value("LivingArea").toDouble();
    double heatingArea = record.value("HeatedArea").toDouble();
    double additionalArea = record.value("AdditionalArea").toDouble();

    double areaCosts = 0.0;

    if (livingArea > 0) {
        areaCosts += livingArea * livingAreaRate;
    } else if (heatingArea > 0) {
        areaCosts += heatingArea * heatingAreaRate;
    } else if (additionalArea > 0) {
        areaCosts += additionalArea * additionalAreaRate;
    } else {
        areaCosts = totalArea * totalAreaRate;
    }

    return areaCosts;
}

double Calculations::calculateTenantsCosts(const QSqlRecord& record)
{
    double registeredResidentsRate = 100;
    double temporaryResidentsRate = 50;

    int registeredResidents = record.value("RegisteredResidents").toInt();
    int temporaryResidents = record.value("TemporaryResidents").toInt();

    double residentsCosts = 0.0;

    residentsCosts += registeredResidents * registeredResidentsRate;
    residentsCosts += temporaryResidents * temporaryResidentsRate;

    return residentsCosts;
}

double Calculations::calculateFixedRates(const QSqlRecord& record)
{
    double waterRate = 7.5;
    double electricityRate = 3.2;
    double gasRate = 3.9;

    double waterConsumption = record.value("WaterConsumption").toDouble();
    double electricityConsumption = record.value("ElectricityConsumption").toDouble();
    double gasConsumption = record.value("GasConsumption").toDouble();

    double fixedRatesCosts = 0.0;

    fixedRatesCosts += waterConsumption * waterRate;
    fixedRatesCosts += electricityConsumption * electricityRate;
    fixedRatesCosts += gasConsumption * gasRate;

    return fixedRatesCosts;
}

double Calculations::calculateByNormatives(const QSqlRecord& record, QSqlQuery query)
{
    double waterRate = 7.5;
    double solidWasteRate = 24.8;
    double electricityRate = 3.2;
    double gasRate = 3.9;

    double waterConsumption = record.value("WaterConsumption").toDouble();
    double solidWasteConsumption = record.value("VolumeOfWaste").toDouble();
    double gasConsumption = record.value("GasConsumption").toDouble();
    double electricityConsumption = record.value("ElectricityConsumption").toDouble();

    double normativeWater = getNormativeValue("WaterSupply", query);
    double normativeSolidWaste = getNormativeValue("SolidWasteManagement", query);
    double normativeGas = getNormativeValue("GasSupply", query);

    int registeredResidents = record.value("RegisteredResidents").toInt();
    double normativeElectricity = 0;
    switch(registeredResidents)
    {
    case 1:
        normativeElectricity = getNormativeValue("Electricity1people", query);
        break;
    case 2:
        normativeElectricity = getNormativeValue("Electricity2people", query);
        break;
    case 3:
        normativeElectricity = getNormativeValue("Electricity3people", query);
        break;
    case 4:
        normativeElectricity = getNormativeValue("Electricity4people", query);
        break;
    default:
        normativeElectricity = getNormativeValue("Electricity5people", query);
        break;
    }

    double normativeCosts = 0.0;

    if (waterConsumption > normativeWater)
    {
        normativeCosts += (waterConsumption - normativeWater) * waterRate;
    }

    if (solidWasteConsumption > normativeSolidWaste)
    {
        normativeCosts += (solidWasteConsumption - normativeSolidWaste) * solidWasteRate;
    }

    if (gasConsumption > normativeGas)
    {
        normativeCosts += (gasConsumption - normativeGas) * gasRate;
    }

    if (electricityConsumption > normativeElectricity)
    {
        normativeCosts += (electricityConsumption - normativeElectricity) * electricityRate;
    }

    return normativeCosts;
}

double Calculations::getNormativeValue(const QString& service, QSqlQuery query)
{
    query.prepare("SELECT Normative FROM Normatives WHERE Service = :service");
    query.bindValue(":service", service);

    if (query.exec() && query.next())
    {
        return query.value(0).toDouble();
    }

    return 0.0;
}

void Calculations::pushToTable(QWidget* parentWidget ,QSqlQuery query, QString account, double costs)
{
    query.prepare("UPDATE TenantsData SET Payment = ? WHERE PersonalAccount = ?");
    query.bindValue(0, costs);
    query.bindValue(1, account);
    if (!query.exec()) {
        QMessageBox::about(parentWidget, "Операция не была проведена", "Что-то пошло не так");
    }
    QMessageBox::about(parentWidget, "Операция проведена", "Счет составляет: " + QString::number(costs) + " byn" );
}
