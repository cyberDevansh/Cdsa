#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL; 

void insertAtEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
       	return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode; 
    } else {
        tail->next = newNode;
        tail = newNode;        
    }
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
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    display();
    return 0;
}
// time complexity: O(1) for each insertion at end