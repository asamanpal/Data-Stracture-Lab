//  Perform linear search in an array. Test all cases of search( best, average and worst). Display the number of comparisons in above cases.


#include <stdio.h>

int linear_search_with_count(const int a[], int n, int key, int *comparisons) {
    int i;
    *comparisons = 0;
    for (i = 0; i < n; ++i) {
        (*comparisons)++;
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main(void) {
    /* --- test array and size --- */
    const int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121 };
    const int n = sizeof(arr) / sizeof(arr[0]);

    int case_comp, idx;

    /* Best-case: target = first element */
    idx = linear_search_with_count(arr, n, arr[0], &case_comp);
    printf("Best case:     found %d at index %d — %d comparison%s\n",
           arr[0], idx, case_comp, case_comp == 1 ? "" : "s");

    /* Average-case (approx.): target = middle element */
    idx = linear_search_with_count(arr, n, arr[n/2], &case_comp);
    printf("Average case:  found %d at index %d — %d comparison%s\n",
           arr[n/2], idx, case_comp, case_comp == 1 ? "" : "s");

    /* Worst-case (found at end): target = last element */
    idx = linear_search_with_count(arr, n, arr[n-1], &case_comp);
    printf("Worst-found:   found %d at index %d — %d comparison%s\n",
           arr[n-1], idx, case_comp, case_comp == 1 ? "" : "s");

    /* Worst-case (not found): target not in list */
    idx = linear_search_with_count(arr, n, 9999, &case_comp);
    printf("Worst-miss:    not found — %d comparison%s\n",
           case_comp, case_comp == 1 ? "" : "s");

    return 0;
}










//OUTPUT

// Best case:     found 11 at index 0 ΓÇö 1 comparison
// Average case:  found 66 at index 5 ΓÇö 6 comparisons
// Worst-found:   found 121 at index 10 ΓÇö 11 comparisons
// Worst-miss:    not found ΓÇö 11 comparisons