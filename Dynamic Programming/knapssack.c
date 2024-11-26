#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

struct Item {
    int weight;
    int value;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, struct Item items[], int n) {
    int dp[MAX_ITEMS][MAX_CAPACITY];

    // Initialize dp array
    // Fill dp array using dynamic programming

    return dp[n][capacity];
}

int main() {
    int capacity, n;
    struct Item items[MAX_ITEMS];

    // Input knapsack capacity and number of items
    // Input weights and values of each item

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int max_value = knapsack(capacity, items, n);
    printf("Maximum value that can be achieved: %d\n", max_value);

    return 0;
}
