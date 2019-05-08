#ifndef FILEWORK_H
#define FILEWORK_H

#include <QFile>
#include "setup_window.h"
#include "correctorderwindow.h"
#include "stock_window.h"


class FileWork
{
public:
    FileWork();
    static void loadFromFiles();
    static void saveToFiles();
};

#endif // FILEWORK_H
