// 111. History Grading

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 
 * 
 * 3 1 2 4 5 
 * 2 1 4 3 5 
 * 3 1 2 4 5 

 * Order = { 3, 1, 2, 4, 5 }
 * Data  = { 2, 1, 4, 3, 5 }
 * 
 * Data[0]=2. Order[0] =3
 * Data[1]=1. Order[1] =1
 * Data[2]=4. Order[2] =2
 * Data[3]=3. Order[3] =4
 * Data[4]=5. Order[4] =5
 * 
 * Inverse[ Data[0]=2 ] = Order[0]=3
 * Inverse[ Data[1]=1 ] = Order[1]=1
 * Inverse[ Data[2]=4 ] = Order[2]=2
 * Inverse[ Data[3]=3 ] = Order[3]=4
 * Inverse[ Data[4]=5 ] = Order[4]=5
 * 
 * Inverse = { 1, 3, 4, 2, 5 } increase sequence : 1, 3, 4, 5 => 4
 */

#define IS_NUMBER(a) ( '0' <= (a) && (a) <= '9' )

int get_score_by_longest_rank( int n, int order[], int data[] )
{
    int order_index [ 21 ] ={0,};
    int lcs[21][21]={0,};
    
    int i, j ;
    
    for ( i = 0 ; i < n ; i ++)
        order_index[ data[ i ] - 1 ] = order [ i ] ;
    
#ifndef ONLINE_JUDGE 
    printf("order   data : ");
    for ( i = 0 ; i < n ; i ++ )
        printf("%5d", order[i ]);
    printf("\n");
    printf("        data : ");
    for ( i = 0 ; i < n ; i ++ )
        printf("%5d", data[i ]);
    printf("\n");
    printf("inverse data : ");
    for ( i = 0 ; i < n ; i ++ )
        printf("%5d", order_index[i ]);
    printf("\n");
#endif
    for ( i = 0 ; i < n ; i ++ )
    {
        for ( j = 0 ; j < n ; j ++ )
        {
            int left, top, leftop;
            
            left = j >0 ? lcs[i][j-1] : 0;
            top = i > 0 ? lcs[i-1][j] : 0;
            leftop = i>0 && j>0 ? lcs[i-1][j-1] : 0;
            
            if ( order_index[ j ] == i + 1)
                lcs[i][j] = leftop + 1 ;
            else
                lcs[i][j] = left > top ? left : top ;
            
#ifndef ONLINE_JUDGE 
            printf("%3d", lcs[i][j] );
#endif
        }
#ifndef ONLINE_JUDGE         
        printf("\n");
#endif
    }
    
    return lcs[n-1][n-1];
}

int string_to_integer_array( char str[], int arr[] )
{
    int idx = 0 ;
    int i ;
    
    arr[ idx ] = 0 ;
    
    for ( i = 0 ; str[ i ] != 0x00 ; i ++ )
    {
        if ( IS_NUMBER( str[i] ) )
        {
            arr[ idx ] = arr[ idx ] * 10 + str[i] - '0' ;
        }
        else
        {
            idx ++;
            arr[ idx ] = 0;
            
            while ( str[i+1] != 0x00 && ! IS_NUMBER( str[i+1] ) )
                i++;
        }
    }
    
    return idx;
}

void process( FILE *fp )
{
    char in[10000]={0,};
    int n;
    int i;
    int order[20]={0,};
    int data[20]={0,};
    
    while ( !feof(fp) )
    {
        in[0] = 0x00;
        
        fgets( in, sizeof(in)-1, fp );

        int ret = string_to_integer_array( in, data ) ;
        
        if ( ret == 1 )
        {
            n = data[ 0 ];
            
            fgets( in, sizeof(in)-1, fp );
            string_to_integer_array( in, order );
        }
        else if ( ret == n )
        {
            int l = get_score_by_longest_rank( n, order, data);
            
            printf("%d\n", l);
        }
        else
            break;
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
