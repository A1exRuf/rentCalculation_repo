#ifndef METHODAREAWINDOW_H
#define METHODAREAWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QComboBox>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>


#include "calculations.h"

namespace Ui {
class MethodAreaWindow;
}

class MethodAreaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MethodAreaWindow(QWidget *parent = nullptr);
    ~MethodAreaWindow();

signals:
    void toChoiceWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MethodAreaWindow *ui;

    QSqlDatabase db;
};

#endif // METHODAREAWINDOW_H
