/*********************************************
 * Id: shar1428
 *
 * QuickHaul Implementation
 *********************************************/

#include <stdio.h>
#include <stdlib.h>



// Declaration of functions
void showArray(int l, int r, int size, int Arr[]);
int HoarePartition(int A[], int l, int r);
void Quicksort(int A[], int l, int r, int size);

// Main function accepting array from command line
int main(int argc, char * argv[])
{
   int n = argc - 1;
   int A[n];
   for (int i = 0; i < n; i++)
   {
      A[i] = atoi(argv[i + 1]);
   }

   Quicksort(A, 0, n - 1, n);
   showArray(0, n - 1, n, A);
   return 0;
}

// Function to print sub-array elements
void showArray(int l, int r, int size, int Arr[])
{
   int i;
   for (i = 0; i < size; i++)
   {
      if (l == i)
      {
         printf("[");
         printf("%d ", Arr[i]);
      }
      else if (r == i)
      {
         printf("%d", Arr[i]);
         printf("]  ");
      }
      else
      {
         printf("%d ", Arr[i]);
      }
   }
   printf("\n");
}

// Function for Hoare's partition scheme
int HoarePartition(int A[], int l, int r)
{
   int p = A[l];
   int i = l - 1;
   int j = r + 1;
   int temp;

   while (1)
   {
      do
      {
         j--;
      } while (A[j] > p);

      do
      {
         i++;
      } while (A[i] < p);

      if (i < j)
      {
         temp = A[i];
         A[i] = A[j];
         A[j] = temp;
      }
      else
      {
         return j;
      }
   }
}

// Function to perform Quick Sort
void Quicksort(int A[], int l, int r, int size)
{
   if (l < r)
   {
      int s = HoarePartition(A, l, r);
      Quicksort(A, l, s, size);
      Quicksort(A, s + 1, r, size);
      showArray(l, r, size, A);
   }
}

