#include <stdio.h>
#define SIZE 10

int main() {
    int pos;
    int size = SIZE;
    int arr[SIZE] = {11,12,13,14,15,16,16,17,18,19};

    printf("Array before deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter index position to delete: ");
    scanf("%d", &pos);

    if (pos >= size || pos < 0) {
        printf("Invalid position.\n");
    } else {
        arr[pos] = arr[size - 1];  
        size--;
    }

    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
