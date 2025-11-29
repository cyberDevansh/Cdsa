#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtPosition(int value, int pos) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (pos == 1) {
        if (head == NULL) {
            head = newNode;
            newNode->next = head; 
        } else {
            struct Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }

            newNode->next = head;
            head = newNode;
            temp->next = head;  
        }

        return;
    }

    struct Node *temp = head;
    int i;


    for (i = 1; i < pos - 1; i++) {

        if (temp->next == head) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtPosition(value, i + 1);
    }

    display();

    printf("\nEnter value to insert: ");
    scanf("%d", &value);

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    insertAtPosition(value, pos);

    display();

    return 0;
}
