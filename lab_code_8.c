//binary search — Iterative:
#include <stdio.h>
int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 40;
    int low = 0, high = n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (A[mid] == key) {
            printf("Element found at index %d", mid);
            found = 1;
            break;
        }
        else if (key < A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (found == 0)
        printf("Element not found");
    return 0;
}