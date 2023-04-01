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

    stack->data = malloc(size * sizeof(NODE));
    if (stack->data == NULL )
    {
        free(stack);
        return NULL;
    }

    stack->size  = size;
    stack->top = 0;

    return stack;
}

bool isFull(STACK* stack) 
/* Checks whether the stack is full */

{
    return stack->top == stack->size - 1;
}

bool isEmpty (STACK* stack)
/* Checks whether the stack is empty */
{
    return stack->top == 0;
}

void push(STACK* stack, int item) 
/* Adds an element to the top of the stack */
{
    if (isFull(stack))
    {
        printf("Error: Stack is full, cannot push element \n");
        return EXIT_FAILURE;
    }
  
    NODE* newNode = malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Error: Could not allocate memory for new node\n");
        return EXIT_FAILURE;
    }

    newNode->data = item;
    newNode->next = stack->data;
    stack->data = newNode;
    stack->top++;
    return EXIT_SUCCESS;
}

int pop(STACK* stack)
/* Removes the topmost element of the stack */
{
    if (isEmpty(stack))
    {
        printf("Error: Stack is empty, cannot pop element\n");
        return EXIT_FAILURE;
    }

    NODE* nodefree = stack->data;
    int item = nodefree->data;
    stack->data = nodefree->next;
    free(nodefree);
    stack->top--;
    return item; 
}
