#include "usersettingwindow.h"
#include "ui_usersettingwindow.h"

UserSettingWindow::UserSettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettingWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("UsersList");
    model->select();
    ui->tableView->setModel(model);
}

UserSettingWindow::~UserSettingWindow()
{
    delete ui;
}

void UserSettingWindow::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

void UserSettingWindow::on_pushButton_add_clicked()
{
    model->insertRow(model->rowCount());
}

void UserSettingWindow::on_pushButton_remove_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Вы уверены?", "Вы уверены, что хотите удалить пользователя?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        model->removeRow(currentRow);
        model->select();
    }
}

void UserSettingWindow::on_pushButton_idSort_clicked()
{
    model->setSort(0, Qt::AscendingOrder);
    model->select();
}

void UserSettingWindow::on_pushButton_loginSort_clicked()
{
    model->setSort(1, Qt::AscendingOrder);
    model->select();
}

void UserSettingWindow::on_pushButton_roleSort_clicked()
{
    model->setSort(2, Qt::AscendingOrder);
    model->select();
}

void UserSettingWindow::on_pushButton_setAdmin_clicked()
{
    model->setData(model->index(currentRow, 3), "admin");
    model->submitAll();
    model->select();
}

void UserSettingWindow::on_pushButton_setUser_clicked()
{
    model->setData(model->index(currentRow, 3), "user");
    model->submitAll();
    model->select();
}

void UserSettingWindow::on_pushButton_toMenu_clicked()
{
    this->close();
    emit toMenuWindow();
}
