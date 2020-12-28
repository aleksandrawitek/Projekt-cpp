#include "rooms.h"
#include "ui_rooms.h"
#include <QApplication>
#include <QScreen>

rooms::rooms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rooms)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Status pokoju");
    this->setStyleSheet("background-color:white;");
}

rooms::~rooms()
{
    delete ui;
}
