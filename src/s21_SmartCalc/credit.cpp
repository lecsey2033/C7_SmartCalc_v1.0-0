#include "credit.h"
#include "ui_credit.h"
#include "mainwindow.h"

credit::credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::credit)
{
    ui->setupUi(this);
}

credit::~credit()
{
    delete ui;
}

void credit::on_calculate_clicked()
{
    double sum = ui->sum->text().toDouble();
    int data = ui->data->text().toInt();
    double procent = ui->procent->text().toDouble();
    int type = ui->radioButton->isChecked() ? 1 : 2;
    double mutualpay = 0.0, overpay = 0.0, every_month[data];

    ui->mutualpay->setText("");
    ui->overpay->setText("");
    ui->textEdit->setText("");
    if (sum <= 0 || data <= 0 || procent <= 0) {
        ui->mutualpay->setText("0");
        ui->overpay->setText("0");
        ui->textEdit->setText("0");
    } else {
        s21_credit(type, sum, data, procent, &mutualpay, &overpay, every_month);
        ui->overpay->setText(QString::number(overpay, 'f', 2));
        ui->mutualpay->setText(QString::number(mutualpay, 'f', 2));
        ui->textEdit->verticalScrollBar();
        for (int i = 1, j = 0; i <= data; i++, j++) {
            ui->textEdit->insertPlainText("Месяц " + QString::number(i) + ": " + QString::number(every_month[j], 'f', 2) + "\n");
            ui->textEdit->textCursor().movePosition(QTextCursor::Start);
        }
    }
}

