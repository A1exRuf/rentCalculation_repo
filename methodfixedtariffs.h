#ifndef METHODFIXEDTARIFFS_H
#define METHODFIXEDTARIFFS_H

#include <QDialog>
#include <QString>
#include <QComboBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

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
    void on_pushButton_setTariff_clicked();

    void on_pushButton_clicked();

private:
    Ui::MethodFixedTariffs *ui;

    QSqlDatabase db;
};

#endif // METHODFIXEDTARIFFS_H
