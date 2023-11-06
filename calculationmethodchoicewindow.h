#ifndef CALCULATIONMETHODCHOICEWINDOW_H
#define CALCULATIONMETHODCHOICEWINDOW_H

#include <QDialog>

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

private:
    Ui::CalculationMethodChoiceWindow *ui;
};

#endif // CALCULATIONMETHODCHOICEWINDOW_H
