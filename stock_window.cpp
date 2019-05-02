#include "stock_window.h"
#include "ui_stock_window.h"
#include "setup_window.h"
#include "QStandardItem"
#include "QStandardItemModel"

vector<int> count_of_ingridients;

Stock_window::Stock_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stock_window)
{
    ui->setupUi(this);
    count_of_ingridients.reserve(all_ingridients.size());
    for (int i = 0; i < count_of_ingridients.size(); i++) {
        count_of_ingridients[i] = 0;
    }
    refresh();
}

Stock_window::~Stock_window()
{
    delete ui;
}


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

void check_ingrid() {
    vector<Ingridient> copy;
    for (auto i = all_ingridients.begin(); i != all_ingridients.end(); i++) {
        if (i->set_of_dishes.size() != 0) {
            copy.push_back(*i);
        }
    }
    all_ingridients = copy;
}
