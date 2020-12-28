#ifndef GUESTS_H
#define GUESTS_H

#include <QDialog>

namespace Ui {
class guests;
}

class guests : public QDialog
{
    Q_OBJECT

public:
    explicit guests(QWidget *parent = nullptr);
    ~guests();

private:
    Ui::guests *ui;
};

#endif // GUESTS_H
