/********************************************
 * Id: shar1428
 *
 * This program computes 2^n for any non-negative integer n
 *********************************************/



#include <stdio.h>
#include <stdlib.h>

// Forward declaration of printMatrix function
void printMatrix(int n, float A[n][n+1]);

int main(int argc, char *argv[]) {
   // Check for sufficient arguments
   if (argc <= 1) {
      printf("Insufficient arguments provided.\n");
      return 1;
   }

   int n = atoi(argv[1]);

   // Validate the number of arguments for matrix dimensions
   if (argc != (n * (n + 1) + 2)) {
      printf("Incorrect number of arguments for matrix.\n");
      return 1;
   }

   float A[n][n+1];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + 1; j++) {
         A[i][j] = atof(argv[i * (n + 1) + j + 2]);
      }
   }

   // Gaussian elimination algorithm
   printMatrix(n, A);
   for (int i = 0; i < n - 1; i++) {
      // Check for division by zero
      if (A[i][i] == 0) {
         printf("Division by zero detected. Exiting...\n");
         return 1;
      }

      for (int j = i + 1; j < n; j++) {
         float tempji = A[j][i];
         for (int k = i; k < n + 1; k++) {
            A[j][k] -= A[i][k] * tempji / A[i][i];
         }
      }
      printMatrix(n, A);
   }

   return 0;
}

//This function will print the matrix
void printMatrix(int n, float A[n][n+1]) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + 1; j++) {
         printf("%.2f ", A[i][j]);
      }
      printf("\n");
   }
}


