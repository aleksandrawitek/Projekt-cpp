#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "checkin.h"
#include "checkout.h"

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
