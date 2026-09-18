//binary search — Recursive:
#include <stdio.h>

int binarySearch(int A[], int low, int high, int key) {

    if (low > high)
        return -1;
    int mid = (low + high) / 2;

    if (A[mid] == key)
        return mid;
    else if (key < A[mid])
        return binarySearch(A, low, mid - 1, key);
    else
        return binarySearch(A, mid + 1, high, key);
}
int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int key = 40;

    int result = binarySearch(A, 0, 4, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");
    return 0;
}