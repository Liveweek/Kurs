#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setup_window.h"
#include "stock_window.h"
#include "makeorderwindow.h"
#include "dialoghistorywindow.h"
#include "filework.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FileWork::loadFromFiles();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setup_button_clicked()
{
    setup_window *win=new setup_window;
    win->show();
    this->hide();
    currentRowNumber = -1;
}

void MainWindow::on_products_button_clicked()
{
    Stock_window *win = new Stock_window;
    win->show();
    this->hide();
}

void MainWindow::on_task_button_clicked()
{
    MakeOrderWindow *win = new MakeOrderWindow;
    win->show();
    this->hide();
}

void MainWindow::on_history_button_clicked()
{
    DialogHistoryWindow *win = new DialogHistoryWindow;
    win->show();
    this->hide();
}
