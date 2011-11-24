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

     gets(line);
     order = atoi(line);

     for (row = 0; row < order; row++)
          for (column = 0; column < order; column++)
               matrix[row][column] = 0;

     row    = 1;
     column = order/2 - 1;
     for (count = 1; count <= order*order; count++) {
          row--;
          column++;
          if (row < 0 && column == order) 
               row = 1, column = order - 1;
          else if (row < 0)
               row = order - 1;
          else if (column == order)
               column = 0;
          if (matrix[row][column] != 0)
               row += 2, column--;
          matrix[row][column] = count;
     }               
     printf("\n\nMagic Square of order %d :\n\n", order);
     for (row = 0; row < order; row++) {
          for (column = 0; column < order; column++)
               printf("%4d", matrix[row][column]);
          printf("\n");
     }
}
