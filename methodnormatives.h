#ifndef METHODNORMATIVES_H
#define METHODNORMATIVES_H

#include <QDialog>
#include <QMessageBox>
#include <QString>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>

#include "calculations.h"

namespace Ui {
class MethodNormatives;
}

class MethodNormatives : public QDialog
{
    Q_OBJECT

public:
    explicit MethodNormatives(QWidget *parent = nullptr);
    ~MethodNormatives();

signals:
    void toChoiceWindow();

private slots:
    void on_pushButton_calculate_clicked();

    void on_pushButton_toChoice_clicked();

private:
    Ui::MethodNormatives *ui;

    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // METHODNORMATIVES_H
