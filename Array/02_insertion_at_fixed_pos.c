#include <stdio.h>
// the last element gets overwritten inthis
int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int num, pos;

    printf("Position to insert (0-4): ");
    scanf("%d", &pos);
    printf("Number to insert: ");
    scanf("%d", &num);
    for( int i=4; i>pos; i-- ) {
        A[i] = A[i-1];
    }
    A[pos] = num;
    for( int i=0; i<5; i++ ) {
        printf("%d ", A[i]);
    }
   
    return 0;
}
