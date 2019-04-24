#ifndef CREATE_EDITDISH_H
#define CREATE_EDITDISH_H

#include <QMainWindow>

namespace Ui {
class Create_editDish;
}

class Create_editDish : public QMainWindow
{
    Q_OBJECT

public:
    explicit Create_editDish(QWidget *parent = nullptr);
    ~Create_editDish();
    void refresh();

private slots:
    void on_cancel_button_clicked();

    void on_save_button_clicked();

    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_ingridients_list_currentRowChanged(int currentRow);

private:
    Ui::Create_editDish *ui;
};

#endif // CREATE_EDITDISH_H
