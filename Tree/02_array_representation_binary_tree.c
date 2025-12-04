#include <stdio.h>
#define MAX 50

int tree[MAX];
void initTree() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}
void insert(int value, int index) {
    if (index >= MAX) {
        printf("Index out of range.\n");
        return;
    }
    tree[index] = value;
}
void display() {
    printf("Binary Tree (Array Representation):\n");
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1)
            printf("Index %d → %d\n", i, tree[i]);
    }
}

int main() {
    initTree();
    insert(10, 0); 
    insert(20, 1);
    insert(30, 2);
    insert(40, 3);
    insert(50, 4);
    insert(60, 5);

    display();

    return 0;
}
