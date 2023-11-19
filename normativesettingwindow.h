#ifndef NORMATIVESETTINGWINDOW_H
#define NORMATIVESETTINGWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class NormativeSettingWindow;
}

class NormativeSettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NormativeSettingWindow(QWidget *parent = nullptr);
    ~NormativeSettingWindow();

signals:
    void toMenuWindow();

private slots:
    void on_pushButton_toMenu_clicked();

private:
    Ui::NormativeSettingWindow *ui;

    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // NORMATIVESETTINGWINDOW_H
