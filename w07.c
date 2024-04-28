/*********************************************
 * Id: shar1428
 *
 * This program is for cyclic Hanoi calculation.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Function declarations
void RotateRight(int n, char A, char C, char B);
void RotateCyclic(int n, char A, char C, char B);

// Main function
int main(int argc, char *argv[])
{
   int disks = atoi(argv[1]);
   RotateCyclic(disks, 'A', 'C', 'B');
   return 0;
}

// Function to perform cyclic rotation of disks in Tower of Hanoi
void RotateCyclic(int n, char A, char C, char B)
{
   if (n > 1)
   {
      RotateCyclic(n - 1, A, C, B);
      printf("MOVE %c TO %c\n", A, B);
      RotateRight(n - 1, B, C, A);
      printf("MOVE %c TO %c\n", B, C);
      RotateCyclic(n - 1, A, C, B);
   }
   else
   {
      printf("MOVE %c TO %c\n", A, B);
      printf("MOVE %c TO %c\n", B, C);
   }
}

// Function to perform right rotation of disks in Tower of Hanoi
void RotateRight(int n, char A, char C, char B)
{
   if (n > 1)
   {
      RotateCyclic(n - 1, C, A, B);
      printf("MOVE %c TO %c\n", C, B);
      RotateCyclic(n - 1, A, B, C);
   }
   else
   {
      printf("MOVE %c TO %c\n", C, B);
   }
}

