/*********************************************
 * Id: shar1428
 *
 * This program computes 2^n for any non-negative integer n
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Function to solve the restricted version of the Tower of Hanoi problem using a recursive approach
void restrictedTowerOfHanoi(int, char, char, char);

// The main function parses the number of disks from command line arguments and initiates the restricted Tower of Hanoi solution
int main(int argc, char *argv[])
{
   int numberOfDisks = atoi(argv[1]); // Convert the argument to an integer representing the number of disks
   restrictedTowerOfHanoi(numberOfDisks, 'A', 'B', 'C'); // Initiate the recursive function to solve the puzzle
   return 0; // Indicate successful program termination
}

// Recursive function to implement the solution for the restricted Tower of Hanoi problem 
void restrictedTowerOfHanoi(int numberOfDisks, char A, char B, char C)
{
   if (numberOfDisks == 1) // Base case: if there's only one disk, make the necessary moves to transfer it to rod C
   {
      printf("MOVE %c TO %c\n", A, B); // Step 1: Move the disk from rod A to rod B
      printf("MOVE %c TO %c\n", B, C); // Step 2: Move the disk from rod B to rod C
      return; // Return from the recursive call
   }
   
   // Recursive cases to move n-1 disks around as per the rules of the restricted Tower of Hanoi problem
   restrictedTowerOfHanoi(numberOfDisks - 1, A, B, C); // Move n-1 disks from A to C using B as the auxiliary rod
   printf("MOVE %c TO %c\n", A, B); // Move a disk from A to B
   restrictedTowerOfHanoi(numberOfDisks - 1, C, B, A); // Move n-1 disks back from C to A using B as the auxiliary rod
   printf("MOVE %c TO %c\n", B, C); // Move a disk from B to C
   restrictedTowerOfHanoi(numberOfDisks - 1, A, B, C); // Repeat the process for the remaining disks
}

