#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include "calculationmethodchoicewindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

signals:
    void toLoginWindow();

private slots:
    void on_pushButton_toLogin_clicked();

    void on_pushButton_toRenctCalculation_clicked();

private:
    Ui::MenuWindow *ui;
    CalculationMethodChoiceWindow *calculationMethodChoiceWindow;
};

#endif // MENUWINDOW_H
