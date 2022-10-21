#include <bits/stdc++.h>
using namespace std;

#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

typedef long long int ll ;
const long long int MOD = 1'000'000'007;
template <typename T> inline T ModPow(T a, T n, T m) {
    a %= m ;
    T r  ;
    for ( r=1 ; n > 0 ; n /= 2 ) {
        if ( n % 2 == 1 )
            r = (r*a) % m ;
        a = (a*a) % m;
    }
    return r ;
}

void process() {
    fastio;
    int M ;
    ll n, s;
    ll ret = 0;
    cin >> M ;

    while ( M -- ) {
        cin >> n >> s ;
        ret = ( ret + s * ModPow(n, MOD-2, MOD)) % MOD;
    }
    cout << ret << endl;
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


