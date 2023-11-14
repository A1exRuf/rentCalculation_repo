#ifndef METHODTENANTCOUNT_H
#define METHODTENANTCOUNT_H

#include <QDialog>
#include <QMessageBox>
#include <QString>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>

#include "calculations.h"

namespace Ui {
class MethodTenantCount;
}

class MethodTenantCount : public QDialog
{
    Q_OBJECT

public:
    explicit MethodTenantCount(QWidget *parent = nullptr);
    ~MethodTenantCount();

signals:
    void toChoiceWindow();

private slots:
    void on_pushButton_calculate_clicked();

    void on_pushButton_toChoiceWin_clicked();

private:
    Ui::MethodTenantCount *ui;

    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // METHODTENANTCOUNT_H
