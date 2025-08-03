// Store some elements in an 1-D array. Display the total size of the array in bytes and physical addresses of all elements.

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // Define a 1-D array
    int n = sizeof(arr) / sizeof(arr[0]);  // Number of elements

    printf("Total size of the array in bytes: %lu \n", sizeof(arr));
    printf("Addresses of all elements:\n");

    for (int i = 0; i < n; i++) {
        printf("Address of arr[%d] = %p\n", i, (void*)&arr[i]);
    }

    return 0;
}



// OUTPUT :-

// Total size of the array in bytes: 20
// Addresses of all elements:
// Address of arr[0] = 0061FF04
// Address of arr[1] = 0061FF08
// Address of arr[2] = 0061FF0C
// Address of arr[3] = 0061FF10
// Address of arr[4] = 0061FF14
