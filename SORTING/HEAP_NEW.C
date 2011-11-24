/* ------------------------------------------------------ */
/* FUNCTION  sort :                                       */
/*    This is a modified Heapsort program in which a way  */
/* to minimize number of comparisons has been implemented.*/
/* NOTE that the given array old_x[] is shifted back one  */
/* position and what we are using is the new array x[].   */
/*                                                        */
/* Copyright Ching-KUang Shene                Mar/22/1990 */
/* ------------------------------------------------------ */

#define  YES        1
#define  NO         0

void  fix_heap(int [], int, int, int);


/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    Given an array x[] and its number of elements, this */
/* function uses fix_heap() to build up a heap and then   */
/* sorts the array by swaping the top and the last items. */
/* ------------------------------------------------------ */

void  sort(int old_x[], int n)  
{
     int  *x = old_x - 1;
     int  temp;
     int  size, i;

     for (i = n/2; i >= 1; i--)    /* starts off from mid */
          fix_heap(x, i, x[i], n); /* fix the heap at this*/

     for (size = n-1; size >= 1; size--) { /* sort phase. */
          temp = x[size+1];        /* pick up the last    */
          x[size+1] = x[1];        /* replace with 1st    */
          fix_heap(x, 1, temp, size); /* restore the heap */
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  fix_heap :                                   */
/*    A modified fix_heap routine using Svante Carlson's  */
/* suggestion to minimize number of comparisons.          */
/* ------------------------------------------------------ */

void  fix_heap(int x[], int root, int key, int bound)
{
     int  son, level;
     int  top, bottom, mid;

     son    = root + root;    /* get the subscript of son */
     level  = 1;              /* level counter            */
     for (;son<bound; level++)/* trace the path of max son*/
          son = (x[son] < x[son+1]) ? (son+1) << 1 : son << 1;
     if (son > bound)
          level--, son >>= 1; /* son=the leave along max.s*/

     top    = level;          /* start binary search along*/
     bottom = 0;              /* the path of max. sons    */
     while (top > bottom) {   
          mid = (top + bottom)/2; 
          if (key <= x[son >> mid]) /* the mid item<=key? */
               top = mid;           /* squeeze downward   */
          else
               bottom = mid + 1;    /* squeeze upward     */
     }

     for (mid = level-1; mid >= top; mid--)  /* copy ..   */
          x[son >> (mid+1)] = x[son >> mid];
     x[son >> top] = key;
}
