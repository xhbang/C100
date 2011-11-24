/* ------------------------------------------------------ */
/* FUNCTION maxsquare :                                   */
/*    Given a square matrix and a key, this function scans*/
/* the input matrix to find out the maximum size of a     */
/* square sub-block such that all elements of this sub-   */
/* block are all the same.  This is the second solution   */
/* of this same problem.                                  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/03/1989 */
/* ------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE   50                   /* matrix size    */
  
typedef  int MATRIX[MAXSIZE][MAXSIZE];  /* matrix type    */
typedef  struct node *  NODE_POINTER;   /* list node ptr  */

struct node {                           /* list node type */
     int           row;
     int           column;
     NODE_POINTER  next;
};

void maxsquare(MATRIX x, int n, int key, int *row, int *column, int *width)
{
     MATRIX        count;               /* counting matrix*/
     NODE_POINTER  list_head, last_node;/* list ctrl var. */
     NODE_POINTER  p;
     int           i, j;

     list_head = last_node = NULL;   /* initial the list  */
     for (i = 0; i < n; i++)         /* and counting mat. */
          for (j = 0; j < n; j++)
               if (x[i][j] == key) { /* if eq to key than */
                    count[i][j] = 1; /* count it and ...  */
                    p = (struct node *) malloc(sizeof(struct node));
                    p->row    = i;   /* put indices to a  */
                    p->column = j;   /* node and put it to*/
                    p->next   = NULL;/* a linked list     */
                    if (list_head == NULL)
                         list_head = last_node = p;
                    else {
                         last_node->next = p;
                         last_node = p;
                    }
               }
               else
                    count[i][j] = 0; /* !eq, set count=0  */

     while (list_head != NULL) { /* the second part.  the */
          last_node = NULL;      /* list is scanned       */
          p         = list_head;
          while (p != NULL) {    /* look at three neighbrs*/
               if (count[p->row][p->column] == count[p->row+1][p->column] &&
                   count[p->row][p->column] == count[p->row][p->column+1] &&
                   count[p->row][p->column] == count[p->row+1][p->column+1]) {
                    count[p->row][p->column]++; /*count it*/
                    last_node = p;
               }
               else 
                    if (last_node == NULL)
                         list_head = p->next;
                    else
                         last_node->next = p->next;
               p = p->next;
          }
     }

     *width = 0;              /* extract the maximum      */
     for (i = 0; i < n; i++)
          for (j = 0; j < n; j++)
               if (*width < count[i][j]) {
                    *width  = count[i][j];
                    *row    = i;
                    *column = j;
               }
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     MATRIX  x = { { 1, 1, 1, 0, 0, 0, 0, 0},
                   { 0, 1, 1, 1, 1, 0, 0, 0},
                   { 0, 0, 1, 1, 1, 1, 1, 0},
                   { 0, 0, 0, 1, 1, 1, 1, 1},
                   { 0, 1, 1, 1, 1, 1, 1, 1},
                   { 0, 1, 1, 1, 1, 0, 1, 1},
                   { 0, 0, 1, 1, 1, 0, 0, 0},
                   { 0, 0, 1, 1, 1, 1, 0, 0}};
     int  n = 8;
     int  row, column, width, key = 1;

     printf("\nFind Maximum Size Square of Same Data");
     printf("\n=====================================");
     printf("\n\nGiven Matrix : \n");
     for (row = 0; row < n; row++) {
          for (column = 0; column < n; column++)
               printf("%2d", x[row][column]);
          printf("\n");
     }
     printf("\nKey to be searched = %d", key);

     maxsquare(x, n, key, &row, &column, &width);

     printf("\nMaximum Square is located at x[%d][%d] with size %d",
            row, column, width);
}
