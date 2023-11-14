#ifndef METHODFIXEDTARIFFS_H
#define METHODFIXEDTARIFFS_H

#include <QDialog>
#include <QMessageBox>
#include <QString>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>

#include "calculations.h"

namespace Ui {
class MethodFixedTariffs;
}

class MethodFixedTariffs : public QDialog
{
    Q_OBJECT

public:
    explicit MethodFixedTariffs(QWidget *parent = nullptr);
    ~MethodFixedTariffs();

signals:
    void toChoiceWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MethodFixedTariffs *ui;

    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // METHODFIXEDTARIFFS_H
