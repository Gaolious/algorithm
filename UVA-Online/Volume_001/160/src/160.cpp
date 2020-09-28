#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <queue>

void process(FILE *fp)
{
    int prime_list[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    int N ;
    int i, j ;

    while ( fscanf(fp, "%d ", &N) == 1 && N > 0 )
    {
        int multiplies[] = {
            0, 
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
            11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
            21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
            31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
            51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 
            61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 
            71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
            81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
            91, 92, 93, 94, 95, 96, 97, 98, 99, 100,             
        };
        int primes[ sizeof(prime_list) / sizeof(int) ] = {0,};
        int max_prime_index = -1 ;

        for ( i = 0 ; i < sizeof(prime_list) / sizeof(int) && prime_list[ i ] <= N ; i ++ )
        {
            for ( j = 2 ; j <= N ; j ++ )
            if ( multiplies[ j ]  > 1 &&  multiplies[ j ] % prime_list[ i ]  == 0 )
            {
                if ( i > max_prime_index ) max_prime_index = i ;
                primes[ i ] ++;
                multiplies[ j ] /= prime_list[ i ] ;
                j --;
                continue;
            }
        }
        
        char p[1024]={0,};

        sprintf(p, "%3d! =", N );

        printf("%s", p);
        for ( i = 0 ; i <= max_prime_index ; i ++ )
        {
            printf("%3d", primes[ i ] );
            if ( i < max_prime_index && ( i + 1 ) % 15 == 0 ) 
            {
                printf("\n%*s", strlen(p), "");
            }
        }
        printf("\n");
    }

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