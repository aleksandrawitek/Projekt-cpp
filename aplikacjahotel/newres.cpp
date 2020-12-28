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
    this->setStyleSheet("background-color:white;");
    QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
    mydb1.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/rezerwacja.db");
    if (mydb1.open())
        ui->label->setText("Połączono z bazą danych");
    else
        ui->label->setText("<font color = 'red'>Brak połączenia z bazą danych </font>");

}

newres::~newres()
{
    delete ui;
}
