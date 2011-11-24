/* ------------------------------------------------------ */
/* PROGRAM Number Puzzle :                                */
/*    This is first solution of the number puzzle.  It is */
/* written under the guidelines in my book.  For each     */
/* digit, there corresponds a for loop and an if statement*/
/* to prevent duplicated digits.  Read it carefully.      */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/30/1989 */
/* ------------------------------------------------------ */

#include <stdio.h>

void main(void)
{
     long  I, N, R=0, E, V, G, C, Q, T=1;
     long  IN, VINGT, CINQ, TRENTE;
     long  sum;

     printf("\nNumber Puzzle\n");
     printf("\n   VINGT");
     printf("\n    CINQ");
     printf("\n+)  CINQ");
     printf("\n--------");
     printf("\n  TRENTE\n");

     for (V=8; V<=9; V++)
       for (I=0; I<=9; I++)
         if (I != V && I!=T)
           for (N=0; N<=9; N++)
             if (N!=I && N!=V && N!=T) {
               IN = I*10 + N;
               for (G=0; G<=9; G++)
                 if (G!=N && G!=I && G!=V && G!=T && G!=R) 
                    for (C=2; C<=9; C++)
                      if (C!=G && C!=N && C!=I && C!= V && C!=T && C!=R)
                        for (Q=2; Q<=9; Q++)
                          if (Q!=C && Q!=G && Q!=N && Q!=I && Q!=V 
                                   && Q!=T && Q!=R)
                             for (E=3; E<=9; E+=2)
                               if (E!=Q && E!=C && E!=G && E!=N && E!=I
                                        && E!=V && E!=T && E!=R) {
                                 TRENTE=((((T*10+R)*10+E)*10+N)*10+T)*10+E;
                                 VINGT=((V*100+IN)*10+G)*10+T;
                                 CINQ =(C*100+IN)*10+Q;
                                 sum=VINGT+CINQ+CINQ;
                                 if (sum==TRENTE) {
                                   printf("\n\nThe answer is :\n");
                                   printf("\n%8ld", VINGT);
                                   printf("\n%8ld", CINQ);
                                   printf("\n+)%6ld", CINQ);
                                   printf("\n--------");
                                   printf("\n%8ld", TRENTE);
                                 }
                               }
             }
}
