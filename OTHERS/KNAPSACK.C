/* ------------------------------------------------------ */
/* FUNCTION  knapsack :                                   */
/*    Given a list of items with size stored in an array  */
/* size[] and a knapsack of size SIZE, this function      */
/* determines whether there are some items summing up to  */
/* the exact size SIZE.   Those selected items are stored */
/* in the array result[].  Function value is the number   */
/* of items selected.  NOT_FOUND means the selection is   */
/* impossible.                                            */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/01/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc() and free()  */

#define   YES          1
#define   NO           0
#define   NOT_FOUND   -1

void  reverse(int [], int);

int  knapsack(int size[], int n, int SIZE, int result[])
{
     int  **exist;            /* exist[][] table          */
     int  **member;           /* member[][] table         */
     int  count;              /* number of items selected */
     int  i, j;

     exist     = (int **) malloc(sizeof(int *)*(n+1));
     exist[0]  = (int *) malloc(sizeof(int)*(n+1)*(SIZE+1));
     member    = (int **) malloc(sizeof(int *)*(n+1));
     member[0] = (int *) malloc(sizeof(int)*(n+1)*(SIZE+1));
     for (i = 1; i <= n; i++) {
          exist[i]  = exist[i-1] + (SIZE+1);
          member[i] = member[i-1] + (SIZE+1);
     }

     exist[0][0] = YES;       /* for 0, there is solvable */
     for (j = 1; j <= SIZE; j++) /* but without any item, */
          exist[0][j] = NO;   /* no solution is possible  */

     for (i = 1; i <= n; i++) /* for i items .....        */
          for (j = 0; j <= SIZE; j++) { /* solvable for j?*/
               exist[i][j] = member[i][j] = NO; /* default*/
               if (exist[i-1][j]) { /* i-1 and j solvable?*/
                    exist[i][j]  = YES; /* YES, i/j too.  */
                    member[i][j] = NO;  /* doesn't inc. i */
               }
               else if (j >= size[i-1]) /* over limit?    */
                    if (exist[i-1][j-size[i-1]]) { /* back*/
                         exist[i][j]  = YES; /* include i */
                         member[i][j] = YES;
                    }
     }

     if (exist[n][SIZE]) {    /* scan back to collect ans */
          for (count = 0, i = n, j = SIZE; i != 0 && j != 0; )
               if (member[i][j] == YES) {
                    result[count++] = --i;
                    j -= size[i];
               }
               else
                    i--;
          reverse(result, count);
     }
     else
          count = NOT_FOUND;

     free(exist[0]);   free(exit);
     free(member[0]);  free(member);
     return count;
}

/* ------------------------------------------------------ */
/* FUNCTION  reverse :                                    */
/*    Reverse the given array x[].                        */
/* ------------------------------------------------------ */

#define   SWAP(a, b)  { temp = a; a = b; b = temp; }

void  reverse(int x[], int n)
{
     int  i, j, temp;

     for (i = 0, j = n-1; i < j; i++, j--)
          SWAP(x[i], x[j]);
}
 
/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  size[] = { 1, 2, 4, 7, 10, 12, 13, 15, 17 };
     int  n = sizeof(size)/sizeof(int);
     int  SIZE = 27;
     int  result[5], count;
     int  i;

     printf("\nKnapsack Problem");
     printf("\n================");
     printf("\n\nGiven Item Size Array : ");
     for (i = 0; i < n; i++)
          printf(" %d", size[i]);
     printf("\n\nGiven Knapsack Size = %d", SIZE);

     if ((count = knapsack(size, n, SIZE, result)) == NOT_FOUND)
          printf("\n\nNo Solution Found.");
     else {
          printf("\n\nSolution is %d=%d", SIZE, size[result[0]]);
          for (i = 1; i < count; i++)
               printf("+%d", size[result[i]]);
     }
}
