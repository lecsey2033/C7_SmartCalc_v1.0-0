#include "graf.h"
#include "ui_graf.h"
#include "mainwindow.h"

graf::graf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graf)
{
    ui->setupUi(this);
}

graf::~graf()
{
    delete ui;
}

void graf::MakeGraf(QString str_test) {
    QString str_buf = str_test;
    h = 0.05;
    xBegin = 0;
    xEnd = 10;
    double yaxis_minus = 0;
    double yaxis_plus = 0;
    for(X = xBegin; X <= xEnd; X += h)
    {
        str_buf.replace("x", QString::number(X));
        QByteArray test = str_buf.toLocal8Bit();
        const char *str = test.data();
        int error = 0;
        double res = polish_notation(str, &error);
        if(error)
        {
            EXIT_FAILURE;
        }
        else
        {
            x.push_back(X);
            y.push_back(res);
            if (res < 0) {
                if(res < yaxis_minus)
                yaxis_minus = res;
            } else {
                if(yaxis_minus > 0)
                yaxis_minus = res;
                if(res > yaxis_plus)
                yaxis_plus = res;
            }
        }
        str_buf = str_test;
    }

    ui->widget->xAxis->setRange(0,10);
    ui->widget->yAxis->setRange(round(yaxis_minus), round(yaxis_plus));

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
}
