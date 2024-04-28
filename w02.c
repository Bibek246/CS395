/*********************************************
 * Id: shar1428
 *
 * This program find the minimum distance between elements of array
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
   // Converting command line arguments to integers
   int n = argc - 1; // ignoring the program name itself
   int A[n];

   for (int i = 0; i < n; i++) {
      A[i] = atoi(argv[i + 1]);
   }

   // Finding the minimum distance
   int dmin = INT_MAX;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (i != j && abs(A[i] - A[j]) < dmin) {
            dmin = abs(A[i] - A[j]);
         }
      }
   }

   printf("%d\n", dmin);
   return 0;
}

