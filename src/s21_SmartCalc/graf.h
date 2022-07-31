#ifndef GRAF_H
#define GRAF_H

#include <QDialog>

namespace Ui {
class graf;
}

class graf : public QDialog
{
    Q_OBJECT

public:
    explicit graf(QWidget *parent = nullptr);
    ~graf();

public slots:
    void MakeGraf(QString str);

private:
    Ui::graf *ui;
    double xBegin, xEnd, h, X;
    QVector<double> x, y;
};

#endif // GRAF_H
