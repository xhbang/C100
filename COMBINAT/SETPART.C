/* ------------------------------------------------------ */
/* FUNCTION  set_partition :                              */
/*    Given an integer n, this function will lists all    */
/* possible partitions of {1,2,3,...,n}.                  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/24/1989 */
/* ------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>           /* for malloc()             */

#define  ALWAYS   1

void  display(int *, int);

void  set_partition(int n)
{
     int  *code, *maxi;       /* arrays for code[], maxi[]*/
     int  i, j;

     code = (int *) malloc(sizeof(int)*n); /* get memory  */
     maxi = (int *) malloc(sizeof(int)*n);

     for (i = 0; i < n; i++)  /* initialization           */
          code[i] = 1, maxi[i] = 2;

     while (ALWAYS) {         /* loop until done.         */
          display(code, n);   /* display one partition    */
          for (i = n-1; code[i] == maxi[i]; i--)
               ;              /* find next 'increasible'  */
          if (i > 0) {        /* found ?                  */
               code[i]++;     /* YES, update              */
               for (j = i + 1; j < n; j++) {
                    code[j] = 1; 
                    maxi[j] = maxi[i]+((code[i]==maxi[i]) ? 1 : 0);
               }
          }
          else                /* NOT FOUND, done.         */
               break;
     }
     free(code);
     free(maxi);
}


/* ------------------------------------------------------ */
/* FUNCTION  display :                                    */
/*    This function displays the code of the partition.   */
/* ------------------------------------------------------ */

void  display(int *code, int n)
{
     int  i;
   
     printf("\n");
     for (i = 0; i < n; i++)
          printf("%3d", *(code+i));
}


/* ------------------------------------------------------ */

void main(void)
{
     char  line[100];
     int   n;

     printf("\nSet Partition Program for {1,2,3,...,N}");
     printf("\n=======================================");
     printf("\n\nN Please --> ");
     gets(line);
     n = atoi(line);
     printf("\nCodes of Partitions.");
     printf("\ni-th position = j means i in partition j\n");
     set_partition(n);
}
