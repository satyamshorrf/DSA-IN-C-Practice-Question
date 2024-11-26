#include <stdio.h>
#include <string.h>

// Function to find all occurrences of pattern in text using Naive algorithm
void naivePatternSearch(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);

    // Repeat the following steps for all possible positions of the pattern in the text
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Compare the pattern and the text from the current position
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
}

int main() {
    char text[] = "THIS IS A TEST TEXT";
    char pattern[] = "TEST";

    naivePatternSearch(text, pattern);

    return 0;
}