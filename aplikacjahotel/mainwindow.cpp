#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap checkinloc("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/logo/checkin.png");
    int w = ui->checkin_label->width();
    int h = ui->checkin_label->height();
    ui->checkin_label->setPixmap(checkinloc.scaled(w,h, Qt::KeepAspectRatio));
    QPixmap checkoutloc("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/logo/checkout.png");
    ui->checkout_label->setPixmap(checkoutloc.scaled(w,h, Qt::KeepAspectRatio));
    QPixmap reservationloc("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/logo/nowarez.png");
    ui->reservation_label->setPixmap(reservationloc.scaled(w,h, Qt::KeepAspectRatio));
    QPixmap historyloc("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/logo/kartoteka.png");
    ui->history_label->setPixmap(historyloc.scaled(w,h, Qt::KeepAspectRatio));
    QPixmap paymentloc("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/logo/platnosc.png");
    ui->payment_label->setPixmap(paymentloc.scaled(w,h, Qt::KeepAspectRatio));
    QPixmap statusloc("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/aplikacjahotel/logo/status.png");
    ui->status_label->setPixmap(statusloc.scaled(w,h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

