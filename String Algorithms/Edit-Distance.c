#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

int editDistance(char *str1, char *str2, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0)
                L[i][j] = j;

            else if (j == 0)
                L[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                L[i][j] = L[i - 1][j - 1];

            else
                L[i][j] = 1 + min(L[i][j - 1], L[i - 1][j], L[i - 1][j - 1]);
        }
    }

    return L[m][n];
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Edit Distance is %d\n", editDistance(str1, str2, strlen(str1), strlen(str2)));
    return 0;
}