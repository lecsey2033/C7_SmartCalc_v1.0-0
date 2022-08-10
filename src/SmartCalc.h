#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// operators
// 1 - '('
// 2 - ')'
// 3 - '+'
// 4 - '-'
// 5 - '*'
// 6 - '/'
// 7 - '^'
// 8 - mod
// 9 - unary plus
// 10 - unary minus
// 11 - cos
// 12 - sin
// 13 - tan
// 14 - acos
// 15 - asin
// 16 - atan
// 17 - sqrt
// 18 - ln
// 19 - log

typedef struct s_info {
    double number;
    int s_operator;
    int priority;
    int error;
} info;

typedef struct s_stack {
    info data;
    struct s_stack* next;
} t_stack;

double polish_notation(const char* function, int* error);
info divide_into_lexems(const char* function, int* i);
int find_of_number(const char* function, char* number, int* i);
info unary_or_not(const char* function, int i);
double operation(t_stack** stack_of_number, t_stack* stack_of_operator,
                 int* err);
void operation_n_pop(t_stack **stack_of_number, t_stack **stack_of_operator,
                 int *err);
void zeroing_info(info* data);
t_stack* create_node(info data);
void push(t_stack** stack, info data);
void pop(t_stack** stack);
int check_of_func(const char* function, int i);

#endif  // SRC_SMARTCALC_H_
