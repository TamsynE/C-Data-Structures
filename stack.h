#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* next;
} NODE;

typedef struct stack
{
    NODE *data;
    int size; 
    int top;
} STACK;


STACK* createStack(int size);
bool isFull(STACK* stack);
bool isEmpty (STACK* stack);
void push(STACK* stack, int item);
int pop(STACK* stack);

#endif