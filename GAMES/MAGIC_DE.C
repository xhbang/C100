/* ------------------------------------------------------ */
/* PROGRAM  doubly even magic builder :                   */
/*    Given an integer n = 4*m, m > 0, this program builds*/
/* up a magic square of order n.                          */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/23/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE   20        /* square size              */
#define   MARK      -1        /* marker for build up      */

void  main(void)
{
     int  square[MAXSIZE][MAXSIZE]; /* the square         */
     int  n;                  /* order of the magic square*/
     int  count, inv_count;   /* 1 -> n^2 and n^2 -> 1    */
     int  marker;             /* working marker 1,-1,1,-1 */
     int  i, j;
     char line[100];

     printf("\nDoubly-Even Magic Square");
     printf("\n========================");
     printf("\n\nOrder (4*m, m>0) please --> ");
     gets(line);
     n = atoi(line);
     if (n % 4 != 0)
          printf("\n*** Illegal Order *****");
     else {
          marker = MARK;      /* mark the upper part      */
          for (i = 0; i < n/2; i++, marker = -marker)
               for (j = 0; j < n/2; j++, marker = -marker)
                    square[i][j] = square[i][n-1-j] = marker;

          count     = 1;      /* upward counter           */
          inv_count = n*n;    /* downward counter         */
          for (i = 0; i < n/2; i++)
               for (j = 0; j < n; j++)
                    if (square[i][j] != MARK) {  /* marked*/
                         square[i][j] = count++;
                         square[n-1-i][n-1-j] = inv_count--;
                    }
                    else {    /* unmarked                 */
                         square[i][j] = inv_count--;
                         square[n-1-i][n-1-j] = count++;
                    }
          printf("\n");
          for (i = 0; i < n; i++) {
               for (j = 0; j < n; j++)
                    printf("%4d", square[i][j]);
               printf("\n");
          }
     }
}
