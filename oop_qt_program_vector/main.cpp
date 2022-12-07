#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(unsigned(time(0)));
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "oop_qt_program_vector_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
