#include "makeorderwindow.h"
#include "ui_makeorderwindow.h"
#include "correctorderwindow.h"

Order ord;

MakeOrderWindow::MakeOrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MakeOrderWindow)
{
    ui->setupUi(this);
    for (const auto& elem : list_of_dishes) {
        ui->dishes->addItem(elem.name);
    }
    ui->dishes->setCurrentRow(0);
    ui->result_label->setText(QString::fromStdString("Итого: 0"));
}

MakeOrderWindow::~MakeOrderWindow()
{
    delete ui;
}


//Обновление Названия, описания и цены блюда
void MakeOrderWindow::refresh() {
    Dish currentDish = list_of_dishes[ui->dishes->currentRow()];
    ui->name_label->setText(QString::fromStdString("Название: ") + currentDish.name);
    ui->textBrowser->setText(currentDish.about);
    ui->Cost_label->setText(QString::fromStdString("Цена: " + std::to_string(currentDish.count_cost())));
}

//Обновление итого и подписи на кнопке "Корзины" ====== что-то происходит с обновлением корзины (циклы ничего не изменили)
void MakeOrderWindow::result_refresh() {
    ui->result_label->setText(QString("Итого: %1").arg(ord.result));
    ui->basket_button->setText(QString("Корзина(%1)").arg(ord.list.size()));
}

//событие смены выбранного элемента
void MakeOrderWindow::on_dishes_currentRowChanged(int currentRow)
{
    refresh();
}

//Добавление блюда в заказ (" в Корзину ")
void MakeOrderWindow::on_add_button_clicked()
{
    ord.list.push_back(list_of_dishes[ui->dishes->currentRow()]);
    ord.set_result();
    result_refresh();
}

void MakeOrderWindow::on_basket_button_clicked()
{
    CorrectOrderWindow *win = new CorrectOrderWindow;
    win->show();
    delete this;
}

//КОНСТРУКТОРЫ, МЕТОДЫ И СТАТИЧЕСКИЕ ФУНКЦИИ класса DATA
//Конструктор по умолчанию
Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

//Коструктор с параметрами
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

QString Date::format_date() {
    return QString("%1%2/%3%4/%5").arg(day / 10, day % 10, month / 10, month % 10, year);
}

//Перегрузка оператора присваивания
Date& Date::operator= (Date &arg) {
    day = arg.day;
    month = arg.month;
    year = arg.year;
    return *this;
}


//КОНСТРУКТОРЫ и МЕТОДЫ класса ORDER
//По умочанию
Order::Order() {
    FIO = "";
    set_result();
    Date dat(1,1,2001);
    data = dat;
}

//С параметрами (который будет использоваться повсеместно)
Order::Order(QString fio, Date data, vector<Dish> l) {
    FIO = fio;
    this->data = data;
    list = l;
    set_result();
}

//Метод за заполнения Итоговой суммы не основе блюд, находящихся в поле list
void Order::set_result() {
    int summ = 0;
    for (int i = 0; i < this->list.size(); i++) {
        summ += this->list[i].count_cost();
    }
    result = summ;
}

//Перегрузка оператора равенства для заказов
Order& Order::operator= (Order& arg) {
    this->FIO = arg.FIO;
    this->list = arg.list;
    this->number_of_dishes = arg.number_of_dishes;
    this->data = arg.data;
    this->set_result();
    return *this;
}

