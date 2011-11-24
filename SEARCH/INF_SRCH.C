/* ------------------------------------------------------ */
/* FUNCTION infinite search :                             */
/*    Given a sorted infinite array ended with unknown    */
/* number of INFINITEs, this function perform an extended */
/* binary search to find a particular input key.          */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/16/1989 */
/* ------------------------------------------------------ */

#define  NOT_FOUND   -1

/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  bound(int [], int, int *, int *);
int   search(int [], int, int, int);

/* ------------------------------------------------------ */
/* FUNCTION inf_search :                                  */
/*    The control routine.                                */
/* ------------------------------------------------------ */

int  inf_search(int x[], int GIVEN)
{
     int  left, right;

     bound(x, GIVEN, &left, &right);        /* dound      */
     return search(x, GIVEN, left, right);  /* then search*/
}

/* ------------------------------------------------------ */
/* FUNCTION bound :                                       */
/*    Given a sorted infinite array and a key GIVEN, this */
/* function returns two subscripts, namely start and end, */
/* which bound the given key.                             */
/* ------------------------------------------------------ */

void  bound(int x[], int GIVEN, int *start, int *end)
{
     int  delta = 1;          /* interval length          */

     *start  = 0;             /* starting from the 1st pos*/
     *end = *start + delta;   /* interval ends before *end*/
     while (!(x[*start] <= GIVEN && GIVEN < x[*end])) {
          delta += delta;     /* if [start,end) can not   */
          *start = *end;      /* bound, then double length*/
          *end   = *start+delta; /* and try again.        */
     }
     (*end)--;                /* returns the true bound   */
}


/* ------------------------------------------------------ */
/* FUNCTION search :                                      */
/*    The traditional binary search function.             */
/* ------------------------------------------------------ */

int  search(int x[], int GIVEN, int low, int high)
{
     int  mid;

     while (low <= high) {
          mid = (low + high)/2;
          if (GIVEN < x[mid])
               high = mid - 1;
          else if (GIVEN > x[mid])
               low = mid + 1;
          else 
               return mid;
     }
     return NOT_FOUND;
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>          /* for atoi()               */
#include  <limits.h>          /* for INT_MAX              */

void main(void)
{
     int  number[30] = {   1,   3,   5,   8,  10, 
                          21,  25,  50,  67,  68,
                          70,  84, 100, 130, 150, 
                         151, 170, 180, 200, 300,
                         459, 480, 499, 503, 555,
                         570, 623, 699, 784, 981};
     int  input[100];
     int  i, key, answer;
     char line[100];

     for (i = 0; i < 30; i++)
          input[i] = number[i];
     for (i = 30; i < 100; i++)
          input[i] = INT_MAX;

     printf("\nInfinite Search Program");
     printf("\n=======================");
     printf("\n\nGiven Infinite Sorted Array :");
     for (i = 0; i < 100; i++) {
          if (i % 15 == 0) printf("\n");
          if (input[i] < INT_MAX) 
               printf("%4d", input[i]);
          else
               printf(" inf");
     }
     printf("\n\nYour Search Key Please --> ");
     gets(line);
     key = atoi(line);

     if ((answer = inf_search(input, key)) >= 0)
          printf("\nKey found at position %d", answer);
     else
          printf("\nKey NOT FOUND!");
}
