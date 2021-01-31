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

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::guests *ui;
};

#endif // GUESTS_H
