#include "checkin.h"
#include "ui_checkin.h"

checkin::checkin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkin)
{
    ui->setupUi(this);
}

checkin::~checkin()
{
    delete ui;
}
