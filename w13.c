/*********************************************
 * Id: shar1428
 *
 * Russian Peasant Method
 *********************************************/



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("Usage: %s <number1> <number2>\n", argv[0]);
      return 1;
   }

   int n = atoi(argv[1]);
   int m = atoi(argv[2]);
   int sum = 0;

   printf("%6d %6d\n", n, m);

   while (n >= 1) {
      if (n % 2 != 0) {  // Check if n is odd
         printf("%6d %6d %6d\n", n, m, m);
         sum += m;
      }
      else {
         printf("%6d %6d\n", n, m);
      }

      n /= 2;  // Halve n
      m *= 2;  // Double m
   }

   printf("%20s\n", "------");
   printf("%20d\n", sum);

   return 0;
}

