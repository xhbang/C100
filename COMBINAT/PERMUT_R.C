/* ------------------------------------------------------ */
/* PROGRAM permutation by rotation :                      */
/*    Give an integer n, this program generates all       */
/* possible permutations by using rotation operations.    */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/08/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE   20
#define   ROTATE(p) {  int  i, temp;              \
                       temp = perm[p];            \
                       for (i = p-1; i >= 0; i--) \
                            perm[i+1] = perm[i];  \
                       perm[0] = temp;            \
                    }

void main(void)
{
     int  perm[MAXSIZE];
     int  position;
     int  n;
     int  i;
     char line[100];

     printf("\nPermutation by Rotation Method");
     printf("\n==============================");
     printf("\n\nNumber of Elements --> ");
     gets(line);
     n = atoi(line);

     for (i = 0; i < n; i++)  /* initialize to 1,2,...,n  */
          perm[i] = i + 1;

     position = n - 1;           
     while (position != 0) {  /* if still have positions..*/
          printf("\n");       /* display result           */
          for (i = 0; i < n; i++)
               printf("%d ", perm[i]);

          position = n - 1;   /* starts from the last pos */
          ROTATE(position);   /* rotate them.             */
          while (perm[position]==position+1 && position!=0) {
               position--;    /* if last pos are equal and*/
               ROTATE(position); /* not zero, rotate again*/
          }
     }
}
