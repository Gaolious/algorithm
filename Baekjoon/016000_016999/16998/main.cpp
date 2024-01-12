#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll S(ll n) {
    return n * ( n + 1 ) / 2;
}
ll F(ll p, ll q, ll n) {
    ll ret = 0 ;
    if ( p > 0 ) {
        if ( p >= q ) {
            ret = S(n) * ( p / q );
            ret += F( p % q , q, n);
        } else {
            ret = n * ( p * n / q ) + n / q;
            ret -= F(q, p, p*n/q);
        }
    }
    return ret;
}
void process() {
    fastio;
    ll w, n, p, q;

    cin >> w ;
    while ( w-- ) {
        cin >> p >> q >> n;
        ll g = gcd(p, q);
        cout << S(n) * p - q * F(p/g, q/g, n) << '\n';
    }
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


