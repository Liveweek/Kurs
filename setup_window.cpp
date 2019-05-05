#include "setup_window.h"
#include "ui_setup_window.h"
#include "mainwindow.h"
#include "create_editdish.h"
#include <QDebug>
#include <QMessageBox>

vector <Dish>list_of_dishes;
int currentRowNumber = -1;

setup_window::setup_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setup_window)
{
    ui->setupUi(this);
    refresh();
}

setup_window::~setup_window()
{
    delete ui;
};

//ОПИСАНИЕ ФУНКЦИЙ И КОНСТРУКТОРОВ КЛАССА DISH
//конструктор класса блюда по умолчанию
Dish::Dish() {
    name = "Название блюда";
    about = "Описание блюда";
    cost = 0;
};

//конструктор класса с параметрами
Dish::Dish(QString name, QString about, vector<Ingridient> list) {
    this->name = name;
    this->about = about;
    this->list = list;
    cost = count_cost();
};

//подсчёт себестоимости
int Dish::count_cost() {
    int result = 0;
    for (const auto &elem: list) {
        result += elem.cost;
    }
    return result;
};

//###############################################


//СОБЫТИЯ В ИНТЕРФЕЙСЕ ОКНА SETUP_WINDOW
//возврат на окно главного меню
void setup_window::on_backtomenu_button_clicked()
{
    MainWindow *win= new MainWindow;
    win->show();
    delete this;
    currentRowNumber = -1;
};

//создание нового блюда
void setup_window::on_create_button_clicked()
{
    Dish newDish;
    list_of_dishes.push_back(newDish);
    refresh();
};

//редактирование выбранного блюда
void setup_window::on_edit_button_clicked()
{
    Create_editDish* w = new Create_editDish;
    w->show();
    delete this;
}

//событие удаления блюда
void setup_window::on_delete_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,QString::fromUtf8("Вопрос"), QString::fromUtf8("Вы действительно хотите удалить это блюдо из списка?"), QMessageBox::No | QMessageBox::Yes);
    if (reply == QMessageBox::Yes) {
        for (auto i = list_of_dishes[currentRowNumber].list.begin(); i != list_of_dishes[currentRowNumber].list.end(); i++) {
            i->set_of_dishes.erase(list_of_dishes[currentRowNumber].name);
            for (int k = 0; k < all_ingridients.size(); k++) {
                if (i->name == all_ingridients[k].name) {
                    all_ingridients[k].set_of_dishes.erase(list_of_dishes[currentRowNumber].name);
                }
            }
        }
        list_of_dishes.erase(list_of_dishes.begin() + currentRowNumber);
        refresh();
    }
}

//обновление списка после каждого действия
void setup_window::refresh() {
    setup_window::ui->dish_list->clear();
    for (const auto& elem: list_of_dishes) {
        setup_window::ui->dish_list->addItem(elem.name);
    }
    ui->edit_button->setEnabled(false);
    currentRowNumber = -1;
}

//событие изменения номера выбранного элемента списка
void setup_window::on_dish_list_currentRowChanged(int currentRow)
{
    ui->dish_list->setCurrentRow(currentRow);
    currentRowNumber = currentRow;
    ui->edit_button->setEnabled(true);
}

//###########################################
