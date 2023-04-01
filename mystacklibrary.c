#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

STACK* createStack(int size) 
{
    STACK* stack = malloc(sizeof(STACK));
    if (stack == NULL)
    {
        return NULL;
    }

    stack->data = malloc(size * sizeof(int));
    if (stack->data == NULL )
    {
        free(stack);
        return NULL;
    }

    stack->size  = size;
    stack->top   = -1;
    stack->count = 0;

    return stack;
}

bool isFull(STACK* stack) 
/* Checks whether the stack is full */

{
    stack->top == stack->size - 1;
    return; 
}

bool isEmpty (STACK* stack)
/* Checks whether the stack is empty */
{
    if (stack->size == - 1)
    {
        return true;
    }
    return false;
}

int push(STACK* stack, int item) 
/* Adds an element to the top of the stack */
{
    if (isFull(stack))
    {
        printf("Error: Stack is full, cannot push element \n");
        return EXIT_FAILURE;
    }
  
    stack->data[++stack->top] = item;
    stack->count++;
    return item;
}

int pop(STACK* stack, int item)
/* Removes the topmost element of the stack */
{
    if (isEmpty(stack) == NULL)
    {
        printf("Error:Stack is empty, cannot pop element\n");
        return EXIT_FAILURE;
    }

    stack->data[stack->top--] = item;
    stack->count--;
    return item; 
}