// 120 Stacks of Flapjacks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**

 */


int cmp( const void *a, const void *b )
{
    if ( *(int *)a < *(int *)b ) return -1;
    else if ( *(int *)a > *(int *)b ) return 1;
    return 0;
}
void flip( int *seq, int size )
{
    for ( int i = 0 ; i <= size/2 ; i ++ )
    {
        int t = seq[i] ;
        seq[i] = seq[size-i];
        seq[size-i] = t;
    }
}
void process( FILE *fp )
{
    while ( !feof(fp) )
    {
        int order[101]={0,};
        int stack[101]={0,};
        int seq[101]={0,};
        int n =0;
        int c, i, j ;
        int nOrder = 0 ;
        
        while ( !feof(fp) && ( c = fgetc(fp) ) != '\n' )
        {
            if ( '0' <= c && c <= '9' )
                stack[n] = stack[n] * 10 + c - '0';
            else if ( stack[ n ] > 0 ) 
                n++;
        }
        if ( stack[n] > 0 ) n++;
        if ( n < 1 ) continue;
        for ( i = 0 ; i < n ; i ++ )
            seq[ i ] = stack[ i ] ;
        
        qsort(seq, n, sizeof(int), cmp );
        
        for ( c = 0 ; c < n ; c ++ ) printf("%d ", stack[ c ] ); printf("\n");
        
        for ( i = n-1 ; i >= 0 ; i -- )
        {
            if ( seq[ i ] == stack[ i ] ) continue ;
            
            for ( j = i-1 ; j >= 0 ; j -- )
            if ( seq[ i ] == stack[ j ] )
            {
                if ( j > 0  )
                {
                    printf("%d ", n-j);
                    //printf("\n");for ( c = 0 ; c < n ; c ++ ) printf("%d ", stack[ c ] ); printf("\t");
                    flip( stack, j);
                    //for ( c = 0 ; c < n ; c ++ ) printf("%d ", stack[ c ] ); printf("\n");
                }
                printf("%d ", n-i);
                //printf("\n");for ( c = 0 ; c < n ; c ++ ) printf("%d ", stack[ c ] ); printf("\t");
                flip( stack, i);
                //for ( c = 0 ; c < n ; c ++ ) printf("%d ", stack[ c ] ); printf("\n");
                break;
            }
        }
        
        printf("0\n");
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
