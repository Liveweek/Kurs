#include "create_editdish.h"
#include "setup_window.h"
#include "ui_create_editdish.h"
#include "stock_window.h"
#include <string>
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>
#include <QtDebug>

//глобальные переменные проекта
vector<Ingridient> all_ingridients;
Dish edit;

//конструктор окна
Create_editDish::Create_editDish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Create_editDish)
{
    ui->setupUi(this);
    edit = list_of_dishes[currentRowNumber];
    ui->nameField->setText(list_of_dishes[currentRowNumber].name);
    ui->aboutField->setText(list_of_dishes[currentRowNumber].about);
    refresh();
}

Create_editDish::~Create_editDish()
{
    delete ui;
}

//обновление значений на странице ====== РАБОТАЕТ (вроде)
void Create_editDish::refresh() {
    ui->money_label->setText(QString::fromStdString("Себестоимость: " + std::to_string(edit.count_cost())));
    ui->ingridients_list->clear();
    for (const auto& elem : edit.list) {
        ui->ingridients_list->addItem(elem.name);
    }
//    ui->delete_button->setEnabled(!(ui->ingridients_list->currentRow() == -1));
}

//кнопка отмены = закрытие окна ====== РАБОТАЕТ
void Create_editDish::on_cancel_button_clicked()
{
    setup_window* win = new setup_window;
    Dish reset;
    edit = reset;
    delete this;
    win->show();
}

//кнопка сохранения -> передача этих данных в вектор и обновление предыдущего окна ====== РАБОТАЕТ
void Create_editDish::on_save_button_clicked()
{
    edit.name = ui->nameField->text();
    edit.about = ui->aboutField->toPlainText();
    for (int i = 0; i < edit.list.size(); i++) {
        bool isIn = false;
        for (int j = 0; j < all_ingridients.size(); j++) {
            if (edit.list[i].name == all_ingridients[j].name) {
                all_ingridients[j].set_of_dishes.insert(edit.name);
                isIn = true;
                break;
            }
        }
        if (!isIn) {
            edit.list[i].set_of_dishes.insert(edit.name);
            all_ingridients.push_back(edit.list[i]);
            count_of_ingridients.push_back(0);
        }
    }
    list_of_dishes[currentRowNumber] = edit;
    setup_window* w = new setup_window;
    w->show();
    delete this;
}

//добавления нового ингридиента в список ====== РАБОТАЕТ
void Create_editDish::on_add_button_clicked()
{
    bool ok; //проверка нажатия кнопки ОК
    bool need_add;//флаг, на основании которого мы будем добавлять новый ингридиент в список или нет
    Ingridient input;
    QString some_ingridient = QInputDialog::getText(this, QString::fromStdString("Введите название ингридиента"), QString::fromStdString("Название: "), QLineEdit::Normal, QDir::home().dirName(), &ok);
    if (ok && !some_ingridient.isEmpty()) {
        bool isInAll = false;
        for (const auto& elem : all_ingridients) {
            if (some_ingridient == elem.name) {
                input = elem;
                isInAll = true;
                need_add = true;
            }
        }
        if (!isInAll) {
            ok = false;
            int cost_ingrid = QInputDialog::getInt(this, QString::fromStdString("Введите стоимость блюда"), QString::fromStdString("Стоимость"), 10, 0, 1000, 1, &ok);
            if (ok) {
                input.cost = cost_ingrid;
                input.name = some_ingridient;
                need_add = true;
            }
        }
        if (need_add) {
            edit.list.push_back(input);
        }
    }
    refresh();
}

//удаление этого игридиента из списка ====== РАБОТАЕТ
void Create_editDish::on_delete_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,QString::fromUtf8("Вопрос"), QString::fromUtf8("Вы действительно хотите удалить это блюдо из списка?"), QMessageBox::No | QMessageBox::Yes);
    if (reply == QMessageBox::Yes) {
        edit.list.erase(edit.list.begin() + ui->ingridients_list->currentRow());
        refresh();
    }
}


//смена выбранного элемента
void Create_editDish::on_ingridients_list_currentRowChanged(int currentRow)
{
    ui->ingridients_list->setCurrentRow(currentRow);
    ui->delete_button->setEnabled(true);
}
