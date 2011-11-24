/* ------------------------------------------------------ */
/* FUNCTION  first_second :                               */
/*    This is a little bit faster function for computing  */
/* the first and the second elements at the same time.    */
/* It employs a recursive  method to implement divide-and-*/
/* conquer technique.  Number of comparisons is about     */
/* 1.5n-2, where n is the number of elements.  The fastest*/
/* algorithm use n+log(n) comparisons only, while the     */
/* conventional one requires 2n-3 comparisons.            */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/27/1989 */
/* ------------------------------------------------------ */

#include  <limits.h>

void  f_and_s(int [], int, int, int *, int *);

void  first_second(int x[], int n, int *first, int *second)
{
     f_and_s(x, 0, n-1, first, second);
}

/* ------------------------------------------------------ */
/* FUNCTION  f_and_s :                                    */
/*    This function accepts the input array x[] and the   */
/* left and right bounds, then returns the smallest and   */
/* the second smallest elements in this range by using    */
/* divide-and-conquer method.                             */
/* ------------------------------------------------------ */

void  f_and_s(int x[], int left, int right, int *f, int *s)
{
     int  mid;
     int  F1, F2;             /* returned smallest items  */
     int  S1, S2;             /* returned second smallest */

     if (left > right)        /* range empty ?            */
          *f = *s = INT_MAX;  /* YES, return INT_MAX      */
     else if (left == right)  /* exactly one item ?       */
          *f = x[left], *s = INT_MAX; /* return it and inf*/
     else {
          mid = (left + right)/2; /* now cut from middle  */
          f_and_s(x, left, mid, &F1, &S1);    /* left     */
          f_and_s(x, mid+1, right, &F2, &S2); /* right    */
          if (F1 < F2)        /* pick 1st and 2nd items.  */
               *f = F1, *s = (S1 < F2) ? S1 : F2;
          else
               *f = F2, *s = (S2 < F1) ? S2 : F1;
     }
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

#define   MAXSIZE     100

void  main(void)
{
     int  x[MAXSIZE];
     int  n, first, second;
     int  i;
     char line[100];

     printf("\nRecursive First-Second Elements");
     printf("\n===============================");
     printf("\n\nHow many elements (at least 2) --> ");
     gets(line);
     n = atoi(line);

     srand((unsigned) clock());
     printf("\nRandomly Generated Data :\n");
     for (i = 0; i < n; i++) {
          x[i] = rand();
          if (i % 10 == 0)  printf("\n");
          printf("%6d", x[i]);
     }

     first_second(x, n, &first, &second);
     printf("\n\nThe Smallest Element --------->%6d", first);
     printf(  "\nThe Second Smallest Element -->%6d", second);
}
