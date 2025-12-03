#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d inserted.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    int deleted = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("%d deleted.\n", deleted);
}


void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    int i = front;
    printf("Circular Queue: ");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
