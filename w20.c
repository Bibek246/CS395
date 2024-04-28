/*********************************************
 * Id: shar1428
 *
 * BFS or DFS bipartite graph determinor.
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Checks if a given graph is bipartite or not using a helper function
int isBipartite(int graph[MAX][MAX], int vertices);

// Helper function to recursively color the graph and check if it's bipartite
int colorGraph(int graph[MAX][MAX], int color[], int position, int currentColor, int vertices);

// Entry point of the program
int main(int argc, char *argv[]) 
{
   int i, j, k, vertices = atoi(argv[1]);
   int inputGraph[MAX - 1][MAX - 1];
   int symmetricalGraph[MAX][MAX];
   int result;

   // Reading input matrix and creating a symmetric matrix
   k = 2;
   for (i = 0; i < vertices - 1; i++) 
   {
      for (j = 0; j < vertices - 1 - i; j++) 
      {
         inputGraph[i][j] = atoi(argv[k]);
         k++;
      }
   }

   // Converting to a symmetrical graph
   for (i = 0; i < vertices - 1; i++) 
   {
      for (j = vertices - 2 - i, k = vertices - 1; j >= 0; j--, k--) 
      {
         symmetricalGraph[i][k] = inputGraph[i][j];
      }
      symmetricalGraph[i][k] = 0;
      for (j = vertices - 1; j > 0; j--, k--) 
      {
         symmetricalGraph[j][i] = symmetricalGraph[i][j];
      }
   }
   symmetricalGraph[i][i] = 0;

   // Printing the symmetrical graph
   for (i = 0; i < vertices; i++) 
   {
      for (j = 0; j < vertices; j++) 
      {
         printf("%d ", symmetricalGraph[i][j]);
      }
      printf("\n");
   }

   // Checking if the graph is bipartite
   result = isBipartite(symmetricalGraph, vertices);
   if (result == 1)
   printf("Graph is Bipartite\n");
   else
   printf("Graph is NOT Bipartite\n");

   return 0;
}

// Recursive function to color the graph and check if it's bipartite
int colorGraph(int graph[MAX][MAX], int color[], int position, int currentColor, int vertices) 
{
   if (color[position] != -1 && color[position] != currentColor)
   return 0;

   color[position] = currentColor;
   int isBipartite = 1;

   for (int i = 0; i < vertices; i++) 
   {
      if (graph[position][i]) 
      {
         if (color[i] == -1)
         isBipartite &= colorGraph(graph, color, i, 1 - currentColor, vertices);

         if (color[i] != -1 && color[i] != 1 - currentColor)
         return 0;
      }

      if (!isBipartite)
      return 0;
   }

   return 1;
}

// Function to check if a graph is bipartite or not
int isBipartite(int graph[MAX][MAX], int vertices) 
{
   int color[vertices];
   for (int i = 0; i < vertices; i++)
   color[i] = -1;

   int startVertex = 0;
   return colorGraph(graph, color, startVertex, 1, vertices);
}

