#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Overflow! Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)   
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Underflow! Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Dequeued: %d\n", temp->data);

    front = front->next;

    if (front == NULL)  
        rear = NULL;

    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
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
}
