/* ------------------------------------------------------ */
/* FUNCTION merge sort :                                  */
/*    Given an input int array and number of elements,    */
/* this function sorts the array with merge sort method.  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/21/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc() and free()  */
#include  <string.h>          /* for memmove()            */

#define   SIZE     sizeof(int)/sizeof(char)  /* int size  */

void  sort(int [], int);
void  mergesort(int [], int[], int, int);
void  merge(int [], int [], int, int, int);

/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    Get working space and start merge sort.             */
/* ------------------------------------------------------ */

void  sort(int x[], int n)
{
     int  *work;

     work = (int *) malloc(n*SIZE);  /* get work space    */
     mergesort(x, work, 0, n-1);     /* call merge sort   */
     free(work);                     /* free work space   */
}


/* ------------------------------------------------------ */
/* FUNCTION mergesort :                                   */
/*    The merge sort driver routine.                      */
/* ------------------------------------------------------ */

void  mergesort(int x[], int work[], int first, int last)
{
     int  mid;

     if (first < last) {
          mid = (first + last)/2;  /* cut from the middle */
          mergesort(x, work, first, mid);   /* sort left  */
          mergesort(x, work, mid+1, last);  /* sort right */
          merge(x, work, first, mid, last); /* merge them */
          memmove(&x[first], &work[first], (last-first+1)*SIZE);
     }
}


/* ------------------------------------------------------ */
/* FUNCTION merge :                                       */
/*    Merge routine for merge sort.                       */
/* ------------------------------------------------------ */

void  merge(int x[], int work[], int first, int mid, int last)
{
     int  in1 = first;
     int  in2 = mid+1;
     int  out = first;

     while (in1 <= mid && in2 <= last) /* merge part      */
          work[out++] = (x[in1] <= x[in2]) ? x[in1++] : x[in2++];
     while (in1 <= mid)       /* output remainder in 1st  */
          work[out++] = x[in1++];
     while (in2 <= last)      /* output remainder in 2nd  */
          work[out++] = x[in2++];
}
