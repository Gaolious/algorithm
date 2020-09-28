
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIMENSION (20)

double ratio[ MAX_DIMENSION ][ MAX_DIMENSION ] ;
double dynamic[MAX_DIMENSION][MAX_DIMENSION][MAX_DIMENSION] = {0,};
int path [MAX_DIMENSION][MAX_DIMENSION][MAX_DIMENSION] = {0,};

void dp(int n)
{
    // O(n^3) / dynamic[ i ][ j ] 2 dimension. 
    //  floyd warshall algorithm is to find optimal path from i to j. ( for all node i, j)
    //  but it is only for one time.
    //
    // O(n^4) / dynamic [ n ][ i ][ j ] 
    // Best Exchange i to j and n times
    //      => i, j in exchange from i to j
    //      => n times.
    // 

    
    int s, e, m, i;
    int d ;
    double exchange ;
    //
    //  in d depth, 
    //      use floyd warshall algorithm to find
    //      s -> e vs s->m->e  in d-1 depth.
    //
    for ( d=0, s = 0 ; s < n ; s ++ )
    for ( e = 0 ; e < n ; e ++ )
    {
        dynamic[ d ][ s ][ e ] = ratio[ s ][ e ] ;
        path[ d ][ s ][ e ] = s ;
    }
    
    for ( d = 0 ; d < n ; d ++ )
    {
        if (d > 0 ) 
        {
            for ( s = 0 ; s < n ; s ++ )
            for ( e = 0 ; e < n ; e ++ )
            {
                dynamic[ d ][ s ][ e ] = 0.0;//dynamic[ d -1 ][ s ][ e ];
                path[ d ][ s ][ e ] = s ;
            }

            for ( m = 0 ; m < n ; m ++)
            for ( s = 0 ; s < n ; s ++ )
            for ( e = 0 ; e < n ; e ++ )
            {
                exchange = dynamic[ d - 1 ][ s ][ m ] * ratio[ m ][ e ] ;

                if ( dynamic[ d ][ s ][ e ] < exchange )
                {
                    dynamic[ d ][ s ][ e ] = exchange ;
                    path [ d ][ s ][ e ] = m ;
#ifndef ONLINE_JUDGE

                    printf("updated : d[%d][%d][%d](=%2.3lf) = Depth[%d][%d][%d](=%2.3lf) * ratio[%d][%d](=%2.3lf)\n"
                            , d, s, e, exchange
                            , d-1, s , m, dynamic[ d - 1 ][ s ][ m ]
                            , m , e , ratio[ m ][ e ]);
#endif
                }
            }
        }
        
#ifndef ONLINE_JUDGE
        printf("------------------------------------------------------------------------------\n");
        printf("Depth #%d\n", d );
        for ( s = 0 ; s < n ; s ++ )
        {
            for ( e = 0 ; e < n ; e ++ )
                printf("\t%05.3lf", dynamic[d][s][e]);
            printf("\n");
        }
        printf("\t--------------------------------------\n");
        
        for ( s = 0 ; s < n ; s ++ )
        {
            for ( e = 0 ; e < n ; e ++ )
                printf("\t%5d", path[d][s][e]);
            printf("\n");
        }
#endif
        double max_profit = -1.0L;
        int max_profit_id = -1;
        
        for ( i = 0 ; i < n ; i ++ )
        {
            if ( 1.01 <= dynamic[d][i][i] )
            {
                int p[MAX_DIMENSION+1] ={0, }, t ;

                s = e = i;
                p[d+1] = e ;
                p[0] = s ;

                for ( t = d ; t > 0 ; t -- )
                {
                    p[t] = path[t][s][e];
                    e = path[t][s][e];
                }

                for ( t = 0 ; t <= d + 1 ; t ++ )
                {
                    printf("%d", p[t] + 1);
                    if ( t <= d ) printf(" ");
                }
                printf("\n");
                return ;
            }
        }
    }
    
    printf("no arbitrage sequence exists\n");
}

void process( FILE *fp )
{
    int n ;
    int i, j;
    
    while ( fscanf(fp, "%d", &n) == 1 )
    {
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
            {
                if ( i == j ) 
                    ratio[i][j] = 0.0l;
                else
                    fscanf(fp, "%lf", &(ratio[i][j]) );
            }
                
        dp(n);
    }
    // 0 -> 0
    // 0 -> 3 -> 2 -> 0
#ifndef ONLINE_JUDGE 
#endif    
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
