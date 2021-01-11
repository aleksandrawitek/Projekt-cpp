#include "guests.h"
#include "ui_guests.h"
#include <QApplication>
#include <QScreen>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>


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
    this->setStyleSheet("background-color:white;");
    //laczenie z baza danych
    QSqlDatabase mydb4 = QSqlDatabase::addDatabase("QSQLITE");
    mydb4.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
    mydb4.open();
    QSqlTableModel *model = new QSqlTableModel(this,mydb4);
    model->setTable("kartoteka");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->guesttable->setModel(model);
    ui->guesttable->show();

}

guests::~guests()
{
    delete ui;
}
