#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int limit) {
    bool prime[limit + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= limit; p++)
        if (prime[p])
            printf("%d ", p);
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are: ", limit);
    sieveOfEratosthenes(limit);
    return 0;
}