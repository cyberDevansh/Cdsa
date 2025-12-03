#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
void enqueue(int x) {
    push(x);
    printf("%d enqueued\n", x);
}
int dequeue() {
    if (top == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    int x = pop();
    if (top == -1)
        return x;
    int item = dequeue();

    push(x);

    return item;
}

void display() {
    if (top == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    enqueue(50);
    display();

    return 0;
}
// time complexity:
// Enqueue: O(1)
// Dequeue: O(n)
// Peek: O(n)