#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {  
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteBegin() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
        printf("Node deleted (list is now empty).\n");
        return;
    }

    struct Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    head = head->next;
    last->next = head;

    printf("Node deleted: %d\n", temp->data);
    free(temp);
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
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(value);
    }

    display();

    printf("\nDeleting from beginning...\n");
    deleteBegin();

    display();

    return 0;
}
