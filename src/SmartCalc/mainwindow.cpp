#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_sum,SIGNAL(clicked()),this,SLOT(operators()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    ui->input_output->setText(ui->input_output->text() + button->text());
}

void MainWindow::operators()
{
    QPushButton *button = (QPushButton *)sender();
    if(button->text() == "+") {
        ui->input_output->setText(ui->input_output->text() + "+");
    } else if(button->text() == "-") {
        ui->input_output->setText(ui->input_output->text() + "-");
    } else if(button->text() == "*") {
        ui->input_output->setText(ui->input_output->text() + "*");
    } else if(button->text() == "/") {
        ui->input_output->setText(ui->input_output->text() + "/");
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->input_output->setText("");
}

void MainWindow::on_pushButton_result_clicked()
{
 //   QPushButton *button = (QPushButton *)sender();
//    const char* str = qPrintable(ui->input_output->text());
//    polish_notation(str);

    QByteArray test = ui->input_output->text().toLocal8Bit();
    const char *str = test.data();
    double result = polish_notation(str);
    ui->input_output->setText(QString::number(result, 'g', 15));
}

//void MainWindow::digits_numbers()
//{
//    QPushButton *button = (QPushButton *)sender();

//    double all_numbers;
//    QString new_label;
//    all_numbers = (ui->input_output->text() + button->text()).toDouble();
//    new_label = QString::number(all_numbers, 'g', 15);

//    ui->input_output->setText(new_label);
//}


//void MainWindow::on_pushButton_dot_clicked()
//{
//    ui->input_output->setText(ui->input_output->text() + ".");
//}

//void MainWindow::unary_plus_minus()
//{
//    QPushButton *button = (QPushButton *)sender();

//    double all_numbers;
//    QString new_label;

//    if(button->text() == "+/-") {
//        all_numbers = (ui->input_output->text()).toDouble();
//        all_numbers = all_numbers * -1;
//        new_label = QString::number(all_numbers, 'g', 15);

//        ui->input_output->setText(new_label);
//    }
//}

//void MainWindow::math_operations()
//{
//    QPushButton *button = (QPushButton *)sender();

//    num_first = ui->input_output->text().toDouble();

//    button->setChecked(true);
//}

