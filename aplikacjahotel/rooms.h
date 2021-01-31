#ifndef ROOMS_H
#define ROOMS_H

#include <QDialog>

namespace Ui {
class rooms;
}

class rooms : public QDialog
{
    Q_OBJECT

public:
    explicit rooms(QWidget *parent = nullptr);
    ~rooms();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rooms *ui;
};

#endif // ROOMS_H
