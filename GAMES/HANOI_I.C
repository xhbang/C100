/* ------------------------------------------------------ */
/* PROGRAM towers of hanoi :                              */
/*    Given the number of disk to be moved, this function */
/* moves the number of disks from pin 1 to pin 3 subject  */
/* to the restriction of the rules of the towers of Hanoi */
/* without recursion.  The basic idea behind this program */
/* is the Gray Code.  But the formulation of this program */
/* follows from an article of Don Perkins and H. Mayer.   */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/20/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAX_DISK   31

int  which_disk(unsigned long *);

void  main(void)
{
     int  number_of_disk;     /* the number of disks      */
     int  pin[MAX_DISK+1];    /* locations of disks       */
     int  dir[2];             /* directions; 0=pos,1=neg  */
     int  disk;               /* disk to be moved         */
     int  next;               /* next position of 'disk'  */
     int  index;              /* direction subscript      */
     unsigned long number_of_moves; /* number of moves    */
     unsigned long counter;   /* counter for Gray Code    */
     unsigned long i;         /* working                  */
     char line[100];          /* input line               */

     printf("\nIterative Towers of Hanoi Program");
     printf("\n=================================");
     printf("\n\nHow many disks (<=31) ? ");
     gets(line);

     number_of_disk  = atoi(line);
     number_of_moves = (0x01UL << number_of_disk) - 1;
     counter         = 0;       /* counter for Gray Code  */

     if (number_of_disk & 0x01) /* setup direction        */
          dir[0] = 0, dir[1] = 1;
     else
          dir[0] = 1, dir[1] = 0;

     for (i = 1; i <= number_of_disk; i++) /* set up loc. */
          pin[i] = 1;

     printf("\n   Step   Disk #    From      To");
     printf("\n   -----------------------------");

     for (i = 1; i <= number_of_moves; i++) {
          disk  = which_disk(&counter); /* get disk #     */
          index = disk & 0x01;  /* compute direction index*/
          next = (pin[disk] + dir[index]) % 3 + 1;
          printf("\n%6lu%8d%10d%8d", i, disk, pin[disk], next);
          pin[disk] = next;
     }
}


/* ------------------------------------------------------ */
/* FUNCTION which_disk :                                  */
/*    Given the previous counter value, this function     */
/* computes the only one bit changed from 0 to 1 by adding*/
/* one.  This value corresponding to Gray Code.           */
/* ------------------------------------------------------ */

int  which_disk(unsigned long *counter)
{
     unsigned long a, b, c;
     int  i;

     a = *counter;
     *counter = b = a + 1;
     for (c = a^b, i = 0; c != 0; c >>= 1, i++)
          ;
     return i;
}
