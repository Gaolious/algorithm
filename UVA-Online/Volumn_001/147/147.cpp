#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(FILE *fp)
{
    unsigned long long cnt[30001]={1,};
    int coin[11] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
    
    for ( int j = 0 ; j < 11 ; j ++ )
    {
        for ( int i = coin[j] ; i <= 30000 ; i ++ )
            cnt[ i ] += cnt[ i - coin[j] ] ;
    }
        
    int n,f;
    while ( fscanf(fp, "%d.%d ", &n, &f) == 2 )
    {
        if ( n * 100 + f == 0 )
            break;
        printf("%3d.%02d%17lld\n", n, f, cnt[n*100+f]);
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
