// DEQUE implementation using circular array
#include <stdio.h>
#define SIZE 5  

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int x)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow! DEQUE is full.\n");
        return;
    }

    if (front == -1) 
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }

    deque[front] = x;
}

void insertRear(int x)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow! DEQUE is full.\n");
        return;
    }

    if (front == -1) 
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Underflow! DEQUE is empty.\n");
        return;
    }

    printf("Deleted element = %d\n", deque[front]);

    if (front == rear) 
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void deleteRear()
{
    if (rear == -1)
    {
        printf("Underflow! DEQUE is empty.\n");
        return;
    }

    printf("Deleted element = %d\n", deque[rear]);

    if (front == rear) 
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void getFront()
{
    if (front == -1)
        printf("DEQUE is empty.\n");
    else
        printf("Front element = %d\n", deque[front]);
}

void getRear()
{
    if (rear == -1)
        printf("DEQUE is empty.\n");
    else
        printf("Rear element = %d\n", deque[rear]);
}

void display()
{
    if (front == -1)
    {
        printf("DEQUE is empty.\n");
        return;
    }

    printf("DEQUE: ");
    int i = front;

    while (i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", deque[rear]);
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);
    display();

    deleteFront();
    deleteRear();
    display();

    getFront();
    getRear();

    return 0;
}