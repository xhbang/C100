/* ------------------------------------------------------ */
/* FUNCTION  containment :                                */
/*    Given a set of intervals, this function determines  */
/* any one interval is contained in some other intervals. */
/* It returns an array mark[] in which YES means the      */
/* corresponding interval is contained in some other      */
/* intervals.  NOTE that on return the end points array   */
/* of the intervals, namely left[] and right[] are in     */
/* sorted order.                                          */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/01/1989 */
/* ------------------------------------------------------ */

#define   YES     1
#define   NO      0

/* ------------------------------------------------------ */
/*             function prototypes of sorting             */
/* ------------------------------------------------------ */

void  sort(int [], int [], int);
void  qsort(int [], int [], int, int);
void  split(int [], int [], int, int, int *);
void  swap(int *, int *);

void  containment(int left[], int right[], int mark[], int n)
{
     int  current_right_end;  /* indicate current right   */
     int  i;

     sort(left, right, n);    /* sort end points          */
     
     current_right_end = right[0];
     mark[0] = NO;
     for (i = 1; i < n; i++)  /* scan all other right ends*/
          if (right[i] <= current_right_end)
               mark[i] = YES; /* if <= current --> YES    */
          else {
               mark[i] = NO;  /* if > current, update it  */
               current_right_end = right[i];
          }
}


/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    This routine converts two arguments to three        */
/* arguments and calls the REAL control routine.          */
/* ------------------------------------------------------ */

void sort(int left[], int right[], int n)
{
     int  first = 0;               /* the fisrt element.  */
     int  last  = n-1;             /* the last element.   */

     qsort(left, right, first, last);
}


/* ------------------------------------------------------ */
/* FUNCTION  qsort :                                      */
/*    This routine accepts an array and two indices       */
/* indicating the first and the last element to be sorted.*/
/* Then calls split() to split the array into two parts   */
/* and sorts them recursively.                            */
/* ------------------------------------------------------ */

void  qsort(int left[], int right[], int first, int last)
{
     int  split_point;

     if (first < last) {
          split(left, right, first, last, &split_point);
          if (split_point - first < last - split_point) {
               qsort(left, right, first, split_point-1);
               qsort(left, right, split_point+1, last);
          }
          else {
               qsort(left, right, split_point+1, last);
               qsort(left, right, first, split_point-1);
          }
     }
}


/* ------------------------------------------------------ */
/* FUNCTION  split :                                      */
/*    This routine splits the given array into two parts  */
/* according to Nico Lomuto's aplitting technique and     */
/* returns the splitting index with 'split_point'.  Note  */
/* that the sorting order is defined as follows: <left[i],*/
/* right[i]> is placed before <left[j],right[j]> if and   */
/* only if left[i]<left[j] or (left[i]=left[j] & right[i] */
/* > right[j]).                                           */
/* ------------------------------------------------------ */

void  split(int left[], int right[], int first, int last, int *sp)
{
     int  current_split,  i;
     int  x, y;

     x = left[first];
     y = right[first];
     current_split = first;
     for (i = first+1; i <= last; i++)
          if (left[i] < x || (left[i] == x && right[i] > y)) {
               (current_split)++;
               swap(&left[current_split], &left[i]);
               swap(&right[current_split], &right[i]);
          }
     swap(&left[first], &left[current_split]);
     swap(&right[first], &right[current_split]);
     *sp = current_split;
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

void  main(void)
{
     int  left[]  = { 0, 4,  7,  6, 4, 1, 3, 5, 0, 4};
     int  right[] = { 3, 5, 10, 10, 7, 2, 5, 9, 4, 6};
     int  n       = sizeof(left)/sizeof(int);
     int  mark[10];
     int  i;
     char marker[] = { ' ', '*'};

     printf("\nInterval Containment Checking Program");
     printf("\n=====================================");
     
     containment(left, right, mark, n);

     printf("\n\nInterval #   [left,right]");
     printf(  "\n----------   ------------");
     for (i = 0; i < n; i++)
          printf("\n%7d      [%d,%d]%c", i+1, 
                 left[i], right[i], marker[mark[i]]);
          
     printf("\n\n\'%c\' means the interval is contained in "
            "some other intervals", marker[1]);
}
