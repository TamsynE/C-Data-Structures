#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "project1queue.c"

int main()
{
    QUEUE *q = malloc(sizeof(QUEUE));
    q -> head = NULL;
    q -> tail = NULL;
    q -> count = 0;

    //adding new head to queue
    enqueue(q, "1");
    enqueue(q, "2");
    enqueue(q, "3");
    enqueue(q, "4");
    enqueue(q, "5");

    //printing out list and count
    dumpList(q);
    printf("The count is: %d\n", q -> count);

    //testing isEmpty()
    if (isEmpty(q))
    {
        printf("The queue is empty but should contain nodes.\n");
        return 0;
    }

    void* temp = dequeue(q);
    printf("%s\n", temp);
    temp = dequeue(q);
    printf("%s\n", temp);
    temp = dequeue(q);
    printf("%s\n", temp);
    temp = dequeue(q);
    printf("%s\n", temp);
    temp = dequeue(q);
    printf("%s\n", temp);

    if (!isEmpty(q))
    {
        printf("The queue is not empty but it should be.\n");
        return 0;
    }

    printf("All tests have passed!\n");
    return 0;
}