// 119 Greedy Gift Givers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * IN : 
 * 5                            • the number of people in the group
 * dave laura owen vick amr     • a list of the names of each person in the group,
 * 
 * dave 200 3 laura owen vick   [name, amount of money spent, # of people to someone, and names, ]
 *                      
 *                              All names are lower-case letters,
 *                              , there are no more than 10 people in a group
 *                              and no name is more than 12 characters in length
 * 
 * 
 * 5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
 * 
 * 
 * dave     -198    +500            = 302
 * owen     66      -500    +75     
 * laura    66      0
 * vick     66      +75
 * amr      0       -150
 * 
 * 
3
liz steve dave
liz 30 1 steve
steve 55 2 liz dave
dave 0 2 steve liz
 * 
 * liz      -30 +27     -3
 * steve    30  -54     -24
 * dave     +27
 * 
dave 302
laura 66
owen -359
vick 141
amr -150
 * 
liz -3
steve -24
dave 27
 * 
 * @param fp
 */

#define MAX_PEOPLE (10)
#define MAX_NAME (12)

void process( FILE *fp )
{
    int n ;
    
    while ( fscanf(fp, "%d ", &n) == 1 )
    {
        char group[ MAX_PEOPLE ][ MAX_NAME + 1 ] ={ 0 ,};
        int points[ MAX_PEOPLE ] ={0,};
        
        int i;
        
        for ( i = 0 ; i < n ; i ++)
            if ( fscanf(fp, "%s ", group[ i ] ) != 1 )
                return ;
        
        for ( i = 0 ; i < n ; i ++ )
        {
            char name[ MAX_NAME + 1 ] = {0,};
            char target[ MAX_NAME + 1 ] = {0,};
            int idx_me, idx_target, amount, number_of_targets ;
            int j;
            
            if ( fscanf(fp, "%s %d %d ", name, &amount, &number_of_targets ) != 3 ) 
                return ;
            
            if ( number_of_targets == 0 ) continue ;
            
            int gifts = ( amount / number_of_targets ) ;
            
            for ( j = 0 ; j < n ; j ++) 
                if ( strcmp( group[ j ], name ) == 0 )
                {
                    points[ j ] -= gifts * number_of_targets;
                    break;
                }

            for ( j = 0 ; j < number_of_targets ; j ++ )
            {
                if ( fscanf( fp, "%s ", target ) != 1 ) 
                    return ;
                
                for ( int t = 0 ; t < n ; t ++ )
                    if ( strcmp( group[ t ], target ) == 0 )
                    {
                        points[ t ] += gifts ;
                        break;
                    }
            }
        }
        
        for ( i = 0 ; i < n ; i ++ )
            printf("%s %d\n", group[ i ], points[ i ] ) ;
        
        if ( !feof(fp) )
            printf("\n");
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
