#include "historyrequestwindow.h"
#include "ui_historyrequestwindow.h"
#include <QtDebug>

HistoryRequestWindow::HistoryRequestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HistoryRequestWindow)
{
    ui->setupUi(this);
    ui->listOrders->clear();
    for (int i = 0; i < request.size(); i++) {
        ui->listOrders->addItem(request[i].FIO + QString("(%1)").arg(request[i].result));
    }
    ui->listOrders->setCurrentRow(0);
    refresh();
}

void HistoryRequestWindow::refresh() {
    int curRow = ui->listOrders->currentRow();
    ui->FIO_label->setText(QString("ФИО: ") + request[curRow].FIO);
    ui->Date_label->setText(QString("Дата: ") + request[curRow].data.format_date());
    ui->result_label->setText(QString("Итого: %1").arg(request[curRow].result));
    ui->listDishes->clear();
    for (const auto& elem : request[curRow].list) {
        ui->listDishes->addItem(elem.name);
    }
}

HistoryRequestWindow::~HistoryRequestWindow()
{
    delete ui;
}

void HistoryRequestWindow::on_listOrders_currentRowChanged(int currentRow)
{
    refresh();
}

void HistoryRequestWindow::on_back_to_menu_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    delete this;
}
