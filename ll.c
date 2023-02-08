#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void* data; 
    int size; // keeps track fo size of what is stored in data - sort by size
    struct node* prev;
    struct node* next;

} NODE;

typedef struct {
    NODE* head;
    NODE* tail;
    int count;
} LLIST;

// CREATE LIST
LLIST* CreateList()
{
    LLIST* list = malloc(sizeof(LLIST));
    list -> head = NULL;
    list -> tail = NULL;
    list -> count = 0;

    return list;
};

void Add(LLIST* list, void* data)
{
    NODE* curr = (NODE*)malloc(sizeof(NODE));
    curr -> data = data;

    // add to end of list
    if(list -> count > 0)
    {
        curr -> prev = list -> tail;
        list -> tail -> next = curr;
        list -> tail = curr;
        curr -> next = NULL;
        list -> count++;
    }
    // add to beginning
    else if(list -> count == 0)
    {
        list -> head = curr;
        curr -> prev = NULL;
        list -> tail = curr;
        list -> count++;
    }
}

NODE* WalkToIndex(LLIST* list, int index)
{
    if(index < 0 || index > list -> count)
    {
        printf("Index out of Range: the list is not that long");
    }
    NODE* curr = list -> head;

    for(int i = 0; i < index; i++)
    {
        curr = curr -> next;
    }
    return curr;
}

int IndexOf(LLIST* list, void* data, int startAtIndex)
{
    int idx = startAtIndex;
    NODE* curr = (NODE*)malloc(sizeof(NODE));
    curr = WalkToIndex(list, startAtIndex);
    while (curr != NULL)
    {
        if(curr -> data == data)
        {
            return idx;
        }

        curr = curr -> next;
        idx++;
    }
    return -1;
}

bool Contains(LLIST* list, void* data)
{
    if(IndexOf(list, data, 0) >= 0)
    {
        return true;
    }
    return false;
}

void Insert(LLIST* list, void* data, int index)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    
    newNode -> data = data;

    // with nothing in list yet
    if(list -> count == 0 && index == 0)
    {
        Add(list, data);
    }

    // before first node
    else if(index == 0)
    {
        newNode -> next = list -> head;
        list -> head -> prev = newNode;
        newNode -> prev = NULL;
        list -> head = newNode;
        list -> count++;
    }

    else if(index > 0 && index < list -> count)
    {
        NODE* nodePrev = WalkToIndex(list, index -1);
        NODE* nodeAfter = WalkToIndex(list, index);

        nodePrev -> next = newNode;
        newNode -> prev = nodePrev;
        newNode -> next = nodeAfter;
        nodeAfter -> prev = newNode;

        list -> count++;
    }

    else if(index == list -> count)
    {
        NODE* nodePrev = WalkToIndex(list, index-1);
        // NODE* nodeAfter = NULL;
        // newNode -> next = nodeAfter;
        newNode -> prev = nodePrev;
        list -> tail -> next = newNode;
        list -> tail = newNode;
        list -> count++;
    }
    
    else if(index < 0 || index > list -> count)
    {
        printf("IndexOutOfRange: that index is not part of the list");
    }
}

void RemoveNode(LLIST* list, void* data)
{
    if(!Contains(list, data))
    {
        printf("Error: This list does not contain that data.\n");
    }

    int index = IndexOf(list, data, 0);
    NODE* node = WalkToIndex(list, index);

    // beginning of list
    if(index == 0)
    {
        //update head to be new head
        list -> head = WalkToIndex(list, index +1);
    }

    // if somewhere in the list
    else if(index > 0 && index < list -> count -1)
    {
        NODE* nodePrev = node -> prev;
        NODE* nodeAfter = node -> next;

        nodePrev -> next = nodeAfter;
    }

    // end of list
    else if(index == list -> count -1)
    {
        NODE* nodePrev = node -> prev;
        NODE* oldTail = list -> tail;
        list -> tail = nodePrev;
        list -> tail -> next = NULL;
        free(oldTail);
    }
    node = NULL;
    list -> count--;
}

void RemoveAt(LLIST* list, int index)
{
    NODE* node = WalkToIndex(list, index);

    // beginning of list
    if(index == 0)
    {
        //update head to be new head
        list -> head = WalkToIndex(list, index +1);
        
    }

    // if somewhere in the list
    else if(index > 0 && index < list -> count -1)
    {
        NODE* nodePrev = node -> prev;
        NODE* nodeAfter = node -> next;

        nodePrev -> next = nodeAfter;
    }

    // end of list
    else if(index == list -> count -1)
    {
        NODE* nodePrev = node -> prev;
        NODE* oldTail = list -> tail;
        list -> tail = nodePrev;
        list -> tail -> next = NULL;
        free(oldTail);
    }
    node = NULL;
    list -> count--;
}

// DESTROY LIST
void Clear(LLIST* list)
{
    list -> tail = list -> head = NULL;
    list -> count = 0;

    NODE* curr = list -> head;
    while(curr != NULL)
    {
        NODE* next = curr -> next;
        free(curr);
        curr = next;
    }
    
    free(list);
}

// DUMP LIST
void printList(LLIST* list)
{
    NODE* curr = list -> head;
    printf("LINKED LIST:\n");
    while(curr != NULL)
    {
        printf("%d\n", (int)curr->data);
        curr = curr -> next;
    }
}

//1) Insert Node Before & After Target?? - same as Insert() function?
//2) Sort List by Values??