/*********************************************
 * Id: shar1428
 *
 * Modified Robot Coin Collecting
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Function to compute the maximum number of coins a robot can collect
int calculateMaxCoins(int rows, int cols, int board[100][100]);

// Function to find and return the maximum value between two numbers
int findMax(int a, int b);

// Main function that initializes and processes the game board
int main(int argc, char *argv[]) 
{
   int numRows = atoi(argv[1]), numCols = atoi(argv[2]);
   int i, j, k = 3;
   int gameBoard[100][100];
   char inputBoard[numRows][numCols];

   // Populating the input board with values from command line arguments
   for (i = 0; i < numRows; i++)
   {
      for (j = 0; j < numCols; j++) 
      {
         inputBoard[i][j] = *(argv[k++]);
      }
   }

   // Displaying the input board
   printf("Board Inputed:\n");
   for (i = 0; i < numRows; i++) 
   {
      for (j = 0; j < numCols; j++)
      {
         printf("%c\t", inputBoard[i][j]);
      }
      printf("\n");
   }

   // Converting the character board to integer representation for calculations
   for (i = 0; i < numRows; i++)
   {
      for (j = 0; j < numCols; j++) 
      {
         if (inputBoard[i][j] != 'X')
         {
            gameBoard[i][j] = inputBoard[i][j] - '0';
         }
         else
         {
            gameBoard[i][j] = -1;
         }
      }
   }

   // Calculating and displaying the coin collecting table
   printf("\nCoin Collecting Table:\n");
   calculateMaxCoins(numRows, numCols, gameBoard);

   return 0;
}

// Function to compute the maximum number of coins a robot can collect
int calculateMaxCoins(int rows, int cols, int coinsBoard[100][100]) 
{
   int maxCoinsTable[rows][cols];
   int i, j, k, flag = 0;

   // Initializing the first cell of the table
   maxCoinsTable[0][0] = coinsBoard[0][0] == -1 ? 0 : coinsBoard[0][0];

   // Initializing all cells to 0
   for (i = 0; i < rows; i++)
   {
      for (j = 0; j < cols; j++)
      {
         maxCoinsTable[i][j] = 0;
      }
   }

   // Filling the first row of the table
   for (j = 1; j < cols; j++)
   {
      if (coinsBoard[0][j] != -1 && flag == 0)
      {
         maxCoinsTable[0][j] = maxCoinsTable[0][j - 1] + coinsBoard[0][j];
      }
      else
      {
         flag++;
         maxCoinsTable[0][j] = 0;
      }
   }

   // Resetting the flag for the first column
   flag = 0;
   for (i = 1; i < rows; i++)
   {
      if (coinsBoard[i][0] != -1 && flag == 0)
      {
         maxCoinsTable[i][0] = maxCoinsTable[i - 1][0] + coinsBoard[i][0];
      }
      else
      {
         flag++;
         maxCoinsTable[i][0] = 0;
      }
   }

   // Filling the rest of the table
   for (i = 1; i < rows; i++)
   {
      for (j = 1; j < cols; j++)
      {
         if (coinsBoard[i][j] != -1)
         {
            maxCoinsTable[i][j] = findMax(maxCoinsTable[i - 1][j], maxCoinsTable[i][j - 1]) + coinsBoard[i][j];
         }
         else
         {
            maxCoinsTable[i][j] = -1;
            if (maxCoinsTable[i][j - 1] == 0)
            {
               for (k = i + 1; k < rows; k++)
               {
                  if (coinsBoard[k][j] != -1)
                  {
                     coinsBoard[k][j] = 0;
                  }
               }
            }
         }
      }
   }

   // Displaying the filled table
   for (i = 0; i < rows; i++)
   {
      for (j = 0; j < cols; j++)
      {
         if (maxCoinsTable[i][j] != -1)
         {
            printf("%d\t", maxCoinsTable[i][j]);
         }
         else
         {
            printf("0\t");
         }
      }
      printf("\n");
   }

   printf("\nThe optimal path with this board is: %d\n", maxCoinsTable[rows - 1][cols - 1]);
   return maxCoinsTable[rows - 1][cols - 1];
}

// Helper function to find the maximum of two integers
int findMax(int a, int b)
{
   return (a > b) ? a : b;
}

