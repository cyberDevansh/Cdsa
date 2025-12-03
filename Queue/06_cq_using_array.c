#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
    {
        printf("Queue Overflow (Full)\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    cq[rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow (Empty)\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Circular Queue: ");

    int i = front;
    while (1)
    {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
