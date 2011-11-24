/* ------------------------------------------------------ */
/* PROGRAM  singly-even magic square :                    */
/*    Given an integer of form 2*(2k+1), this program     */
/* builds up a magic square with numbers from 1 to n*n.   */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/23/1989 */
/* ------------------------------------------------------ */

#define    MAXSIZE   30

void  singly_even(int [][MAXSIZE], int);
void  magic_o(int [][MAXSIZE], int);
void  exchange(int [][MAXSIZE], int);

/* ------------------------------------------------------ */
/* FUNCTION  singly_even :                                */
/*    This is the driver program.  It fills the upper-left*/
/* lower-right, upper-right and lower-left parts by using */
/* odd order magic square routine.  Then exchange some    */
/* parts in each routine in order to maintain the magic   */
/* properties.                                            */
/* ------------------------------------------------------ */

void  singly_even(int matrix[][MAXSIZE], int n)
{
     int  half = n/2;

     magic_o(matrix, half);
     exchange(matrix, n);
}


/* ------------------------------------------------------ */
/* FUNCTION  magic_o :                                    */
/*    Odd order magic square routine.  It fills the block */
/* bounded by left, right, top and bottom with numbers    */
/* starting from 'start'.  Otherwise all are the same as  */
/* the magic square routine discussed before.             */
/* ------------------------------------------------------ */

void  magic_o(int matrix[][MAXSIZE], int n)
{
     int  count;                    /* fill counting      */
     int  row;                      /* row index          */
     int  column;                   /* column index       */

     row    = 0;              /* start of from the middle */
     column = n/2;               /* of the first row.     */
     for (count = 1; count <= n*n; count++) {
          matrix[row][column] = count;      /* put # in A */
          matrix[row+n][column+n] = count + n*n; /* in B  */
          matrix[row][column+n] = count + 2*n*n; /* in C  */
          matrix[row+n][column] = count + 3*n*n; /* in D  */
          if (count % n == 0) /* move downward ?          */
               row++;         /* YES, move down one row   */
          else {              /* compute next indices     */
               row    = (row == 0) ? n - 1 : row - 1;
               column = (column == n-1) ? 0 : column + 1;
          }
     }
}


/* ------------------------------------------------------ */
/* FUNCTION  exchange :                                   */
/*    This function exchanges some parts in each row in   */
/* order to maintain the magic square properties.         */
/* ------------------------------------------------------ */

#define   SWAP(x,y)   { int t; t = x; x = y; y = t;}

void  exchange(int x[][MAXSIZE], int n)
{
     int  width  = n / 4;
     int  width1 = width - 1;
     int  i, j;

     for (i = 0; i < n/2; i++)
          if (i != width) {   /* if not the width-row    */
               for (j = 0; j < width; j++) 
                    SWAP(x[i][j], x[n/2+i][j]);
               for (j = 0; j < width1; j++)
                    SWAP(x[i][n-1-j], x[n/2+i][n-1-j]);
          }
          else {              /* width-row is special    */
               for (j = 1; j <= width; j++)
                    SWAP(x[width][j], x[n/2+width][j]);
               for (j = 0; j < width1; j++)
                    SWAP(x[width][n-1-j], x[n/2+width][n-1-j]);
          }
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void  main(void)
{
     int  matrix[MAXSIZE][MAXSIZE];
     int  n;
     int  i, j;
     char line[100];

     printf("\nSingly-Even Order Magic Square");
     printf("\n==============================");
     printf("\n\nOrder Please (must be 2*(2k+1)) --> ");
     gets(line);
     n = atoi(line);

     if (n % 2 == 0 && (n/2) % 2 == 1) {
          singly_even(matrix, n);
          printf("\n");
          for (i = 0; i < n; i++) {
               for (j = 0; j < n; j++)
                    printf("%4d", matrix[i][j]);
               printf("\n");
          }
     }
     else
          printf("\n*** Illegal Order ***");
}
