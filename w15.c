/*********************************************
 * Id: shar1428
 *
 * Boye-Moore Algorithm 
 *********************************************/

#include<stdio.h>
#include<string.h>

#define NO_CHARS 256
#define MAX_SIZE 50
#define MAX 128
#define TRL 16
#define MIN_WRITEABLE 32

// Function to display the shift table
void printShiftTable(int Table[]);

// Function to create the shift table
int* shifttable(char needle[]); 

// Function to create the Good Suffix Table
void GoodSuffixTable(char *needle);

// Process function for Boyer-Moore algorithm
void bmProcess(char *t, char *p, int m, int n);

// Function for searching using Boyer-Moore
void bmSearch(char *p, char *t, int n, int m, int s[MAX_SIZE]);

// Function to perform the search
void search(char tt[MAX_SIZE], char pp[MAX_SIZE]);

// Function to find the maximum of two numbers
int max(int a, int b);

// Main function
int main(int argc, char *argv[])
{   
   char pp[MAX_SIZE], tt[MAX_SIZE];
   strcpy(tt, argv[2]);
   strcpy(pp, argv[1]);
   shifttable(pp);
   GoodSuffixTable(pp);
   search(tt, pp);        
   return 0;
}

// Function to create the shift table
int* shifttable(char needle[]) 
{
   static int Table[MAX];
   int i, j, m = strlen(needle);
   for (i = 0; i < MAX; i++)
   {
      Table[i] = m;
   }
   for (j = 0; j < m - 1; j++)
   {
      Table[(int)needle[j]] = m - 1 - j;
   }
   printShiftTable(Table); 
   return Table;
}

// Function to display the shift table
void printShiftTable(int Table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX; start += TRL)
   {
      for(i = start; i < start + TRL; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");
      for(i = start; i < start + TRL; i++)
      {
         printf("%d\t", Table[i]);
      }
      printf("\n\n");
   }
}

// Function to construct the good-suffix shift table
void GoodSuffixTable(char *needle)
{	
   int m = strlen(needle), gsuffix[m - 1], i;
   gsuffix[1] = 2;
   gsuffix[2] = 5;
   gsuffix[3] = 5; 
   gsuffix[4] = 5; 
   gsuffix[5] = 5;		
   for(i = 1; i < m; i++)
   {
      printf("%d %*s %d\n", i, m, &needle[m - i], gsuffix[i]);
   }
}  

// Function to perform the search
void search(char *tt, char *pp)
{
   int n = strlen(tt), m = strlen(pp);      
   printf("%s\n", tt);
   bmProcess(tt, pp, m, n);
}

// Process function for Boyer-Moore algorithm
void bmProcess(char *t, char *p, int m, int n)
{
   int s[MAX_SIZE], h;
   for(h = 0; h < m; h++)
   {
      s[h] = 0;
   }
   int i = m, j = m + 1, f[MAX_SIZE];   
   f[i] = j;
   while (i > 0)
   {
      while (j <= m && p[i - 1] != p[j - 1])
      {
         if (s[j] == 0) 
         s[j] = j - i;							
         j = f[j];
      }
      i--;
      j--;
      f[i] = j;
   }   
   i = 0, j = 0;
   j = f[0];
   for (i = 0; i <= m; i++)
   {
      if (s[i] == 0) 									
      s[i] = j;										
      if (i == j) 
      j = f[j];
   }
   bmSearch(p, t, n, m, s);
}

// Function for searching using Boyer-Moore
void bmSearch(char *p, char *t, int n, int m, int s[MAX_SIZE])
{
   int i = 0, k, j, matches = 0, occ[NO_CHARS];   
   char a;   
   for (i = 0; i < NO_CHARS; i++)
   {
      occ[i] = -1;                
   }
   for (j = 0; j < m; j++)
   {
      a = p[j];
      occ[(int)a] = j;               
   }      
   i = 0;
   j = 0;   
   while (i <= n - m)
   {
      j = m - 1;
      while (j >= 0 && p[j] == t[i + j]) 
      j--;
      if (j < 0)
      {            	
         for(k = 0; k < i; k++)
         {
            printf(" ");
         }                
         printf(p);
         printf("---found\n");      
         matches += i;                
         for(k = 0; k <= i; k++)
         {
            printf(" ");
         } 
         printf(p);				
         printf("\nMatches found at locations: %d\n", matches);                  
         i += s[0]; 												
      }
      else
      {         	
         for(k = 0; k < i; k++)
         {
            printf(" ");
         } 
         printf("%s", p);
         if(i > 0)
         {
            printf(" d1=%d d2=%d", (j - occ[(int)t[i + j]]), s[j + 1]);  	
         }	
         printf("\n");
         i += max(s[j + 1], j - occ[(int)t[i + j]]);     				    
      }
   }
}

// Utility function to get the maximum of two integers
int max(int a, int b)
{ 
   return (a > b) ? a : b;
}

