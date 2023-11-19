#ifndef BENEFITSETTINGWINDOW_H
#define BENEFITSETTINGWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QComboBox>
#include <QVariant>

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

namespace Ui {
class BenefitSettingWindow;
}

class BenefitSettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BenefitSettingWindow(QWidget *parent = nullptr);
    ~BenefitSettingWindow();

signals:
    void toMenuWindow();

private slots:
    void on_pushButton_accountComplite_clicked();

    void on_pushButton_accountPartial_clicked();

    void on_pushButton_accountDelete_clicked();

    void on_pushButton_individualComplite_clicked();

    void on_pushButton_individualPartial_clicked();

    void on_pushButton_individualDelete_clicked();

    void on_pushButton_discountChange_clicked();

    void on_pushButton_toMenu_clicked();

private:
    Ui::BenefitSettingWindow *ui;

    QSqlDatabase db;
};

#endif // BENEFITSETTINGWINDOW_H
