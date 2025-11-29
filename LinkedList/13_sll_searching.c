#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


int search(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {  
            return 1;
        }
        temp = temp->next; 
    }
    return 0; 
}

int main() {
  
    struct Node *head = NULL, *second = NULL, *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    if (search(head, key)) {
        printf("Value %d found in linked list.\n", key);
    } else {
        printf("Value %d NOT found in linked list.\n", key);
    }

    return 0;
}
