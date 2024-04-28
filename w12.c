/*********************************************
 * Id: shar1428
 *
 * Sort Compare
 *Usage: ./w12 <base size>
 *cs395 $ ./w12 1000
 *+-----------------------+-----------------+----------------+------------+
 *|    Number of Elements |  Selection Sort | Insertion Sort |  Quicksort |
 *+-----------------------+-----------------+----------------+------------+
 *|                   1000|                2|               1|           0|
 *|                  10000|              146|              83|           1|
 *|                 100000|            14546|            8203|          17|
 *+-----------------------+-----------------+----------------+------------+
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

// Function prototypes
void insertionSort(int array[], int n);
void selectionSort(int array[], int n);
void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);
void copyArray(int source[], int destination[], int n);
void fillRandom(int array[], int n);

// Main function to compare sorting algorithms
int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <base size>\n", argv[0]);
      return 1;
   }

   int baseSize = atoi(argv[1]);
   int sizes[3] = 
   {
      baseSize, baseSize * 10, baseSize * 100
   };

   printf("+-----------------------+-----------------+----------------+------------+\n");
   printf("|    Number of Elements |  Selection Sort | Insertion Sort |  Quicksort |\n");
   printf("+-----------------------+-----------------+----------------+------------+\n");

   for (int i = 0; i < 3; i++) {
      int n = sizes[i];
      int array[n], copy1[n], copy2[n];
      struct timeval start, stop;

      fillRandom(array, n);
      copyArray(array, copy1, n);
      copyArray(array, copy2, n);

      // Selection Sort
      gettimeofday(&start, NULL);
      selectionSort(array, n);
      gettimeofday(&stop, NULL);
      long selectionTime = lround(((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000.0);

      // Insertion Sort
      gettimeofday(&start, NULL);
      insertionSort(copy1, n);
      gettimeofday(&stop, NULL);
      long insertionTime = lround(((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000.0);

      // Quicksort
      gettimeofday(&start, NULL);
      quicksort(copy2, 0, n - 1);
      gettimeofday(&stop, NULL);
      long quicksortTime = lround(((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000.0);

      printf("|%23d|%17ld|%16ld|%12ld|\n", n, selectionTime, insertionTime, quicksortTime);
   }

   printf("+-----------------------+-----------------+----------------+------------+\n");
   return 0;
}

// Implementations of sorting functions and helper functions
// ... (Insert the implementations of insertionSort, selectionSort, quicksort, partition, copyArray, and fillRandom here)


// Insertion sort algorithm
void insertionSort(int array[], int n) {
   int i, j, key;
   for (i = 1; i < n; i++) {
      key = array[i];
      j = i - 1;
      while (j >= 0 && array[j] > key) {
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = key;
   }
}

// Selection sort algorithm
void selectionSort(int array[], int n) {
   int i, j, min_idx, temp;
   for (i = 0; i < n - 1; i++) {
      min_idx = i;
      for (j = i + 1; j < n; j++) {
         if (array[j] < array[min_idx]) {
            min_idx = j;
         }
      }
      temp = array[min_idx];
      array[min_idx] = array[i];
      array[i] = temp;
   }
}

// Quicksort algorithm
void quicksort(int array[], int low, int high) {
   if (low < high) {
      int pi = partition(array, low, high);
      quicksort(array, low, pi - 1);
      quicksort(array, pi + 1, high);
   }
}

// Helper function for Quicksort
int partition(int array[], int low, int high) {
   int pivot = array[high];
   int i = (low - 1), temp;
   for (int j = low; j <= high - 1; j++) {
      if (array[j] < pivot) {
         i++;
         temp = array[i];
         array[i] = array[j];
         array[j] = temp;
      }
   }
   temp = array[i + 1];
   array[i + 1] = array[high];
   array[high] = temp;
   return (i + 1);
}

// Copy contents of one array to another
void copyArray(int source[], int destination[], int n) {
   for (int i = 0; i < n; i++) {
      destination[i] = source[i];
   }
}

// Fill an array with random numbers
void fillRandom(int array[], int n) {
   srand(time(NULL)); // Seed the random number generator
   for (int i = 0; i < n; i++) {
      array[i] = rand() % 10000; // Modify as needed
   }
}
