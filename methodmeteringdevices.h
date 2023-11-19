#ifndef METHODMETERINGDEVICES_H
#define METHODMETERINGDEVICES_H

#include <QDialog>
#include <QString>
#include <QComboBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

namespace Ui {
class MethodMeteringDevices;
}

class MethodMeteringDevices : public QDialog
{
    Q_OBJECT

public:
    explicit MethodMeteringDevices(QWidget *parent = nullptr);
    ~MethodMeteringDevices();

signals:
    void toChoiceWindow();

private slots:
    void on_pushButton_calculate_clicked();

    void on_pushButton_toChoice_clicked();

private:
    Ui::MethodMeteringDevices *ui;

    QSqlDatabase db;
};

#endif // METHODMETERINGDEVICES_H
