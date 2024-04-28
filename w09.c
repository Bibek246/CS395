/*********************************************
 * Id: shar1428
 *
 * Implements Selection Sort algorithm.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int n);
void selectionSort(int A[], int n);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("Usage: %s number1 number2 ...\n", argv[0]);
      return 1;
   }

   int n = argc - 1;
   int A[n];

   // Converting command line arguments to integers and storing them in array A
   for (int i = 0; i < n; i++) {
      A[i] = atoi(argv[i + 1]);
   }

   selectionSort(A, n);
   return 0;
}

// Function to print the array
void printArray(int A[], int n) {
   for (int i = 0; i < n; i++) {
      printf("%d ", A[i]);
   }
   printf("\n");
}

// Implements selection sort algorithm
// Input: Array A[0..n-1] of integers
// Output: Sorted array A[0..n-1]
void selectionSort(int A[], int n) {
   printArray(A, n); // Print the initial array

   for (int i = 0; i < n - 1; i++) {
      int min = i;
      for (int j = i + 1; j < n; j++) {
         if (A[j] < A[min]) {
            min = j;
         }
      }
      // Swap A[i] and A[min]
      int temp = A[i];
      A[i] = A[min];
      A[min] = temp;

      printArray(A, n); // Print array after each swap
   }
}

