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

    void on_basket_button_clicked();

private:
    Ui::MakeOrderWindow *ui;
};

#endif // MAKEORDERWINDOW_H

