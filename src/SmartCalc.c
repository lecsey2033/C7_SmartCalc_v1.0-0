#include "SmartCalc.h"

t_stack *create_node(int data) {
    t_stack *node = (t_stack*)malloc(sizeof(t_stack));
    if (node == NULL) {
        printf("malloc error\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void push(t_stack **stack, int data) {
    t_stack *new_node = create_node(data);

    new_node->next = *stack;
    *stack = new_node;
}

void pop(t_stack **stack) {
    t_stack *tmp = *stack;

    *stack = tmp->next;
    free(tmp);
}