#ifndef CHECKIN_H
#define CHECKIN_H

#include <QDialog>

namespace Ui {
class checkin;
}

class checkin : public QDialog
{
    Q_OBJECT

public:
    explicit checkin(QWidget *parent = nullptr);
    ~checkin();

private:
    Ui::checkin *ui;
};

#endif // CHECKIN_H
