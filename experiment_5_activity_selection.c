#include <stdio.h>

typedef struct {
    int id;
    int start;
    int finish;
} Activity;

void sortActivities(Activity a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].finish > a[j + 1].finish) {
                Activity temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectActivities(Activity a[], int n) {
    sortActivities(a, n);
    printf("Selected Activities: A%d", a[0].id);
    int lastFinish = a[0].finish;
    for (int i = 1; i < n; i++) {
        if (a[i].start >= lastFinish) {
            printf(" A%d", a[i].id);
            lastFinish = a[i].finish;
        }
    }
    printf("\n");
}

int main() {
    Activity a[] = {
        {1, 1, 4}, {2, 3, 5}, {3, 0, 6}, {4, 5, 7},
        {5, 3, 9}, {6, 5, 9}, {7, 6, 10}, {8, 8, 11}
    };
    int n = sizeof(a) / sizeof(a[0]);
    selectActivities(a, n);
    return 0;
}
