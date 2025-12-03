// sll=single linked list
// dll=doubly linked list
// cll=circular linked list


#include<stdio.h>
#include<stdlib.h>
// we use this at end of the each program to free the all nodes
void freeList() {
    struct Node *temp = head;
    struct Node *nextNode;

    while (temp != NULL) {
        nextNode = temp->next; 
        free(temp);           
        temp = nextNode;      
    }
    head = NULL; 
}
