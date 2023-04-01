#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct stack
{
    NODE *data;
    int size; 
    int top
    int count
} STACK;


bool isFull(STACK* stack);
bool isEmpty (STACK* stack);
int push(STACK* stack, int item);
int pop(STACK* stack, int item);

#elif