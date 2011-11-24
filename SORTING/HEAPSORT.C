/* ------------------------------------------------------ */
/* FUNCTION heapsort :                                    */
/*    Given an int array and the number of items in this  */
/* array, this routine sorts the array with heap sort.    */
/* A very important note is that due to special subscript */
/* relationship of a heap, the given array must have one  */
/* more element because heapsort assume the 1st element   */
/* begins with x[1].  In what follows, I have choosen to  */
/* use a trick to fool the C compiler.  heapsort() will   */
/* receive an int pointer old_x pointing to an integer    */
/* array.  But in this function, we define a new point x[]*/
/* which contains the address of old_x[] minus one.  Thus */
/* x[1] is old_x[0] and therefore the problem is resolved.*/
/*    This is one of the very critical point that I HATE  */
/* programming in C.  All GOOD language, even FORTRAN,    */
/* have some special declaration feature to shift the     */
/* origin of an array to somewhere, for example declaring */
/* an array in the range of x[5] to x[10] just like in    */
/* the old friend Pascal.  Don't long live C.             */
/*                                                        */
/* Copyright Ching-Kuang Shene                Mar/22/1990 */
/* ------------------------------------------------------ */

#define  YES        1
#define  NO         0

void  fix_heap(int [], int, int, int);


/* ------------------------------------------------------ */
/* FUNCTION sort :                                        */
/*    Given an array x[] and its number of elements, this */
/* function uses fix_heap() to build up a heap and then   */
/* sorts the array by swaping the top and the last items. */
/* ------------------------------------------------------ */

void  sort(int old_x[], int n)  
{
     int  *x = old_x - 1;          /* fool the C compiler */
     int  temp;
     int  size, i;

     for (i = n/2; i >= 1; i--)    /* starts off from mid */
          fix_heap(x, i, x[i], n); /* fix the heap at this*/

     for (size = n; size >=2; size--) { /* sort phase.    */
          temp = x[1];             /* pick up the largest */
          fix_heap(x, 1, x[size], size-1); /* move to last*/
          x[size] = temp;          /* fix and restore     */
     }
}


/* ------------------------------------------------------ */
/* FUNCTION fix_heap :                                    */
/*    Given a heap rooted at 'root', a new key 'key' and  */
/* the subscript of the last item 'bound', this function  */
/* inserts the new key and restore the heap properties.   */
/* ------------------------------------------------------ */

void  fix_heap(int x[], int root, int key, int bound)
{
     int  father, son;
     int  done;

     father = root;           /* start off from the root  */
     son    = father + father;/* get the subscript of son */
     done   = NO;
     while (son <= bound && !done) { /* son available?    */
          if (son < bound && x[son+1] > x[son]) /* latger?*/
               son++;         /* now son is the larger one*/
          if (key < x[son]) { /* if the son > key         */
               x[father] = x[son]; /* step down until done*/
               father    = son;
          }
          else                /* son < key, thus the key  */
               done      = YES; /* get its position.      */
          son = father + father;
     }
     x[father] = key;         /* insert the key           */
}
