/* ------------------------------------------------------ */
/* PROGRAM  matmul :                                      */
/*    An old trick for FORTRAN programmers.  For those C  */
/* programmers, they have to remember the maximum size of */
/* the second dimension of a two dimension array and pass */
/* this CONSTANT value as part of the array declaration.  */
/* This is a very restrictive feature next to Pascal.  But*/
/* we can recover from this stupid language restriction   */
/* somewaht by old tricks of FORTRAN programmers.         */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/02/1989 */
/* ------------------------------------------------------ */

#define   MAXSIZE   20

void  twoD_to_oneD(int [][MAXSIZE], int, int, int []);
void  oneD_to_twoD(int [], int [][MAXSIZE], int, int);
void  matmul(int [], int [], int [], int, int, int);

/* ------------------------------------------------------ */
/* FUNCTION  twoD_to_oneD :                               */
/*    This function accepts a two dimensional array in C  */
/* form and transforms it to row major linear form.       */
/* ------------------------------------------------------ */

void  twoD_to_oneD(int TwoD[][MAXSIZE], int m, int n, int OneD[])
{
     int  index, i, j;

     index = 0;
     for (i = 0; i < m; i++)
          for (j = 0; j < n; j++)
               OneD[index++] = TwoD[i][j];
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
/* FUNCTION  matmul :                                     */
/*    Row major linear form matrix multiplication routine.*/
/* ------------------------------------------------------ */

void  matmul(int a[], int b[], int c[], int L, int M, int N)
{
     int  index;
     int  i, j, k;
     int  p, pp, qq;
     int  sum;

     index = 0;
     for (i = p = 0; i < L; i++, p += M)
          for (j = 0; j < N; j++) {
               for (sum =k=0, pp=p, qq=j; k < M; pp++, qq+=N, k++)
                    sum += a[pp] * b[qq];
               c[index++] = sum;
          }
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  A[MAXSIZE][MAXSIZE] =
               { { 3, 5, 7, 9},
                 { 2, 5, 1, 7},
                 { 8, 2, 1, 4},
                 { 6, 8, 3, 3}};
     int  B[MAXSIZE][MAXSIZE] =
               { { 1, 3, 5},
                 { 2, 4, 6},
                 { 3, 7, 9},
                 { 4, 5, 8}};
     int  C[MAXSIZE][MAXSIZE];
     int  *AA, *BB, *CC;
     int  L = 4;
     int  M = 4;
     int  N = 3;
     int  i, j;

     printf("\nOne Dimensional Matrix Multiplication Program");
     printf("\n=============================================");
     printf("\n\nMatrix A[][] :");
     for (i = 0; i < L; i++) {
          printf("\n");
          for (j = 0; j < M; j++)
               printf("%4d", A[i][j]);
     }
     AA = (int *) A;
     twoD_to_oneD(A, L, M, AA);
     printf("\n\nTransformed One Dimensional Array A[] :\n");
     for (i = 0; i < L*M; i++)
          printf("%4d", AA[i]);

     printf("\n\nMatrix B[][]:");
     for (i = 0; i < M; i++) {
          printf("\n");
          for (j = 0; j < N; j++)
               printf("%4d", B[i][j]);
     }
     BB = (int *) B;
     twoD_to_oneD(B, M, N, BB);
     printf("\n\nTransformed One Dimensional Array B[] :\n");
     for (i = 0; i < M*N; i++)
          printf("%4d", BB[i]);

     CC = (int *) C;
     matmul(AA, BB, CC, L, M, N);
     printf("\n\nLinear Form of A[][] * B[][] :\n");
     for (i = 0; i < L*N; i++)
          printf("%4d", CC[i]);

     oneD_to_twoD(CC, C, L, N);
     printf("\n\nMatrix C[][]:");
     for (i = 0; i < L; i++) {
          printf("\n");
          for (j = 0; j < N; j++)
               printf("%4d", C[i][j]);
     }
}
