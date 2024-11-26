#include <stdio.h>

void fibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d, ", first);
        } else {
            printf("%d", first);
        }
        next = first + second;
        first = second;
        second = next;
    }
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    fibonacci(terms);

    return 0;
}
