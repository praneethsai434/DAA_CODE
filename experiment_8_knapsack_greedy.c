
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n = 4;
    int W = 7;

    int weight[] = {1, 3, 4, 5};
    int profit[] = {1, 4, 5, 7};

    int dp[n + 1][W + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]],

                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum Profit = %d\n", dp[n][W]);

    // Display selected items
    int w = W;

    printf("Selected Items:\n");

    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("Item %d\n", i);
            w = w - weight[i - 1];
        }
    }

    return 0;
}
