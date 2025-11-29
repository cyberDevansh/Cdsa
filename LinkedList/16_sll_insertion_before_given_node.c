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
        printf("Memory full.\n");
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

void insertBefore(int target, int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot insert before %d\n", target);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (head->data == target)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != target)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Target node %d not found.\n", target);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    int n, value, target, newValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert(value);
    }

    display();

    printf("\nEnter the value of the node BEFORE which you want to insert: ");
    scanf("%d", &target);

    printf("Enter the new value to insert: ");
    scanf("%d", &newValue);

    insertBefore(target, newValue);

    display();

    return 0;
}
