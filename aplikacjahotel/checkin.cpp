#include "checkin.h"
#include "ui_checkin.h"
#include <QApplication>
#include <QScreen>

checkin::checkin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkin)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Check in");
    this->setStyleSheet("background-color:white;");
}

checkin::~checkin()
{
    delete ui;
}
