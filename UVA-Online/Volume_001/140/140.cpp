/*
 140 - Bandwidth
 DFS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_CHAR(a) ( 'A' <= (a) && (a) <= 'Z' )
#define INDEX(a) ( (a) - 'A' )
#define IS_COLON(a) ( (a) == ':' )
#define IS_SEMICOLON(a) ( (a) == ';' )


int nNodes = 0 ;
int Nodes['Z'-'A'+1] = {0, };   // stack of input
int ConnectMap['Z'-'A'+1]['Z'-'A'+1] = {0, }; // connected map
int MinDistance = 0 ;

int sequence[26+1]={0,};
int check[26+1]={0,};

int min_sequence[ 26+1 ]={0, };

void print(int currIndex, int dist)
{
    for (int i = 0 ; i < currIndex ; i ++)
        printf("%c ", 'A' + sequence[i] ) ;
    printf(" : %d\n", dist);
}

void process(int currIndex, int dist)
{
    if ( currIndex >= nNodes )
    {
        if ( MinDistance == 0 || MinDistance > dist )
        {
            MinDistance = dist ;
            memcpy( min_sequence, sequence, sizeof(sequence[0]) * nNodes );
        }
        return ;
    }
    
    for ( int i = 0 ; i < nNodes ; i ++)    
    if ( check[i] == 0 )
    {
        check[i] = 1 ;
        sequence[currIndex] = Nodes[i] ;
        
        int max_dist = dist ;
        for ( int j = 0 ; j < currIndex - max_dist ; j ++ )
        {
            if ( ConnectMap[ sequence[j] ][ sequence[currIndex] ] == 1 )
            {
                if ( max_dist <= 0 || max_dist < currIndex - j )
                    max_dist = currIndex - j;
            }
        }
        
        //print(currIndex+1, max_dist );
        if ( MinDistance == 0 || MinDistance > max_dist )
            process(currIndex + 1, max_dist );
        
        sequence[currIndex] = 0 ;
        check[i] = 0 ; 
    }
}

int comp(const void *a, const void *b)
{
    int l = *(int *)a;
    int r = *(int *)b;
    
    if ( l < r ) return -1;
    else if (l > r ) return 1;
    return 0;
}
void input(FILE *fp)
{
    int ret = 0 ;
    
    while ( 1 )
    {
        int tmp['Z'-'A'+1]={0,};
        char str[10240]={0,};
        char *p = str+0;
        
        fgets(str, sizeof(str)-1, fp);
        if ( str[0] == '#' )
            return;
        
        MinDistance = 0;
        
        nNodes = 0 ;
        memset( Nodes, 0x00, sizeof(Nodes) ) ;
        memset( ConnectMap, 0x00, sizeof(ConnectMap) ) ;
        memset( sequence, 0x00, sizeof(sequence) ) ;
        memset( check, 0x00, sizeof(check) ) ;
        memset( min_sequence, 0x00, sizeof(min_sequence) ) ;
        
        while ( p && *p )
        {
            while ( p &&  *p && !IS_CHAR(*p) ) p++;
            int start_index = INDEX(*p);
            
            if ( tmp[ start_index ] == 0 )
            {
                tmp[ start_index ] = 1;
                Nodes[nNodes++] = start_index;
            }
            
            while ( p &&  *p && !IS_COLON(*p) ) p++;
            while ( p &&  *p && IS_COLON(*p) ) p++;
            
            for ( ; p && *p && !IS_SEMICOLON(*p) ; p ++ )
            if ( IS_CHAR(*p) )
            {
                int neighbor = INDEX(*p);
                //printf("Connect %c %c\n", start_index + 'A', neighbor + 'A');
                ConnectMap[ start_index ][ neighbor ] = 1;
                ConnectMap[ neighbor ][ start_index ] = 1;
                if ( tmp[ neighbor ] == 0 )
                {
                    tmp[ neighbor ] = 1;
                    Nodes[nNodes++] = neighbor;
                }
            }
            while ( p &&  *p && IS_SEMICOLON(*p) ) p++;
        }
        
        qsort(Nodes, nNodes, sizeof(int), comp );
        
        process(0, 0);
        if ( MinDistance > 0 )
        {
            for ( int i = 0 ; i < nNodes ; i ++ )
            {
                if ( i != 0 ) printf(" ");
                printf("%c", 'A' + min_sequence[i] );
            }
            printf(" -> %d\n", MinDistance);
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
    input(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
