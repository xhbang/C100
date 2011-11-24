/* ------------------------------------------------------ */
/* PROGRAM  classify :                                    */
/*    Given a set of m n-vectors organized into a m*n     */
/* matrix, this program will classify these vector into   */
/* several class by assigning class numbers without       */
/* sorting.  In other words, only comparisons of equal or */
/* unequal are used in this program.                      */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/01/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE     20

/* ------------------------------------------------------ */
/*                  type definitions                      */
/* ------------------------------------------------------ */

typedef   struct node   Node; /* type of node             */

struct node {                 /* a node consists of ...   */
     int   row;               /*    row #                 */
     Node  *next;             /*    and a pointer to next */
};

/* ------------------------------------------------------ */
/*                 external variables                     */
/* ------------------------------------------------------ */

int   class_no;               /* # of classes found       */
Node  **class_list;           /* table for class list     */

/* ------------------------------------------------------ */
/*                 function prototypes                    */
/* ------------------------------------------------------ */

void  classify(int [][MAXSIZE], int, int, int []);
void  group(Node *, int, int, int [][MAXSIZE]);
Node  *dispatch(Node *, int, int [][MAXSIZE]);

/* ------------------------------------------------------ */
/* FUNCTION  classify :                                   */
/*    Given m n-vectors stored in matrix data[][], this   */
/* function returns the class number of each vector with  */
/* array class[].                                         */
/* ------------------------------------------------------ */

void  classify(int data[][MAXSIZE], int m, int n, int class[])
{
     Node *node_list, *tail, *p;
     int  i;

     /* --------------- initial class list -------------- */

     class_list = (Node **) malloc(sizeof(Node *)*m);
     class_no   = 0;
     for (i = 0; i < m; i++)
          class_list[i] = (Node *) NULL;

     /* --------------- build up node list -------------- */

     node_list = tail = (Node *) malloc(sizeof(Node));
     node_list->row   = 0;
     node_list->next  = NULL;
     for (i = 1; i < m; i++) {
          p = (Node *) malloc(sizeof(Node));
          p->row  = i;
          p->next = NULL;
          tail = tail->next = p;
     }

     group(node_list, 0, n, data);  /* classify           */

     for (i = 0; i < class_no; i++) /* retrieve class #   */
          for (p = class_list[i]; p != NULL; p = p->next)
               class[p->row] = i;

     free(class_list);        /* release storage          */
     while (node_list != NULL) {
          p = node_list;
          node_list = node_list->next;
          free(p);
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  group :                                      */
/*    Given a list containing those vector code to be     */
/* classified and their classification column, this       */
/* function classify all nodes in the list recursively.   */
/* ------------------------------------------------------ */

void  group(Node *list, int column, int n, int data[][MAXSIZE])
{
     Node  *other;

     if (column >= n)         /* any column available ?   */
          class_list[class_no++] = list; /* NO, store ans */
     else {                   /* YES, dispatch the list   */
          other = dispatch(list, column, data); 
          group(list, column+1, n, data); /* classify orig*/
          if (other != NULL)  /* if there is 'other' list */
               group(other, column, n, data); /* classify */
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  dispatch :                                   */
/*    Give a list of nodes, this function separates the   */
/* list into to lists, one containing all nodes with same */
/* classification column and the other contains all others*/
/* ------------------------------------------------------ */

Node  *dispatch(Node *head, int column, int data[][MAXSIZE])
{
     int   value;
     Node  *first, *last, *p;

     value = data[head->row][column]; /* class. value     */
     first = last = NULL;
     p     = head->next;      /* the followup pointer     */

     for ( ; p != NULL; p = head->next) /* scan each node */
          if (data[p->row][column] != value) { /* same val*/
               head->next = p->next; /* NO, extract it    */
               p->next    = NULL;    /* link to another   */
               if (first == NULL)
                    first = last = p;
               else
                    last = last->next = p;
          }
          else                /* YES, scan next node      */
               head = head->next;

     return first;
}

/* ------------------------------------------------------ */

void  main(void)
{
     int  data[MAXSIZE][MAXSIZE] 
               = { { 3, 5, 7, 9},  { 4, 3, 7, 5},  { 3, 5, 7, 8},
                   { 2, 1, 4, 6},  { 3, 5, 7, 9},  { 1, 3, 5, 9},
                   { 4, 3, 7, 5},  { 2, 4, 6, 8},  { 2, 1, 4, 6},
                   { 4, 3, 1, 7},  { 3, 5, 7, 9},  { 1, 2, 3, 4},
                   { 1, 2, 3, 4},  { 9, 7, 5, 3},  { 2, 4, 6, 8}};
     int  m = 15;
     int  n =  4;
     int  class[MAXSIZE];
     int  i, j;

     printf("\nClassification of Vectors");
     printf("\n=========================");

     classify(data, m, n, class);
     printf("\n\nClassified Vectors with Code :");
     printf("\n\n Code   Input Vectors");
     printf(  "\n-----   -------------");
     for (i = 0; i < m; i++) {
          printf("\n%5d - ", class[i]);
          for (j = 0; j < n; j++)
               printf("%3d", data[i][j]);
     }
}
