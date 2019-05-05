#ifndef CORRECTORDERWINDOW_H
#define CORRECTORDERWINDOW_H

#include <QMainWindow>

namespace Ui {
class CorrectOrderWindow;
}

class CorrectOrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CorrectOrderWindow(QWidget *parent = nullptr);
    ~CorrectOrderWindow();

private:
    Ui::CorrectOrderWindow *ui;
};

#endif // CORRECTORDERWINDOW_H
