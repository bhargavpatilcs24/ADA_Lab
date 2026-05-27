#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findSelectedItems(int **dp, int wt[], int val[], int n, int W) {
    int i = n;
    int w = W;

    printf("\nItems included in the knapsack:\n");
    printf("-------------------------------\n");
    printf("%-10s %-10s %-10s\n", "Item #", "Weight", "Value");

    while (i > 0 && w > 0) {
        // If the value comes from the row above, the item wasn't picked
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %-6d %-10d %-10d\n", i, wt[i - 1], val[i - 1]);

            // Subtract weight and move to the remaining capacity
            w = w - wt[i - 1];
        }
        i--;
    }
    printf("-------------------------------\n");
}

void solveKnapsack() {
    int n, W, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));

    printf("Enter values of items: ");
    for (i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("Enter weights of items: ");
    for (i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // Dynamic allocation of DP table
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Fill the DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum value possible: %d\n", dp[n][W]);

    // Trace back to find items
    findSelectedItems(dp, wt, val, n, W);

    // Memory Cleanup
    for (i = 0; i <= n; i++) free(dp[i]);
    free(dp);
    free(val);
    free(wt);
}

int main() {
    solveKnapsack();
    return 0;
}
