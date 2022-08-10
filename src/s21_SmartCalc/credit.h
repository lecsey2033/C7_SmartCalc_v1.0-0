#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

extern "C" {
#include "./credit_calc.h"
}

namespace Ui {
class credit;
}

class credit : public QWidget
{
    Q_OBJECT

public:
    explicit credit(QWidget *parent = nullptr);
    ~credit();

public slots:
    void on_calculate_clicked();

private:
    Ui::credit *ui;
};

#endif // CREDIT_H
