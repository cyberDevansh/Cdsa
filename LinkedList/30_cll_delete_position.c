#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
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

void display()
{
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

void deleteAtPosition(int pos)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (pos == 1) {
       
        if (head->next == head) {
            printf("Deleted: %d\n", head->data);
            free(head);
            head = NULL;
            return;
        }

        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }

        printf("Deleted: %d\n", head->data);

        last->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    int count = 1;
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

int main()
{
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(value);
    }

    display();

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    deleteAtPosition(pos);

    display();

    return 0;
}
