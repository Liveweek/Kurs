#include "dialoghistorywindow.h"
#include "ui_dialoghistorywindow.h"
#include <QMessageBox>

vector<Order> request;

DialogHistoryWindow::DialogHistoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistoryWindow)
{
    ui->setupUi(this);
}

DialogHistoryWindow::~DialogHistoryWindow()
{
    delete ui;
}

int Date::isCorrect(Date arg1, Date arg2) {
    int days_in_month_4[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (((arg1.year % 4 == 0) && !(arg1.day <= days_in_month_4[arg1.month - 1])) || !(arg1.day <= days_in_month[arg1.month - 1])) {
        return 1;
    }
    if (((arg2.year % 4 == 0) && !(arg2.day <= days_in_month_4[arg2.month - 1])) || !(arg2.day <= days_in_month[arg2.month - 1])) {
        return 2;
    }
    if (arg1.year > arg2.year) {
        return 3;
    } else if (arg1.year == arg2.year) {
        if (arg1.month > arg2.month) {
            return 3;
        } else if (arg1.month == arg2.month) {
            if (arg1.day > arg2.day) {
                return 3;
            }
        }
    }
    return 0;
}

void DialogHistoryWindow::on_buttonBox_accepted()
{
    Date from(ui->day_from->value(),ui->month_from->value(),ui->year_from->value());
    Date to(ui->day_to->value(),ui->month_to->value(), ui->year_to->value());
    int key = Date::isCorrect(from, to);
    QMessageBox::StandardButton reply;
    bool needOpen = false;
    switch (key) {
    case 0:
        request.clear();
        for (int i = 0; i < history.size(); i++) {
            bool isBigger = true;
            bool isSmaller = true;
            if (history[i].data.get_year() < from.get_year()) {
                isBigger = false;
            } else if (history[i].data.get_year() == from.get_year()) {
                if (history[i].data.get_month() < from.get_month()) {
                    isBigger = false;
                } else if ((history[i].data.get_day() < from.get_day()) && (history[i].data.get_month() == from.get_month())) {
                    isBigger = false;
                }
            }
            if (history[i].data.get_year() > to.get_year()) {
                isSmaller = false;
            } else if (history[i].data.get_year() == to.get_year()) {
                if (history[i].data.get_month() > to.get_month()) {
                    isSmaller = false;
                } else if ((history[i].data.get_day() > to.get_day()) && (history[i].data.get_month() == to.get_month())) {
                    isSmaller = false;
                }
            }
            if (isBigger && isSmaller) {
               request.push_back(history[i]);
            }
        }
        needOpen = true;
        break;
    case 1:
        reply = QMessageBox::information(this,QString("Ошибка!"), QString("Ошибка формирования первой даты. Скорее всего связана с тем, что такой даты не могло существовать."));
        break;
    case 2:
        reply = QMessageBox::information(this,QString("Ошибка!"), QString("Ошибка формирования второй даты. Скорее всего связана с тем, что такой даты не могло существовать."));
        break;
    case 3:
        reply = QMessageBox::information(this,QString("Ошибка!"), QString("Ошибка интервала. Первая дата не может быть больше второй!"));
        break;
    }
    if (needOpen) {
        HistoryRequestWindow *win = new HistoryRequestWindow;
        win->show();
        delete this;
    } else {
        MainWindow *win = new MainWindow;
        win->show();
        delete this;
    }
}
