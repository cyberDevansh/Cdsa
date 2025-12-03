// #include <stdio.h>
// #define SIZE 10

// int deque[SIZE];
// int front = -1, rear = -1;

// void insertFront(int value) {
//     if (front == 0 && rear == SIZE - 1 || front == rear + 1) {
//         printf("DEQUE is FULL\n");
//         return;
//     }

//     if (front == -1) { 
//         front = rear = 0;
//     }
//     else if (front == 0) {
//         front = SIZE - 1;
//     }
//     else {
//         front--;
//     }

//     deque[front] = value;
// }

// void insertRear(int value) {
//     if (front == 0 && rear == SIZE - 1 || front == rear + 1) {
//         printf("DEQUE is FULL\n");
//         return;
//     }

//     if (front == -1) {
//         front = rear = 0;
//     }
//     else if (rear == SIZE - 1) {
//         rear = 0;
//     }
//     else {
//         rear++;
//     }

//     deque[rear] = value;
// }

// void deleteFront() {
//     if (front == -1) {
//         printf("DEQUE is EMPTY\n");
//         return;
//     }

//     printf("Deleted from front: %d\n", deque[front]);

//     if (front == rear) {
//         front = rear = -1;
//     }
//     else if (front == SIZE - 1) {
//         front = 0;
//     }
//     else {
//         front++;
//     }
// }

// void deleteRear() {
//     if (front == -1) {
//         printf("DEQUE is EMPTY\n");
//         return;
//     }

//     printf("Deleted from rear: %d\n", deque[rear]);

//     if (front == rear) {
//         front = rear = -1;
//     }
//     else if (rear == 0) {
//         rear = SIZE - 1;
//     }
//     else {
//         rear--;
//     }
// }

// void display() {
//     if (front == -1) {
//         printf("DEQUE is EMPTY\n");
//         return;
//     }

//     printf("DEQUE: ");

//     int i = front;
//     while (i != rear) {
//         printf("%d ", deque[i]);
//         i = (i + 1) % SIZE;
//     }

//     printf("%d\n", deque[rear]);
// }

// int main() {
//     insertRear(10);
//     insertRear(20);
//     insertFront(5);
//     insertFront(2);

//     display();

//     deleteFront();
//     deleteRear();

//     display();

//     return 0;
// }
// // Time Complexity:
// // Insertion at Front: O(1)
// // Insertion at Rear: O(1)
// // Deletion from Front: O(1)
// // Deletion from Rear: O(1)
// // Display: O(n)
