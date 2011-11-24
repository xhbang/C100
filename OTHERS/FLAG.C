/* ------------------------------------------------------ */
/* FUNCTION dutch national flag :                         */
/*    Given a char array containing 'b', 'r' and 'w', this*/
/* function rearranges these colors into bbb...ww...rrr   */
/* form by testing each element for each color exactly    */
/* once and minimizing number of swaps.                   */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/16/1989 */
/* ------------------------------------------------------ */

#include  <string.h>          /* for strlen()             */

#define   BLUE    'b'
#define   WHITE   'w'
#define   RED     'r'

#define   SWAP(x, y)  {char temp;            \
                       temp     = color[x];  \
                       color[x] = color[y];  \
                       color[y] = temp;      \
                       }

void  dutch_flag(char color[])
{
     int  white = 0;
     int  blue  = 0;
     int  red   = strlen(color) - 1;

     while (white <= red)     /* if there are more token  */
          if (color[white] == WHITE) /* is it a white?    */
               white++;       /* YES, just inc. white ptr */
          else if (color[white] == BLUE) { /* is it blue? */
               SWAP(blue, white); /* YES, swap the last w */
               blue++, white++; /* and the last b and inc.*/
          }
          else {              /* or is is a read, skip all*/
               while (white < red && color[red] == RED)
                    red--;    /* red token and            */
               SWAP(red, white);  /* swap with the last w */
               red--;         /* dec red ptr              */
          }
}


/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE  100

void main(void)
{
     char  flag[MAXSIZE];

     printf("\nDutch National Flag Problem");
     printf("\n===========================");
     printf("\n\nInput a String of Color Tokens (b, w and r)\n");
     gets(flag);

     dutch_flag(flag);

     printf("\nRearranged Flag is :");
     printf("\n%s", flag);
}
