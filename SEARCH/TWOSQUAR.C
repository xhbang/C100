/* ------------------------------------------------------ */
/* PROGRAM  twosquare :                                   */
/*    Given an integer, this program computes all sums of */
/* two squares of this given number by using the concept  */
/* discussed in the previous program (M_SEARCH.C).        */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/28/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>           /* for I/O functions        */
#include  <stdlib.h>          /* for atoi()               */
#include  <math.h>            /* for sqrt()               */

void  main(void)
{
     int  given;              /* the given number         */
     int  row, column;        /* row and column indicators*/
     int  count;              /* number of solutions      */
     char line[100];

     printf("\nRepresenting a Given Number as the Sum of Two Squares");
     printf("\n=====================================================\n");
     printf("\nAn Integer Please ---> ");
     gets(line);
     given = atoi(line);
     printf("\nCount      X      Y");
     printf("\n-----  -----  -----");

     row    = 1;              /* starts from far enough   */
     column = (int) (sqrt((double) given) + 0.5);
     count  = 0;              /* so solution yet          */
     while (row <= given && column > 0)  /* scan down...  */
          if (row*row + column*column == given) {
               count++;
               printf("\n%5d%7d%7d", count, row, column);
               row++;
               column--;
          }
          else if (row*row + column*column > given)
               column--;
          else
               row++;

     if (count == 0)
          printf("\n\nSorry, NO ANSWER found.");
     else
          printf("\n\nThere are %d possible answers.");
}
