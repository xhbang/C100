/* ------------------------------------------------------ */
/* PROGRAM  matmul :                                      */
/*    Another trick of old FORTRAN programmer to overcome */
/* the storage, efficiency and syntax program for         */
/* symmetric matrices.  A symmetric matrix can be         */
/* transformed to an one dimensional linear array and     */
/* manipulated by ONE index only.                         */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/03/1989 */
/* ------------------------------------------------------ */

#define   MAXSIZE   20

void  StwoD_to_oneD(int [][MAXSIZE], int, int []);
void  oneD_to_StwoD(int [], int [][MAXSIZE], int);
void  oneD_to_twoD(int [], int [][MAXSIZE], int, int);
void  Smatmul(int [], int [], int [], int);

/* ------------------------------------------------------ */
/* FUNCTION  twoD_to_oneD :                               */
/*    This function accepts a two dimensional symmetric   */
/* array in C form and transforms it to row major linear  */
/* form.                                                  */
/* ------------------------------------------------------ */

void  StwoD_to_oneD(int TwoD[][MAXSIZE], int n, int OneD[])
{
     int  index, i, j;

     index = 0;
     for (i = 0; i < n; i++)
          for (j = i; j < n; j++)
               OneD[index++] = TwoD[i][j];
}

/* ------------------------------------------------------ */
/* FUNCTION  oneD_to_StwoD :                              */
/*    This function tranforms the row major linear form   */
/* back to C's two dimension symmetric array.             */
/* ------------------------------------------------------ */

void  oneD_to_StwoD(int OneD[], int TwoD[][MAXSIZE], int n)
{
     int  index, i, j;

     index = n*(n+1)/2 - 1;
     for (i = n - 1; i >= 0; i--)
          for (j = n - 1; j >= i; j--)
               TwoD[i][j] = TwoD[j][i] = OneD[index--];
}

/* ------------------------------------------------------ */
/* FUNCTION  Smatmul :                                    */
/*    Row major linear form symmetric matrices            */
/* multiplication routine.                                */
/* ------------------------------------------------------ */

#define   GAP(k, i)    ((k <= i) ? gap : 1)

void  Smatmul(int a[], int b[], int c[], int n)
{
     int  index;
     int  i, j, k;
     int  p, q, gap;
     int  sum;

     index = 0;
     for (i = 0; i < n; i++)
          for (j = 0; j < n; j++) {
               sum = 0;  gap = n - 1;
               p   = i;  q   = j;
               for(k = 0; k < n; k++, p+=GAP(k,i), q+=GAP(k,j), gap--)
                    sum += a[p]*b[q];
               c[index++] = sum;
          }
}

/* ------------------------------------------------------ */
/* FUNCTION  oneD_to_twoD :                               */
/*    This function tranforms the row major linear form   */
/* back to C's two dimension array.                       */
/* ------------------------------------------------------ */

void  oneD_to_twoD(int OneD[], int TwoD[][MAXSIZE], int m, int n)
{
     int  index, i, j;

     index = m*n - 1;
     for (i = m - 1; i >= 0; i--)
          for (j = n - 1; j >= 0; j--)
               TwoD[i][j] = OneD[index--];
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  A[MAXSIZE][MAXSIZE] =
               { { 3, 5, 7, 9, 2},
                 { 5, 5, 1, 7, 3},
                 { 7, 1, 1, 4, 5},
                 { 9, 7, 4, 3, 1},
                 { 2, 3, 5, 1, 4}};
     int  B[MAXSIZE][MAXSIZE] =
               { { 1, 3, 5, 7, 9},
                 { 3, 4, 6, 8, 1},
                 { 5, 6, 9, 2, 4},
                 { 7, 8, 2, 1, 2},
                 { 9, 1, 4, 2, 5}};
     int  C[MAXSIZE][MAXSIZE];
     int  *AA, *BB, *CC;
     int  N = 5;
     int  NN = (N+1)*N/2;
     int  i, j;

     printf("\nOne Dimensional Symmetric Matrix Multiplication");
     printf("\n===============================================");
     printf("\n\nMatrix A[][] :");
     for (i = 0; i < N; i++) {
          printf("\n");
          for (j = 0; j < i; j++)
               printf("    ");
          for ( ; j < N; j++)
               printf("%4d", A[i][j]);
     }
     AA = (int *) A;
     StwoD_to_oneD(A, N, AA);
     printf("\n\nTransformed One Dimensional Array A[] :\n");
     for (i = 0; i < NN; i++)
          printf("%4d", AA[i]);

     printf("\n\nMatrix B[][]:");
     for (i = 0; i < N; i++) {
          printf("\n");
          for (j = 0; j < i; j++)
               printf("    ");
          for ( ; j < N; j++)
               printf("%4d", B[i][j]);
     }
     BB = (int *) B;
     StwoD_to_oneD(B, N, BB);
     printf("\n\nTransformed One Dimensional Array B[] :\n");
     for (i = 0; i < NN; i++)
          printf("%4d", BB[i]);

     CC = (int *) C;
     Smatmul(AA, BB, CC, N);
     printf("\n\nLinear Form of A[][] * B[][] :\n");
     for (i = 0; i < N*N; i++)
          printf("%4d", CC[i]);

     oneD_to_twoD(CC, C, N, N);
     printf("\n\nMatrix C[][]:");
     for (i = 0; i < N; i++) {
          printf("\n");
          for (j = 0; j < N; j++)
               printf("%4d", C[i][j]);
     }
}
