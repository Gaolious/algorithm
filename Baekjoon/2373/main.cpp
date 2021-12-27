#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
typedef long long int ll ;

vector<ll> F;
int lower(int l, int r, ll v) {
    int m, ret = 0 ;
    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        if ( F[m] == v ) return m;
        if ( F[m] < v ) {
            ret = m ;
            l = m + 1 ;
        }
        else {
            r = m - 1 ;
        }
    }
    return ret ;
}

ll ans(ll N, int nF) {
    if ( N < 2 ) return -1;

    ll ret = lower(0, nF, N);
    if ( F[ret] == N ) {
        return -1;
    }
    else {
        ll v = ans(N - F[ret], nF);
        return ( v < 0 ) ? N - F[ret] : v ;
    }
}
void process() {
    ll N;
    int i;
    F.push_back(2);
    F.push_back(3);
    for ( i = 2 ; F[i-1] + F[i-2] <= 1000000000000000 ; i ++ )
        F.push_back(F[i-1] + F[i-2]);

    scanf("%lld ", &N);
    ll ret = ans(N, F.size()-1) ;
    printf("%lld\n", ret < 0 ? N : ret );

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


