#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct _trees
{
    int x, y, z;
} TREE;

double distnace(TREE *a, TREE *b)
{
    double x = ( a->x - b->x );
    double y = ( a->y - b->y );
    double z = ( a->z - b->z );

    return sqrt(x*x + y*y + z*z);
}

void process(FILE *fp)
{
    TREE tree[5000 + 1]={0,};
    int nTrees;
    int dist[10]={0,};
    int i, j;

    for ( nTrees = 0 ; fscanf(fp, "%d %d %d ", &tree[nTrees].x, &tree[nTrees].y, &tree[nTrees].z) == 3 ; nTrees ++ )
    {
        if ( tree[nTrees].x == 0 && tree[nTrees].y == 0 && tree[nTrees].z == 0 )
            break;
    }

    for ( i = 0 ; i < nTrees ; i ++ )
    {
        int min_dist = -1 ;
        for ( j = 0 ; j < nTrees ; j ++ )
        {
            if ( i == j ) continue;

            int d = (int)distnace(tree + i, tree + j);
            if ( min_dist < 0 || min_dist > d ) min_dist = d;
        }
        if ( min_dist >= 0 && min_dist < 10 )
            dist[ min_dist ] ++;
    }
    for ( i = 0 ; i < 10 ; i ++)
        printf("%4d", dist[i]);
    printf("\n");
}

int main()
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input/input.txt", "rt");
#endif

process(fp);

#ifdef ONLINE_JUDGE
#else
    if (fp)
        fclose(fp);
#endif

}