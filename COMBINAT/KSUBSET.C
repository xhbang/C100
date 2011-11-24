/* ------------------------------------------------------ */
/* PROGRAM Lexical Order of k-Subsets :                   */
/*    Given a n-element set {1,2,3,...,n} and a k <= n,   */
/* this program lists all k-element subsets of {1,2,..,n} */
/* in lexical order.                                      */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/08/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE    20
#define   LOOP        1

void main(void)
{
     int  set[MAXSIZE];
     int  n;
     int  k;
     int  position;
     int  i, j;
     char line[100];

     printf("\nAll k Elements Subsets from a n Elements Set");
     printf("\n============================================");
     printf("\n\nNumber of Elements in the Set --> ");
     gets(line);
     n = atoi(line);
     printf("\n\nNumber of Elements in Subset ---> ");
     gets(line);
     k = atoi(line);

     for (i = 0; i < k; i++)  /* initialize the subset to */
          set[i] = i + 1;     /* {1,2,3,...,k}            */
     printf("\n{%d", set[0]); /* display it               */
     for (j = 1; j < k; j++)
          printf(",%d", set[j]);
     printf("}");


     position = k - 1;        /* 'position' indicates the */
     while (LOOP) {           /* pos to be increased      */
          if (set[k-1] == n)  /* if last pos is full, then*/
               position--;    /* move position left       */
          else                /* or if not full, then the */
               position = k - 1; /* pos is always the last*/
          set[position]++;    /* so add one to the pos.   */
          for (i = position+1; i < k; i++) /* add inc. all*/
               set[i] = set[i-1] + 1; /* pos to its right */

          printf("\n{%d", set[0]); /* display it.         */
          for (j = 1; j < k; j++)
               printf(",%d", set[j]);
          printf("}");

          if (set[0] >= n-k+1) break; /* if 1st pos full  */
     }
}
