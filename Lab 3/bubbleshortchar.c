#include <stdio.h>


int main() {
    int n, i, j;
    char temp;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char arr[n + 1];
    printf("Enter %d characters:\n", n);
    for(i = 0; i < n; i++) {
        scanf(" %c", &arr[i]); 
    }


    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted characters in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
    return 0;
}