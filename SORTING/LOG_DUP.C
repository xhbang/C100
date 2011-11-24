/* ------------------------------------------------------ */
/* FUNCTION  LOG_sort :                                   */
/*    Given an array of n elements with only log(n)       */
/* distinct elements and each element maybe repeated      */
/* n/log(n) times, this function sorts this highly        */
/* duplicated array with merge technique.                 */
/*    This function requires a sorting routine such as    */
/* quick sort, merge sort or heapsort, but not bucket     */
/* sort discussed in this book.                           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/27/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc()             */
#include  <math.h>            /* for log()                */

#define   MIN(x, y)   ((x) <= (y) ? (x) : (y))
#define   SWAP(x, y)  { int *t; t=x; x=y; y=t; }

/* ------------------------------------------------------ */
/*                     external data                      */
/* ------------------------------------------------------ */

int  *in1_data,  *in2_data,  *out_data;  /* for data      */
int  *in1_count, *in2_count, *out_count; /* for counting  */
int  number;                             /* result count  */

/* ------------------------------------------------------ */
/*                  function prototype                    */
/* ------------------------------------------------------ */

void  LOG_sort(int [], int);               /* main funct. */
int   LOG_merge(int [], int, int);         /* for merge   */
int   compress(int [], int, int *, int *); /* compress    */
void  LOG_expand(int []);                  /* expand      */
void  sort(int [], int);                   /* sorting     */

/* ------------------------------------------------------ */
/* FUNCTION  LOG_sort :                                   */
/*    control driver.  It cuts the given array into small */
/* segments with about log(n) elements each and then sorts*/
/* these segments.  Finally by using a modified merging   */
/* technique we can merge these segments in a faster way. */
/* ------------------------------------------------------ */

void  LOG_sort(int x[], int n)
{
     int  log_n  = (int) (log((double)n) + 0.5);
     int  i;

     for (i = 0; i < n; i += log_n)   /* sort segments    */
          sort(x+i, MIN(log_n, n-i));

     /* ------------ allocate working spece ------------- */

     in1_data  = (int *) malloc(sizeof(int)*log_n);
     in2_data  = (int *) malloc(sizeof(int)*log_n);
     out_data  = (int *) malloc(sizeof(int)*log_n);
     in1_count = (int *) malloc(sizeof(int)*log_n);
     in2_count = (int *) malloc(sizeof(int)*log_n);
     out_count = (int *) malloc(sizeof(int)*log_n);

     number = LOG_merge(x, n, log_n);  /* merge segments  */
     LOG_expand(x);                    /* expand the final*/

     free(in1_data);          /* free working space       */
     free(in2_data);
     free(out_data);
     free(in1_count);
     free(in2_count);
     free(out_count);
}

/* ------------------------------------------------------ */
/* FUNCTION  LOG_merge :                                  */
/*    A special merge routine.  It calls compress() to    */
/* compress the segments into a data/counting form so that*/
/* there is no duplications.  Then merges these short     */
/* forms.  Because there are only log(n) distinct items,  */
/* the merged segment of any two segments contains no more*/
/* than log(n) elements.                                  */
/* ------------------------------------------------------ */

int  LOG_merge(int x[], int n, int seg_size)
{
     int  no1, no2;           /* # of elements in two in  */
     int  start, len;         /* start is the cursor      */
     int  i, j, k;

     no1 = compress(x, seg_size, in1_data, in1_count);

     for (start = seg_size; start < n; start += len) {
          len = MIN(seg_size, n-start); /* compute length  */
          no2 = compress(x + start, len, in2_data, in2_count);
          for (i = j = k = 0; i < no1 && j < no2; ) /*merge*/
               if (in1_data[i] < in2_data[j]) {
                    out_data[k]  = in1_data[i];
                    out_count[k] = in1_count[i];
                    i++, k++;
               }
               else if (in1_data[i] > in2_data[j]) {
                    out_data[k]  = in2_data[j];
                    out_count[k] = in2_count[j];
                    j++, k++;
               }
               else {         /* if equal, update count   */
                    out_data[k]  = in1_data[i];
                    out_count[k] = in1_count[i] + in2_count[j];
                    i++, j++, k++;
               }
          for (; i < no1; i++, k++) {  /* the copy part   */
               out_data[k]  = in1_data[i];
               out_count[k] = in1_count[i];
          }
          for (; j < no2; j++, k++) {
               out_data[k]  = in2_data[j];
               out_count[k] = in2_count[j];
          }
          no1 = k;            /* k contains # of output   */
          SWAP(in1_data,  out_data);  /* let out be in1   */
          SWAP(in1_count, out_count); /* for next run     */
     }
     return no1;
}

/* ------------------------------------------------------ */
/* FUNCTION :                                             */
/*    Given a segment of an sorted array, this function   */
/* extracts those distinct elements with its count.       */
/* ------------------------------------------------------ */

int  compress(int x[], int n, int *data, int *count)
{
     int  i;
     int  no = 0;

     if (n == 0)
          return 0;
     else {
          data[0]  = x[0];
          count[0] = 1;
          for (i = 1; i < n; i++)
               if (x[i] == x[i-1])
                    count[no]++;
               else {
                    data[++no] = x[i];
                    count[no]  = 1;
               }
          no++;
          return no;
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  LOG_expand :                                 */
/*    Given the data/count form (pointed by in1_data[] &  */
/* in1_count[], this function expands it into the original*/
/* form based on counting value.                          */
/* ------------------------------------------------------ */

void  LOG_expand(int x[])
{
     int  total;
     int  i, j;

     for (total = i = 0; i < number; i++)
          for (j = 0; j < in1_count[i]; j++)
               x[total++] = in1_data[i];
}

/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE     100

void main(void)
{
     int  x[MAXSIZE];
     int  n, log_n;
     int  i, j, temp;
     char line[100];

     printf("\nArray Sorting with Duplicated Distinct Elements");
     printf("\n===============================================");
     printf("\n\nHow many elements do you want ? ");
     gets(line);
     n = atoi(line);
     log_n = log((double) n) + 0.5;

     srand((unsigned) clock()); /* generate random data   */
     for (i = 0; i < n; ) {
          temp = rand();      /* duplicate n/log(n) times */
          for (j = 0; j < n/log_n && i < n; i++, j++)
               x[i] = temp;
     }

     for (i = 0; i < n; i++) {  /* random permutation     */
          j = ((double) rand()/RAND_MAX) * n;
          temp = x[i];
          x[i] = x[j];
          x[j] = temp;
     }

     printf("\nGenerated Array :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%6d", x[i]);
     }

     LOG_sort(x, n);          /* sort them                */
     printf("\n\nSorted Array :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%6d", x[i]);
     }
}
