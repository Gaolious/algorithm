#include <stdio.h>
#include <ctime>

void process() {
    long long int n, r, s, t ;

    fscanf(stdin, "%lld ", &n);
    for ( s = 1, t = 1 ; n/t >= 10 ; t *= 10 )
        s = s*10 + 1;

    for ( r = 0, t = 1 ; n/t > 0 ; t *= 10 )
        r += s * ( (n/t)%10 );

    printf("%lld\n", r);
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t;
    t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


