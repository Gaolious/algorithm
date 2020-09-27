#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (32)
int StampPrice[MAX_N+1]={0,};
int check[MAX_N+1]={0,};
int nStampPrice = 0 ;

int h, k;
int MaxContinuousSequenceLength = -1 ;
int MaxStampPriceList[MAX_N+1]={0,};
int MaxStampPrice = 0;
void gen_stamp(int start_num)
{
    int i ;
    int j;
    int a ;

    char D[2][1000]={0,};
    int MaxN = -1;
    int continuous_sequence_length = 0 ;

#ifdef AJAVA_DEBUG

    printf("Stamp :\n");
    for ( j = 0 ; j < nStampPrice ; j ++ )
        printf("%2d", StampPrice[j]);
    printf("\n");
#endif
    for ( i = 0 ; i < h ; i ++ )    
    {
        if ( i == 0 )
        {
            for ( j = 0 ; j < nStampPrice ; j ++ )
            {
                D[0][ StampPrice[ j ] ] = 1 ;
                if ( MaxN < StampPrice[ j ] ) 
                    MaxN = StampPrice[ j ] ;        
            }
        }
        else 
        {
            for ( j = 0 ; j < nStampPrice ; j ++ )
            {
                for ( a = MaxN ; a >= 1 ; a -- )
                if ( D[1 - i%2][ a ] )
                {
                    D[i%2][ a ] = 1 ;
                    D[i%2][ a + StampPrice[ j ] ] = 1 ;
                    if ( MaxN < a + StampPrice[ j ] ) 
                        MaxN = a + StampPrice[ j ] ;
                }
            }
        }
#ifdef AJAVA_DEBUG
        for ( j = 0 ; j < 20 ; j ++ )
            printf("%2d", D[i%2][j]);
        printf("\n");
#endif        
    }
    for ( i = 1 ; i <= MaxN && D[1-h%2][ i ] == 1 ; i ++ )
        continuous_sequence_length ++;

    if ( MaxContinuousSequenceLength < continuous_sequence_length )
    {
        MaxContinuousSequenceLength = continuous_sequence_length ;
        for ( i = 0 ; i < nStampPrice ; i ++ )
            MaxStampPriceList[i] = StampPrice[ i ] ;
        MaxStampPrice = nStampPrice ;
    }

    // if ( MaxContinuousSequenceLength > 0 )
    // {
    //     if ( start_num < MaxContinuousSequenceLength - 1 )
    //         start_num = MaxContinuousSequenceLength - 1;
    // }
    if ( continuous_sequence_length < 1 && start_num != 1 ) return ;

    for ( i = start_num ; i <= MAX_N && nStampPrice < k ; i ++ )
    if ( check[ i ] == 0 )
    {
        check[ i ] = 1 ;
        StampPrice[ nStampPrice++ ] = i ;

        gen_stamp(i+1);

        StampPrice[ --nStampPrice ] = 0;
        check[i] = 0 ;
    }

}

void process()
{
    while ( scanf("%d %d ", &h, &k) == 2 )
    {
        if ( h == 0 && k == 0 ) break;

        memset(StampPrice, 0x00, sizeof(StampPrice));
        memset(check, 0x00, sizeof(check));
        nStampPrice = 0;
        MaxContinuousSequenceLength = -1 ;
        memset(MaxStampPriceList, 0x00, sizeof(MaxStampPriceList));
        MaxStampPrice = 0;
        gen_stamp(1);

        for ( int i = 0 ; i < MaxStampPrice ; i ++ )
            printf("%3d", MaxStampPriceList[ i ] );
        printf(" ->%3d\n", MaxContinuousSequenceLength);
    }
}
int main() 
{
    process();     

    return 0;
}

