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
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_exp,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_sin,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_asin,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_acos,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_tan,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_atan,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_log,SIGNAL(clicked()), this, SLOT(math_operations()));
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
    } else if(button->text() == "mod") {
        ui->input_output->setText(ui->input_output->text() + "mod");
    } else if(button->text() == "^") {
        ui->input_output->setText(ui->input_output->text() + "^");
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
    if(ui->input_output->text().contains("x")) {
        QString str_buf = ui->input_output->text();
        str_buf.replace("x", QString::number(0.1));
        QByteArray test = str_buf.toLocal8Bit();
        const char *str = test.data();
        int error = 0;
        polish_notation(str, &error);
        if (!error) {
            graph = new graf(this);
            graph->show();
            graph->MakeGraf(ui->input_output->text());
        } else {
            ui->input_output->setText("error");
        }
    } else {
        QByteArray test = ui->input_output->text().toLocal8Bit();
        const char *str = test.data();
        int error = 0;
        double result = polish_notation(str, &error);
        if(!error) {
            ui->input_output->setText(QString::number(result, 'g', 15));
        } else {
            ui->input_output->setText("error");
        }
    }
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


void MainWindow::on_pushButton_dot_clicked()
{
    ui->input_output->setText(ui->input_output->text() + ".");
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    if(button->text() == "sin") {
        ui->input_output->setText(ui->input_output->text() + "sin(");
    } else if(button->text() == "asin") {
        ui->input_output->setText(ui->input_output->text() + "asin(");
    } else if(button->text() == "cos") {
        ui->input_output->setText(ui->input_output->text() + "cos(");
    } else if(button->text() == "acos") {
        ui->input_output->setText(ui->input_output->text() + "acos(");
    } else if(button->text() == "tan") {
        ui->input_output->setText(ui->input_output->text() + "tan(");
    }else if(button->text() == "atan") {
        ui->input_output->setText(ui->input_output->text() + "atan(");
    }else if(button->text() == "ln") {
        ui->input_output->setText(ui->input_output->text() + "ln(");
    }else if(button->text() == "log") {
        ui->input_output->setText(ui->input_output->text() + "log(");
    }
}


void MainWindow::on_pushButton_lbracket_clicked()
{
    ui->input_output->setText(ui->input_output->text() + "(");
}


void MainWindow::on_pushButton_rbracket_clicked()
{
    ui->input_output->setText(ui->input_output->text() + ")");
}


void MainWindow::on_pushButton_x_clicked()
{
    ui->input_output->setText(ui->input_output->text() + "x");
}

