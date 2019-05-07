#include "correctorderwindow.h"
#include "ui_correctorderwindow.h"
#include <QInputDialog>
#include <QDate>
#include <QtDebug>
#include <QMessageBox>

vector<int> count_dish;
vector<Dish> dishes;
vector<Order> history;

CorrectOrderWindow::CorrectOrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CorrectOrderWindow)
{
    ui->setupUi(this);
    for (const auto& elem: ord.list) {
        bool IsIn = false;
        for (int i = 0; i < dishes.size(); i++) {
            if (elem.name == dishes[i].name) {
                IsIn = true;
                count_dish[i] += 1;
            }
        }
        if (!IsIn) {
            dishes.push_back(elem);
            count_dish.push_back(1);
        }
    }
    refresh();
}

CorrectOrderWindow::~CorrectOrderWindow()
{
    count_dish.clear();
    dishes.clear();
    delete ui;
}

void CorrectOrderWindow::refresh() {
    ui->list_result->clear();
    for (int i = 0; i < dishes.size(); i++) {
        ui->list_result->addItem(dishes[i].name + QString(" (%1)").arg(count_dish[i]));
    }
    int sum = 0;
    for (int i = 0; i < count_dish.size(); i++) {
        sum += dishes[i].count_cost() * count_dish[i];
    }
    ui->result_label->setText(QString("К оплате: %1").arg(sum));
}

void CorrectOrderWindow::on_correct_button_clicked()
{
    bool ok;
    int count_del = QInputDialog::getInt(this, QString("Сколько нужно убрать?"), QString("Сколько?"), 0,0, count_dish[ui->list_result->currentRow()],1,&ok);
    if (ok) {
        count_dish[ui->list_result->currentRow()] -= count_del;
    }
    vector<int> copy;
    vector<Dish> copy_d;
    for (int i = 0; i < count_dish.size(); i++) {
        if (count_dish[i] != 0) {
            copy.push_back(count_dish[i]);
            copy_d.push_back(dishes[i]);
        }
    }
    count_dish = copy;
    dishes = copy_d;
    refresh();
}

void CorrectOrderWindow::on_back_button_clicked()
{
    MakeOrderWindow *win = new MakeOrderWindow;
    win->show();
    delete this;
}

void CorrectOrderWindow::on_accept_button_clicked()
{
    ord.FIO = ui->FIO_line->text();
    QDate date = QDate::currentDate();
    Date curdate(date.day(), date.month(), date.year());
    ord.data = curdate;
    ord.list.clear();
    for (int i = 0; i < count_dish.size(); i++) {
        for (int j = 0; j < count_dish[i]; j++) {
            ord.list.push_back(dishes[i]);
        }
    }
    history.push_back(ord);
    Order clear;
    QMessageBox::StandardButton reply = QMessageBox::information(this,QString("Успешно"),QString("Заказ был успешно оформлен, %1").arg(ord.FIO));
    if (reply == QMessageBox::Ok) {
        ord = clear;
        MainWindow *win = new MainWindow;
        win->show();
        delete this;
    }
}
