#include <bits/stdc++.h>

void process() {
    long long int N;
    long long int cnt ;
    fscanf(stdin,"%lld", &N);
    for ( cnt = 1 ; N != 1 ; cnt ++ )
    {
        if ( N % 2 == 0 ) {
            N /= 2;
        } else {
            cnt ++;
            N = ( N * 3 + 1 ) / 2;
        }
    }
    printf("%lld\n", cnt);
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


