// inserting AFTER a given node in a singly linked list
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
        printf("Memory allocation failed.\n");
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

void insertAfter(int key, int value)
{
    struct Node *temp = head;

  
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found. Insertion failed.\n", key);
        return;
    }

  
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next; 
    temp->next = newNode;      

    printf("Inserted %d after %d successfully.\n", value, key);
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

int main()
{
    int n, value, key, newValue, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert(value);
    }

    display();

    printf("\nEnter the node value after which to insert: ");
    scanf("%d", &key);

    printf("Enter value of new node: ");
    scanf("%d", &newValue);

    insertAfter(key, newValue);

    display();

    return 0;
}
