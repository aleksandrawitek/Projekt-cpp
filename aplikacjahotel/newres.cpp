#include "newres.h"
#include "ui_newres.h"
#include <QApplication>
#include <QScreen>

newres::newres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newres)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Nowa rezerwacja");
}

newres::~newres()
{
    delete ui;
}
