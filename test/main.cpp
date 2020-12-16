#include "mainwindow.h"

#include <QApplication>

#include <QWidget>

#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


   // QApplication app(argc, argv);
    //QScreen *screen = QGuiApplication::primaryScreen();
    //QRect  screenGeometry = screen->geometry();
    //int height = screenGeometry.height();
    //int width = screenGeometry.width();
    //QWidget window;
    //window.resize(width, height);
    //window.show();
    //window.setWindowTitle(
      //  QApplication::translate("Aplikacja hotelowa","Aplikacja hotelowa"));
//window.setStyleSheet("background-color:white;");
  //  return app.exec();

