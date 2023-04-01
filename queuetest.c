/*
Queue Test Program
Tests Queue 
file: queuetest.c
author: Andie Perreira
*/

#include <stdio.h>
#include <stdlib.h>
#include "project1.h"

int main()
{
    QUEUE *q = malloc(sizeof(QUEUE));
    q -> head = NULL;
    q -> count = 0;

    //adding new head to queue
    enqueue(q, "1");
    enqueue(q, "2");
    enqueue(q, "3");
    enqueue(q, "4");
    enqueue(q, "5");

    //printing out list and count
    dumpQueue(q);

    if(q -> count != 5)
    {
        printf("ERROR: COUNT SHOULD BE 5");
        return EXIT_FAILURE;
    }

    //testing isEmpty()
    if (isEmpty(q))
    {
        printf("ERROR: The queue is empty but should contain nodes.\n");
        return EXIT_FAILURE;
    }

    void* temp = dequeue(q);
    printf("Dequeue %s\n", temp);
    temp = dequeue(q);
    printf("Dequeue %s\n", temp);
    temp = dequeue(q);
    printf("Dequeue %s\n", temp);
    temp = dequeue(q);
    printf("Dequeue %s\n", temp);
    temp = dequeue(q);
    printf("Dequeue %s\n", temp);

    if (!isEmpty(q))
    {
        printf("ERROR: The queue is not empty but it should be.\n");
        return EXIT_FAILURE;
    }

    printf("SUCCESS!! All tests have passed!\n");
    return EXIT_SUCCESS;
}
