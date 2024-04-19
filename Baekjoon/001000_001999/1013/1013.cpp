#include <stdio.h>


void process(FILE *fp)
{
    const int F = 8 ;
    int MATA[ 2 ][ F +1 ]={
            //    0  1  2  3  4  5  6  7
            { 1, F, 3, 4, 4, 1, 7, 4, F},
            { 2, 0, F, F, 5, 6, 6, 0, F}
            // { 1, F, 3, 4, 4, 1, 7, 3, F},
            // { 2, 0, F, F, 5, 6, 6, 1, F},
    };
    /*
        100111010101010101100111100111100111
        1023445
    */
    int T ;

    fscanf(fp, "%d ", &T);

    while ( T -- )
    {
        char str[200+1]={0,};
        int idx, i ;
        fscanf(fp, "%s ", str ) ;
        //printf("%s\n", str);
        for ( idx = 0, i = 0 ; str[i] && idx != F; i ++ )
        {
            idx = MATA[ str[i]-'0' ][ idx ] ;
            //printf("%d", idx);
        }
        //printf("\n");

        if ( idx == 5 || idx == 6 || idx == 0 )
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    FILE *fp = fopen("input/input.txt", "rt");
#else
    FILE *fp = stdin ;
#endif

    process(fp);

#ifndef ONLINE_JUDGE
    if (fp) fclose(fp);
    fflush(stdout);
    fflush(stdin);
    getchar();
#else
#endif
    return 0;
}