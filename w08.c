/*********************************************
 * Id: shar1428
 *
 * Implements brute-force string matching.
 *********************************************/

#include <stdio.h>
#include <string.h>

int BruteForceStringMatch(char T[], int n, char P[], int m);

int main(int argc, char *argv[]) {
   if (argc < 3) {
      printf("Usage: %s pattern text\n", argv[0]);
      return 1;
   }

   char *P = argv[1]; // Pattern
   char *T = argv[2]; // Text

   printf("Matches found at locations: ");
   int firstPrint = 1; // Flag to check if it's the first print

   int n = strlen(T);
   int m = strlen(P);

   for (int i = 0; i <= n - m; ) {
      int result = BruteForceStringMatch(T + i, n - i, P, m);
      if (result != -1) {
         if (!firstPrint) {
            printf(" "); // Print space only if it's not the first match
         }
         printf("%d", result + i);
         firstPrint = 0; // Update flag after the first print
         i += result + 1; // Move to the next character after the match
      }
      else {
         break;
      }
   }

   printf("\n");
   return 0;
}

// Performs brute-force string matching
// Input: Text T[0..n-1], Text length n, Pattern P[0..m-1], Pattern length m
// Output: The index of the first character in T that starts a matching substring or -1 if the search is unsuccessful
int BruteForceStringMatch(char T[], int n, char P[], int m) {
   for (int i = 0; i <= n - m; i++) {
      int j = 0;
      while (j < m && P[j] == T[i + j]) {
         j++;
      }
      if (j == m) return i;
   }
   return -1;
}

