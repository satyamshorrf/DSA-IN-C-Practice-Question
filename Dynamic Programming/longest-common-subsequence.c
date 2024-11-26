// A Naive recursive implementation 
// of LCS problem 
#include <stdio.h> 

int max(int a, int b); 

// Returns length of LCS for X[0..m-1], 
// Y[0..n-1] 
int lcs(char* X, char* Y, int i, int j) 
{ 
	if (X[i] == 0 || Y[j] == 0) 
		return 0; 
	if (X[i] == Y[j]) 
		return 1 + lcs(X, Y, i + 1, j + 1); 
	else
		return max(lcs(X, Y, i, j + 1), 
				lcs(X, Y, i + 1, j)); 
} 

// Utility function to get max of 
// 2 integers 
int max(int a, int b) { return (a > b) ? a : b; } 

// Driver code 
int main() 
{ 
	char S1[] = "BD"; 
	char S2[] = "ABCD"; 
	int m = strlen(S1); 
	int n = strlen(S2); 
	int i = 0, j = 0; 

	// Function Call 
	printf("Length of LCS is %d", lcs(S1, S2, i, j)); 

	return 0; 
}
