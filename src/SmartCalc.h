#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int data;
    struct s_stack *next;
} t_stack;

t_stack *create_node(int data);

#endif  // SRC_SMARTCALC_H_