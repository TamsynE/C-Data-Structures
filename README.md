# C-Data-Structures
# Usage
//This project creates a stack, queue, and a linked list in the coding language C.  In the stack library, we are able to push or pop a node from the top of the stack.  In the queue library, we are able to enqueue or dequeue a node from the end of the queue.  In the linked list library, we are able to insert or remove a node from anywhere in the linked list.
This project implements the stack, queue, and linked list data structures in the C language and makes them available to our operating system components.

# Installation
The steps required to run this program would be to first enter the file the project is currently in.  From there, we will need to compile it by using gcc (filename) (filename) -o (test file name.exe) for as many files you have.  If there are no errors, you can run the program by using ./(test file name.exe).

# Dependencies
- stdbool.h
- stdio.h
- stdlib.h

# Stack
The Stack is a Last In First Out (LIFO) data structure that uses the Push and Pop operations to add and remove data. It is implemented on top of arrays and linked lists. // The Linked List Library is used to implement the Stack. 

- struct Stack
- struct Stack* createStack
- int isFull
- int isEmpty
- void push
- int pop

# Queue
The Queue operates in a First In First Out (FIFO) order and uses Enqueue and Dequeue operations to add and remove data. // The Linked List Library is used to implement the Queue.

- typedef struct node
- typedef struct queue
- void enqueue
- void* dequeue
- bool isEmpty
- void dumpQueue

# Linked List
The Linked List is a generic data structure that grows and shrinks dynamically. It is implemented with a series of individually allocated nodes that point from one item to the next, in a specified order. Nodes can be added and inserted arbitrarily in O(1) time if a link to the insertion/deletion point is known ahead of time. Searching a linked-list is an O(n) operation.

Our Linked List Library implements a doubly-linked list that tracks pointers for the head and tail of the list, which point to the first and last node, respectively.

- typedef struct node
- typedef struct LLIST
- LLIST* CreateList
- void* Add
- NODE* WalkToIndex
- int IndexOf
- bool Contains
- void Insert
- void* RemoveNode
- void* RemoveAt
- void Clear
- void printList
