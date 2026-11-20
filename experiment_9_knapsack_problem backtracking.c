#include <stdio.h>

int maxProfit = 0;

void knapsackBacktrack(int i, int n, int w, int p, int W, int wt[], int val[]) {
    if (w <= W && p > maxProfit) {
        maxProfit = p;
    }
    if (i == n || w >= W) {
        return;
    }
    if (w + wt[i] <= W) {
        knapsackBacktrack(i + 1, n, w + wt[i], p + val[i], W, wt, val);
    }
    knapsackBacktrack(i + 1, n, w, p, W, wt, val);
}

int main() {
    int val[] = {40, 30, 20, 10};
    int wt[] = {4, 5, 4, 3};
    int W = 10;
    int n = sizeof(val) / sizeof(val[0]);

    knapsackBacktrack(0, n, 0, 0, W, wt, val);
    printf("Optimal Profit (Backtracking): %d\n", maxProfit);
    return 0;
}
