#include "rooms.h"
#include "ui_rooms.h"
#include <QApplication>
#include <QScreen>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDateTime>
#include <QMessageBox>

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
    //laczenie z baza danych
    QSqlDatabase mydb3 = QSqlDatabase::addDatabase("QSQLITE");
    mydb3.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/pokoje.db");
    mydb3.open();
    QSqlTableModel *model = new QSqlTableModel(this,mydb3);
    model->setTable("pokoje");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QString check;
    check = "numer < 1000" ;
    model->setFilter(check);
    model->select();
    ui->roomstable->setModel(model);
    ui->roomstable->show();
    if (mydb3.open())
        ui->status_2->setText("Połączono z bazą danych");
    else
        ui->status_2->setText("<font color = 'red'>Brak połączenia z bazą danych </font>");





}

rooms::~rooms()
{
    delete ui;
}

void rooms::on_pushButton_clicked()
{
    QString numer = ui -> numer -> text();
    QString status = ui -> status -> text();
    QString wolny = ui -> wolny -> text();
    int num = numer.toInt();
    if(num < 1 or num > 15){
        QMessageBox::critical(this, "Nowa rezerwacja", "<FONT COLOR='#ff0000'>Błędny numer pokoju</FONT>");
    }
    else
    {
        QSqlDatabase mydb4 = QSqlDatabase::addDatabase("QSQLITE");
        mydb4.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/pokoje.db");
        mydb4.open();
        QSqlQuery query;
        if(status != ""){
            query.prepare("UPDATE pokoje SET status=:status WHERE numer=:numer");
            query.bindValue(":numer", numer);
            query.bindValue(":status", status);
            query.exec();
        }

        else if(wolny != ""){
            query.prepare("UPDATE pokoje SET wolny=:wolny WHERE numer=:numer");
            query.bindValue(":numer", numer);
            query.bindValue(":wolny", wolny);
            query.exec();
        }
        else
        {
            QMessageBox::critical(this, "Nowa rezerwacja", "<FONT COLOR='#ff0000'>Proszę uzupełnić wartości</FONT>");
        }
        mydb4.close();
        ui -> wolny -> setText("");
        ui -> numer -> setValue(0);
        ui -> status -> setText("");
        QSqlDatabase mydb5 = QSqlDatabase::addDatabase("QSQLITE");
        mydb5.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/pokoje.db");
        mydb5.open();
        QSqlTableModel *model = new QSqlTableModel(this,mydb5);
        model->setTable("pokoje");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        QString check;
        check = "numer < 1000" ;
        model->setFilter(check);
        model->select();
        ui->roomstable->setModel(model);
        ui->roomstable->show();

    }


}
