#ifndef NEWRES_H
#define NEWRES_H

#include <QDialog>

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
