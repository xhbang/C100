/* ------------------------------------------------------ */
/* FUNCTION  maxset :                                     */
/*    Given a set of points on the plane, this function   */
/* computes all those maximal points.  A point (x,y) is   */
/* said to be maximal, if and only if for all other point */
/* (a,b) we have a<=x, b<=y, or a<=x, b>y, or a>x, b<=y.  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/28/1989 */
/* ------------------------------------------------------ */

#include  <limits.h>

/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  sort(int [], int [], int);
void  qsort(int [], int [], int, int);
void  split(int [], int [], int, int, int *);
void  swap(int *, int *);


void  max_set(int x[], int y[], int n, int xx[], int yy[], int *no)
{
     int  max, i;

     sort(x, y, n);           /* sort the x-coordinate    */
     for (i = n-1, *no = 0, max=INT_MIN; i >= 0; i--)
          if (y[i] > max) {   /* process downward.        */
               xx[*no] = x[i];/* if y[i]>current max, then*/
               yy[*no] = y[i];/* y[i] is a newly found max*/
               (*no)++;       /* point.  Thus save it and */
               max = y[i];    /* update current max.      */
          }
}

/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    This routine converts two arguments to three        */
/* arguments and calls the REAL control routine.          */
/* ------------------------------------------------------ */

void sort(int x[], int y[], int n)
{
     int  first = 0;               /* the fisrt element.  */
     int  last  = n-1;             /* the last element.   */

     qsort(x, y, first, last);
}


/* ------------------------------------------------------ */
/* FUNCTION  qsort :                                      */
/*    This routine accepts two arrays and two indices     */
/* indicating the first and the last element to be sorted.*/
/* Then calls split() to split the first array into two   */
/* parts and sorts them recursively.                      */
/* ------------------------------------------------------ */

void  qsort(int x[], int y[], int first, int last)
{
     int  split_pt;

     if (first < last) {
          split(x, y, first, last, &split_pt);
          if (split_pt - first < last - split_pt) {
               qsort(x, y, first, split_pt-1);
               qsort(x, y, split_pt+1, last);
          }
          else {
               qsort(x, y, split_pt+1, last);
               qsort(x, y, first, split_pt-1);
          }
     }
}


/* ------------------------------------------------------ */
/* FUNCTION  split :                                      */
/*    This routine splits the given array into two parts. */
/* ------------------------------------------------------ */

void  split(int x[], int y[], int first, int last, int *split_pt)
{
     int  current_split,  unknown;
     int  xx;

     xx = x[first];
     current_split = first;
     for (unknown = first+1; unknown <= last; unknown++)
          if (x[unknown] < xx) {
               (current_split)++;
               swap(&x[current_split], &x[unknown]);
               swap(&y[current_split], &y[unknown]);
          }
     swap(&x[first], &x[current_split]);
     swap(&y[first], &y[current_split]);
     *split_pt = current_split;
}


/* ------------------------------------------------------ */
/* FUNCTION  swap :                                       */
/*    This is the simplest routine which swaps two data.  */
/* ------------------------------------------------------ */

void  swap(int *p, int *q)
{
     int  temp;

     temp = *p;
     *p   = *q;
     *q   = temp;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE    100

void  main(void)
{
     int  x[] = { 7, 3,  1, 8, 5, 4, 10, 9, 6, 0 };
     int  y[] = { 5, 6, 10, 7, 8, 9,  6, 8, 9, 8 };
     int  n   = sizeof(x)/sizeof(int);
     int  dom_x[MAXSIZE], dom_y[MAXSIZE];
     int  count;
     int  i;

     printf("\nMaximal Point Set Program");
     printf("\n=========================");
     printf("\n\nGiven Points :\n");
     printf("\nx[] = ");
     for (i = 0; i < n; i++)
          printf("%3d", x[i]);
     printf("\ny[] = ");
     for (i = 0; i < n; i++)
          printf("%3d", y[i]);

     max_set(x, y, n, dom_x, dom_y, &count);
     printf("\n\nThere are %d Maximal Points :\n", count);
     printf("\nx[] = ");
     for (i = 0; i < count; i++)
          printf("%3d", dom_x[i]);
     printf("\ny[] = ");
     for (i = 0; i < count; i++)
          printf("%3d", dom_y[i]);
}
