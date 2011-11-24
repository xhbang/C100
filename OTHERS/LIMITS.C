/* ------------------------------------------------------ */
/* PROGRAM  integer type characteristics :                */
/*    This program determines those characteristics, such */
/* as number of bits, max and min values of integer type. */
/* There is an include file <limits.h> containing all of  */
/* these data, but a self-contained program that can finds*/
/* all of them should be very interesting.                */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/26/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>

#define   SIGNED           0
#define   UNSIGNED         1

/* ------- structure for int type characteristics ------- */

struct limits {
     int            CHAR_BIT; /* no. of bits in char      */
     int            CHAR_SIGN;/* char type signed or not  */
     signed char    SCHAR_MAX;/* max value of signed char */
     signed char    SCHAR_MIN;/* min value of signed char */
     int            SHRT_BIT; /* bit # of short type      */
     short          SHRT_MAX; /* max of signed short      */
     short          SHRT_MIN; /* min of signed short      */
     int            INT_BIT;  /* bit # of int type        */
     int            INT_MAX;  /* max of signed int        */
     int            INT_MIN;  /* min of signed int        */
     int            LONG_BIT; /* bit # in long type       */
     long           LONG_MAX; /* max of signed long       */
     long           LONG_MIN; /* min of signed long       */
     unsigned char  UCHAR_MAX;/* max of unsigned char     */
     unsigned short USHRT_MAX;/* max of unsigned short    */
     unsigned int   UINT_MAX; /* max of unsigned int      */
     unsigned long  ULONG_MAX;/* max of unsigned long     */
}   param;

/* ------------------------------------------------------ */
/* FUNCTION  char_test :                                  */
/*    This function determines various characteristics of */
/* char type, signed or unsigned.                         */
/* ------------------------------------------------------ */

void  char_test(void)
{
     unsigned char  uc;
     union {
          unsigned char  uc;
          signed char    sc;
          char           c;
     } u;
     int  i;
     char *sign[] = { "signed", "unsigned"};

     for (i = 0, uc = ~0; uc != 0; uc >>= 1, i++)
          ;                   /* determine char length    */
     param.CHAR_BIT  = i;     /* and signed or unsigned   */
     u.sc = -1;
     param.CHAR_SIGN = (u.c < 0) ? SIGNED : UNSIGNED;

     param.UCHAR_MAX = ~0;    /* the max of unsigned is ~0*/
     param.SCHAR_MAX = param.UCHAR_MAX >> 1; /* signed    */
     u.sc = -1;               /* one's or 2's complement? */
     uc   = ~0;
     if (u.uc == uc)          /* 2's complement           */
          param.SCHAR_MIN = -param.SCHAR_MAX - 1;
     else                     /* 1's complement           */
          param.SCHAR_MIN = -param.SCHAR_MAX;

     printf("\nchar Characteristics : \n");
     printf("\nCHAR_BIT (number of bits)       %d", param.CHAR_BIT);
     printf("   (%s)", sign[param.CHAR_SIGN]);
     printf("\nUCHAR_MAX (unsigned char max)   %uU", param.UCHAR_MAX);
     printf("\nSCHAR_MAX (signed char max)     %d", param.SCHAR_MAX);
     printf("\nSCHAR_MIN (signed char min)     %d", param.SCHAR_MIN);
}

/* ------------------------------------------------------ */
/* FUNCTION  short_test :                                 */
/*    This function determines various characteristics of */
/* short type, signed or unsigned.                        */
/* ------------------------------------------------------ */

void  short_test(void)
{
     unsigned short  ui;
     union {
          unsigned short  ui;
          signed   short  si;
     }  u;
     int  i;

     for (i = 0, ui = ~0; ui != 0; ui >>= 1, i++)
          ;
     param.SHRT_BIT  = i;

     param.USHRT_MAX = (unsigned short) ~0;
     param.SHRT_MAX  = param.USHRT_MAX >> 1;
     u.si = -1;
     ui   = ~0;
     if (u.ui == ui)          /* 2's complement           */
          param.SHRT_MIN = -param.SHRT_MAX - 1;
     else                     /* 1's complement           */
          param.SHRT_MIN = -param.SHRT_MAX;

     printf("\n\nshort Characteristics : \n");
     printf("\nSHRT_BIT (number of bits)       %d", param.SHRT_BIT);
     printf("\nUSHRT_MAX (unsigned short max)  %uU", param.USHRT_MAX);
     printf("\nSHRT_MAX (short max)            %d", param.SHRT_MAX);
     printf("\nSHRT_MIN (short min)            %d", param.SHRT_MIN);
}

/* ------------------------------------------------------ */
/* FUNCTION  int_test :                                   */
/*    This function determines various characteristics of */
/* int type, signed or unsigned.                          */
/* ------------------------------------------------------ */

void  int_test(void)
{
     unsigned int  ui;
     union {
          unsigned int  ui;
          signed   int  si;
     }  u;
     int  i;

     for (i = 0, ui = ~0; ui != 0; ui >>= 1, i++)
          ;
     param.INT_BIT  = i;

     param.UINT_MAX = (int) ~0;
     param.INT_MAX  = param.UINT_MAX >> 1;
     u.si = -1;
     ui   = ~0;
     if (u.ui == ui)          /* 2's complement           */
          param.INT_MIN = -param.INT_MAX - 1;
     else                     /* 1's complement           */
          param.INT_MIN = -param.INT_MAX;

     printf("\n\nint Characteristics : \n");
     printf("\nINT_BIT (number of bits)        %d", param.INT_BIT);
     printf("\nUINT_MAX (unsigned int max)     %uU", param.UINT_MAX);
     printf("\nINT_MAX (int max)               %d", param.INT_MAX);
     printf("\nINT_MIN (int min)               %d", param.INT_MIN);
}

/* ------------------------------------------------------ */
/* FUNCTION  long_test :                                  */
/*    This function determines various characteristics of */
/* long type, signed or unsigned.                         */
/* ------------------------------------------------------ */

void  long_test(void)
{
     unsigned long  ul;
     union {
          unsigned long  ul;
          signed   long  sl;
     }  u;
     int  i;

     for (i = 0, ul = ~0; ul != 0; ul >>= 1, i++)
          ;
     param.LONG_BIT  = i;

     param.ULONG_MAX = (unsigned long) ~0;
     param.LONG_MAX  = param.ULONG_MAX >> 1;
     u.sl = -1L;
     ul   = ~0UL;
     if (u.ul == ul)          /* 2's complement           */
          param.LONG_MIN = -param.LONG_MAX - 1;
     else                     /* 1's complement           */
          param.LONG_MIN = -param.LONG_MAX;

     printf("\n\nlong Characteristics : \n");
     printf("\nLONG_BIT (number of bits)       %d", param.LONG_BIT);
     printf("\nULONG_MAX (unsigned long max)   %luU", param.ULONG_MAX);
     printf("\nLONG_MAX (long max)             %ld", param.LONG_MAX);
     printf("\nLONG_MIN (long min)             %ld", param.LONG_MIN);
}

/* ------------------------------------------------------ */

void  main(void)
{
     printf("\nMachine Integer Types Characteristics");
     printf("\n   You can find them in <limits.h>   ");
     printf("\n=====================================\n");
     char_test();
     short_test();
     int_test();
     long_test();
}
