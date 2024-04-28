/*********************************************
 * Id: shar1428
 *
 * This program is to build the tower of Hanoi
 *********************************************/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Using recurssion to solve the Hanoi tower
void solveTowerOfHanoi(int numDiscs, char sourcePeg, char targetPeg, char auxiliaryPeg);


//Main Function
int main(int argc, char *argv[])
{
   if(argc < 2) {
      fprintf(stderr, "Usage: %s <number_of_discs>\n", argv[0]);
      return EXIT_FAILURE;
   }

   int numDiscs = atoi(argv[1]);

   int minimumMoves = exp2(numDiscs) - 1;
   printf("It will take %d moves to solve the Tower of Hanoi with %d disks.\n", minimumMoves, numDiscs);

   solveTowerOfHanoi(numDiscs, 'A', 'C', 'B');

   return 0;
}


//Moves the entire stack using Recursion and solve the tower of Hanoi
void solveTowerOfHanoi(int numDiscs, char sourcePeg, char targetPeg, char auxiliaryPeg)
{
   if(numDiscs == 1)
   {
      printf("MOVE %c TO %c\n", sourcePeg, targetPeg);
      return;
   }
   solveTowerOfHanoi(numDiscs-1, sourcePeg, auxiliaryPeg, targetPeg);
   printf("MOVE %c TO %c\n", sourcePeg, targetPeg);
   solveTowerOfHanoi(numDiscs-1, auxiliaryPeg, targetPeg, sourcePeg);
}

