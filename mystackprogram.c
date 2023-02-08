#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() 
{
    int size = 100;
    struct Stack* stack = createStack(size);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    return 0;
}