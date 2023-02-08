#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    void* data;
    int size;
    struct node* next;
    struct node* previous;
}NODE;

typedef struct
{
    NODE *head;
    NODE *tail;
    int count;
}QUEUE;

void enqueue(QUEUE *queue, void* temp)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode -> data = temp;
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

void* dequeue(QUEUE *delete)
{
    delete -> count--;
    NODE* temp = delete -> head;
    delete -> head = delete -> head -> next;
    void* data = temp -> data;
    free (temp);  //deleteing it
    return data;
}

bool isEmpty(QUEUE *q)
{
    if (q -> count == 0)
    {
        return true;
    }

    if (q -> count != 0)
    {
        return false;
    }
    return 0;
}


void dumpList(QUEUE *q)
{
    NODE *curr = q -> head;

    while (curr != NULL)
    {
        printf("%s\n", curr -> data);
        curr = curr -> next;
    }
}