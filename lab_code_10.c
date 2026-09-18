// Merge Sort 
#include <stdio.h>

void merge(int A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];
    while (i <= mid && j <= high) {
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
        temp[k++] = A[i++];
    while (j <= high)
        temp[k++] = A[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        A[i] = temp[k];
}
void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main() {
    int A[5] = {5, 2, 8, 1, 3};
    int n = 5;
    mergeSort(A, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}