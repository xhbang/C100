/* ------------------------------------------------------ */
/* FUNCTION  max_visitors :                               */
/*    Given a time table of arrival/departure data, this  */
/* function computes the maximum number of visitors in a  */
/* party at the same time.                                */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/11/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc()             */

#define   IN     1            /* this is an ARRIVAL time  */
#define   OUT    0            /* this is an DEPART. time  */

struct table {                /* a table contains mixed   */
     int  clock;              /* timing data with IN/OUT  */
     int  status;             /* marking by 'status' field*/
};

typedef   struct table  TABLE;/* table type               */

/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  sort(TABLE [], int);
void  qsort(TABLE [], int, int);
void  split(TABLE [], int, int, int *);
void  swap(TABLE *, TABLE *);


int  max_visitors(int x[], int y[], int n)
{
     TABLE *time_table;        /* working time table addr */
     int  max_count;           /* max. count              */
     int  count;
     int  i;

     time_table = (TABLE *) malloc(sizeof(TABLE)*(2*n));

     for (i = 0; i < n; i++) { /* move time to work table */
          (time_table+i)->clock  = x[i];
          (time_table+i)->status = IN; /* ARRAIVAL time   */
     }
     for (i = 0; i < n; i++) { /* move departure time     */
          (time_table+i+n)->clock  = y[i];
          (time_table+i+n)->status = OUT;
     }

     sort(time_table, 2*n);    /* sort this time table    */

     for (max_count = count = i = 0; i < 2*n; i++) 
          if ((time_table + i)->status == OUT) /* OUT?    */
               count--;        /* visitors decrease by 1  */
          else {               /* IN !                    */
               count++;        /* visitors increase by 1  */
               max_count = (max_count < count) ? count : max_count;
          }
     free(time_table);
     return max_count;
}

/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    This routine converts two arguments to three        */
/* arguments and calls the REAL control routine.          */
/* ------------------------------------------------------ */

void sort(TABLE x[], int n)
{
     int  first = 0;               /* the fisrt element.  */
     int  last  = n-1;             /* the last element.   */

     qsort(x, first, last);
}


/* ------------------------------------------------------ */
/* FUNCTION  qsort :                                      */
/*    This routine accepts an array and two indices       */
/* indicating the first and the last element to be sorted.*/
/* Then calls split() to split the array into two parts   */
/* and sorts them recursively.                            */
/* ------------------------------------------------------ */

void  qsort(TABLE x[], int first, int last)
{
     int  split_point;

     if (first < last) {
          split(x, first, last, &split_point);
          if (split_point - first < last - split_point) {
               qsort(x, first, split_point-1);
               qsort(x, split_point+1, last);
          }
          else {
               qsort(x, split_point+1, last);
               qsort(x, first, split_point-1);
          }
     }
}


/* ------------------------------------------------------ */
/* FUNCTION  split :                                      */
/*    This routine splits the given array into two parts  */
/* according to Nico Lomuto's aplitting technique and     */
/* returns the splitting index with 'split_point'.        */
/* ------------------------------------------------------ */

void  split(TABLE x[], int first, int last, int *split_point)
{
     int  current_split,  next;
     int  temp;

     temp = x[first].clock;
     current_split = first;
     for (next = first+1; next <= last; next++)
          if (x[next].clock < temp || 
             (x[next].clock == temp && x[next].status == OUT)) {
               (current_split)++;
               swap(&x[current_split], &x[next]);
          }
     swap(&x[first], &x[current_split]);
     *split_point = current_split;
}


/* ------------------------------------------------------ */
/* FUNCTION  swap :                                       */
/*    This is the simplest routine which swaps two data.  */
/* ------------------------------------------------------ */

void  swap(TABLE *p, TABLE *q)
{
     int  temp;

     temp      = p->clock;
     p->clock  = q->clock;
     q->clock  = temp;

     temp      = p->status;
     p->status = q->status;
     q->status = temp;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 3, 2, 6, 2,  7, 1, 4,  6};
     int  y[] = { 9, 5, 8, 6, 11, 3, 8, 11};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMaximum Number of Visitors");
     printf("\n==========================");
     printf("\n\nGiven Time Table :");
     printf("\n\n  #  Arrival  Departure");
     printf(  "\n-----------------------");
     for (i = 0; i < n; i++)
          printf("\n%3d%7d%10d", i+1, x[i], y[i]);
     printf("\n\nMaximum Number of Visitors = %d", max_visitors(x,y,n));
}
