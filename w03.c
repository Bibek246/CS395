/*********************************************
 * Id: shar1428
 *
 * This program computes 2^n for any non-negative integer n
 *********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int pow2(int n);

int main(int argc, char *argv[]) {
   // Check if user provided an argument
   if (argc != 2) {
      printf("Usage: %s <non-negative integer>\n", argv[0]);
      return 1;
   }

   int n = atoi(argv[1]);

   if (n < 0) {
      printf("Please enter a non-negative integer.\n");
      return 1;
   }

   int result = pow2(n);
   printf("2^%d = %d\n", n, result);
   return 0;
}

// The most brute force way to calculate 2^n.
int pow2(int n) {
   // Base case
   if (n < 1) return 1;  // As 2^0 = 1

   // Recursive calls
   return pow2(n - 1) + pow2(n - 1);
}
