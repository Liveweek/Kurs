#include "correctorderwindow.h"
#include "ui_correctorderwindow.h"

CorrectOrderWindow::CorrectOrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CorrectOrderWindow)
{
    ui->setupUi(this);
}

CorrectOrderWindow::~CorrectOrderWindow()
{
    delete ui;
}
