Here is an example of the Heap Sort algorithm implemented in C:
#include <stdio.h>

// Function to heapify a subtree rooted at a given index
// This assumes that the subtrees are already heapified
void heapify(int arr[], int n, int i) {
 int largest = i; // Initialize the largest as the root
 int left = 2 * i + 1; // Left child
 int right = 2 * i + 2; // Right child

 // If the left child is larger than the root
 if (left < n && arr[left] > arr[largest])
  largest = left;

 // If the right child is larger than the largest so far
 if (right < n && arr[right] > arr[largest])
  largest = right;

 // If the largest is not the root
 if (largest != i) {
  swap(&arr[i], &arr[largest]);

  // Recursively heapify the affected sub-tree
  heapify(arr, n, largest);
 }
}

// Function to build a max-heap
void buildHeap(int arr[], int n) {
 // Build a max-heap from the unsorted data
 for (int i = n / 2 - 1; i >= 0; i--)
  heapify(arr, n, i);
}

// Function to implement Heap Sort
void heapSort(int arr[], int n) {
 // Build a max-heap
 buildHeap(arr, n);

 // One by one extract elements from the heap
 for (int i = n - 1; i >= 0; i--) {
  // Move the root element to the end
  swap(&arr[0], &arr[i]);

  // Call heapify on the reduced heap
  heapify(arr, i, 0);
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
 int arr[] = { 12, 11, 13, 5, 6, 7 };
 int n = sizeof(arr) / sizeof(arr[0]);

 printf("Given array is \n");
 printArray(arr, n);

 heapSort(arr, n);

 printf("Sorted array is \n");
 printArray(arr, n);
 return 0;
}

