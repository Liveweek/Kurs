#ifndef STOCK_WINDOW_H
#define STOCK_WINDOW_H

#include <QMainWindow>
#include <vector>

using namespace std;

extern vector<int> count_of_ingridients;

void check_ingrid();

namespace Ui {
class Stock_window;
}

class Stock_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stock_window(QWidget *parent = nullptr);
    ~Stock_window();
    void refresh();

private slots:
    void on_backtomenu_button_clicked();

    void on_order_button_clicked();

private:
    Ui::Stock_window *ui;
};

#endif // STOCK_WINDOW_H
