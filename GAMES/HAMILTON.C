/* ------------------------------------------------------ */
/* PROGRAM  Hamilton cycle finder :                       */
/*    Given an undirected graph with at least 3 vertices, */
/* this program dins out one of the Hamilton Cycle.  If   */
/* there is no such cycle at all, this result will also   */
/* be reported.  NOTE that Hamilton Cycle problem is a    */
/* NP-Complete problem and so don't expect any efficient  */
/* algorithm.  This program employs the backtrack method  */
/* used in previous problems.                             */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/23/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE  30         /* no more than 30 vertices */
#define   ALWAYS    1
#define   SUCCESS   1
#define   FAILURE   0
#define   YES       1
#define   NO        0

/* ------------------------------------------------------ */
/* FUNCTION  read_in :                                    */
/*    Read in the number of vertices and the edges.  Then */
/* build up the adjacenct matrix.  NOTE that because the  */
/* graph is undirected, an edga (s,t) will represent two  */
/* 'edges' in the graph, namely (s,t) and (t,s).  This    */
/* function reflects this fact by set two entries.        */
/* ------------------------------------------------------ */

void  read_in(int connected[][MAXSIZE], int *n)
{
     int  i, j;

     scanf("%d", n);          /* read in the number of VTX*/
     for (i = 0; i < *n; i++) /* clear the adjacent matrix*/
          for (j = 0; j < *n; j++)
               connected[i][j] = NO;

     scanf("%d%d", &i, &j);   /* read in first edge       */
     while (i != 0 && j != 0) {  /* end ?                 */
          connected[i-1][j-1] = YES; /* NO, setup two     */
          connected[j-1][i-1] = YES; /* symmetric edges   */
          scanf("%d%d", &i, &j); /* read next one         */
     }
     for (i = 0; i < *n; i++) /* clear diagonal           */
          connected[i][i] = NO;
}

/* ------------------------------------------------------ */
/* FUNCTION  hamilton :                                   */
/*    Given the adjacent matrix connected[], the number   */
/* of vertices and the start vertex, this function finds  */
/* a Hamilton Cycle and stores it in cycle[].             */
/* ------------------------------------------------------ */

int  hamilton(int  connected[][MAXSIZE], int cycle[], int n, int start)
{
     int  *visited;           /* visited marks            */
     int  top, i;

     visited = (int *) malloc(sizeof(int)*n); /* get mem. */
     for (i = 0; i < n; i++)  /* clear marks to NO        */
          visited[i] = NO;
     visited[start] = YES;    /* but the start has visited*/

     cycle[0] = start;        /* the cycle has 'start'    */
     cycle[1] = 0;            /* next in cycle is VTX 0   */
     top      = 1;            /* the top working element  */

     while (ALWAYS) {         /* loop until done          */
          for (i = cycle[top]; i < n; i++) /* find next   */
               if (connected[cycle[top-1]][i] && !visited[i])
                    break;
          if (i < n) {        /* all neighbors tried?     */
               cycle[top] = i;/* NO, a new vertex in cycle*/
               visited[cycle[top]] = YES;
               if (top == n-1 && connected[cycle[top]][start]) {
                    free(visited); /* if all visited ...  */
                    return SUCCESS;/* return SUCCES       */
               }
               else           /* otherwise, advance.      */
                    cycle[++top] = 0;
          }
          else {              /* next not found .....     */
               visited[cycle[--top]] = NO; /* backtrack   */
               if (top == 0) { /* return to the start VTX?*/
                    free(visited); /* YES, failed.        */
                    return FAILURE;
               }
                    cycle[top]++;  /* NO, move to neighbr */
          }
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  display :                                    */
/*    Display the found cycle.                            */
/* ------------------------------------------------------ */

void  display(int cycle[], int n)
{
     int  i;
  
     printf("\n\nA Hamilton Cycle is Listed as Follows :");
     printf("\n\n%d", cycle[0]+1);
     for (i = 1; i < n; i++)
          printf("->%d", cycle[i]+1);
     printf("->%d", cycle[0]+1);
}


/* ------------------------------------------------------ */

void  main(void)
{
     int  connected[MAXSIZE][MAXSIZE];
     int  cycle[MAXSIZE];
     int  n;

     printf("\nHamilton Cycle Program");
     printf("\n======================");
     read_in(connected, &n);
     if (hamilton(connected, cycle, n, 0) == SUCCESS)
          display(cycle, n);
     else
          printf("\n\nNO Hamilton Cycle at all.");
}
