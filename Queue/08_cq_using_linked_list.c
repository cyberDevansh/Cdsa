#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *tail = NULL; 
void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    }
    else {
        newNode->next = tail->next;  
        tail->next = newNode;        
        tail = newNode;             
    }

    printf("%d enqueued.\n", value);
}
void dequeue() {
    if (tail == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = tail->next;

    if (tail == temp) {
        printf("Dequeued: %d\n", temp->data);
        tail = NULL;
        free(temp);
    }
    else {
        printf("Dequeued: %d\n", temp->data);
        tail->next = temp->next;
        free(temp);
    }
}
void peek() {
    if (tail == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element: %d\n", tail->next->data);
}
void display() {
    if (tail == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Circular Queue: ");
    struct Node *temp = tail->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
