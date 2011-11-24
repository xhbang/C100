/* ------------------------------------------------------ */
/* FUNCTION  unique :                                     */
/*    Given an array of integers, this functions packs    */
/* this array with all distinct elements.  NOTE that it   */
/* uses sorting functions and thus you can use any one    */
/* sort program in my book.  Don't misunderstand with the */
/* conventional technique that this program can be done   */
/* efficiently with simple-minded method.  Actually, the  */
/* most efficient technique (of course, it can be proven  */
/* formally) is by using sorting.                         */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/22/1989 */
/* ------------------------------------------------------ */

void  sort(int [], int);      /* for sort()               */

void  unique(int x[], int n, int *number)
{
     int  i;

     sort(x, n);              /* sort the data first      */
     *number = 1;             /* the 1st must be presented*/
     for (i = 1; i < n; i++)  /* process the 2nd to last  */
          if (x[i] != x[i-1]) /* if it is NOT a duplicate:*/
               x[(*number)++] = x[i]; /* save it.         */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 100,  37, 100,  37,  15, 111,
                   37,  15, 111,  98, 100,  98};
     int  n   = sizeof(x)/sizeof(int);
     int  number;
     int  i;

     printf("\nElement Uniquness Program");
     printf("\n=========================");
     printf("\n\nOriginal Array  :");
     for (i = 0; i < n; i++)
          printf("%4d", x[i]);

     unique(x, n, &number);
     printf("\n\nProcessed Array :");
     for (i = 0; i < number; i++)
          printf("%4d", x[i]);
}
