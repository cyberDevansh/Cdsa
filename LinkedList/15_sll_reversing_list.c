// reversing a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display()
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot reverse.\n");
        return;
    }

    while (current != NULL)
    {
        nextNode = current->next;   
        current->next = prev;     
        prev = current;            
        current = nextNode;         
    }

    head = prev; 
}

int main()
{
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert(value);
    }

    printf("\nOriginal List:\n");
    display();

    reverse();

    printf("\nReversed List:\n");
    display();

    return 0;
}
