/*********************************************
 * Id: shar1428
 *
 * Implements Quick Sort using Hoare's Partition algorithm.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Partitions a subarray using Hoare's algorithm
int HoarePartition(int A[], int l, int r);

// Sorts an array using Quick Sort
void Quicksort(int A[], int l, int r, int size);

// Displays the array elements with the active portion enclosed in square brackets
void showArray(int l, int r, int size, int Arr[]);

int main(int argc, char *argv[]) {
   int numberOfElements = argc - 1;
   int array[numberOfElements];
   for (int i = 0; i < numberOfElements; i++) {
      array[i] = atoi(argv[i + 1]);
   }
   Quicksort(array, 0, numberOfElements - 1, numberOfElements);
   showArray(0, numberOfElements - 1, numberOfElements, array);
   return 0;
}

// Implements Hoare's partition algorithm for Quick Sort
// Input: Array 'array', left index 'l', and right index 'r'
// Output: The pivot index where partitioning is done
int HoarePartition(int array[], int l, int r) {
   int p = array[l];
   int i = l;
   int j = r + 1;
   int temp;

   do {
      do {
         i++;
      } while (array[i] < p);

      do {
         j--;
      } while (array[j] > p);

      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   } while (i < j);

   if (i > j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   }
   temp = array[l];
   array[l] = array[j];
   array[j] = temp;
   return j;
}

// Sorts an array using the Quick Sort algorithm
// Input: Array 'array', left index 'l', right index 'r', and array size 'size'
// Output: Sorted array elements with each step of sorting displayed
void Quicksort(int array[], int l, int r, int size) {
   if (l < r) {
      int s = HoarePartition(array, l, r);
      Quicksort(array, l, s - 1, size);
      Quicksort(array, s + 1, r, size);
      showArray(l, r, size, array);
   }
}

// Displays the current state of the array during the sorting process
// Input: Array 'Arr', left index 'l', right index 'r', and array size 'size'
// Output: Printed array with the currently processed subarray enclosed in square brackets
void showArray(int l, int r, int size, int Arr[]) {
   for (int i = 0; i < size; i++) {
      if (i == l) {
         printf("[");
      }
      printf("%d", Arr[i]);
      if (i == r) {
         printf("]  ");
      }
      else {
         printf(" ");
      }
   }
   printf("\n");
}
