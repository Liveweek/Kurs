#ifndef DIALOGHISTORYWINDOW_H
#define DIALOGHISTORYWINDOW_H

#include <QDialog>
#include "correctorderwindow.h"
#include "mainwindow.h"
#include "correctorderwindow.h"
#include "historyrequestwindow.h"


namespace Ui {
class DialogHistoryWindow;
}

class DialogHistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHistoryWindow(QWidget *parent = nullptr);
    ~DialogHistoryWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogHistoryWindow *ui;
};

#endif // DIALOGHISTORYWINDOW_H
