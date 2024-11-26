#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the hash value of a string
unsigned long hash(char str[], int m, unsigned long q) {
    unsigned long h = 1;

    // Calculate the hash value using the given formula
    for (int i = 0; i < m; i++) {
        h = (h * 256 + str[i]) % q;
    }

    return h;
}

// Function to find all occurrences of pattern in text using Rabin-Karp algorithm
void rabinKarpPatternSearch(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);

    // Choose a prime number and a modulus
    unsigned long q = 101;

    // Calculate the hash value of the pattern
    unsigned long p = hash(pattern, m, q);

    // Calculate the hash value of the first window of the text
    unsigned long t = hash(text, m, q);

    // Compare the hash values of the pattern and the first window of the text
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            // Compare the characters of the pattern and the text
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            // If all characters of the pattern match with the text, print the current position
            if (j == m) {
                printf("Pattern found at index %d\n", i);
            }
        }

        // If the current window is not the pattern, update the hash value of the next window
        if (i < n - m) {
            t = (t - text[i] * 256 + text[i + m]) % q;

            // If the hash value is negative, add the modulus
            if (t < 0) {
                t += q;
            }
        }
    }
}

int main() {
    char text[] = "THIS IS A TEST TEXT";
    char pattern[] = "TEST";

    rabinKarpPatternSearch(text, pattern);

    return 0;
}