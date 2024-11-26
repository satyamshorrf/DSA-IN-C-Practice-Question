Here is an example of the Quick Sort algorithm implemented in C:
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
 int t = *a;
 *a = *b;
 *b = t;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
 int pivot = arr[high]; // Choosing the last element as the pivot
 int i = (low - 1);

 for (int j = low; j <= high - 1; j++) {
  if (arr[j] < pivot) {
   i++;
   swap(&arr[i], &arr[j]);
  }
 }

 swap(&arr[i + 1], &arr[high]);
 return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
 if (low < high) {
  int pivot = partition(arr, low, high);

  quickSort(arr, low, pivot - 1);
  quickSort(arr, pivot + 1, high);
 }
}

// Function to print the array
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++) {
  printf("%d ", arr[i]);
 }
 printf("\n");
}

// Driver program
int main() {
 int arr[] = { 10, 7, 8, 9, 1, 5 };
 int n = sizeof(arr) / sizeof(arr[0]);

 printf("Given array is \n");
 printArray(arr, n);

 quickSort(arr, 0, n - 1);

 printf("Sorted array is \n");
 printArray(arr, n);
 return 0;
}

