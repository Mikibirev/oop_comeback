/* ---------------------------------
-- Студент:         Кибирев М.Г.  --
-- Преподаватель:   Ветров С.В.   --
--------------------------------- */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
