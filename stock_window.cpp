#include "stock_window.h"
#include "ui_stock_window.h"
#include "setup_window.h"
#include "QStandardItem"
#include "QStandardItemModel"
#include "mainwindow.h"
#include "dialogorderingrid.h"

vector<int> count_of_ingridients;

Stock_window::Stock_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stock_window)
{
    ui->setupUi(this);
    refresh();
}

Stock_window::~Stock_window()
{
    ui->tableView->reset();
    delete ui;
}

//Обновление данных в таблице
void Stock_window::refresh() {
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList HorHeader;
    QStringList VerHeader;

    HorHeader.append("Наименование");
    HorHeader.append("Стоимость");
    HorHeader.append("Кол-во на складе");
    model->setHorizontalHeaderLabels(HorHeader);

    check_ingrid();
    for (int i = 0; i < all_ingridients.size(); i++) {
        VerHeader.append(QString::fromStdString(std::to_string(i + 1)));
        item = new QStandardItem(all_ingridients[i].name);
        model->setItem(i,0,item);
        item = new QStandardItem(QString::fromStdString(std::to_string(all_ingridients[i].cost)));
        model->setItem(i,1,item);
        item = new QStandardItem(QString::fromStdString(std::to_string(count_of_ingridients[i])));
        model->setItem(i,2,item);
    }

    model -> setVerticalHeaderLabels(VerHeader);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}


//Проверка на то, что ингридиент ещё востребован, то есть есть блюда, в которых он используется
void check_ingrid() {
    vector<Ingridient> copy;
    vector<int> copy_i;

    for (int i = 0; i < all_ingridients.size(); i++) {
        if (all_ingridients[i].set_of_dishes.size() != 0) {
            copy.push_back(all_ingridients[i]);
            copy_i.push_back(count_of_ingridients[i]);
        }
    }
    all_ingridients = copy;
    count_of_ingridients = copy_i;
}

//назад в меню программы
void Stock_window::on_backtomenu_button_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    delete this;
}

void Stock_window::on_order_button_clicked()
{
    DialogOrderIngrid *w = new DialogOrderIngrid;
    w->show();
    delete this;
}
