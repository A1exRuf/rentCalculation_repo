#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>

class dbmanager
{
public:
    dbmanager();
private:
    QSqlDatabase rent_db;
};

#endif // DBMANAGER_H
