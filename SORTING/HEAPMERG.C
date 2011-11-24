/* ------------------------------------------------------ */
/* FUNCTION  heap_merge :                                 */
/*    Given file_no sorted sequences each with file_len   */
/* elements, this function merges these sequence into a   */
/* sorted sequence with a heap.                           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/29/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc()             */
#include  <limits.h>          /* for INT_MAX              */

#define   MAXSIZE    20       /* max of file_len, file_no */
#define   YES   1
#define   NO    0

/* ------------------------------------------------------ */
/*                 function prototypes                    */
/* ------------------------------------------------------ */

void  prepare(int [][MAXSIZE], int, int);  /* build heap  */
int   ask_data(int [][MAXSIZE], int);      /* ask for next*/
int   delete_top(int *);      /* delete the top-most item */
void  insert(int, int);       /* insert new item to top   */
void  release(void);          /* release allocated memory */
void  makeheap(void);         /* build the heap           */
void  siftdown(void);         /* sift the top-most item   */
void  fix_heap(int);          /* actual working heap RTN  */

/* ------------------------------------------------------ */
/*                 heap data structure                    */
/* ------------------------------------------------------ */

int  *heap;                   /* pointer to heap          */
int  *location;               /* pointer to correspond loc*/
int  *index;                  /* next item in sequence    */
int  file_no;                 /* no of sequences          */
int  file_len;                /* no of elements in seq.   */

/* ------------------------------------------------------ */
/* FUNCTION heap_merge :                                  */
/*    The control routine.  It accepts matrix[] and its   */
/* actual row and column numbers, merges them and then    */
/* send the merged sequence to out[] array.               */
/* ------------------------------------------------------ */

void  heap_merge(int matrix[][MAXSIZE], int m, int n, int out[])
{
     int  out_no;
     int  row;
     int  temp;

     prepare(matrix, m, n);   /* prepare the initial heap */
     out_no = 0;              /* # of output = 0          */
     while ((temp = delete_top(&row)) != INT_MAX) {
          out[out_no++] = temp; /* always output the top  */
          insert(ask_data(matrix, row), row); /* ins. new */
     }
     release();               /* release all memeory      */
}

/* ------------------------------------------------------ */
/* FUNCTION  prepare :                                    */
/*    This function allocates memory for the heap[],      */
/* location[] and index[] arrays and then build up the    */
/* initial heap with the first elements from each seq.    */
/* ------------------------------------------------------ */

void  prepare(int matrix[][MAXSIZE], int m, int n)
{
     int  i;

     heap     = (int *) malloc(sizeof(int)*(m+1));
     location = (int *) malloc(sizeof(int)*(m+1));
     index    = (int *) malloc(sizeof(int)*m);
     file_no  = m;
     file_len = n;
     for (i = 1; i <= file_no; i++) {   /* use 1st item   */
          heap[i]     = matrix[i-1][0]; /* to build up the*/
          location[i] = i - 1;          /* working heap.  */
          index[i-1]  = 1;    /* next item pointer to seq.*/
     }
     makeheap();              /* build up the heap.       */
}

/* ------------------------------------------------------ */
/* FUNCTION  ask_data :                                   */
/*    This routine returns the next element in the seq.   */
/* indicated by parameter 'row'.  In case of the seq being*/
/* empty, a maximum value is returned.                    */
/* ------------------------------------------------------ */

int  ask_data(int matrix[][MAXSIZE], int row)
{
     if (index[row] >= file_len)
          return  INT_MAX;
     else
          return  matrix[row][index[row]++];
}

/* ------------------------------------------------------ */
/* FUNCTION  delete_top :                                 */
/*    This routine deletes the top-most element of the    */
/* heap, but does not make any re-heap operation because  */
/* the next operation must be an insert.                  */
/* ------------------------------------------------------ */

int  delete_top(int *row)
{
     *row = location[1];
     return heap[1];
}

/* ------------------------------------------------------ */
/* FUNCTION  insert :                                     */
/*    This routine inserts a data 'data' located in the   */
/* 'row'-th sequence into the top-most element of the heap*/
/* ------------------------------------------------------ */

void  insert(int data, int row)
{
     location[1] = row;
     heap[1]     = data;
     siftdown();
}

/* ------------------------------------------------------ */
/* FUNCTION  release :                                    */
/*    This routine release all allocated memeory.         */
/* ------------------------------------------------------ */

void  release(void)
{
     free(heap);
     free(location);
     free(index);
}

/* ------------------------------------------------------ */
/* FUNCTION  makeheap :                                   */
/*    This routine builds up a heap with the smallest item*/
/* being on the top-most position.                        */
/* ------------------------------------------------------ */

void  makeheap(void)  
{
     int  temp;
     int  size, i;

     for (i = file_no/2; i >= 1; i--)  /* starts from mid */
          fix_heap(i);             /* fix the heap at this*/
}

/* ------------------------------------------------------ */
/* FUNCTION  siftdown :                                   */
/*    This routine sift the top-most item, which is put   */
/* there by insert(), down to an appropriate position.    */
/* ------------------------------------------------------ */

void  siftdown(void)
{
     fix_heap(1);
}

/* ------------------------------------------------------ */
/* FUNCTION fix_heap :                                    */
/*    Given a heap rooted at 'root', this routine sifts   */
/* that element down to an appropriate position so that   */
/* the result is still a heap.  NOTE that the smallest    */
/* element is on the top of each sub-heap.                */
/* ------------------------------------------------------ */

void  fix_heap(int root)
{
     int  father, son;
     int  key_heap = heap[root];
     int  key_loc  = location[root];
     int  done;

     father = root;           /* start off from the root  */
     son    = father + father;/* get the subscript of son */
     done   = NO;
     while (son <= file_no && !done) { /* son available?  */
          if (son < file_no && heap[son+1] < heap[son])
               son++;         /* now son is the larger one*/
          if (key_heap > heap[son]) { /* if the son > key */
               heap[father] = heap[son]; /* step down     */
               location[father] = location[son];
               father    = son;
          }
          else                /* son < key, thus the key  */
               done      = YES; /* get its position.      */
          son = father + father;
     }
     heap[father] = key_heap; /* insert the key           */
     location[father] = key_loc;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  matrix[MAXSIZE][MAXSIZE] 
            = { {  1,  3,  5,  7,  9, 10, 15, 20, 50, 80},
                {  5,  6,  9, 11, 14, 19, 23, 45, 67, 78},
                {  2, 10, 20, 23, 39, 47, 60, 75, 82, 90},
                {  9, 18, 27, 42, 55, 76, 83, 87, 88, 91},
                {  4,  9, 19, 29, 39, 49, 59, 69, 79, 99}};
     int  m = 5;
     int  n = 10;
     int  out[MAXSIZE*MAXSIZE];
     int  i, j;

     printf("\nHeap Merge Program");
     printf("\n==================");

     for (i = 0; i < m; i++) {
          printf("\n\nFile #%d :", i);
          for (j = 0; j < n; j++) {
               if (j % 10 == 0) printf("\n");
               printf("%4d", matrix[i][j]);
          }
     }

     heap_merge(matrix, m, n, out);
     printf("\n\nThe Merged Result :");
     for (i = 0; i < m*n; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%4d", out[i]);
     }
}
