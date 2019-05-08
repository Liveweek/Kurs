#ifndef CORRECTORDERWINDOW_H
#define CORRECTORDERWINDOW_H

#include <QMainWindow>
#include <vector>
#include "makeorderwindow.h"
#include "mainwindow.h"


namespace Ui {
class CorrectOrderWindow;
}

class CorrectOrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CorrectOrderWindow(QWidget *parent = nullptr);
    ~CorrectOrderWindow();
     void refresh();

private slots:
     void on_correct_button_clicked();

     void on_back_button_clicked();

     void on_accept_button_clicked();

private:
    Ui::CorrectOrderWindow *ui;
};

//Класс даты, будет записываться на момент нажатия подтверждения заказа в реальном времени
class Date {
private:
    int day;
    int month;
    int year;
public:
    QString format_date();
    int get_day();
    int get_month();
    int get_year();
    Date();
    Date(int d, int m, int y);
    Date& operator= (Date& arg);
    static int isCorrect(Date arg1, Date arg2);
};

//Класс заказа
class Order {
private:
    vector<int> number_of_dishes;//запоминает индексы блюд из общего списка
public:
    QString FIO;//ФИО заказчика
    int result;//итоговая сумма
    Date data;//дата заказа
    vector<Dish> list;
    Order();
    Order(QString fio, Date data, vector<Dish> l);
    void set_result();
    Order& operator=(Order& arg);
};

extern Order ord;
extern vector<Order> history;
extern vector<Order> request;


#endif // CORRECTORDERWINDOW_H
