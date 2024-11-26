#include <stdio.h>

#define N 8

int is_safe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    int i = row, j;
    while (i >= 0 && col >= 0) {
        if (board[i][col] == 1) {
            return 0;
        }
        i--;
        col--;
    }

    i = row, j = col;
    while (i >= 0 && j < N) {
        if (board[i][j] == 1) {
            return 0;
        }
        i--;
        j++;
    }

    return 1;
}

int solve(int board[N][N], int row) {
    if (row == N) {
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 1;

            if (solve(board, row + 1) == 1) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}
                      };

    if (solve(board, 0) == 1) {
        printf("Solution exists\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}