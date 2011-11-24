/* ------------------------------------------------------ */
/* FUNCTION  product_sequence :                           */
/*    Given a sequence of dimensions of matrices, this    */
/* function finds out the optimum product sequence such   */
/* that the number of multiplications is minimum.         */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/17/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc() and free()  */
#include  <limits.h>          /* for INT_MAX              */

void  display(int *[], int, int);
void  show_order(int *[], int, int);

void  product_sequence(int dim[], int n)
{
     long  **cost;            /* cost matrix              */
     int   **factor;          /* factorization record     */
     long  min_cost;          /* running minimum cost     */
     long  previous, this_one;/* other two cost value     */
     int   pos, i, j, k;

     /* ----- get memory for dope vector and matrix ----- */

     cost      = (long **) malloc(sizeof(long)*n);
     factor    = (int  **) malloc(sizeof(int)*n);
     cost[0]   = (long *) malloc(sizeof(long)*n*n);
     factor[0] = (int  *) malloc(sizeof(int)*n*n);
     for (i = 1; i < n; i++) {
          cost[i]   = cost[i-1] + n;
          factor[i] = factor[i-1] + n;
     }
  
     for (i = 0; i < n; i++)  /* clear the diagonal       */
          cost[i][i] = 0;

     for (j = 1; j < n; j++)  /* compute each item left to*/
          for (i = j-1; i >= 0; i--) { /* right & bot->up */
               min_cost = INT_MAX; 
               pos      = -1;
               for (k = i; k < j; k++) { /* compute min.  */
                    previous = cost[i][k] + cost[k+1][j];
                    this_one = ((long) dim[i])*dim[k+1]*dim[j+1];
                    if (min_cost > previous + this_one)
                         min_cost = previous + this_one, pos = k;
               }
               cost[i][j]   = min_cost;  /* save min cost */
               factor[i][j] = pos;       /* and position  */
          }
     display(factor, n, cost[0][n-1]);   /* display result*/

     free(cost[0]);           /* free all memory          */
     free(cost);
     free(factor[0]);
     free(factor);
}

/* ------------------------------------------------------ */
/* FUNCTION  display :                                    */
/*    Given the factorization matrix, this function prints*/
/* the optimum product sequence by calling show_order().  */
/* ------------------------------------------------------ */

void  display(int *factor[], int n, int total)
{
     printf("\n\nThe Factorization is ");
     show_order(factor, 0, n-1);
     printf("\n\nNumber of Multiplications to be Perfomed = %d", total);
}

/* ------------------------------------------------------ */
/* FUNCTION  show_order :                                 */
/*    The working function to show the optimum product    */
/* order.                                                 */
/* ------------------------------------------------------ */

void  show_order(int *factor[], int start, int end)
{
     int  mid;

     if (start == end)          /* if there is onlu 1...  */
          printf("M%d", start); /* show it!               */
     else {
          printf("(");          /* OR initiate a new seq. */
          mid = factor[start][end]; /* get the divide pt  */
          show_order(factor, start, mid); /* show 1st half*/
          printf("*");          /* then a multiplication  */
          show_order(factor, mid + 1, end); /* 2nd half   */
          printf(")");          /* close this sequence.   */
     }
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  dim[] = { 30, 1, 40, 10, 25, 1, 10, 30};
     int  n     = sizeof(dim)/sizeof(int);
     int  i;
    
     printf("\nOptimum Matrix Product Sequence");
     printf("\n===============================");
     printf("\n\nGiven Dimension List :\n");

     for (i = 0; i < n - 1; i++)
          printf("\nMatrix %2d has dimension %dx%d ", i, dim[i], dim[i+1]);

     product_sequence(dim, n - 1);
}
