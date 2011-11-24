/* ------------------------------------------------------ */
/* FUNCTION  quicksort :                                  */
/*    An array of int and the number of elements  are     */
/* handed to quicksort(), the control routine which       */
/* implements the Quick Sort algorithm.  It in turn       */
/* converts two two arguments version to three arguments  */
/* and transfers control to qsort().  Then qsort() sorts  */
/* these data and outputs the sorted array.               */
/*                                                        */
/*    qsort  -- The real control routine of Quick Sort.   */
/*    split  -- This routine splits the input array into  */
/*              two parts and returns the splitting index.*/
/*    swap   -- swaps two given elements.                 */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/22/1989 */
/* ------------------------------------------------------ */


/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  qsort(int [], int, int);
void  split(int [], int, int, int *);
void  swap(int *, int *);


/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    This routine converts two arguments to three        */
/* arguments and calls the REAL control routine.          */
/* ------------------------------------------------------ */

void sort(int input[], int n)
{
     int  first = 0;               /* the fisrt element.  */
     int  last  = n-1;             /* the last element.   */

     qsort(input, first, last);
}


/* ------------------------------------------------------ */
/* FUNCTION  qsort :                                      */
/*    This routine accepts an array and two indices       */
/* indicating the first and the last element to be sorted.*/
/* Then calls split() to split the array into two parts   */
/* and sorts them recursively.                            */
/* ------------------------------------------------------ */

void  qsort(int input[], int first, int last)
{
     int  split_point;

     if (first < last) {
          split(input, first, last, &split_point);
          if (split_point - first < last - split_point) {
               qsort(input, first, split_point-1);
               qsort(input, split_point+1, last);
          }
          else {
               qsort(input, split_point+1, last);
               qsort(input, first, split_point-1);
          }
     }
}


/* ------------------------------------------------------ */
/* FUNCTION  split :                                      */
/*    This routine splits the given array into two parts  */
/* according to Nico Lomuto's aplitting technique and     */
/* returns the splitting index with 'split_point'.  Note  */
/* that all elements in x[first..split_point-1] are less  */
/* than or equal to x[split_point], while all elements in */
/* x[split_point+1..last] are grater than or equal to     */
/* x[split_point].  Therefore after these two segments    */
/* are sorted, the entire array is sorted also.           */
/* ------------------------------------------------------ */

void  split(int input[], int first, int last, int *split_point)
{
     int  current_split,  unknown;
     int x;

     x = input[first];
     current_split = first;
     for (unknown = first+1; unknown <= last; unknown++)
          if (input[unknown] < x) {
               (current_split)++;
               swap(&input[current_split], &input[unknown]);
          }
     swap(&input[first], &input[current_split]);
     *split_point = current_split;
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
