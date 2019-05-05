#include "dialogorderingrid.h"
#include "ui_dialogorderingrid.h"
#include "setup_window.h"
#include "stock_window.h"


DialogOrderIngrid::DialogOrderIngrid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOrderIngrid)
{
    ui->setupUi(this);
    for (const auto& elem: all_ingridients) {
        ui->ingrid_list->addItem(elem.name);
    }
}

DialogOrderIngrid::~DialogOrderIngrid()
{
    ui->ingrid_list->clear();
    delete ui;
}

void DialogOrderIngrid::on_buttonBox_accepted()
{
    int currentIndex = ui->ingrid_list->currentIndex();
    count_of_ingridients[currentIndex] += ui->count_box->value();
    delete this;
    Stock_window *w = new Stock_window;
    w->show();
}
