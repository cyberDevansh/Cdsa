#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("CLL is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    while (1)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

        if (temp == head)
            break;
    }

    printf("(back to head)\n");
}

void reverse()
{
    if (head == NULL || head->next == head)
        return;

    struct Node *prev = NULL, *current = head, *nextNode = NULL;

    while (1)
    {
        nextNode = current->next; 
        current->next = prev;     
        prev = current;           

        if (nextNode == head)
            break;

        current = nextNode;
    }

    head->next = prev;  
    current->next = prev; 

    head = prev;  
}

int main()
{
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(value);
    }

    printf("\nOriginal CLL:\n");
    display();

    reverse();

    printf("\nReversed CLL:\n");
    display();

    return 0;
}
