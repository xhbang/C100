/* ------------------------------------------------------ */
/* PROGRAM magic square of odd order :                    */
/*    This program will fills a matrix of order n*n with  */
/* integers of 1 to n*n such that the sums of rows,       */
/* columns and two disgonals are all the same.  DON'T     */
/* READ THIS PROGRAM before read my book.                 */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/03/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE   20

void main(void)
{
     int  matrix[MAXSIZE][MAXSIZE]; /* the magic square   */
     int  count;                    /* 1..n*n counting    */
     int  row;                      /* row index          */
     int  column;                   /* column index       */
     int  order;                    /* input order        */
     char line[100];

     printf("\nOdd Order Magic Square Generator");
     printf("\n================================");
     printf("\n\nOrder Please --> ");
     gets(line);
     order = atoi(line);

     if (order > MAXSIZE)
          printf("\n*** ERROR ***  Order should be <= %d", MAXSIZE);
     else if (order % 2 == 0)
          printf("\n*** ERROR ***  Order must be an odd integer");
     else {
          row    = 0;         /* start of from the middle */
          column = order/2;   /* of the first row.        */
          for (count = 1; count <= order*order; count++) {
               matrix[row][column] = count; /* put next # */
               if (count % order == 0)  /* move down ?    */
                    row++;    /* YES, move down one row   */
               else {         /* compute next indices     */
                    row    = (row == 0) ? order - 1 : row - 1;
                    column = (column == order-1) ? 0 : column + 1;
               }
          }
          printf("\n\nMagic Square of order %d :\n\n", order);
          for (row = 0; row < order; row++) {
               for (column = 0; column < order; column++)
                    printf("%4d", matrix[row][column]);
               printf("\n");
          }
     }
}
