/* ------------------------------------------------------ */
/* FUNCTION  sort :                                       */
/*    Here is a beautiful little program from Huang       */
/* Bing-Chao and Donald E. Knuth.  Actually this is an    */
/* iterative implementation of Hoare's Quicksort in a     */
/* one-way, stackless fashion.  A restriction is that it  */
/* sorts positive integers only.  Can you find any        */
/* meaningful way to extend this method ?  One more thing,*/
/* this program requires one more element in your array.  */
/* This means that if you are going to sort n integers,   */
/* you have to provide n+1 locations.                     */
/*                                                        */
/* Copyright Ching-Kuang Shene                Jan/11/1990 */
/* ------------------------------------------------------ */

#define   YES      1
#define   NO       0
#define   ALWAYS   1

#define   SWAP(x, y)    { int t;  t=x; x=y; y=t; }

void  sort(int x[], int n)
{
     int  sorted;             /* next will be sorted      */
     int  split;              /* split element as usual   */
     int  next;               /* next element pointer     */
     int  key;

     x[n] = -1;               /* a sentinel at the end    */
     for (sorted = 0; sorted < n; sorted++) { /* sort all */
          while (x[sorted] > 0) {     /* if it is !sorted:*/
               key   = x[sorted];     /* start Lomuto's   */
               split = sorted;        /* split procedure  */
               for (next = sorted+1; x[next] > 0; next++)
                    if (x[next] < key) {
                         split++;
                         SWAP(x[split], x[next]);
                    }
               SWAP(x[sorted], x[split]);
               x[split] = -x[split];
          }                   /* set the split sorted     */
          x[sorted] = -x[sorted];     /* switch back      */
     }
}
