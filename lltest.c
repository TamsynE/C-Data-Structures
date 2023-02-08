#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ll.c"

int main() {

    // CREATE LIST
    LLIST* list1 = CreateList();
  
    Add(list1, (void*)12);
    Add(list1, (void*)1);
    Add(list1, (void*)3);

    //test printList()
    printList(list1);

    //test WalkToIndex() with Add()
    NODE* idx0d = WalkToIndex(list1, 0);
    printf("This is in index 0: %d\n", (int)idx0d-> data);
    NODE* idx1d = WalkToIndex(list1, 1);
    printf("This is in index 1: %d\n", (int)idx1d-> data);
    NODE* idx2d = WalkToIndex(list1, 2);
    printf("This is in index 2: %d\n", (int)idx2d-> data);

    //test IndexOf()
    int idx0p = IndexOf(list1, (void*)12, 0);
    printf("%d is at index %d\n", (int)idx0d-> data, idx0p);
    int idx1p = IndexOf(list1, (void*)1, 0);
    printf("%d is at index %d\n", (int)idx1d-> data, idx1p);
    int idx2p = IndexOf(list1, (void*)3, 0);
    printf("%d is at index %d\n", (int)idx2d-> data, idx2p);
    //test count
    printf("The count is %d\n", list1 -> count);

    //test Contains()
    bool tf0 = Contains(list1, (void*)12);
    bool tf1 = Contains(list1, (void*)1);
    bool tf2 = Contains(list1, (void*)3);
    bool tf3 = Contains(list1, (void*)23);

    printf("Does ll Contain %d: %d\n", (int)idx0d-> data, tf0);
    printf("Does ll Contain %d: %d\n", (int)idx1d-> data, tf1);
    printf("Does ll Contain %d: %d\n", (int)idx2d-> data, tf2);
    printf("Does ll Contain %d: %d\n", 23, tf3);

    //test Insert()
    Insert(list1, (void*)9, 1);
    Insert(list1, (void*)0, 0);
    Insert(list1, (void*)5, 5);

    printList(list1);

    //test RemoveAt()
    RemoveAt(list1, 5); 
    RemoveAt(list1, 0);
    RemoveAt(list1, 2);

    printList(list1);

    //test Clear()
    Clear(list1);

    LLIST* list2 = CreateList();
    Insert(list2, (void*)0, 0);
    Insert(list2, (void*)1, 1);
    Insert(list2, (void*)2, 2);
    Insert(list2, (void*)3, 3);
    Insert(list2, (void*)4, 4);
    printf("  \n");
    printf("NEW LIST...\n");

    printList(list2);

    printf("Now, to remove 4\n");
    RemoveNode(list2, (void*)4);
    printList(list2);

    printf("Now, to remove 0\n");
    RemoveNode(list2, (void*)0);
    printList(list2);

    printf("Now, to remove 2\n");
    RemoveNode(list2, (void*)2);
    printList(list2);
    Clear(list2);
    printList(list2);

    // Remove node doesn't work after clearing list

    return 0;
}