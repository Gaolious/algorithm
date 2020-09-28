#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LARGE ( 9999999 )
#define DIV5

void process()
{
// The set of New Zealand coins comprises 5c, 10c, 20c, 50c, $1 and $2.
// Thus if we need to pay 55c, 
// and we do not hold a 50c coin, 
// we could pay this as 2 × 20c + 10c + 5c to make a total of 4 coins. 
// If we tender $1 we will
// receive 45c in change which also involves 4 coins, but if we tender $1.05 ($1 + 5c), 
// we get 50c change and the total number of coins that changes hands is only 3.

// Write a program that will read in the resources available to you and the amount of the purchase
// and will determine the minimum number of coins that change hands.
// 5 10 20 50  1  2
// 2  4  2  2  1  0 0.95
    const int MAX_CHANGE = 100000 ;
    int change[MAX_CHANGE+1]={0,};
    int pay, i, j ;

    int coins[] = {5, 10, 20, 50, 100, 200};
#ifdef DIV5
    for ( i = 0 ; i < 6 ; i ++ ) coins[ i ] /= 5 ;
#endif
    for ( i = 1 ; i <= MAX_CHANGE ; i ++ )
    {
        change[i] = LARGE;

        for ( j = 0 ; j < 6 ; j ++ )
        {
            if ( i < coins[j] ) break;
            if ( change[ i ] > change[ i - coins[j] ] + 1 ) 
                change[ i ] = change[ i - coins[j] ] + 1 ;
        }
    }

    while ( 1 ) 
    {
        int D[MAX_CHANGE]={0,};
        int my_coins[6] = {0,};
        int my_sum = 0 ;
        int  k ;

        for ( i = 0 ; i <6 ; i ++ )
        {
            scanf("%d ", my_coins + i);
            my_sum += coins[ i ] * my_coins[ i ] ;
        }
        scanf("%d.%d", &i, &j);
        pay = i*100 + j ;

        if ( my_sum == 0 ) break;
#ifdef DIV5
        pay /= 5 ;
#endif
        // 5 5 10
        // 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
        //         1         2
        //                   1          1          1
        // 
        for ( i = my_sum ; i >= 1 ; i -- ) 
            D[ i ] = LARGE ;
        
        for ( i = 0 ; i < 6 ; i ++ )
        {
            for ( j = my_sum ; j >= coins[i] ; j -- )
            {
                for ( k = 1 ; k <= my_coins[ i ] && j >= k * coins[ i ] ; k ++ )
                {
                    if ( D[ j ] > D[ j - k * coins[ i ] ] + k )
                    {
                        D[ j ] = D[ j - k * coins[ i ] ] + k ;
                    }
                }
            }
        }
        
        int minimum_coins = LARGE;
        for ( i = my_sum ; i >= pay ; i -- )
        if ( D[ i ] < LARGE )
        {
            if ( D[i] + change[i - pay] < minimum_coins )
                minimum_coins = D[i] + change[i - pay];
        }

        printf("%3d\n", minimum_coins );
    }
}
int main() 
{
    process();     

    return 0;
}

