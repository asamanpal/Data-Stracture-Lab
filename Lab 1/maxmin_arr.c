// Store some elements in an integer array. Find the minimum and maximum element in the array.


#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}




// OUTPUT


// Enter number of elements: 4
// Enter 4 elements:
// 34
// 56
// 43
// 23
// Minimum element: 23
// Maximum element: 56