#ifndef DIALOGHISTORYWUNDOW_H
#define DIALOGHISTORYWUNDOW_H

#include <QDialog>

namespace Ui {
class DialogHistoryWundow;
}

class DialogHistoryWundow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHistoryWundow(QWidget *parent = nullptr);
    ~DialogHistoryWundow();

private:
    Ui::DialogHistoryWundow *ui;
};

#endif // DIALOGHISTORYWUNDOW_H
