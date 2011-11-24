/* ------------------------------------------------------ */
/* FUNCTION  monotone_max :                               */
/*    Given a monotone matrix, this finds the maximum of  */
/* each row in O(n*log(n)) time with divide-amd-conquer   */
/* technique.                                             */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/03/1989 */
/* ------------------------------------------------------ */

#include  <limits.h>          /* for INT_MIN              */

#define   SIZE   10

/* ------------------------------------------------------ */
/*                 function prototypes                    */
/* ------------------------------------------------------ */

void  monotone_max(int [][SIZE], int, int, int []);
void  get_max(int [][SIZE], int, int, int, int, int []);

void  monotone_max(int data[][SIZE], int m, int n, int loc[])
{
     get_max(data, 0, m-1, 0, n-1, loc);
}

/* ------------------------------------------------------ */
/* FUNCTION  get_max :                                    */
/*    The working routine for monotone matrix max. finder.*/
/* Given a monotone matrix, its top(T), bottom(B), left(L)*/
/* and right(R) bound, this function finds the maximum of */
/* each row by divide-and-conquer technique and stores the*/
/* column numbers in which the max. occurres in loc[].    */
/* ------------------------------------------------------ */

void  get_max(int data[][SIZE], int T, int B, int L, int R, int loc[])
{
     int  mid_row = (T + B)/2;
     int  pos, max;
     int  j;

     if (T <= B) {            /* if we still have more    */
          for (max = INT_MIN, j = L; j <= R; j++) 
               if (data[mid_row][j] > max) /* get max.    */
                    max = data[mid_row][j], pos = j;
          loc[mid_row] = pos; /* save max. location       */
          get_max(data, T, mid_row-1, L, pos, loc);
          get_max(data, mid_row+1, B, pos, R, loc);
     }
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[SIZE][SIZE] = 
                    {{ 2, 5, 4, 3, 1, 2, 4},
                     { 1, 3, 2, 1, 0, 1, 2},
                     { 2, 4, 7, 3, 1, 3, 4},
                     { 5, 3, 1, 6, 4, 3, 2},
                     { 1, 3, 5, 7, 6, 5, 4},
                     { 2, 4, 6, 8, 6, 7, 9}};
     int  location[SIZE];
     int  m = 6;
     int  n = 7;
     int  i, j;

     printf("\nMonotone Matrix Max. Computation");
     printf("\n================================");
     printf("\n\nInput Matrix :");
     for (i = 0; i < m; i++) {
          printf("\n");
          for (j = 0; j < n; j++)
               printf("%3d", x[i][j]);
     }

     monotone_max(x, m, n, location);
     printf("\n\nRow   Max.Col   Value");
     printf(  "\n---   -------   -----");
     for (i = 0; i < m; i++)
          printf("\n%3d%8d%9d", i, location[i], x[i][location[i]]);
}
