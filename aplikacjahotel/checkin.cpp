#include "checkin.h"
#include "ui_checkin.h"
#include <QApplication>
#include <QScreen>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
checkin::checkin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkin)
{
    ui->setupUi(this);
    //okno
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height =screenGeometry.height();
    int width = screenGeometry.width();
    setGeometry(width/6,height/6,width/1.5,height/1.5);
    this->setWindowTitle("Check in");
    this->setStyleSheet("background-color:white;");
    //wyswietlanie daty
    QDateTime today = QDateTime::currentDateTime();
    ui-> date ->setText("<font>" + today.toString("dd.MM.yyyy") + "</font>");
    //laczenie z baza danych
    QSqlDatabase mydb2 = QSqlDatabase::addDatabase("QSQLITE");
    mydb2.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/rezerwacja.db");
    mydb2.open();
    QSqlTableModel *model = new QSqlTableModel(this,mydb2);
    model->setTable("rezerwacja");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QString check;
    check = "przyjazd='"+today.toString("dd.MM.yyyy")+"'" ;
    model->setFilter(check);
    model->select();
    ui->checkintable->setModel(model);
    ui->checkintable->show();



}

checkin::~checkin()
{
    delete ui;
}
