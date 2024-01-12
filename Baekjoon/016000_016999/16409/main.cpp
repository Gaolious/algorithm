#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 10'000'000 ;
int mobius [ MaxN + 1] ;

void setMobius() {
    int i, j ;
    mobius[ 1 ] = 1 ;
    for ( i = 1 ; i <= MaxN ; i ++ ) {
        for ( j=i+i ; j<= MaxN ; j += i )
            mobius[j] -= mobius[i];
        mobius[i] += mobius[i-1];
    }
}

ll F(int from, int to) {
    int i, a, b, n;
    ll ret = 0 ;
    for ( i = 1, n = 0 ; i <= from && i <= to ; i = n + 1) {
        a = from / i ;
        b = to / i ;
        n = min( from / a, to / b );
        ret += 1ll * (mobius[n] - mobius[i-1] ) * a * b;
    }
    return ret;
}

void process() {
    fastio;
    int a, b, c, d ;
    ll ret = 0 ;
    setMobius();
    cin >> a >> b >> c >> d;
    ret += F(b, d);
    ret -= F(a-1, d);
    ret -= F(b, c-1);
    ret += F(a-1, c-1);
    cout << ret<< endl ;
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


