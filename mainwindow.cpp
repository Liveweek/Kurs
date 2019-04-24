#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setup_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
