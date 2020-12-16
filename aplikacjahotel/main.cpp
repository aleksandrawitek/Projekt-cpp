#include "mainwindow.h"

#include <QApplication>

#include <QScreen>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //dopasowanie wielkosci okna do ekranu
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    w.resize(width, height);
    w.setWindowTitle(QApplication::translate("Aplikacja hotelowa","Aplikacja hotelowa"));
    w.setStyleSheet("background-color:white;");
    w.show();
    return a.exec();
}
