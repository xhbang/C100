/* ------------------------------------------------------ */
/* FUNCTION  quick sort (list version) :                  */
/*    Given an array of integers, this function sorts this*/
/* array with a variation of Quick Sort.  It transfoms    */
/* the array into a linked list, then sorts this linked   */
/* list with Quick Sort idea by partitioning the list     */
/* into three sublists, namely lists containing all       */
/* elements less than, equal to and greater than the      */
/* pivot.                                                 */
/*    This list version has an advantage in that all equal*/
/* keys are in their original order.  In other words, it  */
/* is stable.                                             */
/*                                                        */
/* Copyright Ching-Kuang Shene                Jan/11/1990 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for NULL and malloc()    */

typedef  struct node *  Node; /* pointer to a list node   */

struct node {                 /* list node type           */
     int   data;
     Node  next;
};

/* ------------------------------------------------------ */
/*                 function prototypes                    */
/* ------------------------------------------------------ */

void  list_quicksort(Node *, Node *);
Node  insert(Node *, Node *, Node);
void  join(Node *, Node *, Node, Node);


void  sort(int x[], int n)
{
     Node first = NULL;
     Node last  = NULL;
     Node p, q;
     int  i;

     for (i = 0; i < n; i++) {  /* build up a linked list */
          p = (Node) malloc(sizeof(struct node));
          p->data = x[i];
          (void) insert(&first, &last, p);
     }

     list_quicksort(&first, &last);  /* sort the list     */

     for (p = first, i = 0; i < n; i++) { /* put back     */
          x[i] = p->data;
          q    = p;
          p    = p->next;
          free(q);
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  list_quicksort :                             */
/*    This is the heart of the list version of Quick Sort.*/
/* It accepts two pointers pointing to the head and the   */
/* tail of a linked list.  Then sorts this list & returns */
/* two new pointers pointing to the result list.          */
/* ------------------------------------------------------ */

void  list_quicksort(Node *first, Node *last)
{
     Node less_first    = NULL;
     Node less_last     = NULL;
     Node equal_first   = NULL;
     Node equal_last    = NULL;
     Node greater_first = NULL;
     Node greater_last  = NULL;
     Node p;
     int  pivot;

     pivot = (*first)->data;  /* get the pivot            */
     p = insert(&equal_first, &equal_last, *first);
     while (p != NULL)        /* scan list...             */
          if (p->data < pivot) /* if < pivot, move to less*/
               p = insert(&less_first, &less_last, p);
          else if (p->data > pivot) /* if >, move to great*/
               p = insert(&greater_first, &greater_last, p);
          else                /* if =, move to equal      */
               p = insert(&equal_first, &equal_last, p);

     if (less_first != NULL)  /* sort < and > lists       */
          list_quicksort(&less_first, &less_last);
     if (greater_first != NULL)
          list_quicksort(&greater_first, &greater_last);

     join(&less_first, &less_last, equal_first, equal_last);
     join(&less_first, &less_last, greater_first, greater_last);

     *first = less_first;
     *last  = less_last;
}

/* ------------------------------------------------------ */
/* FUNCTION  insert :                                     */
/*    This function receives first and last pointers to a */
/* list, and a pointer to a node, then insert that node   */
/* to the tail of the list.  Finally returns the next node*/
/* of the given node as function value.                   */
/* ------------------------------------------------------ */

Node  insert(Node *first, Node *last, Node work)
{
     Node  p;

     if (*first == NULL)
          *first = *last = work;
     else {
          (*last)->next = work;
          *last         = work;
     }
     p = work->next;
     work->next = NULL;
     return p;
}

/* ------------------------------------------------------ */
/* FUNCTION  join :                                       */
/*    This function accepts two set of pointers pointing  */
/* to two linked list, then append the second list to the */
/* end of the first list.  The two pointers will be       */
/* changed to point to the newly formed list.             */
/* ------------------------------------------------------ */

void  join(Node *first, Node *last, Node head, Node tail)
{
     if (*first == NULL)
          *first = head, *last = tail;
     else if (head != NULL) {
          (*last)->next = head;
          *last         = tail;
     }
}
