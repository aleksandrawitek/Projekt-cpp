#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "checkin.h"
#include "checkout.h"
#include "newres.h"
#include "guests.h"
#include "rooms.h"
#include "payment.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkin_button_clicked()
{
    checkin checkin;
    checkin.setModal(true);
    checkin.exec();
}

void MainWindow::on_checkout_button_clicked()
{
    checkout checkout;
    checkout.setModal(true);
    checkout.exec();
}

void MainWindow::on_newres_button_clicked()
{
    newres newres;
    newres.setModal(true);
    newres.exec();
}

void MainWindow::on_guests_button_clicked()
{
    guests guests;
    guests.setModal(true);
    guests.exec();
}

void MainWindow::on_rooms_button_clicked()
{
    rooms rooms;
    rooms.setModal(true);
    rooms.exec();
}

void MainWindow::on_payment_button_clicked()
{
    payment payment;
    payment.setModal(true);
    payment.exec();
}
