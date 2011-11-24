/* ------------------------------------------------------ */
/* FUNCTION  stable_marriage :                            */
/*    Stable Marriage problem by Gale-Shapley Algorithm.  */
/* Given man's and woman's preference matrices man[][] &  */
/* woman[][], this function determines the stable marriage*/
/* couples in man-oriented order and returns the marriage */
/* by two arrays, namely m_eng[] and w_eng[].             */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/05/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc() and free()  */

#define   SIZE        10      /* size of preference matrix*/
#define   FREE        -1      /* means no engagement      */

/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  get_mem(int [][SIZE], int, int ***, int **, int **);
void  release_mem(int **, int *, int *);

/* ------------------------------------------------------ */
/* FUNCTION  stable_marriage :                            */
/*    The main routine.                                   */
/* ------------------------------------------------------ */

void  stable_marriage(int man[][SIZE], int woman[][SIZE], int n,
                      int m_eng[], int w_eng[])
{
     int  **rank;             /* pointer to rank[][]      */
     int  *waiting;           /* pointer to waiting stack */
     int  *next;              /* pointer to next to try   */
     int  boy, girl, top;     /* working variables        */

     get_mem(woman, n, &rank, &waiting, &next); /* get mem*/
     for (girl = 0; girl < n; girl++) /* no one engaged.  */
          w_eng[girl] = FREE;

     for (top = n - 1; top >= 0; ) {  /* for a FREE man...*/
          boy  = waiting[top];        /* get his name and */
          girl = man[boy][(next[boy])++]; /* girl in list */
          if (w_eng[girl] == FREE) {  /* is she free?     */
               w_eng[girl] = boy;     /* YES, engage with */
               m_eng[boy]  = girl;    /* this girl.       */
               top--;                 /* pop off this guy */
          }
          else if (rank[girl][boy] < rank[girl][w_eng[girl]]) {
               waiting[top] = w_eng[girl]; /* kick off the*/
               w_eng[girl] = boy;     /* current fiance of*/
               m_eng[boy]  = girl;    /* this girl. engage*/
          }
     }
     release_mem(rank, waiting, next);/* release all mem. */
}

/* ------------------------------------------------------ */
/* FUNCTION  get_mem :                                    */
/*    Allocate memory and initialize.                     */
/* ------------------------------------------------------ */

void  get_mem(int w[][SIZE], int n, int ***rank, int **wait, int **next)
{
     int  i, j;

     *rank = (int **) malloc(sizeof(int *)*n);
     *wait = (int *) malloc(sizeof(int)*n);
     *next = (int *) malloc(sizeof(int)*n);
     (*rank)[0] = (int *) malloc(sizeof(int)*n*n);
     for (i = 1; i < n; i++)
          (*rank)[i] = (*rank)[i-1] + n;

     for (i = 0; i < n; i++) {    /* make ranking list    */
          (*wait)[i] = n - 1 - i; /* n-1,...,1,0 in stack */
          (*next)[i] = 0;         /* next girl to try     */
          for (j = 0; j < n; j++) /* for the j-th boy.... */
               (*rank)[i][w[i][j]] = j; /* save his rank  */
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  release_mem :                                */
/*    Release all allocated memory.                       */
/* ------------------------------------------------------ */

void  release_mem(int **rank, int *wait, int *next)
{
     free(rank[0]);
     free(rank);
     free(wait);
     free(next);
}

/* ------------------------------------------------------ */

void  main(void)
{
     int  man[SIZE][SIZE] = { 
               { 4, 6, 0, 1, 5, 7, 3, 2},
               { 1, 2, 6, 4, 3, 0, 7, 5},
               { 7, 4, 0, 3, 5, 1, 2, 6},
               { 2, 1, 6, 3, 0, 5, 7, 4},
               { 6, 1, 4, 0, 2, 5, 7, 3},
               { 0, 5, 6, 4, 7, 3, 1, 2},
               { 1, 4, 6, 5, 2, 3, 7, 0},
               { 2, 7, 3, 4, 6, 1, 5, 0}};
     int  woman[SIZE][SIZE] = {
               { 4, 2, 6, 5, 0, 1, 7, 3},
               { 7, 5, 2, 4, 6, 1, 0, 3},
               { 0, 4, 5, 1, 3, 7, 6, 2},
               { 7, 6, 2, 1, 3, 0, 4, 5},
               { 5, 3, 6, 2, 7, 0, 1, 4},
               { 1, 7, 4, 2, 3, 5, 6, 0},
               { 6, 4, 1, 0, 7, 5, 3, 2},
               { 6, 3, 0, 4, 1, 2, 5, 7}};
     int  m_eng[SIZE], w_eng[SIZE];
     int  n = 8;
     int  i, j;

     printf("\nStable Marriage Problem");
     printf("\n=======================");
     printf("\n\nMan's Preference Matrix");
     for (i = 0; i < n; i++) {
          printf("\n");
          for (j = 0; j < n; j++)
               printf("%3d", man[i][j]);
     }

     printf("\n\nWoman's Preference Matrix");
     for (i = 0; i < n; i++) {
          printf("\n");
          for (j = 0; j < n; j++)
               printf("%3d", woman[i][j]);
     }

     stable_marriage(man, woman, n, m_eng, w_eng);

     printf("\n\nMan-Oriented Stable Marriage Engagement List");
     printf("\n\nMan  Woman     Woman  Man");
     printf(  "\n----------     ----------");
     for (i = 0; i < n; i++)
          printf("\n%3d%6d%10d%6d", i, m_eng[i], i, w_eng[i]);
}
