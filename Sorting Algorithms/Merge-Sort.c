
#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
 int n1 = q - p + 1;
 int n2 = r - q;
 int L[n1], M[n2];
 int i, j, k;

 for (i = 0; i < n1; i++)
  L[i] = arr[p + i];
 for (j = 0; j < n2; j++)
  M[j] = arr[q + 1 + j];

 i = 0;
 j = 0;
 k = p;

 while (i < n1 && j < n2) {
  if (L[i] <= M[j]) {
   arr[k] = L[i];
   i++;
  } else {
   arr[k] = M[j];
   j++;
  }
  k++;
 }

 while (i < n1) {
  arr[k] = L[i];
  i++;
  k++;
 }

 while (j < n2) {
  arr[k] = M[j];
  j++;
  k++;
 }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
  int m = l + (r - l) / 2;

  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);

  merge(arr, l, m, r);
 }
}

// Print the array
void printArray(int arr[], int size) {
 int i;
 for (i = 0; i < size; i++)
  printf("%d ", arr[i]);
 printf("\n");
}

// Driver program
int main() {
 int arr[] = {12, 11, 13, 5, 6, 7};
 int arr_size = sizeof(arr) / sizeof(arr[0]);

 printf("Given array is \n");
 printArray(arr, arr_size);

 mergeSort(arr, 0, arr_size - 1);

 printf("\nSorted array is \n");
 printArray(arr, arr_size);
 return 0;
}
