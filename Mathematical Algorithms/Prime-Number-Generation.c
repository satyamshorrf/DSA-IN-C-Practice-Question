#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void generatePrimes(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(limit);
    return 0;
}