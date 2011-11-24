/* ------------------------------------------------------ */
/* FUNCTION  incorrect_dutch_flag :                       */
/*    This program contains a logical error.  Can you see */
/* it?  Find a configuration of color[] arrae such that   */
/* this program will report an incorrect answer please.   */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/30/1989 */
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
     int  red   = 0;

     while (red < strlen(color))
          if (color[red] == RED)
               red++;
          else if (color[red] == WHITE) {
               SWAP(white, red);
               white++, red++;
          }
          else {
               SWAP(blue, red);   
                    blue++;
               SWAP(white, red);  
                    white++, red++;
          }
}
