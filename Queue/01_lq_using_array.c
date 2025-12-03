#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;  
    }

    rear++;
    queue[rear] = value;
    printf("%d inserted\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}
//  this is also 
// int dequeue() {
//     if (front == -1) {              
//         printf("Queue is EMPTY.\n");
//         return -1;
//     }

//     int removed = queue[front];

//     if (front == rear) {
//         front = rear = -1;
//     } else {
//         front++;
//     }

//     return removed;
// }


void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
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
                printf("Enter value to insert: ");
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
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
// time complexity:
// Enqueue: O(1)
// Dequeue: O(1)
// Peek: O(1)