#include "dialoghistorywundow.h"
#include "ui_dialoghistorywundow.h"

DialogHistoryWundow::DialogHistoryWundow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistoryWundow)
{
    ui->setupUi(this);
}

DialogHistoryWundow::~DialogHistoryWundow()
{
    delete ui;
}
