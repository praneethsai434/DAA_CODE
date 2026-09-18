//insertion sort
#include <stdio.h>

int main() {
    int A[5] = {5, 2, 4, 6, 1};
    int n = 5;
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}