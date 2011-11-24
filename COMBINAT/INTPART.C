/* ------------------------------------------------------ */
/* PROGRAM  integer partition :                           */
/*    Given a positive integer n, this program lists all  */
/* partition of n in anti-lexical order.                  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/21/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>          /* for atoi()               */

#define   MAXSIZE   20

void  display(int [], int [], int);

void  main(void)
{
     int  partition[MAXSIZE+1]; /* the actuall partition  */
     int  mult[MAXSIZE+1];      /* multiplicity           */
     int  part_no;              /* no. of parts           */
     int  sum, size, remainder, count;
     int  n;
     char line[100];

     printf("\nPartition of Integer");
     printf("\n====================");
     printf("\n\nInput a Positive Integer --> ");
     gets(line);
     n = atoi(line);

     partition[1] = n;        /* at the biginning, we have*/
     mult[1]      = part_no = count = 1; /* only one part.*/
     display(partition, mult, part_no);

     do {                     /* size one sum in 'sum'    */
          sum  = (partition[part_no]==1) ? mult[part_no--]+1 : 1;
          size = partition[part_no] - 1; /* dec. size     */
          if (mult[part_no] != 1)  /* last part with mul=1*/
               mult[part_no++]--;  /* NO, cut this part   */
          partition[part_no] = size; /* set new part=size */
          mult[part_no]      = sum/size + 1; /* fill other*/
          if ((remainder = sum % size) != 0) {
               partition[++part_no] = remainder;
               mult[part_no]        = 1;
          }
          count++;
          display(partition, mult, part_no);
     } while (mult[part_no] != n);
     printf("\n\nThere are %d partitions in anti-lexical order",
             count);
}


/* ------------------------------------------------------ */
/* FUNCTION display :                                     */
/*    This routine displays the given partition.          */
/* ------------------------------------------------------ */

void  display(int partition[], int mult[], int part_no)
{
     int  i, j;

     printf("\n");
     for (i = 1; i <= part_no; i++)      /* for each part */
          for (j = 1; j <= mult[i]; j++) /* and its mult. */
               printf("%3d", partition[i]); /* show them  */
}
