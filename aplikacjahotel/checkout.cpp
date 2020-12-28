#include "checkout.h"
#include "ui_checkout.h"

checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
}

checkout::~checkout()
{
    delete ui;
}
