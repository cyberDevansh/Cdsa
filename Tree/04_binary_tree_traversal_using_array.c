#include <stdio.h>

#define MAX 100

int tree[MAX];
int n; 

void inorder(int index)
{
    if (index >= n) return;

    inorder(2 * index + 1); 
    printf("%d ", tree[index]);
    inorder(2 * index + 2);  
}

void preorder(int index)
{
    if (index >= n) return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void postorder(int index)
{
    if (index >= n) return;

    postorder(2 * index + 1);  
    postorder(2 * index + 2); 
    printf("%d ", tree[index]); 
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements of tree (level order):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("\nInorder Traversal: ");
    inorder(0);

    printf("\nPreorder Traversal: ");
    preorder(0);

    printf("\nPostorder Traversal: ");
    postorder(0);

    return 0;
}
