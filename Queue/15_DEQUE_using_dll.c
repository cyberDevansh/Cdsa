// DEQUE implementation using Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL) { 
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }

    printf("Inserted %d at front.\n", value);
}

void insertRear(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d at rear.\n", value);
}

void deleteFront() {
    if (front == NULL) {
        printf("DEQUE is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted %d from front.\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("DEQUE is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted %d from rear.\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

void display() {
    struct Node *temp = front;

    if (temp == NULL) {
        printf("DEQUE is empty.\n");
        return;
    }

    printf("DEQUE: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

int main() {
    insertFront(10);
    insertFront(20);
    insertRear(5);
    insertRear(1);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
