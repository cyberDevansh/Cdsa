#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    // temp = last node
    // prev = second last node
    prev->next = head;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("CLL: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    deleteEnd();
    display();

    deleteEnd();
    display();

    return 0;
}
