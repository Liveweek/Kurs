#ifndef SETUP_WINDOW_H
#define SETUP_WINDOW_H

#include <QMainWindow>
#include <QString>
#include <vector>
#include <set>

using namespace std;
namespace Ui {
class setup_window;
}

class setup_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit setup_window(QWidget *parent = nullptr);
    ~setup_window();
    void refresh();
private slots:

    void on_backtomenu_button_clicked();

    void on_create_button_clicked();

    void on_dish_list_currentRowChanged(int currentRow);

    void on_delete_button_clicked();

    void on_edit_button_clicked();

private:
    Ui::setup_window *ui;
};


//описание класса игридиент
class Ingridient {
public:
    int cost;//стоимость ингридиента
    QString name;//название ингридиента
    set <QString>set_of_dishes;//множество названий блюд, которые используют данный ингридиент
};

//описание класса блюдо
class Dish {
private:
    int cost;//себестоимость
public:
    QString name;//название блюда
    QString about;//описание блюда
    vector <Ingridient>list;//список ингридиентов
    Dish();//конструктор блюда по-умолчанию
    Dish(QString name, QString about, vector<Ingridient> list);//конструктор с аргументами
    int count_cost();//расчёт себестоимости блюда
};

//ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ, КОТОРЫЕ БУДУТ ПРИМЕНЯТЬСЯ ВЕЗДЕ
extern vector<Dish> list_of_dishes;
extern int currentRowNumber;
extern vector<Ingridient> all_ingridients;

#endif // SETUP_WINDOW_H
