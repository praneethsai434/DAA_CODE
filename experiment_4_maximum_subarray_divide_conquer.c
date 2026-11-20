#include <stdio.h>
#include <limits.h>

// Structure to return the maximum subarray result
typedef struct {
    int low;
    int high;
    int sum;
} SubarrayResult;

// Counter for element inspections / additions
long long bruteForceSteps = 0;
long long divideConquerSteps = 0;
long long kadaneSteps = 0;

// =========================================================================
// 1. DIVIDE AND CONQUER APPROACH (O(n log n))
// =========================================================================
SubarrayResult findMaxCrossingSubarray(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--) {
        divideConquerSteps++;
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid + 1;

    for (int j = mid + 1; j <= high; j++) {
        divideConquerSteps++;
        sum += arr[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    SubarrayResult res = {maxLeft, maxRight, leftSum + rightSum};
    return res;
}

SubarrayResult findMaximumSubarray(int arr[], int low, int high) {
    if (low == high) {
        divideConquerSteps++;
        SubarrayResult res = {low, high, arr[low]};
        return res;
    }

    int mid = low + (high - low) / 2;

    SubarrayResult leftRes = findMaximumSubarray(arr, low, mid);
    SubarrayResult rightRes = findMaximumSubarray(arr, mid + 1, high);
    SubarrayResult crossRes = findMaxCrossingSubarray(arr, low, mid, high);

    if (leftRes.sum >= rightRes.sum && leftRes.sum >= crossRes.sum)
        return leftRes;
    else if (rightRes.sum >= leftRes.sum && rightRes.sum >= crossRes.sum)
        return rightRes;
    else
        return crossRes;
}

// =========================================================================
// 2. BRUTE-FORCE APPROACH (O(n^2))
// =========================================================================
SubarrayResult bruteForceMaxSubarray(int arr[], int n) {
    SubarrayResult best = {0, 0, INT_MIN};

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            bruteForceSteps++;
            currentSum += arr[j];
            if (currentSum > best.sum) {
                best.sum = currentSum;
                best.low = i;
                best.high = j;
            }
        }
    }
    return best;
}

// =========================================================================
// 3. KADANE'S ALGORITHM (Linear O(n))
// =========================================================================
SubarrayResult kadaneMaxSubarray(int arr[], int n) {
    int maxSoFar = arr[0];
    int currentMax = arr[0];
    int start = 0, end = 0, s = 0;

    kadaneSteps++;
    for (int i = 1; i < n; i++) {
        kadaneSteps++;
        if (arr[i] > currentMax + arr[i]) {
            currentMax = arr[i];
            s = i;
        } else {
            currentMax += arr[i];
        }

        if (currentMax > maxSoFar) {
            maxSoFar = currentMax;
            start = s;
            end = i;
        }
    }

    SubarrayResult res = {start, end, maxSoFar};
    return res;
}

int main() {
    printf("========================================================================\n");
    printf(" EXPERIMENT 4: MAXIMUM SUBARRAY PROBLEM (DIVIDE & CONQUER VS BASELINES)\n");
    printf("========================================================================\n\n");

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4, -2, 6, -3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array (%d elements):\n[ ", n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("]\n\n");

    // 1. Divide and Conquer
    divideConquerSteps = 0;
    SubarrayResult dcRes = findMaximumSubarray(arr, 0, n - 1);

    // 2. Brute Force
    bruteForceSteps = 0;
    SubarrayResult bfRes = bruteForceMaxSubarray(arr, n);

    // 3. Kadane's
    kadaneSteps = 0;
    SubarrayResult kdRes = kadaneMaxSubarray(arr, n);

    printf("--- Results ---\n");
    printf("1. Divide and Conquer:\n");
    printf("   Maximum Subarray: indices [%d .. %d], Max Sum = %d\n", dcRes.low, dcRes.high, dcRes.sum);
    printf("   Subarray elements: [ ");
    for (int i = dcRes.low; i <= dcRes.high; i++) printf("%d ", arr[i]);
    printf("]\n   Steps / operations: %lld\n\n", divideConquerSteps);

    printf("2. Brute Force Baseline (O(n^2)):\n");
    printf("   Maximum Subarray: indices [%d .. %d], Max Sum = %d\n", bfRes.low, bfRes.high, bfRes.sum);
    printf("   Steps / operations: %lld\n\n", bruteForceSteps);

    printf("3. Kadane's Algorithm (O(n)):\n");
    printf("   Maximum Subarray: indices [%d .. %d], Max Sum = %d\n", kdRes.low, kdRes.high, kdRes.sum);
    printf("   Steps / operations: %lld\n\n", kadaneSteps);

    printf("------------------------------------------------------------------------\n");
    printf("%-24s | %-16s | %-16s\n", "Paradigm / Approach", "Time Complexity", "Auxiliary Space");
    printf("------------------------------------------------------------------------\n");
    printf("%-24s | %-16s | %-16s\n", "Divide and Conquer", "O(n log n)", "O(log n) stack");
    printf("%-24s | %-16s | %-16s\n", "Brute Force", "O(n^2)", "O(1)");
    printf("%-24s | %-16s | %-16s\n", "Kadane's Algorithm", "O(n)", "O(1)");
    printf("------------------------------------------------------------------------\n");
    printf("Recurrence Relation for Divide and Conquer:\n");
    printf("T(n) = 2*T(n/2) + Theta(n) => by Master Theorem Case 2: T(n) = Theta(n log n).\n");

    return 0;
}
