#include "checkout.h"
#include "ui_checkout.h"
#include <QApplication>
#include <QScreen>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>


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
    QDateTime today = QDateTime::currentDateTime();
    ui-> date ->setText("<font>" + today.toString("dd.MM.yyyy") + "</font>");
    //laczenie z baza danych
    QSqlDatabase mydb3 = QSqlDatabase::addDatabase("QSQLITE");
    mydb3.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/zameldowani.db");
    mydb3.open();
    QSqlTableModel *model = new QSqlTableModel(this,mydb3);
    model->setTable("zameldowani");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QString check;
    check = "wyjazd='"+today.toString("dd.MM.yyyy")+"'" ;
    model->setFilter(check);
    model->select();
    ui->checkouttable->setModel(model);
    ui->checkouttable->show();

}

checkout::~checkout()
{
    delete ui;
}
