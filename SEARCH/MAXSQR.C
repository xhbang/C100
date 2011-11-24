/* ------------------------------------------------------ */
/* FUNCTION maxsquare :                                   */
/*    Given a square matrix and a key, this function scans*/
/* the input matrix to find out the maximum size of a     */
/* square sub-block such that all elements of this sub-   */
/* block are all the same.                                */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/03/1989 */
/* ------------------------------------------------------ */

#define   MAXSIZE     10
#define   min(a,b,c)  (((a) < (b)) ? ((a) < (c) ? (a) : (c)) \
                                   : ((b) < (c) ? (b) : (c)))

typedef   int MATRIX[MAXSIZE][MAXSIZE];

void maxsquare(MATRIX x, int n, int key, int *row, int *column, int *width)
{
     MATRIX  size;            /* a working matrix         */
     int     i, j;            /* working storages         */

     for (j = 0; j < n; j++)  /* copy last row of matrix  */
          size[n-1][j] = x[n-1][j]; /* x[][] to size[][]  */

     for (i = n-2; i >= 0; i--) { /* process bottom-up    */
          size[i][n-1] = x[i][n-1]; /* copy i-th row and  */
          for (j = n-2; j >= 0; j--)/* update size value  */
               size[i][j] = (x[i][j] == key) ? 
                    1 + min(size[i+1][j],size[i][j+1],size[i+1][j+1]) :
                    0;
     }

     *width = 0;              /* assume width is zero     */
     for (i = 0; i < n; i++)  /* scan size[] matrix for   */
          for (j = 0; j < n; j++)  /* the maximum and the */
               if (size[i][j] > *width) { /* cooresponding*/
                    *width  = size[i][j]; /* locations.   */
                    *row    = i;
                    *column = j;
               }
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     MATRIX  x = { { 1, 1, 1, 0, 0, 0, 0, 0},
                   { 0, 1, 1, 1, 1, 0, 0, 0},
                   { 0, 0, 1, 1, 1, 1, 1, 0},
                   { 0, 0, 0, 1, 1, 1, 1, 1},
                   { 0, 1, 1, 1, 1, 1, 1, 1},
                   { 0, 1, 1, 1, 1, 0, 1, 1},
                   { 0, 0, 1, 1, 1, 0, 0, 0},
                   { 0, 0, 1, 1, 1, 1, 0, 0}};
     int  n = 8;
     int  row, column, width, key = 1;

     printf("\nFind Maximum Size Square of Same Data");
     printf("\n=====================================");
     printf("\n\nGiven Matrix : \n");
     for (row = 0; row < n; row++) {
          for (column = 0; column < n; column++)
               printf("%2d", x[row][column]);
          printf("\n");
     }
     printf("\nKey to be searched = %d", key);

     maxsquare(x, n, key, &row, &column, &width);

     printf("\nMaximum Square is located at x[%d][%d] with size %d",
            row, column, width);
}
