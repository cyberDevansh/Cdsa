#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFromEnd()
{
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted node: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted node: %d\n", temp->data);

    temp->prev->next = NULL; 
    free(temp);
}

void display()
{
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert(value);
    }

    display();

    deleteFromEnd();

    display();

    return 0;
}
