#ifndef PAYMENTTABLEWINDOW_H
#define PAYMENTTABLEWINDOW_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class PaymentTableWindow;
}

class PaymentTableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentTableWindow(QWidget *parent = nullptr);
    ~PaymentTableWindow();

signals:
    void toPaymentAccounting();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_toPaymentAccounting_clicked();

    void on_pushButton_sortByPayment_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_sortByAccount_clicked();

private:
    Ui::PaymentTableWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
};

#endif // PAYMENTTABLEWINDOW_H
