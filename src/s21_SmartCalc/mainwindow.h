#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include <QVector>
#include "graf.h"
#include "credit.h"

extern "C" {
#include "../SmartCalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    graf *graph;
    credit *cred;

private slots:
    void digits_numbers();
    void operators();
    void math_operations();
    void on_pushButton_AC_clicked();
    void on_pushButton_result_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_lbracket_clicked();
    void on_pushButton_rbracket_clicked();
    void on_pushButton_x_clicked();
    void on_credit_calc_clicked();
};

#endif // MAINWINDOW_H

