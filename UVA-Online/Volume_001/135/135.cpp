// 135 - No Rectangles
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
Consider a grid such as the one shown. We wish to mark k intersections
in each of n rows and n columns in such a way that no 4 of the selected
intersections form a rectangle with sides parallel to the grid. Thus for
k = 2 and n = 3, a possible solution is:
It can easily be shown that for any given value of k, k
2 − k + 1 is a
lower bound on the value of n, and it can be shown further that n need
never be larger than this.
Write a program that will find a solution to this problem for k ≤ 32,
k − 1 will be 0, 1 or prime.
Input
Input will consist of some values for k, one per line. 
 
 * 
 * |  |  |  |  |  |  |  |  |  |  |  |
 * +--+--+--+--+--+--+--+--+--+--+--+
 * 
 * 1
 * O
 * 
 * 2
 * O--O--+
 * |  |  |
 * O--+--O
 * |  |  |
 * +--O--O
 * 
 * 3
 * O--O--O--+--+--+--+
 * |  |  |  |  |  |  |
 * O--+--+--O--O--+--+
 * |  |  |  |  |  |  |
 * O--+--+--+--+--O--O
 * |  |  |            
 * +--O--+  O--+  O--+
 * |  |  |  |  |  |  |
 * +--O--+  +--O  +--O
 * |  |  |              
 * +--+--O  O--+  +--O
 * |  |  |  |  |  |  |
 * +--+--O  +--O  O--+

 * 
 * 4
 * O--O--O--O--+--+--+--+--+--+--+--+--+
 * |  |  |  |  |  |  |  |  |  |  |  |  |
 * O--+--+--+--O--O--O--+--+--+--+--+--+
 * |  |  |  |  |  |  |  |  |  |  |  |  |
 * O--+--+--+--+--+--+--O--O--O--+--+--+
 * |  |  |  |  |  |  |  |  |  |  |  |  |            
 * O--+--+--+--+--+--+--+--+--+--O--O--O
 *               c=0      c=1      c=2                    
 * +--O--+--+  O--+--+  O--+--+  O--+--+                 b=0
 * |  |  |  |  |  |  |  |  |  |  |  |  |             a=0 
 * +--O--+--+  +--O--+  +--O--+  +--O--+                 b=1
 * |  |  |  |  |  |  |  |  |  |  |  |  |                 
 * +--O--+--+  +--+--O  +--+--O  +--+--O                 b=2
 *                                       
 * +--+--O--+  O--+--+  +--O--+  +--+--O
 * |  |  |  |  |  |  |  |  |  |  |  |  |             a=1
 * +--+--O--+  +--O--+  +--+--O  +--O--+
 * |  |  |  |  |  |  |  |  |  |  |  |  |
 * +--+--O--+  +--+--O  O--+--+  O--+--+
 *                                       
 * +--+--+--O  O--+--+  +--+--O  +--O--+
 * |  |  |  |  |  |  |  |  |  |  |  |  |             a=2
 * +--+--+--O  +--O--+  O--+--+  +--+--O
 * |  |  |  |  |  |  |  |  |  |  |  |  |
 * +--+--+--O  +--+--O  +--O--+  O--+--+
 *             
 *             s
 */
void process(FILE *fp)
{
    int k;
    
    for (int r=0 ; fscanf(fp, "%d ", &k ) == 1 ; r=1 )
    {
        int a, b, c, d, n;

        if ( r ) printf("\n");
        
        for ( a = 0 ; a < k ; a ++ )
        {
            printf("1");
            for ( b = 1 ; b < k ; b ++ )
                printf(" %d", a*(k-1) + b+1);
            printf("\n");
        }
        for ( a = 0 ; a < k - 1; a ++ )
        {
            for ( b = 0 ; b < k - 1; b ++ )
            {
                printf("%d", a+2);
                
                for ( c = 0 ; c < k - 1 ; c ++ )
                {
                    int s = ( a * c + b ) % ( k - 1 ) ;
                    int offset = c * ( k - 1 ) + k + 1;
                    
                    printf(" %d", offset + s);
                }
                printf("\n");
            }
        }
    }
}
int main()
{
#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif
    process(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}