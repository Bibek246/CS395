/********************************************
 * Id: shar1428
 *
 * This program computes the given input using Gussian Elimmination method
 *********************************************/



#include<stdio.h>
#include<stdlib.h>

// Function for Gaussian elimination
void gaussian_elimination(int matrix_size, float matrix[matrix_size][matrix_size + 1]);
// Function for printing the matrix
void print_matrix(int matrix_size, float matrix[matrix_size][matrix_size + 1]);

// Main function
int main(int argc, char *argv[]){
   int row, col, matrix_size = atoi(argv[1]);
   float matrix[matrix_size][matrix_size + 1];
   for(row = 0; row < matrix_size; row++){
      for(col = 0; col < matrix_size + 1; col++){
         matrix[row][col] = atof(argv[row * (matrix_size + 1) + col + 2]);
      }
   }

   gaussian_elimination(matrix_size, matrix);
   return 0;
}

// Function for printing the matrix
void print_matrix(int matrix_size, float matrix[matrix_size][matrix_size + 1]){
   int row, col;
   for(row = 0; row < matrix_size; row++){
      for(col = 0; col < matrix_size + 1; col++){
         printf("%.2f ", matrix[row][col]);
      }
      printf("\n");
   }
   printf("\n");
}

// Function for Gaussian elimination
void gaussian_elimination(int matrix_size, float matrix[matrix_size][matrix_size + 1]){
   int i, j, k;
   float factor;
   print_matrix(matrix_size, matrix);
   for(i = 0; i <= matrix_size - 2; i++){
      for(j = i + 1; j <= matrix_size - 1; j++){
         factor = matrix[j][i];
         for(k = i; k <= matrix_size; k++){
            matrix[j][k] = matrix[j][k] - (matrix[i][k] * factor / matrix[i][i]);
         }
      }
      print_matrix(matrix_size, matrix);
   }
}

