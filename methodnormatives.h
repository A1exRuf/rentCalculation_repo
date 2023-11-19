#ifndef METHODNORMATIVES_H
#define METHODNORMATIVES_H

#include <QDialog>
#include <QString>
#include <QComboBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

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
};

#endif // METHODNORMATIVES_H
