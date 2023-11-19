#ifndef CALCULATIONMETHODCHOICEWINDOW_H
#define CALCULATIONMETHODCHOICEWINDOW_H

#include <QDialog>

#include "methodareawindow.h"
#include "methodtenantcount.h"
#include "methodfixedtariffs.h"
#include "methodnormatives.h"
#include "methodmeteringdevices.h"

namespace Ui {
class CalculationMethodChoiceWindow;
}

class CalculationMethodChoiceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalculationMethodChoiceWindow(QWidget *parent = nullptr);
    ~CalculationMethodChoiceWindow();

signals:
    void toMenuWindow();

private slots:
    void on_pushButton_toMenu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_meteringDevices_clicked();

private:
    Ui::CalculationMethodChoiceWindow *ui;
    MethodAreaWindow *methodAreaWindow;
    MethodTenantCount *methodTenantCount;
    MethodFixedTariffs *methodFixedTariffs;
    MethodNormatives *methodNormatives;
    MethodMeteringDevices *methodMeteringDevices;
};

#endif // CALCULATIONMETHODCHOICEWINDOW_H
