#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int getLength() {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;      
        temp = temp->next;  
    }

    return count;
}

void display() {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

int main() {
    int value;

    printf("Enter values for nodes (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1)
            break;
        insert(value);
    }

    display();

    printf("\nLength of Linked List = %d\n", getLength());

    return 0;
}
