#include <stdio.h>
#include <string.h>

// Function to compute the lps array for the given pattern
void computeLPSArray(char pattern[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    // Iterate through the pattern
    for (int i = 1; i < m; i++) {
        // If the current character matches the previous character, increment the length
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
        }
        // If the current character does not match the previous character, reset the length
        else {
            if (len != 0) {
                len = lps[len - 1];
                i--;
            }
            else {
                lps[i] = 0;
            }
        }
    }
}

// Function to find all occurrences of pattern in text using KMP algorithm
void kmpPatternSearch(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);

    // Create an array to store the longest proper prefix that is also a suffix
    int lps[m];

    // Compute the lps array for the given pattern
    computeLPSArray(pattern, m, lps);

    // Initialize the indices for the text and the pattern
    int i = 0;
    int j = 0;

    // Repeat the following steps until we reach the end of the text
    while (i < n) {
        // If the current character of the text matches the current character of the pattern, increment both indices
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        // If the current character of the text does not match the current character of the pattern, reset the index of the pattern
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }

        // If the current character of the text does not match the current character of the pattern, reset the index of the pattern
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "THIS IS A TEST TEXT";
    char pattern[] = "TEST";

    kmpPatternSearch(text, pattern);

    return 0;
}