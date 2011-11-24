/* ------------------------------------------------------ */
/* PROGRAM  euler :                                       */
/*    This porgram accepts a multi-graph and finds an     */
/* Euler Trail if possible.                               */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/30/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE    20
#define   ALWAYS      1
#define   YES         1
#define   NO          0
#define   SUCCESS     1
#define   FAIL       -1

/* ------------------------------------------------------ */
/*             types and external variables               */
/* ------------------------------------------------------ */

typedef   struct node  Node;  /* trail node (linked list) */

struct node {                 /* a node consists of ...   */
     int   vertex;            /*    a vertex number field */
     Node  *next;             /*    and a next node ptr   */
};

int  connect[MAXSIZE][MAXSIZE];  /* the connection matrix */
int  deg[MAXSIZE];            /* degree array             */
int  n;                       /* number of vertices       */
Node *trail;                  /* pointer to Euler trail   */

/* ------------------------------------------------------ */
/*                 function prototypes                    */
/* ------------------------------------------------------ */

void  read_in(void);
Node  *euler(void);
int   prepare(Node **, Node **);
int   find_next(Node **);
void  find_trail(int, Node **, Node **);
void  display(void);

/* ------------------------------------------------------ */

void  main(void)
{
     printf("\nEuler Trail Program");
     printf("\n===================\n");

     read_in();               /* get data                 */
     trail = euler();         /* compute Euler Trail      */
     display();               /* display result           */
}
     
/* ------------------------------------------------------ */
/* FUNCTION  read_in :                                    */
/*    This function reads in the connection matrix and    */
/* then compute the degree array.                         */
/* ------------------------------------------------------ */

void  read_in(void)
{
     int  i, j;
     char line[100];

     gets(line);              /* get in number of vertices*/
     n = atoi(line);
     for (i = 0; i < n; i++) { /* clear the connection mtx*/
          deg[i] = 0;
          for (j = 0; j < n; j++)
               connect[i][j] = 0;
     }
     gets(line);              /* get 1st line of edge set */
     sscanf(line, "%d%d", &i, &j);
     while (i != 0 && j != 0) { /* end of file ?          */
          if (i != j) {       /* a loop ?                 */
               connect[i-1][j-1]++;   /* increase edge cnt*/
               connect[j-1][i-1]++;
               deg[i-1]++;    /* increase degree count    */
               deg[j-1]++;
          }
          else                /* ignore all self loops    */
               printf("\n*** ERROR *** A loop found.  Data ignored");
          gets(line);         /* get next edge            */
          sscanf(line, "%d%d", &i, &j);
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  euler :                                      */
/*    This is the main working routine of this program.   */
/* It calls prepare() to initialize various data field and*/
/* some checks.  Then compute the Euler Trail loop by loop*/
/* ------------------------------------------------------ */

Node  *euler(void)
{
     Node *current;           /* processing cursor        */
     Node *head, *tail;       /* bound a partial trail    */
     Node *p1, *p2;           /* working pointer variables*/
     int  VTX;

     if (prepare(&head, &tail) == FAIL) /* prepare data   */
          return NULL;        /* if fail, return NULL     */

     current = tail;          /* start from the tail      */
     while (ALWAYS) 
          if ((VTX = find_next(&current)) != FAIL) {
               find_trail(VTX, &p1, &p2);
               p2->next = current->next; /* join the trail*/
               current->next = p1;
               current = p1;  /* step to next node        */
          }
          else
               break;
     return head;             /* return the trail list    */
}

/* ------------------------------------------------------ */
/* FUNCTION  prepare :                                    */
/*    This function checks to see if there are more two   */
/* odd degree vertices.  It reject a graph with more than */
/* two odd degree vertices.  Then it builds a preliminary */
/* trail list consisting of one node (if all vertices are */
/* even), or two nodes (for the two odd degree vertices). */
/* ------------------------------------------------------ */

int   prepare(Node **first, Node **last)
{
     Node *p1, *p2;
     int  no, odd_no, i;
     int  odd[2];

     for (no = odd_no = i = 0; i < n; i++) /* test odd deg*/
          if (deg[i] % 2 != 0) {
               odd_no++;
               if (no < 2)
                    odd[no++] = i;
          }
     if (odd_no > 2) {        /* more than two odd deg VTX*/
          printf("\n*** ERROR *** too many odd degree vertices.");
          return FAIL;
     }
     if (odd_no == 2) {       /* exactly two odd VTX      */
          p1 = (Node *) malloc(sizeof(Node)); /* get mem. */
          p2 = (Node *) malloc(sizeof(Node));
          connect[odd[0]][odd[1]]--;  /* just remove this */
          connect[odd[1]][odd[0]]--;  /* odd degree edge  */
          deg[odd[0]]--;
          deg[odd[1]]--;
          p1->vertex = odd[0]; /* these two vertices are  */
          p1->next   = p2;     /* the must for first step */
          p2->vertex = odd[1]; /* thus put them into the  */
          p2->next   = NULL;   /* trail list              */
          *first = p1;         /* return this list        */
          *last  = p2;
     }
     else {                   /* all vertices are even    */
          p1 = (Node *) malloc(sizeof(Node)); /* get mem. */
          p1->vertex = 0;     /* it is the only one node  */
          p1->next   = NULL;  /* in the trail list        */
          *first = *last = p1;/* return the trail list    */
     }
     return SUCCESS;
}

/* ------------------------------------------------------ */
/* FUNCTION  find_next :                                  */
/*    Given a pointer to some vertex which has already    */
/* been put into trail list, this function scans the trail*/
/* list in order to find a vertex with non-zero degree.   */
/* ------------------------------------------------------ */

int   find_next(Node **p)
{
     for (;(*p)!=NULL && deg[(*p)->vertex]==0; (*p)=(*p)->next)
          ;
     return ((*p) == NULL) ? FAIL : (*p)->vertex;
}

/* ------------------------------------------------------ */
/* FUNCTION  find_trail :                                 */
/*    Given a vertex, this function computes a trail      */
/* starting from the given vertex and returns the trail   */
/* list found.                                            */
/* ------------------------------------------------------ */

void  find_trail(int start, Node **head, Node **tail)
{
     Node *first, *last, *ptr;
     int  p, i, done;

     first = last = NULL;     /* no node in list currently*/
     p     = start;           /* p is a moving vertex     */
     done  = NO;
     while (ALWAYS) {
          for (i = 0; i < n && !connect[p][i]; i++)
               ;              /* find a VTX adjacent to p */
          if (i < n) {        /* p->i is possible         */
               connect[p][i]--,  connect[i][p]--; 
               deg[p]--,         deg[i]--;
               ptr = (Node *) malloc(sizeof(Node));
               ptr->vertex = i;     /* make node and put  */
               ptr->next   = NULL;  /* it into the trail  */
               if (first == NULL)
                    first = last = ptr;
               else {
                    last->next = ptr;
                    last       = ptr;
               }
               p = i;         /* step to the next         */
          }
          else                /* if can not proceed, stop */
              break;
     }
     *head = first;           /* return the trail list    */
     *tail = last;
}

/* ------------------------------------------------------ */
/* FUNCTION  display :                                    */
/*    Simple routine.  It display the Euler Trail.        */
/* ------------------------------------------------------ */

void  display(void)
{
     Node *ptr = trail;
     int  i = 0;

     if (trail == NULL) 
          return;
     printf("\nAn Euler Trail has been Found :\n");
     for ( ; ptr->next != NULL; ptr = ptr->next, i++) {
          if (i % 15 == 0)  printf("\n");
          printf("%2d->", ptr->vertex+1);
     }
     if (i % 15 == 0) printf("\n");   /* the last item    */
     printf("%2d", ptr->vertex+1);
}
