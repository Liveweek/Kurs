#ifndef DIALOGORDERINGRID_H
#define DIALOGORDERINGRID_H

#include <QDialog>


namespace Ui {
class DialogOrderIngrid;
}

class DialogOrderIngrid : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOrderIngrid(QWidget *parent = nullptr);
    ~DialogOrderIngrid();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogOrderIngrid *ui;
};

#endif // DIALOGORDERINGRID_H
