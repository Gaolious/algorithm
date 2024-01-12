#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

const long long int MaxSR = 1000000;
int Cnt[ MaxSR + 1 ]={0,};

unsigned long long int FindK(unsigned long long K) {
    long long int l, r, m, cnt, i, j ;
    r = 100000000000;
    l = 1 ;
    unsigned long long ret = 0 ;
    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        for ( cnt=0, i = 1 ; i * i <= m ; i ++ )
            cnt += ( m / (i*i) ) * Cnt[i] ;

        if ( m - cnt >= K ) {
            ret = m ;
            r = m - 1 ;
        }
        else {
            l = m + 1 ;
        }
    }
    return ret;
}
void process() {
    unsigned long long int i, j, K ;

    fastio;

    Cnt[1] = 1;
    for ( i = 1 ; i <= MaxSR ; i ++ )
        for ( j = i+i ; j <= MaxSR ; j += i )
            Cnt[j] -= Cnt[i];

    cin >> K ;
    cout << FindK(K) << '\n';
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


