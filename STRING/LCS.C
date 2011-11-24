/* ------------------------------------------------------ */
/* FUNCTION  longest_common_subsequence :                 */
/*    Given two strings, this function computes one of    */
/* the longest common subsequence of the given strings.   */
/* Here we use a standard dynamic programming technique,  */
/* but there exist faster methods.                        */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/01/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>
#include  <string.h>

void longest_common_subsequence(char *a, char *b, char *result)
{
     int  **d;                           /* working matrix*/
     int  m = strlen(a), n = strlen(b);  /* string length */
     int  count, i, j;

     /* ----- get memory and initialize dope vector ----- */

     d    = (int **) malloc(sizeof(int)*(m+1));
     d[0] = (int *) malloc(sizeof(int)*(m+1)*(n+1));
     for (i = 1; i <= m; i++)
          d[i] = d[i-1] + n + 1;

     /* ------ Clear the dynamic programming table ------ */

     d[0][0] = 0;        
     for (i = 1; i <= m; d[i][0] = 0, i++)
          ;
     for (j = 1; j <= n; d[0][j] = 0, j++)
          ;

     /* --------- dynamic programming technique --------- */

     for (i = 1; i <= m; i++)        /* for each pair of  */
          for (j = 1; j <= n; j++)   /* chars in strings: */
               if (a[i-1] == b[j-1]) /* are they equal ?  */
                    d[i][j] = d[i-1][j-1] + 1; /* one more*/
               else if (d[i][j-1] > d[i-1][j]) /* or pick */
                    d[i][j] = d[i][j-1]; /* a smaller     */
               else                      /* neighbor      */
                    d[i][j] = d[i-1][j];
     
     /* -------- finally display the subsequence -------- */

     count         = d[m][n]; /* d[m][n] is the length    */
     result[count] = '\0';    /* put a EOS there          */
     for (i = m,j = n; (i != 0) && (j != 0);) /* R->L odr */
          if (d[i][j] == d[i-1][j]) /* are they contribute*/
               i--;           /* equal counting ? NO,     */
          else if (d[i][j] == d[i][j-1])
               j--;           /* NO, backup               */
          else {              /* YES, save this character */
               result[--count] = a[i-1];
               i--, j--;      /* backup both string       */
          }
     free(d[0]);
     free(d);
}

/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE    50

void main(void)
{
     char  a[] = "ABXZWTP01=+C*US";
     char  b[] = "TX013W+-P12=+CCTXU";
     char  c[MAXSIZE];

     printf("\nLongest Common Subsequence Program");
     printf("\n==================================\n");
     printf("\nFirst  String : %s", a);
     printf("\nSecond String : %s", b);
     longest_common_subsequence(a, b, c);
     printf("\nL.C.S. String : %s", c);
}
