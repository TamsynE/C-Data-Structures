#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mystacklibrary.c"
#include "stack.h"

int main(int argc, char* argv[]) 
{
    int size = 5;  // decrease the size to 5 for testing
    Stack* stack = createStack(size);

    if (!isEmpty(stack))
    {
        printf("ERROR: THE STACK IS NOT EMPTY BUT IT SHOULD BE\n");
        return EXIT_FAILURE;
    }

    if (isFull(stack))
    {
        printf("ERROR: THE STACK IS FULL BUT IT SHOULD BE\n");
        return EXIT_FAILURE;
    }

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 49);

    if (isEmpty(stack))
    {
        printf("ERROR: THE STACK IS EMPTY BUT IT SHOULDN'T BE\n");
        return EXIT_FAILURE;
    }

    if (!isFull(stack))
    {
        printf("ERROR: THE STACK IS NOT FULL BUT IT SHOULD BE\n");
        return EXIT_FAILURE;
    }

    if (push(stack, 53) == EXIT_SUCCESS)
    {
        printf("ERROR: THE PUSH SHOULD HAVE FAILED\n");
        return EXIT_FAILURE;
    }

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    if (pop(stack) == EXIT_SUCCESS)
    {
        printf("ERROR: THE POP SHOULD HAVE FAILED\n");
        printf("ERROR: POPPED FROM AN EMPTY STACK\n");
        return EXIT_FAILURE;
    }

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 49);

    if (push(stack, 53) == EXIT_SUCCESS)
    {
        printf("ERROR: PUSHED TO A FULL STACK\n");
        return EXIT_FAILURE;
    }


    while (!isEmpty(stack)) 
    { 
        pop(stack);
        
    }

    if (!isEmpty(stack))
    {
        printf("ERROR: FAILED TO POP ALL ELEMENTS\n");
        return EXIT_FAILURE;
    }

    if (stack -> count != 2) 
    {
        printf("ERROR: THE COUNT SHOULD BE 2 BUT IT IS %d\n", stack->count);
        return EXIT_FAILURE;
    }

    // last two pops
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    // one last pop should fail
    if (pop(stack) != EXIT_FAILURE) 
    {
        printf("ERROR: THE POP SHOULD HAVE FAILED\n");
        return EXIT_FAILURE;
    }

    if (stack -> count != 0) 
    {
        printf("ERROR: THE COUNT SHOULD BE 0 BUT IT IS %d\n", stack -> count);
        return EXIT_FAILURE;
    }

    printf("SUCCESS: ALL TEST HAVE PASSED\n");
    return EXIT_SUCCESS;
}