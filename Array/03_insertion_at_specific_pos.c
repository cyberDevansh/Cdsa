#include <stdio.h>
int main(){
    int i, n, num, pos, arr[5];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\n arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("\n ENter the number to be inserted: ");
    scanf("%d", &num);
    printf("\n Enter the position where to insert the number: ");
    scanf("%d", &pos);
    for (i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=num;
    n=n+1;
    printf("\n The array after insertion is: \n");
    for(i=0;i<n;i++){
        printf("arr[%d] = %d ", i, arr[i]);
    }  
    return 0;
}