#include "credit_calc.h"

void s21_credit(int type, double sum, int data, double procent, double *mutualpay,
           double *overpay, double *every_month) {
    procent = procent / 100. / 12.;
    if (type == 1) {
        double month = sum * (procent / (1 - powf(1 + procent, -1 * data)));
        month = round(month * 100) / 100.;
        *mutualpay = data * month;
        *overpay = *mutualpay - sum;
        for (int i = 0; i < data; i++)
            every_month[i] = month;
    } else {
        int stat = sum / (double)data;
        double sum_static = sum;
        for (int i = 0; i < data; i++) {
            every_month[i] = round((stat + sum * procent) * 100) / 100.;
            *mutualpay += every_month[i];
            sum -= every_month[i];
        }
        *overpay = *mutualpay - sum_static;
    }
}