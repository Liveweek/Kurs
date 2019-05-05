#include "makeorderwindow.h"
#include "ui_makeorderwindow.h"

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

//Добавление блюда в заказ (" в Корзину ") ====== каким-то чудом не работает
void MakeOrderWindow::on_add_button_clicked()
{
    ord.list.push_back(list_of_dishes[ui->dishes->currentRow()]);
    ord.set_result();
    result_refresh();
}

//КОНСТРУКТОРЫ и МЕТОДЫ класса ORDER
//По умочанию
Order::Order() {
    FIO = "";
    set_result();
    data = "01/02/2001";
}

//С параметрами (который будет использоваться повсеместно)
Order::Order(QString fio, QString data, vector<Dish> l) {
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
