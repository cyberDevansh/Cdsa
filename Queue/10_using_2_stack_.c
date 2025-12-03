#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    stack1[++top1] = x;
}

void push2(int x) {
    stack2[++top2] = x;
}

int pop1() {
    return stack1[top1--];
}

int pop2() {
    return stack2[top2--];
}
void enqueue(int x) {
    push1(x);
    printf("%d enqueued\n", x);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    return pop2();
}
int peek() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    return stack2[top2];
}
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    printf("Front element: %d\n", peek());

    enqueue(40);
    enqueue(50);

    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    return 0;
}
// time complexity:
// Enqueue: O(1)
// Dequeue: O(n)
// Peek: O(n)
// Space complexity: O(n) 