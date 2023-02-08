#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct Stack {
    int *data;
    int top;
    int size;
};

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->data = (int*) malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

int isFull(struct Stack* stack) 
/* Checks whether the stack is full */

{
    return stack->top == stack->size - 1;
}

int isEmpty(struct Stack* stack)
/* Checks whether the stack is empty */
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item) 
/* Adds an element to the top of the stack */
{
    if (isFull(stack))
    {
        printf("Error: Stack is full, cannot push element \n");
        return -1;
    }
       
    stack->data[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) 
/* Removes the topmost element of the stack */
{
    if (isEmpty(stack))
    {
        printf("Error:Stack is empty, cannot pop element\n");
        return -1;
    }

    return stack->data[stack->top--];
}