#include "newres.h"
#include "ui_newres.h"
#include <QApplication>
#include <QScreen>
#include <QDateTime>
#include <QSqlDatabase>
#include <QMessageBox>

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

    // ustawienie dzisiejszej daty jako daty przyjazdu
    QDateTime today = QDateTime::currentDateTime();
    ui -> przyjazd -> setDateTime(today);
    ui -> wyjazd -> setDateTime(today);

}

newres::~newres()
{
    delete ui;
}

void newres::on_pushButton_clicked()
{
    QString tytul = ui -> tytul -> text();
    QString imie = ui -> imie -> text();
    QString nazwisko = ui -> imie -> text();
    QString pakiet = ui -> pakiet -> text();
    QString osoby = ui -> osoby -> text();
    QString dzieci = ui -> dzieci -> text();
    QString kwota = ui -> kwota -> text();
    QString przyjazd = ui -> przyjazd -> text();
    QString wyjazd = ui -> wyjazd -> text();

    if(tytul == "" or imie == "" or nazwisko == "" or pakiet == "" or kwota == "" or osoby == "0"){
       QMessageBox::critical(this, "Nowa rezerwacja", "<FONT COLOR='#ff0000'>Proszę uzupełnić wszystkie pola</FONT>");
    }
    else{
        QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
        mydb1.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/rezerwacja.db");
        mydb1.open();
        QSqlQuery query;
        query.prepare("INSERT INTO rezerwacja (tytul, imie, nazwisko, kwota, liczbaosob, liczbadzieci, pakiet, przyjazd, wyjazd) "
                   "VALUES (:tytul, :imie, :nazwisko, :pakiet, :osoby, :dzieci, :kwota, :przyjazd, :wyjazd)");
        query.bindValue(":tytul", tytul);
        query.bindValue(":imie", imie);
        query.bindValue(":nazwisko", nazwisko);
        query.bindValue(":pakiet", pakiet);
        query.bindValue(":osoby", osoby);
        query.bindValue(":dzieci", dzieci);
        query.bindValue(":kwota", kwota);
        query.bindValue(":przyjazd", przyjazd);
        query.bindValue(":wyjazd", wyjazd);
        query.exec();
        mydb1.close();

        //dodanie osob do kartoteki
        QSqlDatabase mydb2 = QSqlDatabase::addDatabase("QSQLITE");
        mydb2.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
        mydb2.open();
        QSqlQuery query2;
        query2.prepare("INSERT INTO kartoteka (tytul, imie, nazwisko)"
                   "VALUES (:tytul, :imie, :nazwisko)");
        query2.bindValue(":tytul", tytul);
        query2.bindValue(":imie", imie);
        query2.bindValue(":nazwisko", nazwisko);
        query2.exec();
        mydb2.close();
        ui -> tytul -> setText("");
        ui -> imie -> setText("");
        ui -> nazwisko -> setText("");
        ui -> pakiet -> setText("");
        ui -> kwota -> setText("");
        ui -> dzieci -> setValue(0);
        ui -> osoby -> setValue(0);
        QDateTime today = QDateTime::currentDateTime();
        ui -> przyjazd -> setDateTime(today);
        ui -> wyjazd -> setDateTime(today);}

}
