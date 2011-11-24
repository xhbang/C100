/* ------------------------------------------------------ */
/* PROGRAM  sorttest :                                    */
/*    This is a sample program to drive various sorting   */
/* function testing.  It generates positive random data,  */
/* puts them into an array and finally calls the sorting  */
/* function named sort().  NOTE that for bucket sort, you */
/* have to change the data type from 'int' to 'unsigned'. */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

#define   MAXSIZE   1000

void sort(int [], int);

void main(void)
{
     int  input[MAXSIZE+1];
     int  n, i;
     char line[100];

     printf("\nSort Program Testing Driver for Random Data");
     printf("\n===========================================");
     printf("\n\nHow many data items ( <= 1000) ? ");
     gets(line);
     n = atoi(line);

     srand((unsigned) clock());
     printf("\nGenerated Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          input[i] = rand();
          printf("%6d", input[i]);
     }

     sort(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}
