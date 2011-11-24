/* ------------------------------------------------------ */
/* FUNCTION dup_sort :                                    */
/*    Given an array of n elements with about log(n)      */
/* duplicated items, this function sorts the array with   */
/* some tricks.                                           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/16/1989 */
/* ------------------------------------------------------ */

void  sort(int [], int);      /* use any sort function    */

void  dup_sort(int  x[], int n)
{
     int  dup;
     int  count, index, i, j;

     for (i = 1; i < n; i++)  /* detect the dup. item     */
          if (x[i] == x[i-1]) {
               dup = x[i];    /* store it in variable dup */
               break;
          }

     for (count = i = 0; i < n; i++) /* move other items  */
          if (x[i] != dup)    /* to the beginning of the  */
               x[count++] = x[i]; /* array and add one dup*/
     x[count++] = dup;        /* at the end               */

     sort(x, count);          /* then sort these log(n)   */

     for (index=n-1, i=count-1; i >= 0 && x[i] != dup; i--)
          x[index--] = x[i];  /* put the dup. items back  */
     if (i >= 0 && x[i] == dup)
          for (j = i + 1; j <= index; j++)
               x[j] = dup;
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

void  main(void)
{
     int  x[100];
     int  dup;
     int  i, j, k;

     srand((unsigned) clock());
     dup = rand();
     for (i = 0; i < 100; i++) /* gen. 100 dup items      */
          x[i] = dup;

     for (i = 1; i <= 10; i++) { /* add 10 distinct ones  */
          j = (int) ((double) rand() / RAND_MAX * 100);
          k = rand();
          x[j] = k;
     }

     printf("\nSoring with a lot of Duplicated Data");
     printf("\n====================================");
     printf("\nGenerated Data :");
     for (i = 0; i < 100; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%6d", x[i]);
     }

     dup_sort(x, 100);
     printf("\n\nSorted Data :");
     for (i = 0; i < 100; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%6d", x[i]);
     }
}
