/* ------------------------------------------------------ */
/* FUNCTION matrix_search :                               */
/*    Given a matrix with a special property that for each*/
/* m[i][j] we have m[i][j] < m[i,j+1] and < m[i+1][j],    */
/* also given is a key value, this function will locate   */
/* this value in the matrix m[][] in a fashion like binary*/
/* search.  This method follow from Eric S. Rosenthal.    */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/02/1989 */
/* ------------------------------------------------------ */

#define  MAXSIZE  10                    /* matrix size    */

typedef  int MATRIX[MAXSIZE][MAXSIZE];  /* matrix type    */

void matrix_search(MATRIX mat, int n, int key, int *index_x, int *index_y)
{
     int  i = 0, j = n-1;     /* start from upper right   */

     for (*index_x = *index_y = -1; i < n && j >= 0; )
          if (mat[i][j] < key)/* element too small ?      */
               i++;           /* move down one row.       */
          else if (mat[i][j] > key) /* element to large ? */
               j--;           /* move left one column     */
          else {
               *index_x = i;  /* found, record locations  */
               *index_y = j;
               return;        /* and return               */
          }
     return;
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void main(void)
{
     MATRIX  x = { { 1,  3,  7,  9, 13},
                   { 2,  4,  8, 10, 14},
                   { 5,  6,  9, 12, 15},
                   { 7, 12, 13, 15, 19},
                   {11, 13, 16, 18, 25}};
     int  n    = 5;
     int  key;
     char line[100];
     int  i, j;

     printf("\nSpecial Format Matrix Search Program");
     printf("\n====================================\n");
     printf("\nGiven Matrix :\n");
     for (i = 0; i < n; i++) {
          for (j = 0; j < n; j++)
               printf("%5d", x[i][j]);
          printf("\n");
     }

     printf("\n\nThe Key to be Searched for --> ");
     gets(line);
     key = atoi(line);
     matrix_search(x, n, key, &i, &j);
     if (i < 0 || j < 0)
          printf("\n\nNO! Key value not found");
     else
          printf("\n\nThe Key is located at mat[%d][%d]", i, j);
}
