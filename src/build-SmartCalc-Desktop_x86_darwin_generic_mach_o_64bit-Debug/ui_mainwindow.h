/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *input_output;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_4;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_1;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_result;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_div;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(477, 383);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        input_output = new QLineEdit(centralwidget);
        input_output->setObjectName(QString::fromUtf8("input_output"));
        input_output->setGeometry(QRect(90, 10, 321, 51));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 90, 51, 51));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(90, 90, 51, 51));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(140, 90, 51, 51));
        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(190, 90, 51, 51));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 140, 51, 51));
        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(190, 140, 51, 51));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(90, 140, 51, 51));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 140, 51, 51));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(40, 190, 51, 51));
        pushButton_sum = new QPushButton(centralwidget);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));
        pushButton_sum->setGeometry(QRect(190, 190, 51, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 190, 51, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 190, 51, 51));
        pushButton_AC = new QPushButton(centralwidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(40, 240, 51, 51));
        pushButton_result = new QPushButton(centralwidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(190, 240, 51, 51));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(90, 240, 51, 51));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(140, 240, 51, 51));
        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(240, 90, 51, 51));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
