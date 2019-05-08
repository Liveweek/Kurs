#ifndef HISTORYREQUESTWINDOW_H
#define HISTORYREQUESTWINDOW_H

#include <QMainWindow>
#include "correctorderwindow.h"
#include "mainwindow.h"

namespace Ui {
class HistoryRequestWindow;
}

class HistoryRequestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HistoryRequestWindow(QWidget *parent = nullptr);
    ~HistoryRequestWindow();
    void refresh();

private slots:
    void on_listOrders_currentRowChanged(int currentRow);

    void on_back_to_menu_clicked();

private:
    Ui::HistoryRequestWindow *ui;
};

#endif // HISTORYREQUESTWINDOW_H
