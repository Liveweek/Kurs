#ifndef MAKEORDERWINDOW_H
#define MAKEORDERWINDOW_H

#include <QMainWindow>
#include <vector>
#include "setup_window.h"
#include "stock_window.h"


namespace Ui {
class MakeOrderWindow;
}

class MakeOrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MakeOrderWindow(QWidget *parent = nullptr);
    ~MakeOrderWindow();
    void refresh();
    void result_refresh();

private slots:
    void on_dishes_currentRowChanged(int currentRow);

    void on_add_button_clicked();

private:
    Ui::MakeOrderWindow *ui;
};

//Класс заказа
class Order {
private:
    vector<int> number_of_dishes;//запоминает индексы блюд из общего списка
public:
    QString FIO;//ФИО заказчика
    int result;//итоговая сумма
    QString data;//
    vector<Dish> list;
    Order();
    Order(QString fio,QString data, vector<Dish> l);
    void set_result();
};

extern Order ord;

#endif // MAKEORDERWINDOW_H

