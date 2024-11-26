#include <stdio.h>
#include <string.h>

int lcs(char *X, char *Y, int m, int n) {
    int L[m+1][n+1];
    int i, j;

    // To store the length of longest common substring
    int length = 0;

    // To store the index of the cell which contains the longest common substring
    int index = 0;

    // Fill up the table L with dimensions (m+1) x (n+1)
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;

                // Update the length and index if required
                if (L[i][j] > length) {
                    length = L[i][j];
                    index = i - 1;
                }
            } else
                L[i][j] = 0;
        }
    }

    // If we have a common substring, print it
    if (length > 0) {
        printf("Longest common substring is %s\n", X + index - length + 1);
    } else {
        printf("No common substring found\n");
    }

    return length;
}

int main() {
    char X[] = "thisisatest";
    char Y[] = "testing123testing";

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}