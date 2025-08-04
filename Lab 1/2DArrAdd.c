// Store some elements in 2-D array. Display the addresses of all elements.

#include <stdio.h>

int main() {
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("Element\tAddress\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t%p\n", array[i][j], (void*)&array[i][j]);
        }
    }

    return 0;
}





// OUTPUT

// Element Address
// 1       0061FEE8
// 2       0061FEEC
// 3       0061FEF0
// 4       0061FEF4
// 5       0061FEF8
// 6       0061FEFC
// 7       0061FF00
// 8       0061FF04
// 9       0061FF08
// 10      0061FF0C
// 11      0061FF10
// 12      0061FF14
