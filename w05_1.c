/*********************************************
 * Id: shar1428
 *
 * This program is to build the tower of Hanoi
 *********************************************/


#include <stdio.h>
#include <stdlib.h>

// Function prototype for the recursive Tower of Hanoi solution
void towerOfHanoi(int numDisks, char sourcePeg, char targetPeg, char auxiliaryPeg);

// Main function to accept the number of disks as a command line argument and initiate the solution
int main(int argc, char *argv[])
{
   // Validate the command line input and convert it to an integer
   if(argc < 2) {
      fprintf(stderr, "Usage: %s <number_of_disks>\n", argv[0]);
      return EXIT_FAILURE;
   }

   int numDisks = atoi(argv[1]);

   // Call the recursive function to solve the Tower of Hanoi
   towerOfHanoi(numDisks, 'A', 'C', 'B');
   return 0;
}

// Recursive function to solve the Tower of Hanoi puzzle and print the required moves
void towerOfHanoi(int numDisks, char sourcePeg, char targetPeg, char auxiliaryPeg)
{
   // Base case: if there is only one disk, move it from the source peg to the target peg
   if(numDisks == 1)
   {
      printf("MOVE %c TO %c\n", sourcePeg, targetPeg);
      return;
   }
   // Move (numDisks - 1) disks from the source peg to the auxiliary peg using the target peg
   towerOfHanoi(numDisks - 1, sourcePeg, auxiliaryPeg, targetPeg);

   // Move the remaining disk from the source peg to the target peg
   printf("MOVE %c TO %c\n", sourcePeg, targetPeg);

   // Move the (numDisks - 1) disks from the auxiliary peg to the target peg using the source peg
   towerOfHanoi(numDisks - 1, auxiliaryPeg, targetPeg, sourcePeg);
}

