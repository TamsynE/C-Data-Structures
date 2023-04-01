/*
Linked List Test Program
Tests Linked List 
file: lltest.c
author: Tamsyn Evezard
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "project1.h"

int main() {

    // CREATE LIST
    LLIST* list1 = CreateList();
  
    Add(list1, (void*)12, 1, false);
    Add(list1, (void*)1, 3, false);
    Add(list1, (void*)3, 2, false);

    //test WalkToIndex() with Add()
    NODE* idx0d = WalkToIndex(list1, 0);
    NODE* idx1d = WalkToIndex(list1, 1);
    NODE* idx2d = WalkToIndex(list1, 2);

    int idx0 = 12;
    int size0 = 1;
    int idx1 = 1;
    int size1 = 3;
    int idx2 = 3;
    int size2 = 2;

    if((int)idx0d -> data == idx0 && (int)idx1d -> data == idx1 && (int)idx2d -> data == idx2)
    {
        printf("DATA ADDED & WALK TO INDEX SUCCESSFUL: UPDATED LIST\n");
        //test printList()
        printList(list1);

    }
    else
    {
        return EXIT_FAILURE;
    }

    if(size0 == idx0d -> size && size1 == idx1d -> size && size2 == idx2d -> size)
    {
        printf("SIZE ALLOCATION SUCCESSFUL\n");

    }
    else
    {
        return EXIT_FAILURE;
    }

    //test IndexOf()
    int idx0p = IndexOf(list1, (void*)12, 0);
    int idx1p = IndexOf(list1, (void*)1, 0);
    int idx2p = IndexOf(list1, (void*)3, 0);
    
    if(idx0p == 0 && idx1p == 1 && idx2p == 2)
    {
        printf("FIND INDEX SUCCESSFUL\n");
  
    }
    else
    {
        return EXIT_FAILURE;
    }

    //test count
    if(list1 -> count == 3)
    {
        printf("COUNT CORRECT\n");

    }
    else
    {
        return EXIT_FAILURE;
    }

    //test Contains()
    bool tf0 = Contains(list1, (void*)12);
    bool tf1 = Contains(list1, (void*)1);
    bool tf2 = Contains(list1, (void*)3);
    bool tf3 = Contains(list1, (void*)23);

    if((tf0 && tf1 && tf2 == true) && (tf3 == false))
    {
        printf("LIST CONTAINS CORRECT DATA\n");

    }
    else
    {
        return EXIT_FAILURE;
    }

    //test Insert()
    Insert(list1, (void*)9, 1, 34, false);
    Insert(list1, (void*)0, 0, 20, false);
    Insert(list1, (void*)5, 5, 19, false);
    Insert(list1, (void*)333, 10, 10, false); // should print error


    NODE* i2 = WalkToIndex(list1, 2);
    NODE* i0 = WalkToIndex(list1, 0);
    NODE* i5 = WalkToIndex(list1, 5);

    if(((int)i2 -> data == 9 && (int)i0 -> data == 0 && (int)i5 -> data == 5))
    {
        if(i2 -> size == 34 && i0 -> size == 20 && i5 -> size == 19)
        {
            printf("DATA INSERTED SUCCESSFULLY: UPDATED LIST\n");
            printList(list1);
        }
    }
    else
    {
        return EXIT_FAILURE;
    }
    
    //test RemoveAt()
    RemoveAt(list1, 5); 
    RemoveAt(list1, 0);
    RemoveAt(list1, 2);

    if(((int)WalkToIndex(list1, 0) -> data == 12 && (int)WalkToIndex(list1, 1) -> data == 9 && (int)WalkToIndex(list1, 2) -> data == 3))
    {
        if(WalkToIndex(list1, 0) -> size == 1 && WalkToIndex(list1, 1) -> size == 34 && WalkToIndex(list1, 2) -> size == 2)
        {
            printf("ITEMS REMOVED BY INDEX SUCCESSFULLY: UPDATED LIST\n");
            printList(list1);
        }
    }
    else
    {
        return EXIT_FAILURE;
    }

    //test Clear()
    Clear(list1);
    if(list1 -> count == 0)
    {
        printf("CLEARED LIST SUCCESSFULLY\n");
    }
    else
    {
        return EXIT_FAILURE;
    }

    LLIST* list2 = CreateList();
    Insert(list2, (void*)7, 0, 50, false);
    Insert(list2, (void*)0, 1, 6, false);
    Insert(list2, (void*)12, 2, 7, false);
    Insert(list2, (void*)3, 3, 4, false);
    Insert(list2, (void*)10, 4, 8, false);

    printf("\n");
    printf("NEW LIST:\n");
    printList(list2);

    //test RemoveNode()
    RemoveNode(list2, (void*)7);
    RemoveNode(list2, (void*)0);
    RemoveNode(list2, (void*)2);

    if((int)WalkToIndex(list2, 0) -> data == 12 && (int)WalkToIndex(list2, 1) -> data == 3 && (int)WalkToIndex(list2, 2) -> data == 10)
    {
        printf("LIST ITEMS REMOVED SUCCESSFULLY: UPDATED LIST\n");
        printList(list2);
    }
    else
    {
        return EXIT_FAILURE;
    }

    //test SortList()
    SortList(list2);

    if((int)WalkToIndex(list2, 0) -> data <= (int)WalkToIndex(list2, 1) -> data <= (int)WalkToIndex(list2, 2) -> data)
    {
        printf("LIST SORTED SUCCESSFULLY: UPDATED LIST\n");
        printList(list2);
    }
    else
    {
        return EXIT_FAILURE;
    }

    //test InsertBefore() and InsertAfter()
    InsertBefore(list2, (void*)100, (void*)3, 100, false);
    InsertBefore(list2, (void*)200, (void*)10, 1, false);
    InsertBefore(list2, (void*)23, (void*)23, 1, false); 

    int indx = IndexOf(list2, (void*)100, 0);
    int indx2 = IndexOf(list2,(void*)200, 0);
    int indx3 = IndexOf(list2, (void*)23, 0); // should print error

    if(indx == 0 && indx2 == 2 && indx3 == -1)
    {
        printf("DATA INSERTED BEFORE TARGETS SUCCESSFULLY: UPDATED LIST\n");
        printList(list2);
    }
    else
    {
        return EXIT_FAILURE;
    }

    InsertAfter(list2, (void*)4, (void*)12, 1, false);
    InsertAfter(list2, (void*)2, (void*)200, 1, false);
    InsertAfter(list2, (void*)23, (void*)23, 1, false); 

    int ind = IndexOf(list2, (void*)4, 0);
    int ind2 = IndexOf(list2,(void*)2, 0);
    int ind3 = IndexOf(list2, (void*)23, 0); // should print error

    if(ind == 6 && ind2 == 3 && ind3 == -1)
    {
        printf("DATA INSERTED AFTER TARGETS SUCCESSFULLY: UPDATED LIST\n");
        printList(list2);
    }
    else
    {
        return EXIT_FAILURE;
    }

    printf("ALL UNIT TESTS PASSED");
    printf("\n");
    return 0;
}
