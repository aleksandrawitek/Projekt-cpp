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

private slots:
    void on_pushButton_clicked();

private:
    Ui::newres *ui;
};

#endif // NEWRES_H
