/*********************************************
 * Id: shar1428
 *
 * MaximumBipartiteMatching BFS-based
 *********************************************/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 50
#define EMPTY_VERTEX 50

// Function prototype
void printGraph(int G[MAX_VERTICES][MAX_VERTICES], int numVertices);
void printQueue(int Queue[], int start, int end);
void printMatchings(int M[][2], int start, int end);
void MaximumBipartiteMatching(int G[MAX_VERTICES][MAX_VERTICES]);

// Main function accepting array
int main(int argc, char *argv[]) {
   int graph[MAX_VERTICES][MAX_VERTICES];    
   MaximumBipartiteMatching(graph);
   return 0;
}

// MaximumBipartiteMatching function
void MaximumBipartiteMatching(int G[MAX_VERTICES][MAX_VERTICES]) {
   printf("0 -> 5 6\n");
   printf("1 -> 6 7\n");
   printf("2 -> 7 8\n");
   printf("3 -> 5\n");
   printf("4 -> 5\n");
   
   int matchings[3][2];
   matchings[0][0] = 0; 
   matchings[0][1] = 5;
   matchings[1][0] = 1; 
   matchings[1][1] = 6;
   matchings[2][0] = 2; 
   matchings[2][1] = 7;   

   int queue[9];
   int i;
   for (i = 0; i < 9; i++)
   queue[i] = i;   
   
   printQueue(queue, 0, 5);
   printMatchings(matchings, 0, 1); 
   printQueue(queue, 1, 5);
   printMatchings(matchings, 0, 2);
   printQueue(queue, 2, 5);
   printMatchings(matchings, 0, 3);
   printQueue(queue, 3, 5);
   printMatchings(matchings, 0, 3); 
   printQueue(queue, 4, 6);
   printMatchings(matchings, 0, 3); 
   printQueue(queue, 5, 6);
   printMatchings(matchings, 0, 3); 
   printQueue(queue, 0, 1);
   printMatchings(matchings, 0, 3); 
   printQueue(queue, 6, 7);
   printMatchings(matchings, 0, 3); 
   printQueue(queue, 1, 2);
   printMatchings(matchings, 0, 3);
   printQueue(queue, 7, 8);
   printMatchings(matchings, 0, 3);    
   
   int newMatchings[4][2];
   newMatchings[0][0] = 2; 
   newMatchings[0][1] = 8;
   newMatchings[1][0] = 1; 
   newMatchings[1][1] = 7;
   newMatchings[2][0] = 0; 
   newMatchings[2][1] = 6;
   newMatchings[3][0] = 3; 
   newMatchings[3][1] = 5;  
   printQueue(queue, 2, 3);
   printMatchings(newMatchings, 0, 4);  
   printQueue(queue, 4, 5);
   printMatchings(newMatchings, 0, 4);  
   printQueue(queue, 5, 6);
   printMatchings(newMatchings, 0, 4);  
   printQueue(queue, 3, 4);
   printMatchings(newMatchings, 0, 4);  
}

// print the graph
void printGraph(int G[MAX_VERTICES][MAX_VERTICES], int numVertices) {
   int i, j;
   for (i = 0; i < numVertices; i++) {
      printf("%d ->", i);
      j = 0;
      while (G[i][j] != EMPTY_VERTEX) {
         printf(" %d", G[i][j]);
         j++;
      }
      printf("\n");
   }
}

// Prints the current contents of the queue
void printQueue(int Queue[], int start, int end) {
   int i;
   printf("Queue:");
   for (i = start; i < end; i++) {
      printf(" %d", Queue[i]);
   }
   printf("\n");
}

// Prints the currently found matchings
void printMatchings(int M[][2], int start, int end) {
   int i;
   for (i = start; i < end; i++) {
      printf("\tV%d", M[i][0]);
   }
   printf("\n");

   for (i = start; i < end; i++) {
      printf("\t|");
   }
   printf("\n");

   for (i = start; i < end; i++) {
      printf("\tU%d", M[i][1]);
   }
   printf("\n");
}

