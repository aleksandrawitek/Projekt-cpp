#ifndef NEWRES_H
#define NEWRES_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class newres;
}

class newres : public QDialog
{
    Q_OBJECT

public:
    explicit newres(QWidget *parent = nullptr);
    ~newres();

private:
    Ui::newres *ui;
};

#endif // NEWRES_H
