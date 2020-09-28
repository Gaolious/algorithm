// 117 - The Postal Worker Rings Once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * dp.
 */

void process( FILE *fp )
{
    char in[1024]={0,};
    
    while ( fscanf(fp, "%s", in) == 1  )
    {
        int cost[26][26] = {0,};
        int vertex[26]={0,};
        int sum_len = 0;
        
        do 
        {
            int s, e ;
            int len = strlen(in);
            s = in[ 0 ] - 'a' ;
            e = in[ len-1 ] - 'a';

            sum_len += len;

            if ( cost[ s ][ e ] <= 0 || cost[ s ][ e ] > len ) cost[ s ][ e ] = len ;
            if ( cost[ e ][ s ] <= 0 || cost[ e ][ s ] > len ) cost[ e ][ s ] = len ;
            vertex[ s ] ++ ;
            vertex[ e ] ++ ;            
            
            if ( fscanf(fp, "%s", in) != 1 )
                return ;
            
        } while ( strcmp( in, "deadend") != 0 );
        
        int odd1=-1, odd2=-1;
        for ( int i = 0 ; i < 26 ; i ++)
            if ( vertex[ i ] % 2 == 1 )
            {
                if ( odd1 < 0 ) 
                {
                    odd1 = i;
                }
                else 
                {
                    odd2 = i ;
                    break;
                }
            }
        
        if ( odd2 >= 0  )
        {
            int s, e, m ;
            for ( m = 0 ; m < 26 ; m ++ )
            for ( s = 0 ; s < 26 ; s ++ )
            if ( cost[ s ][ m ] > 0 )
            {
                for ( e = 0 ; e < 26 ; e ++ )
                if ( cost[ m ][ e ] > 0 )
                {
                    if ( cost[ s ][ e ] == 0 || cost [ s ][ e ] > cost[s][m] + cost[m][e] )
                        cost[s][e] = cost[s][m] + cost[m][e];
                }
            }
            
            sum_len += cost[odd1][odd2];
        }
        
        printf("%d\n", sum_len);
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
