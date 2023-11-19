#ifndef METHODTENANTCOUNT_H
#define METHODTENANTCOUNT_H

#include <QDialog>
#include <QString>
#include <QComboBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

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
};

#endif // METHODTENANTCOUNT_H
