#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 1'000'000'007;

ll G(ll startN, ll M, ll cnt) {
    ll ret = 0;
    if ( startN > 0 ) {
        ll c = min( cnt, (M - startN ));
        ret += (startN-1)*c % MOD + c * (c+1) / 2 % MOD ;
        ret %= MOD ;
        cnt -= c;
    }
    if ( cnt >= M ) {
        ll c = cnt / M ;
        ret += M * (M - 1 ) / 2 % MOD * c % MOD;
        ret %= MOD ;
        cnt %= M ;
    }
    if ( cnt > 1 ) {
        ret += cnt * (cnt - 1 ) / 2 % MOD ;
        ret %= MOD;
    }
    return ret;
}
void process() {
    fastio;
    ll N, M, sN;
    ll i, f, l, r, g, cnt ;
    ll ret = 0;

    cin >> N >> M ;
    sN = sqrt(N);
    for ( i = 1 ; i <= sN ; i ++ ) {
        ret += (N/i) % MOD * (i % M) % MOD;
        ret %= MOD;
    }
    for (l = sN + 1,  f = N / l ; f >= 1 ; f --, l = r + 1 ) {
        r = N / f ;
        g = G(l % M, M, r-l+1);
        ret += f * g % MOD ;
        ret %= MOD ;
    }
    cout << ret << '\n';
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


