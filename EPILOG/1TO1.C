/* ------------------------------------------------------ */
/* FUNCTION find_one_to_one :                             */
/*    This function accepts accepts a table representing  */
/* a function and then construct a one-to-one function    */
/* from the given function table.  funct[] is the given   */
/* function table representing a function from [0,n-1] to */
/* [0,n-1].  status[] is an output vector containing SAVED*/
/* or DELETED, where SAVED means the corresponding point  */
/* should be kept while DELETED indicates it has to be    */
/* deleted.  counter[] is a working array.                */
/*    This is a rather complicated program.  Read my book */
/* before try to study it please.                         */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

#define  QUEUE_SIZE   100     /* size of a queue          */
#define  SAVED          1
#define  DELETED       -1

void find_one_to_one(int  funct[], int status[], int counter[], int n)
{
     int  queue[QUEUE_SIZE];  /* we need a queue          */
     int  head, tail;         /* queue pointers           */
     int  i, j;

     for (i = 0; i < n; i++) { /* initialization          */
          counter[i] = 0;     /* size of inverse-images   */
          status[i]  = SAVED; /* assume all are SAVED     */
     }

     for (i = 0; i < n; i++)  /* count inverse-image size */
          counter[funct[i]]++;

     for (tail = -1, i = 0; i < n; i++) /* put all i such */
          if (counter[i] == 0) /* that counter[i]=0 to Q  */
               queue[++tail] = i; 

     head = 0;                /* main loop. start from H  */
     while (head <= tail) {   /* if there have elements   */
          j = queue[head++];  /* get it and put it to j   */
          status[j] = DELETED;/* delete it. no inv-image  */
          if (--counter[funct[j]] == 0)
               queue[++tail] = funct[j];
     }
}


/* ------------------------------------------------------ */

#include <stdio.h>

#define  MAXSIZE  100


void main(void)
{
     int  funct_table[7] = { 2, 0, 0, 4, 4, 3, 5};
     int  n              = sizeof(funct_table)/sizeof(int);
     int  status[sizeof(funct_table)/sizeof(int)];
     int  counter[sizeof(funct_table)/sizeof(int)];
     int  i;

     printf("\nOne-To-One Function Construction Program");
     printf("\n========================================\n");
     printf("\nDomain    Range    Status");
     printf("\n------    -----    ------");

     find_one_to_one(funct_table, status, counter, n);

     for (i = 0; i < n; i++) {
          printf("\n%4d%10d", i, funct_table[i]);
          if (status[i] == SAVED)
               printf("        SAVED");
          else
               printf("       DELETED");
     }

     printf("\n\nConstructed New 1-1 Function\n");
     printf("\nDomain    Range");
     printf("\n------    -----");
     for (i = 0; i < n; i++)
          if (status[i] == SAVED)
               printf("\n%4d%10d", i, funct_table[i]);
}
