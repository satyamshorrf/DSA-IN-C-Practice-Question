#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int matrixChainMultiplication(int dims[], int n) {
    int dp[MAX_SIZE][MAX_SIZE];

    // Initialize dp array
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill dp array using dynamic programming
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int dims[] = {10, 30, 5, 60}; // Example dimensions of matrices
    int n = sizeof(dims) / sizeof(dims[0]);

    int minCost = matrixChainMultiplication(dims, n);
    printf("Minimum number of multiplications needed: %d\n", minCost);

    return 0;
}
