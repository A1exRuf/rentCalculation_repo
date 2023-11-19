#ifndef PAYMENTACCOUNTINGWINDOW_H
#define PAYMENTACCOUNTINGWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QVariant>
#include <QComboBox>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>

#include "paymenttablewindow.h"

namespace Ui {
class PaymentAccountingWindow;
}

class PaymentAccountingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentAccountingWindow(QWidget *parent = nullptr);
    ~PaymentAccountingWindow();

signals:
    void toMenuWindow();

private slots:
    void on_pushButton_toMenu_clicked();

    void on_pushButton_checkPayment_clicked();

    void on_pushButton_toTable_clicked();

private:
    Ui::PaymentAccountingWindow *ui;
    PaymentTableWindow *paymentTableWindow;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // PAYMENTACCOUNTINGWINDOW_H
