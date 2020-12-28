#include "payment.h"
#include "ui_payment.h"
#include <QApplication>
#include <QScreen>

payment::payment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Regulacja płatności");
    this->setStyleSheet("background-color:white;");
}

payment::~payment()
{
    delete ui;
}
