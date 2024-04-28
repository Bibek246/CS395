/*********************************************
 * Id: shar1428
 *
 * Implements Insertion Sort algorithm.
 * The program sorts an array of integers provided
 * as command line arguments.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void insertionSort(int array[], int n);
void showArray(int n, int array[], int v);

int main(int argc, char *argv[]) {
   // Convert command line arguments to integers and store in array
   int noOfElements = argc - 1;
   int array[noOfElements];
   for (int i = 0; i < noOfElements; i++) {
      array[i] = atoi(argv[i + 1]);
   }

   // Perform insertion sort on the array
   insertionSort(array, noOfElements);

   // Display the final sorted array
   showArray(noOfElements, array, 0);
   return 0;
}

// Function to perform insertion sort
void insertionSort(int array[], int n) {
   int i, v, j;
   for (i = 1; i < n; i++) {
      v = array[i]; // Element to be inserted
      j = i - 1;

      // Display array state before insertion
      showArray(n, array, v);

      // Shift elements to the right to create position for 'v'
      while (j >= 0 && array[j] > v) {
         array[j + 1] = array[j];
         j--;
      }
      array[j + 1] = v; // Insert 'v' at the correct position
   }
}

// Function to display array elements with a visual marker
void showArray(int n, int array[], int v) {
   for (int i = 0; i < n; i++) {
      if (array[i] == v) {
         // Mark the current element being inserted
         printf("| %d ", array[i]);
      } 
      else {
         printf("%d ", array[i]);
      }
   }

   // Mark the end of the array if v is 0
   if (v == 0) {
      printf("| ");
   }
   printf("\n");
}

