Here is an example of the Linear Search algorithm implemented in C:
#include <stdio.h>

// Function to implement Linear Search
int linearSearch(int arr[], int n, int target) {
 for (int i = 0; i < n; i++) {
  if (arr[i] == target) {
   return i; // Return the index of the target element
  }
 }
 return -1; // Return -1 if the target element is not found
}

// Function to print the result
void printResult(int index, int target) {
 if (index != -1) {
  printf("Element %d found at index %d\n", target, index);
 } else {
  printf("Element %d not found in the array\n", target);
 }
}

// Driver program
int main() {
 int arr[] = {10, 20, 30, 40, 50};
 int n = sizeof(arr) / sizeof(arr[0]);
 int target = 30;

 printf("Given array is \n");
 for (int i = 0; i < n; i++) {
  printf("%d ", arr[i]);
 }
 printf("\n");

 int index = linearSearch(arr, n, target);

 printResult(index, target);

 return 0;
}

