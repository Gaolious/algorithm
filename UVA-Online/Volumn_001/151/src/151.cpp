#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int next( int arr[], int N, int m, int sp)
{
    int cnt = 0 ;

    for ( int i = sp ; ; i = i % N + 1 )
    {
        if ( arr[i] > 0 ) cnt ++;

        if ( cnt == m ) return i;
    }
}
void dump(int arr[], int N)
{
    for ( int i = 1 ; i <= N ; i ++)
    {
        if ( arr[i] > 0 )
            printf("%3d", arr[i]);
        else
            printf("  *");
    }
    printf("\n");
}
void solve()
{
    int N, m ;
    int i ;
    for ( int N = 13 ; N < 100 ; N ++ )
    {
        for ( m = 1 ;  ; m ++ )
        {
            int arr[100]={0,};
            for ( i = 1 ; i <= N ; i ++ )
                arr[ i ] = i ;

            int idx = 1;
            int cnt ;
            int removed ;
            int fail = 0;

            for ( removed = 0 ; ;  )
            {
                // printf("remvoed %d\n", idx ) ;
                arr[ idx ] = -1 ;
                // dump(arr, N);
                removed ++;
                if ( removed + 1 == N )
                    break;
                idx = next( arr, N, m, idx ) ;
                if ( idx == 13 )
                {
                    fail = 1;
                    break;
                }
            }
            if ( fail ) 
                continue ;

            printf( "%d,", m );
            if ( N % 10 == 0 ) printf("\n");
            else printf(" ");
            //printf("N=%d, m=%d , last removed : %d : \n", N, m, idx);
            //dump(arr, N);
            break;
        }
    }
}
void process(FILE *fp)
{
    int sol[] = {
        0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 18, 10, 11, 7, 17, 11, 15,
        29, 5, 21, 13, 26, 14, 11, 23, 22, 9,
        73, 17, 42, 7, 98, 15, 61, 22, 84, 24,
        30, 9, 38, 15, 54, 27, 9, 61, 38, 22,
        19, 178, 38, 53, 79, 68, 166, 20, 9, 22,
        7, 21, 72, 133, 41, 10, 82, 92, 64, 129,
        86, 73, 67, 19, 66, 115, 52, 24, 22, 176,
        10, 57, 137, 239, 41, 70, 60, 116, 81, 79,
        55, 102, 49, 5, 22, 54, 52, 113, 15,
    };
    int n ;

    while ( fscanf(fp, "%d ", &n) == 1 && n > 0 )
        printf("%d\n", sol[n]);
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