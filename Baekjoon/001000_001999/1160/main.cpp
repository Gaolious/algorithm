#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
//#define ADD(x, y, m) ( ( (x) + (y) ) % (m) )
//#define MUL(x, y, m) ( ( (x) * (y) ) % (m) )

ll ADD(ll a, ll b, ll m) {
    __int128 ret = ( (__int128)a + (__int128)b ) % (__int128)m;
    return (ll)ret;
}
ll MUL(ll a, ll b, ll m) {
    __int128 ret = (__int128)a * (__int128)b % (__int128)m;
    return (ll)ret;
}
ll POW(ll r, ll n, ll m) {
    ll a, b;
    if ( n == 0 ) a=b=1;
    else if ( n % 2 == 0 )
        a = b = POW(r, n/2, m);
    else
        a = r, b = POW(r, n-1, m);
    return MUL(a, b, m);
}

ll series(ll r, ll k, ll m) {
    ll ret ;
    if ( k == 0 ) {
        return 0;
    } else if ( k == 1 ) {
        return 1;
    } else if ( k % 2 == 0 ) {
        ll t = ( 1 + POW(r, k/2, m) ) % m ;
        ret = MUL(t, series(r, k/2, m), m);
    } else {
        ll t = POW(r, k-1, m);
        ret = ADD(t, series(r, k-1, m), m);
    }
    return ret;
}

ll series(ll a, ll r, ll k, ll m) {
    // a*r^0 + a*r^1 + a*r^2 + ... a*r^k + a*r^(k+1) + a*r^(k+2) + ...
    // a*r^0 + a*r^1 + a*r^2 + ... a*r^k * ( a*r^0 + a*r^1 + a*r^2 )
    return MUL(a, series(r, k, m), m);
}

int main()
{
    fastio;
    ll m, a, c, x0, n, g ;
    cin >> m >> a >> c >> x0 >> n >> g;

    ll first = MUL(x0, POW(a, n, m), m);
    ll second = series(c, a, n, m);
    ll ans = ADD(first, second, m);
    cout << ans % g  << '\n';
    return 0;
}


