#include "checkout.h"
#include "ui_checkout.h"
#include <QApplication>
#include <QScreen>


checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Check out");
    this->setStyleSheet("background-color:white;");
}

checkout::~checkout()
{
    delete ui;
}
