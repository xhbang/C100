/* ------------------------------------------------------ */
/* FUNCTION search :                                      */
/*    Given three sorted arrays, this functions locates   */
/* the first common element common to all three arrays    */
/* (if any).                                              */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/17/1989 */
/* ------------------------------------------------------ */

#define  FOUND       1
#define  NOT_FOUND   0

int  search(int x[], int y[], int z[], int X, int Y, int Z,
                                       int *XX, int *YY, int *ZZ)
{
     *XX = *YY = *ZZ = 0;
     while (*XX < X && *YY < Y && *ZZ < Z) 
          if (x[*XX] < y[*YY])
               (*XX)++;
          else if (y[*YY] < z[*ZZ])
               (*YY)++;
          else if (z[*ZZ] < x[*XX])
               (*ZZ)++;
          else
               return FOUND;
     return NOT_FOUND;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 1, 3, 5,  7,  9, 11, 13, 15, 17, 19};
     int  y[] = { 2, 4, 9, 10, 12, 14, 16, 18, 20, 21};
     int  z[] = { 1, 2, 3,  4,  5,  6,  7,  8,  9, 10};
     int  X   = sizeof(x)/sizeof(int);
     int  Y   = sizeof(y)/sizeof(int);
     int  Z   = sizeof(z)/sizeof(int);
     int  XX, YY, ZZ;

     printf("\nSearch for a Common Element from Three Arrays");
     printf("\n=============================================");
     printf("\n\nFirst Array :\n");
     for (XX = 0; XX < X; XX++)
          printf("%3d", x[XX]);
     printf("\n\nSecond Array :\n");
     for (YY = 0; YY < Y; YY++)
          printf("%3d", y[YY]);
     printf("\n\nThird Array :\n");
     for (ZZ = 0; ZZ < Z; ZZ++)
          printf("%3d", z[ZZ]);

     if (search(x, y, z, X, Y, Z, &XX, &YY, &ZZ) > 0)
          printf("\n\n%d is common to x[%d], y[%d] and z[%d]",
                      x[XX], XX, YY, ZZ);
     else
          printf("\n\nNO COMMON ELEMENT FOUND.");
}
