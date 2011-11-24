/* -------------------------------------------------------- */
/* FUNCTION  bucketsort :                                   */
/*    A list implementation of Bucket sort algorithm for    */
/* int's.  This package contains several functions as       */
/* follows :                                                */
/*                                                          */
/*    sort          : the control program for bucket sort.  */
/*    listgen       : this function accepts an input array  */
/*                    and number of elements in that array  */
/*                    than generates a list containing 3    */
/*                    items, namely data (input), x (the    */
/*                    shifted data item) and next (a list   */
/*                    pointer.  The head of this list is    */
/*                    stored in an external variable 'head' */
/*    distribute    : this function dispatches data from the*/
/*                    list to a set of buckets.             */
/*    recollect     : this function collects data items from*/
/*                    those buckets and rebuilds the list.  */
/*                    Also all data items will be right     */
/*                    shfited several bits for next run.    */
/*    putback       : this function retrieves data item in  */
/*                    the sorted array and put them back to */
/*                    the input array.                      */
/*                                                          */
/* Copyright Ching-Kuang SHENE                  Feb/26/1989 */
/* -------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>

#define   LENGTH      4       /* mask size                  */
#define   BUCKET_NO   16      /* number of buckets=2*LENGTH */
#define   LOOP_COUNT  sizeof(int)*8/LENGTH


/* -------------------------------------------------------- */
/*                 external data items                      */
/* -------------------------------------------------------- */

struct node {                 /* data structure for list    */
     int  data;               /*    original data           */
     int  x;                  /*    working data            */
     struct node   *next;     /*    list pointer            */
};

struct node *head;            /* list head                  */

struct cell {                 /* bucket cell data structure */
     struct node *first;      /*    point to 1st list ele.  */
     struct node *last;       /*    point to last list ele. */
} buckets[BUCKET_NO];

int  mask = 0x0FU;            /* the mask 000....1111       */


/* -------------------------------------------------------- */
/*                  function prototypes                     */
/* -------------------------------------------------------- */

struct node *listgen(int [], int);
void   distribute(void);
void   recollect(void);
void   putback(int []);


/* -------------------------------------------------------- */
/* FUNCTION sort :                                          */
/*    control routine of Bucket sort.                       */
/* -------------------------------------------------------- */

void sort(int input[], int n)
{
     int  i, count;


     head = listgen(input, n);/* get the data item list     */

     /* iterates enough times to sort the list              */

     for (count = 1; count <= LOOP_COUNT; count++) {
          for (i = 0; i < BUCKET_NO; i++) /* initial buckets*/
               buckets[i].first = buckets[i].last = NULL;
          distribute();
          recollect();
     }
     putback(input);
}


/* -------------------------------------------------------- */
/* FUNCTION listgen :                                       */
/*    This function takes an input array input[] and put    */
/* all elements therein to a list.                          */
/* -------------------------------------------------------- */

struct node *listgen(int input[], int n)
{
     struct node *first;
     struct node *last;
     struct node *temp;
     int    i;

     first = last = (struct node *) malloc(sizeof(struct node));
     first->data = first->x = input[0];
     first->next = NULL;
     for (i = 1; i < n; i++) {
          temp = (struct node *) malloc(sizeof(struct node));
          temp->data = temp->x = input[i];
          temp->next = NULL;
          last->next = temp;
          last       = temp;
     }
     return first;
}


/* -------------------------------------------------------- */
/* FUNCTION distribute :                                    */
/*    This function distributs data items stored in the list*/
/* to backets according to the value of last 'LENGTH' bits. */
/* -------------------------------------------------------- */

void distribute(void)
{
     struct node *temp;
     int         index;

     while (head != NULL) {
          index = (head->x) & mask;
          (head->x) >>= LENGTH;
          if (buckets[index].first == NULL)
               buckets[index].first = buckets[index].last = head;
          else {
               (buckets[index].last)->next = head;
               buckets[index].last         = head;
          }
          temp       = head->next;
          if (head->next != NULL)
               head->next = NULL;
          head       = temp;
     }
}


/* -------------------------------------------------------- */
/* FUNCTION recollect :                                     */
/*    This function collects data items from buckets and    */
/* buckets information for next run.                        */
/* -------------------------------------------------------- */

void recollect(void)
{
     int  i, j;

     for (i = 0; i < BUCKET_NO && buckets[i].first == NULL; i++)
          ;
     head = buckets[i].first; /* i indicates 1st non-NULL   */

     for (j = i+1; j < BUCKET_NO; j++)
          if (buckets[j].first != NULL) {
               (buckets[i].last)->next = buckets[j].first;
               i = j;
          }
}


/* -------------------------------------------------------- */
/* FUNCTION putback :                                       */
/*    This function puts all sorted elements in the list    */
/* back to the given array and frees storage occupied by    */
/* the list.                                                */
/* -------------------------------------------------------- */

void  putback(int input[])
{
     struct node *temp;
     int    i;

     for (i = 0; head != NULL; i++) {
          input[i] = head->data;
          temp     = head->next;
          free(head);
          head     = temp;
     }
}
