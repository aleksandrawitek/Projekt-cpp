#include "guests.h"
#include "ui_guests.h"
#include <QApplication>
#include <QScreen>


guests::guests(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guests)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Kartoteka gości");
}

guests::~guests()
{
    delete ui;
}
