/* ------------------------------------------------------ */
/* PROGRAM  subtlerr :                                    */
/*    This program contains a subtle error.  Can you see  */
/* it without running this program?  Actually, you CAN NOT*/
/* run it to pinpoint the error and this is what the word */
/* 'subtle' means.  Suppose you are running this program  */
/* on a machine which fits this program, you won't get any*/
/* error.  So, your job is that pinpoint the error spot by*/
/* EXAMINEing the source code only.                       */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/30/1989 */
/* ------------------------------------------------------ */

void main(void)
{
     long  l;

     for (l = 0x8000000fL; l <= 1; l--)
          ;
     l++;
     printf("\nMinimum long value = %ld", l);

     for (l = 0x7ffffff0L; l > 0; l++)
          ;
     l--;
     printf("\nMaximum long value = %ld", l);
}
