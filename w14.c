/*********************************************
 * Id: shar1428
 *
 * Implement Horspool's algorithm
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32
#define MAX_MATCHES 1000  // Maximum number of matches to record

// Function prototypes
void printShiftTable(int table[]);
void ShiftTable(char needle[], int table[]);
int HorspoolMatching(char needle[], char haystack[]);

// Main function to run Horspool's algorithm
int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("Usage: %s <needle> <haystack>\n", argv[0]);
      return 1;
   }

   char *needle = argv[1];
   char *haystack = argv[2];
   HorspoolMatching(needle, haystack);
   return 0;
}

// Function to print the shift table
void printShiftTable(int table[]) {
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH) {
      for(i = start; i < start + TABLE_ROW_LENGTH; i++) {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start + TABLE_ROW_LENGTH; i++) {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

// Function to create the shift table for Horspool’s algorithm
void ShiftTable(char needle[], int table[]) {
   int m = strlen(needle);
   for (int i = 0; i < MAX_ALPHABET; i++) {
      table[i] = m;
   }
   for (int j = 0; j < m - 1; j++) {
      table[(int)needle[j]] = m - 1 - j;
   }
   printShiftTable(table);
}

// Function to implement Horspool’s algorithm for string matching
int HorspoolMatching(char needle[], char haystack[]) {
   int m = strlen(needle);
   int n = strlen(haystack);
   int table[MAX_ALPHABET];
   ShiftTable(needle, table);
   int matches[MAX_MATCHES], matchNum = 0;

   printf("%s\n", haystack);
   int i = m - 1;
   while (i <= n - 1) {
      int k = 0;
      while (k <= m - 1 && needle[m - 1 - k] == haystack[i - k]) {
         k++;
      }
      if (k == m) {
         printf("%*s%s---found\n", i - m + 1, "", needle);
         if (matchNum < MAX_MATCHES) {
            matches[matchNum++] = i - m + 1;
         }
         i += m; // Continue searching for the next occurrence
      }
      else {
         printf("%*s%s\n", i - m + 1, "", needle);
         i += table[(int)haystack[i]];
      }
   }

   printf("Matches found at locations:");
   for(i = 0; i < matchNum; i++) {
      printf(" %d", matches[i]);
   }
   printf("\n");
   return -1;
}

