#include <stdio.h>

long long int factorial(int num) {
    long long int result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %lld\n", num, factorial(num));
    return 0;
}