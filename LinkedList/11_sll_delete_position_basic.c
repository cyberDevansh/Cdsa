#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 0) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted at position %d.\n", pos);
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    int i = 0;

    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted at position %d.\n", pos);
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

    head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    display();
    deleteAtPosition(1);
    display();
    return 0;
}
