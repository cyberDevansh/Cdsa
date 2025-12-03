#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }

    printf("%d deleted.\n", queue[front]);

    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;
    }
}
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
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
// time complexity:
// Enqueue: O(1)
// Dequeue: O(1)
// Peek: O(1)