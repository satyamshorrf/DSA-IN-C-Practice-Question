Here are examples of Binary Search algorithms implemented in C, both iterative and recursive:

Iterative Binary Search
#include <stdio.h>

int binarySearchIterative(int arr[], int n, int target) {
 int low = 0;
 int high = n - 1;

 while (low <= high) {
  int mid = (low + high) / 2;

  if (arr[mid] == target) {
   return mid; // Return the index of the target element
  } else if (arr[mid] < target) {
   low = mid + 1;
  } else {
   high = mid - 1;
  }
 }

 return -1; // Return -1 if the target element is not found
}

int main() {
 int arr[] = {10, 20, 30, 40, 50};
 int n = sizeof(arr) / sizeof(arr[0]);
 int target = 30;

 int index = binarySearchIterative(arr, n, target);

 if (index != -1) {
  printf("Element %d found at index %d\n", target, index);
 } else {
  printf("Element %d not found in the array\n", target);
 }

 return 0;
}


Recursive Binary Search
#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int target) {
 if (low > high) {
  return -1; // Return -1 if the target element is not found
 }

 int mid = (low + high) / 2;

 if (arr[mid] == target) {
  return mid; // Return the index of the target element
 } else if (arr[mid] < target) {
  return binarySearchRecursive(arr, mid + 1, high, target);
 } else {
  return binarySearchRecursive(arr, low, mid - 1, target);
 }
}

int main() {
 int arr[] = {10, 20, 30, 40, 50};
 int n = sizeof(arr) / sizeof(arr[0]);
 int target = 30;

 int index = binarySearchRecursive(arr, 0, n - 1, target);

 if (index != -1) {
  printf("Element %d found at index %d\n", target, index);
 } else {
  printf("Element %d not found in the array\n", target);
 }

 return 0;
}


