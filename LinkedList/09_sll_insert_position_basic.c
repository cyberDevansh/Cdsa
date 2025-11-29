#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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
        newNode->next = head;
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
    temp->next = newNode;
}

void display() {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
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
// time complexity: O(n) for each insertion at given position