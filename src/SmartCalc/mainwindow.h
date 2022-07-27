#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

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

private slots:
    void digits_numbers();
    void operators();
//    void on_pushButton_dot_clicked();
//    void unary_plus_minus();
    void on_pushButton_AC_clicked();
//    void math_operations();
    void on_pushButton_result_clicked();
};
#endif // MAINWINDOW_H

