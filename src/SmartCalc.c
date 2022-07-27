#include "SmartCalc.h"

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_info {
    double number;
    int s_operator;
    int priority;
    int error;
} info;

typedef struct s_stack {
    info data;
    struct s_stack *next;
} t_stack;

void polish_notation(char *function);
info divide_into_lexems(char *function, int *i);
void find_of_number(char* function, char* number, int* i);
info unary_or_not(char* function, int* i);
double operation(t_stack **stack_of_number, t_stack *stack_of_operator);
void zeroing_info(info* data);
t_stack *create_node(info data);
void push(t_stack **stack, info data);
void pop(t_stack **stack);
void stack_print(t_stack *stack);*/

// int main() {
//     const char function[500] = "370/60";
//     printf("%f", polish_notation(function));
// }

double polish_notation(const char *function) {
    info data;
    t_stack* stack_of_number;
    t_stack* stack_of_operator;
    int error = 0;
    int begin_stack_of_number = 0;
    int begin_stack_of_operator = 0;
    double number = 0;

    zeroing_info(&data);
    for (int i = 0; function[i];) {
        data = divide_into_lexems(function, &i);
        // printf("oper %d\n", data.s_operator);
        if (data.error == 1) {
            error = 1;
            break;
        } else if (!data.s_operator || data.s_operator == 20) {
            if (begin_stack_of_number == 0) {
                stack_of_number = create_node(data);
                stack_of_number->data = data;
                begin_stack_of_number = 1;
            } else {
                push(&stack_of_number, data);
            }
        } else {
            if (begin_stack_of_operator == 0) {
                stack_of_operator = create_node(data);
                stack_of_operator->data = data;
                begin_stack_of_operator = 1;
            } else if (data.s_operator == 1 || data.s_operator == 9 || data.s_operator == 10) {
                push(&stack_of_operator, data);
            } else if (data.s_operator == 2) {
                while (stack_of_operator->data.s_operator != 1) {
                    number = operation(&stack_of_number, stack_of_operator);
                    stack_of_number->data.number = number;
                    pop(&stack_of_operator);
                }
                pop(&stack_of_operator);
                if (!stack_of_operator) { 
                    begin_stack_of_operator = 0;
                } else {
                    if (stack_of_operator->data.s_operator >= 11 && stack_of_operator->data.s_operator <= 19) {
                        number = operation(&stack_of_number, stack_of_operator);
                        stack_of_number->data.number = number;
                        pop(&stack_of_operator);
                    }
                }
            } else {
                while (stack_of_operator) {
                    if (data.priority <= stack_of_operator->data.priority && data.s_operator != 1) {
                        number = operation(&stack_of_number, stack_of_operator);
                        stack_of_number->data.number = number;
                        pop(&stack_of_operator);
                    } else {
                        break;
                    }
                }
                if (!stack_of_operator) { 
                    stack_of_operator = create_node(data);
                } else {
                    push(&stack_of_operator, data);
                }
            }
        } 
        // if (data.s_operator) {
        //     printf("%d ", data.s_operator);
        // } else {
        //     printf("%f ", data.number);
        // }
    }
    // stack_print(stack_of_operator);
    while (stack_of_operator) {
        number = operation(&stack_of_number, stack_of_operator);;
        stack_of_number->data.number = number;
        pop(&stack_of_operator);
    }
    // printf("%f", stack_of_number->data.number);
    double result = stack_of_number->data.number;
    pop(&stack_of_number);
    // stack_print(stack_of_number);
    // printf("\n");
    // stack_print(stack_of_operator);
    if (error) { printf("error"); }
    return result;
}

info divide_into_lexems(const char* function, int *i) {
    info data;
    char number[100] = "";

    zeroing_info(&data);
    if (function[*i] >= '0' && function[*i] <= '9') {
        find_of_number(function, number, i);
        data.number = atof(number);
    }
    else if (function[*i] == '(') { data.s_operator = 1; *i += 1; }
    else if (function[*i] == ')') { data.s_operator = 2; *i += 1; }
    else if (function[*i] == '+' || function[*i] == '-') {
        data = unary_or_not(function, i);
        *i += 1;
    }
    else if (function[*i] == '*') { data.s_operator = 5; data.priority = 2; *i += 1; }
    else if (function[*i] == '/') { data.s_operator = 6; data.priority = 2; *i += 1; }
    else if (function[*i] == '^') { data.s_operator = 7; data.priority = 3; *i += 1; }
    else if (function[*i] == 'm' && function[*i+1] == 'o' && function[*i+2] == 'd') {
        data.s_operator = 8; data.priority = 2; *i += 3;
    }
    else if (function[*i] == 'c' && function[*i+1] == 'o' && function[*i+2] == 's') {
        data.s_operator = 11; data.priority = 4; *i += 3; }
    else if (function[*i] == 's' && function[*i+1] == 'i' && function[*i+2] == 'n') {
        data.s_operator = 12; data.priority = 4; *i += 3; }
    else if (function[*i] == 't' && function[*i+1] == 'a' && function[*i+2] == 'n') {
        data.s_operator = 13; data.priority = 4; *i += 3; }
    else if (function[*i] == 'a' && function[*i+1] == 'c' && function[*i+2] == 'o' && function[*i+3] == 's') {
        data.s_operator = 14; data.priority = 4; *i += 4; }
    else if (function[*i] == 'a' && function[*i+1] == 's' && function[*i+2] == 'i' && function[*i+3] == 'n') {
        data.s_operator = 15; data.priority = 4; *i += 4; }
    else if (function[*i] == 'a' && function[*i+1] == 't' && function[*i+2] == 'a' && function[*i+3] == 'n') {
        data.s_operator = 16; data.priority = 4; *i += 4; }
    else if (function[*i] == 's' && function[*i+1] == 'q' && function[*i+2] == 'r' && function[*i+3] == 't') {
        data.s_operator = 17; data.priority = 4; *i += 4; }
    else if (function[*i] == 'l' && function[*i+1] == 'n') {
        data.s_operator = 18; data.priority = 4; *i += 2; }
    else if (function[*i] == 'l' && function[*i+1] == 'o' && function[*i+2] == 'g') {
        data.s_operator = 19; data.priority = 4; *i += 3; }
    else if (function[*i] == 'x') { data.s_operator = 20; *i += 1; }
    else { data.error = 1; }
    return data;
}

info unary_or_not(const char* function, int* i) {
    info data;

    zeroing_info(&data);
    if (*i == 0 || (*i != 0 && function[*i - 1] == '(')) {
        if (function[*i] == '+') { data.s_operator = 9; data.priority = 5; }
        else { data.s_operator = 10; data.priority = 5; }
    } else {
        if (function[*i] == '+') { data.s_operator = 3; data.priority = 1;}
        else { data.s_operator = 4; data.priority = 1;}
    }
    return data;
}

void find_of_number(const char* function, char* number, int* i) {
    int j = 0;

    while ((function[*i] >= '0' && function[*i] <= '9') || function[*i] == '.') {
        number[j++] = function[*i];
        *i += 1;
    }
    number[j] = '\0';
}

double operation(t_stack **stack_of_number, t_stack *stack_of_operator) {
    double result = 0;
    double number_two = 0;
    double number_one = 0;

    number_two = (*stack_of_number)->data.number;
    if (stack_of_operator->data.s_operator >= 3 && stack_of_operator->data.s_operator <= 8) {
        pop(stack_of_number);
        number_one = (*stack_of_number)->data.number;
    }
    switch (stack_of_operator->data.s_operator) {
        case 3: { result = number_one + number_two; break; }
        case 4: { result = number_one - number_two; break; }
        case 5: { result = number_one * number_two; break; }
        case 6: { result = number_one / number_two; break; }
        case 7: { result = pow(number_one, number_two); break; }
        case 8: { result = fmod(number_one, number_two); break; }
        case 9: { result = number_two * 1; break; }
        case 10: { result = number_two * (-1); break; }
        case 11: { result = cos(number_two); break; }
        case 12: { result = sin(number_two); break; }
        case 13: { result = tan(number_two); break; }
        case 14: { result = acos(number_two); break; }
        case 15: { result = asin(number_two); break; }
        case 16: { result = atan(number_two); break; }
        case 17: { result = sqrt(number_two); break; }
        case 18: { result = log(number_two); break; }
        case 19: { result = log10(number_two); break; }
        default:
            break;
    }
    return result;
}

void zeroing_info(info* data) {
    data->number = 0.0;
    data->s_operator = 0;
    data->priority = 0;
    data->error = 0;
}

t_stack *create_node(info data) {
    t_stack *node = (t_stack*)malloc(sizeof(t_stack));
    if (node == NULL) {
        printf("malloc error\n");
        exit(1); // учитывать
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void push(t_stack **stack, info data) {
    t_stack *new_node = create_node(data);

    new_node->next = *stack;
    *stack = new_node;
}

void pop(t_stack **stack) {
    t_stack *tmp = *stack;

    *stack = tmp->next;
    free(tmp);
}

void stack_print(t_stack *stack) {
    t_stack *tmp = stack;

    while(tmp) {
        if (!tmp->data.s_operator || tmp->data.s_operator == 20) {
            if (tmp->data.s_operator == 20) {
                printf("%d ", tmp->data.s_operator);
            } else {
                printf("%f ", tmp->data.number);
            }  
        } else {
            printf("%d ", tmp->data.s_operator);
        } 
        tmp = tmp->next;
    }
}