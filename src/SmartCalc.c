#include "SmartCalc.h"

double polish_notation(const char *function, int *err) {
    info data;
    t_stack *stack_of_number = NULL;
    t_stack *stack_of_operator = NULL;
    int begin_stack_of_number = 0;
    int begin_stack_of_operator = 0;
    int bracket_count = 0;

    zeroing_info(&data);
    for (int i = 0; function[i];) {
        data = divide_into_lexems(function, &i);
        if (data.s_operator >= 11 && data.s_operator <= 19) {
            *err = check_of_func(function, i);
            if (*err == 1) {
                data.error = 1;
            }
        }
        if (data.error == 1) {
            *err = 1;
            break;
        } else if (!data.s_operator) {
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
            } else if (data.s_operator == 9 || data.s_operator == 10) {
                push(&stack_of_operator, data);
            } else if (data.s_operator == 1) {
                bracket_count++;
                push(&stack_of_operator, data);
            } else if (data.s_operator == 2) {
                if (--bracket_count < 0 || begin_stack_of_number == 0) {
                    *err = 1;
                    break;
                }
                while (stack_of_operator->data.s_operator != 1) {
                    operation_n_pop(&stack_of_number, &stack_of_operator, err);
                }
                pop(&stack_of_operator);
                if (!stack_of_operator) {
                    begin_stack_of_operator = 0;
                } else {
                    if (stack_of_operator->data.s_operator >= 11 &&
                        stack_of_operator->data.s_operator <= 19) {
                        operation_n_pop(&stack_of_number, &stack_of_operator,
                                        err);
                    }
                }
            } else {
                while (stack_of_operator) {
                    if (data.priority <= stack_of_operator->data.priority) {
                        operation_n_pop(&stack_of_number, &stack_of_operator,
                                        err);
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
    }
    if (begin_stack_of_number == 0 || bracket_count != 0) {
        *err = 1;
    }
    double result = 0;
    if (*err == 0) {
        while (stack_of_operator) {
            operation_n_pop(&stack_of_number, &stack_of_operator, err);
        }
        result = stack_of_number->data.number;
        pop(&stack_of_number);
    }
    if (stack_of_number && stack_of_number->data.number) {
        *err = 1;
    }
    while (stack_of_number) {
        pop(&stack_of_number);
    }
    while (stack_of_operator) {
        pop(&stack_of_operator);
    }
    return result;
}

info divide_into_lexems(const char *function, int *i) {
    info data;
    char* number = (char*)calloc(200, sizeof(char));

    zeroing_info(&data);
    if (function[*i] >= '0' && function[*i] <= '9') {
        int err;
        err = find_of_number(function, number, i);
        data.number = atof(number);
        data.error = err;
    } else if (function[*i] == '(') {
        data.s_operator = 1;
        *i += 1;
    } else if (function[*i] == ')') {
        data.s_operator = 2;
        *i += 1;
    } else if (function[*i] == '+' || function[*i] == '-') {
        data = unary_or_not(function, *i);
        *i += 1;
    } else if (function[*i] == '*') {
        data.s_operator = 5;
        data.priority = 2;
        *i += 1;
    } else if (function[*i] == '/') {
        data.s_operator = 6;
        data.priority = 2;
        *i += 1;
    } else if (function[*i] == '^') {
        data.s_operator = 7;
        data.priority = 3;
        *i += 1;
    } else if (function[*i] == 'm' && function[*i + 1] == 'o' &&
               function[*i + 2] == 'd') {
        data.s_operator = 8;
        data.priority = 2;
        *i += 3;
    } else if (function[*i] == 'c' && function[*i + 1] == 'o' &&
               function[*i + 2] == 's') {
        data.s_operator = 11;
        data.priority = 4;
        *i += 3;
    } else if (function[*i] == 's' && function[*i + 1] == 'i' &&
               function[*i + 2] == 'n') {
        data.s_operator = 12;
        data.priority = 4;
        *i += 3;
    } else if (function[*i] == 't' && function[*i + 1] == 'a' &&
               function[*i + 2] == 'n') {
        data.s_operator = 13;
        data.priority = 4;
        *i += 3;
    } else if (function[*i] == 'a' && function[*i + 1] == 'c' &&
               function[*i + 2] == 'o' && function[*i + 3] == 's') {
        data.s_operator = 14;
        data.priority = 4;
        *i += 4;
    } else if (function[*i] == 'a' && function[*i + 1] == 's' &&
               function[*i + 2] == 'i' && function[*i + 3] == 'n') {
        data.s_operator = 15;
        data.priority = 4;
        *i += 4;
    } else if (function[*i] == 'a' && function[*i + 1] == 't' &&
               function[*i + 2] == 'a' && function[*i + 3] == 'n') {
        data.s_operator = 16;
        data.priority = 4;
        *i += 4;
    } else if (function[*i] == 's' && function[*i + 1] == 'q' &&
               function[*i + 2] == 'r' && function[*i + 3] == 't') {
        data.s_operator = 17;
        data.priority = 4;
        *i += 4;
    } else if (function[*i] == 'l' && function[*i + 1] == 'n') {
        data.s_operator = 18;
        data.priority = 4;
        *i += 2;
    } else if (function[*i] == 'l' && function[*i + 1] == 'o' &&
               function[*i + 2] == 'g') {
        data.s_operator = 19;
        data.priority = 4;
        *i += 3;
    } else {
        data.error = 1;
    }
    if ((data.s_operator >= 11 && data.s_operator <= 19 &&
         function[*i] != '(') ||
        (data.s_operator >= 3 && data.s_operator <= 10 &&
         (function[*i] == '+' || function[*i] == '*' || function[*i] == '/' ||
          function[*i] == '^' || function[*i] == 'm'))) {
        data.error = 1;
    }
    free(number);
    return data;
}

info unary_or_not(const char *function, int i) {
    info data;

    zeroing_info(&data);
    if (i == 0 || function[i - 1] == '(') {
        if (function[i] == '+') {
            data.s_operator = 9;
            data.priority = 5;
        } else {
            data.s_operator = 10;
            data.priority = 5;
        }
    } else {
        if (function[i] == '+') {
            data.s_operator = 3;
            data.priority = 1;
        } else {
            data.s_operator = 4;
            data.priority = 1;
        }
    }
    return data;
}

int find_of_number(const char *function, char *number, int *i) {
    int j = 0;
    int err = 0;
    int check_of_dot = 0;

    while ((function[*i] >= '0' && function[*i] <= '9') ||
           function[*i] == '.') {
        number[j++] = function[*i];
        *i += 1;
        if (function[*i] == '.') {
            check_of_dot++;
        }
    }
    if (check_of_dot > 1) {
        err = 1;
    }
    number[j] = '\0';
    return err;
}

double operation(t_stack **stack_of_number, t_stack *stack_of_operator,
                 int *err) {
    double result = 0;
    double number_two = 0;
    double number_one = 0;

    number_two = (*stack_of_number)->data.number;
    if (stack_of_operator->data.s_operator >= 3 &&
        stack_of_operator->data.s_operator <= 8) {
        pop(stack_of_number);
        number_one = (*stack_of_number)->data.number;
    }
    switch (stack_of_operator->data.s_operator) {
        case 3: {
            result = number_one + number_two;
            break;
        }
        case 4: {
            result = number_one - number_two;
            break;
        }
        case 5: {
            result = number_one * number_two;
            break;
        }
        case 6: {
            if (number_two == 0.0) {
                *err = 1;
            } else {
                result = number_one / number_two;
            }
            break;
        }
        case 7: {
            result = pow(number_one, number_two);
            break;
        }
        case 8: {
            result = fmod(number_one, number_two);
            break;
        }
        case 9: {
            result = number_two * 1;
            break;
        }
        case 10: {
            result = number_two * (-1);
            break;
        }
        case 11: {
            result = cos(number_two);
            break;
        }
        case 12: {
            result = sin(number_two);
            break;
        }
        case 13: {
            result = tan(number_two);
            break;
        }
        case 14: {
            result = acos(number_two);
            break;
        }
        case 15: {
            result = asin(number_two);
            break;
        }
        case 16: {
            result = atan(number_two);
            break;
        }
        case 17: {
            result = sqrt(number_two);
            break;
        }
        case 18: {
            result = log(number_two);
            break;
        }
        case 19: {
            result = log10(number_two);
            break;
        }
        default:
            break;
    }
    return result;
}

int check_of_func(const char *function, int i) {
    int check_of_bracket = 0;
    int err = 0;
    int amount_of_numbers = 0;

    if (function[i] == '(') {
        check_of_bracket++;
        i++;
        for (; function[i] && check_of_bracket != 0; i++) {
            if (function[i] >= '0' && function[i] <= '9') {
                amount_of_numbers++;
            } else if (function[i] == '(') {
                check_of_bracket++;
            } else if (function[i] == ')') {
                check_of_bracket--;
            }
        }
    } else {
        err = 1;
    }
    if (amount_of_numbers == 0 || check_of_bracket != 0) {
        err = 1;
    }
    return err;
}

void operation_n_pop(t_stack **stack_of_number, t_stack **stack_of_operator,
                     int *err) {
    double number = 0;
    number = operation(stack_of_number, (*stack_of_operator), err);
    (*stack_of_number)->data.number = number;
    pop(stack_of_operator);
}

void zeroing_info(info *data) {
    data->number = 0.0;
    data->s_operator = 0;
    data->priority = 0;
    data->error = 0;
}

t_stack *create_node(info data) {
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (node == NULL) {
        printf("malloc error\n");
        exit(1);
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
