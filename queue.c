/*
Queue
Enqueues and dequeues individually allocated nodes to and from a queue.
file: queue.c
author: Andie Perreira
*/

#include <stdio.h>
#include <stdlib.h>
#include "project1.h"

void enqueue(QUEUE *queue, void* newData)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode -> data = newData;
    newNode -> next = NULL;

    //list is empty
    if (queue -> head == NULL)
    {
        queue -> head = newNode;
        queue -> count = 1;
    }

    else
    {
        struct node *lastNode = queue -> head;

        while(lastNode -> next != NULL)
        {
            lastNode = lastNode -> next;
        }

        //add new node to end
        lastNode -> next = newNode;
        queue -> count++;
    }
}

void* dequeue(QUEUE *q)
{
    q -> count--;
    NODE* temp = q -> head;
    q -> head = q -> head -> next;
    void* data = temp -> data;
    free (temp);  //deleting node
    return data;
}

bool isEmpty(QUEUE *q)
{
    if (q -> count == 0)
    {
        return true;
    }
    return false;
}


void dumpQueue(QUEUE *q)
{
    printf("QUEUE:\n");
    NODE *curr = q -> head;

    while (curr != NULL)
    {
        printf("%p\n", curr -> data);
        curr = curr -> next;
    }
}
