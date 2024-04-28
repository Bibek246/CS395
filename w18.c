/*********************************************
 * Id: shar1428
 *
 * The Clique Problem
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Finds the maximum of two integers
int maxOfTwo(int a, int b);

// Determines if a given set of vertices forms a clique
int checkClique(int count, int vertexSet[100], int matrix[100][100]);

// Computes the size of the largest clique
int computeMaxCliqueSize(int currIndex, int depth, int vertexSet[100], int matrix[100][100], int totalVertices);

// Entry point of the program
int main(int argc, char *argv[]) {
   int vertexSet[100];
   int adjacencyMatrix[100][100]; 
   int numVertices = atoi(argv[1]);
   int upperTriangle[numVertices - 1][numVertices - 1];
   int i, j, k;
   int extendedMatrix[numVertices][numVertices];
   int edgePairs[numVertices * numVertices][2];
   int largestCliqueSize;

   // Reading the upper triangle of the adjacency matrix
   k = 2;
   for (i = 0; i < numVertices - 1; i++) {      
      for (j = 0; j < numVertices - 1 - i; j++) {
         upperTriangle[i][j] = atoi(argv[k]);
         k++;   
      }
   }

   // Building the full adjacency matrix
   k = 0;
   for (i = 0; i < numVertices - 1; i++) {      
      for (j = numVertices - 2 - i, k = numVertices - 1; j >= 0; j--, k--) {         
         extendedMatrix[i][k] = upperTriangle[i][j];   
      }
      extendedMatrix[i][k] = 0;
      for (j = numVertices - 1, k = numVertices - 1; j > 0; j--, k--) {         
         extendedMatrix[j][i] = extendedMatrix[i][j];   
      }      
   }
   extendedMatrix[i][i] = 0;

   // Printing the full adjacency matrix
   for (i = 0; i < numVertices; i++) {      
      for (j = 0; j < numVertices; j++) {
         printf("%d ", extendedMatrix[i][j]);   
      }
      printf("\n");   
   }

   // Converting the matrix into an edge list
   k = 0;
   for (i = 0; i < numVertices - 1; i++) {      
      for (j = 0; j < numVertices - 1 - i; j++) {         
         if (upperTriangle[i][j] == 1) {
            edgePairs[k][0] = i + 1;
            edgePairs[k][1] = j + i + 2;            
            k++;            
         }
      }   
   }

   // Building the adjacency matrix from the edge list
   for (i = 0; i < k; i++) {      
      adjacencyMatrix[edgePairs[i][0]][edgePairs[i][1]] = 1;
      adjacencyMatrix[edgePairs[i][1]][edgePairs[i][0]] = 1;
   }

   // Finding the largest clique size
   largestCliqueSize = computeMaxCliqueSize(0, 1, vertexSet, adjacencyMatrix, numVertices);
   
   // Printing the result
   for (i = numVertices; i >= 1; i--) {
      if (i != largestCliqueSize)
      printf("No clique found of size %d\n", i);
      else {
         printf("Clique found of size %d\n", i);
         break;
      }
   }   
   return 0;
} 

// Finds the maximum of two integers
int maxOfTwo(int a, int b) {   
   return (a > b ? a : b);
} 

// Determines if a given set of vertices forms a clique
int checkClique(int count, int vertexSet[100], int matrix[100][100]) { 
   int i, j;
   for (i = 1; i < count; i++) {
      for (j = i + 1; j < count; j++) 
      if (matrix[vertexSet[i]][vertexSet[j]] == 0)
      return 0;
   }
   return 1;
} 

// Computes the size of the largest clique
int computeMaxCliqueSize(int currIndex, int depth, int vertexSet[100], int matrix[100][100], int totalVertices) {
   int j;      
   int largestClique = 0;
   for (j = currIndex + 1; j <= totalVertices; j++) { 
      vertexSet[depth] = j;
      if (checkClique(depth + 1, vertexSet, matrix)) { 
         largestClique = maxOfTwo(largestClique, depth); 
         largestClique = maxOfTwo(largestClique, computeMaxCliqueSize(j, depth + 1, vertexSet, matrix, totalVertices));
      }
   }
   return largestClique;
} 

