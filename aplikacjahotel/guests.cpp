#include "guests.h"
#include "ui_guests.h"
#include <QApplication>
#include <QScreen>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>

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
    if (mydb4.open())
        ui->status_2->setText("Połączono z bazą danych");
    else
        ui->status_2->setText("<font color = 'red'>Brak połączenia z bazą danych </font>");

}

guests::~guests()
{
    delete ui;
}

void guests::on_pushButton_3_clicked()
{
    QString wyszukaj = ui -> wyszukaj -> text();
    if(wyszukaj != "")
    {
        QSqlDatabase mydb5 = QSqlDatabase::addDatabase("QSQLITE");
        mydb5.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
        mydb5.open();
        QSqlTableModel *model2 = new QSqlTableModel(this,mydb5);
        model2->setTable("kartoteka");
        model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model2->select();
        QString check;
        check = "imie = '" + wyszukaj + "'";
        model2->setFilter(check);
        model2->select();
        ui->guesttable->setModel(model2);
        ui->guesttable->show();
        ui -> wyszukaj -> setText("");
    }
}

void guests::on_pushButton_4_clicked()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
    mydb.open();
    QSqlTableModel *model3 = new QSqlTableModel(this,mydb);
    model3->setTable("kartoteka");
    model3->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model3->select();
    ui->guesttable->setModel(model3);
    ui->guesttable->show();
}

void guests::on_pushButton_clicked()
{
    QString tytul = ui -> tytul -> text();
    QString imie = ui -> imie -> text();
    QString nazwisko = ui -> nazwisko -> text();
    QString komentarz = ui -> komentarz -> text();
    QString czarnalista = ui -> czarnalista -> text();



    QSqlDatabase mydb2 = QSqlDatabase::addDatabase("QSQLITE");
    mydb2.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
    mydb2.open();
    QSqlQuery query;
    if(komentarz != ""){
            query.prepare("UPDATE kartoteka SET komentarz=:komentarz WHERE imie=:imie and nazwisko=:nazwisko");
            query.bindValue(":nazwisko", nazwisko);
            query.bindValue(":imie", imie);
            query.bindValue(":komentarz", komentarz);
            query.exec();
        }

        else if(czarnalista != ""){
            query.prepare("UPDATE kartoteka SET czarnalista=:czarnalista WHERE imie=:imie  and nazwisko=:nazwisko");
            query.bindValue(":nazwisko", nazwisko);
            query.bindValue(":imie", imie);
            query.bindValue(":czarnalista", czarnalista);
            query.exec();
        }
        else if(tytul != ""){
            query.prepare("UPDATE kartoteka SET tytul=:tytul WHERE imie=:imie and nazwisko=:nazwisko");
            query.bindValue(":nazwisko", nazwisko);
            query.bindValue(":imie", imie);
            query.bindValue(":tytul", tytul);
            query.exec();
        }

        else
        {
            QMessageBox::critical(this, "Kartoteka gości", "<FONT COLOR='#ff0000'>Proszę uzupełnić wartości</FONT>");
        }
        mydb2.close();
        ui -> imie -> setText("");
        ui -> nazwisko -> setText("");
        ui -> tytul -> setText("");
        ui -> komentarz -> setText("");
        ui -> czarnalista -> setText("");
        QSqlDatabase mydb6 = QSqlDatabase::addDatabase("QSQLITE");
        mydb6.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
        mydb6.open();
        QSqlTableModel *model6 = new QSqlTableModel(this,mydb6);
        model6->setTable("kartoteka");
        model6->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model6->select();
        ui->guesttable->setModel(model6);
        ui->guesttable->show();



}

void guests::on_pushButton_2_clicked()
{

    QString imie = ui -> imie -> text();
    QString nazwisko = ui -> nazwisko -> text();



    QSqlDatabase mydb2 = QSqlDatabase::addDatabase("QSQLITE");
    mydb2.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
    mydb2.open();
    QSqlQuery query;
    if(imie != "" and nazwisko != ""){
            query.prepare("DELETE FROM kartoteka WHERE imie=:imie and nazwisko=:nazwisko");
            query.bindValue(":nazwisko", nazwisko);
            query.bindValue(":imie", imie);
            query.exec();
        }

        else
        {
            QMessageBox::critical(this, "Kartoteka gości", "<FONT COLOR='#ff0000'>Proszę uzupełnić wartości</FONT>");
        }
        mydb2.close();
        ui -> imie -> setText("");
        ui -> nazwisko -> setText("");
        ui -> tytul -> setText("");
        ui -> komentarz -> setText("");
        ui -> czarnalista -> setText("");
        QSqlDatabase mydb6 = QSqlDatabase::addDatabase("QSQLITE");
        mydb6.setDatabaseName("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/database/goscie.db");
        mydb6.open();
        QSqlTableModel *model6 = new QSqlTableModel(this,mydb6);
        model6->setTable("kartoteka");
        model6->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model6->select();
        ui->guesttable->setModel(model6);
        ui->guesttable->show();
}
