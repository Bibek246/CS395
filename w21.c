/*********************************************
 * Id: shar1428
 *
 * Permutation
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void swap(int *x, int *y);
void permute(int *array, int start, int end);
void printArray(int *array, int size);

// Main function
int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Usage: ./permutations n\n");
      return 1;
   }

   int n = atoi(argv[1]);
   int array[n];

   // Initialize the array with 1 to n
   for (int i = 0; i < n; i++)
   {
      array[i] = i + 1;
   }

   // Generate permutations
   permute(array, 0, n);
   return 0;
}

// Function to swap two integers
void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}

// Recursive function to generate permutations
void permute(int *array, int start, int end)
{
   if (start == end)
   {
      printArray(array, end);
      return;
   }
   for (int i = start; i < end; i++)
   {
      swap(&array[start], &array[i]);
      permute(array, start + 1, end);
      swap(&array[start], &array[i]); // backtrack
   }
}

// Function to print the array
void printArray(int *array, int size)
{
   for (int i = 0; i < size; i++)
   {
      printf("%d", array[i]);
   }
   printf("\n");
}

