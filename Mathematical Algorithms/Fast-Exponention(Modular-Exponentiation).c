#include <stdio.h>

// Function to perform fast exponentiation (modular exponentiation)
long long fastExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // Ensure base is within the modulus

    while (exp > 0) {
        // If exponent is odd, multiply base with result
        if (exp & 1) {
            result = (result * base) % mod;
        }
        // Reduce the exponent by half and square the base
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long base = 3; // Example base
    long long exp = 7;  // Example exponent
    long long mod = 1000000007; // Example modulus

    // Call the fast exponentiation function and print the result
    printf("Result: %lld\n", fastExpo(base, exp, mod));
    return 0;
}
























