#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtPosition(int value, int pos) {
    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 0) {
        struct Node *newNode = malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    struct Node *temp = head;
    int i = 0;

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    //  this logic also work 
    
    // if (temp->next != NULL) {
    //     newNode->next->prev=newNode;
    // }
    // temp->next=newNode;

}

void display() {
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtPosition(10, 0); 
    insertAtPosition(30, 1); 
    insertAtPosition(20, 1);

    display();
    return 0;
}
