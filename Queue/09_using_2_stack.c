// Queue implementation using two stacks
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
void push2(int x) { stack2[++top2] = x; }

int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

void enqueue(int x)
{
    push1(x);
    printf("%d enqueued\n", x);
}
int dequeue()
{
    if (isEmpty1() && isEmpty2())
    {
        printf("Queue Underflow! No elements.\n");
        return -1;
    }

    if (isEmpty2())
    {
        while (!isEmpty1())
        {
            push2(pop1());
        }
    }

    return pop2();
}
int peek()
{
    if (isEmpty1() && isEmpty2())
    {
        printf("Queue is empty.\n");
        return -1;
    }

    if (isEmpty2())
    {
        while (!isEmpty1())
        {
            push2(pop1());
        }
    }

    return stack2[top2];
}
void display()
{
    if (isEmpty1() && isEmpty2())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = top2; i >= 0; i--)
    {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Queue Using Two Stacks ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            if (value != -1)
                printf("Dequeued: %d\n", value);
            break;

        case 3:
            value = peek();
            if (value != -1)
                printf("Front element: %d\n", value);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
// time complexity:
// Enqueue: O(1)
// Dequeue: O(n)
// Peek: O(n)
// Space complexity: O(n) 