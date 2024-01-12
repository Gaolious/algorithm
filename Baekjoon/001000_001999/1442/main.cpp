#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll D[2][2][2][2][33];

ll F(ll N, ll sumN, ll nth, ll a, ll b, bool zero_padding) {
    int k;
    if ( sumN > N || nth < 0 || ( a!=b && nth < 1 ))
        return 0;
    bool enough = N - sumN > ( 1ll << (nth+1) ) ;
    ll &ret = D[zero_padding][enough][a][b][nth];
    if (ret < 0)
    {
        ret = 0 ;
        for ( ll i = 0 ; i <= 1 ; i ++ ) {
            ll t = i << nth;
            if ( sumN + t > N ) continue;

            if ( sumN > 0 && a == b && b == i )
            {
                ll cnt = min( N - sumN - t + 1, 1ll << nth);
                ret += cnt;
            }
            else
                ret += F(N, sumN + t, nth-1, b, i, zero_padding && a == 0 );
        }
    }
//    cout << "N = " << N << " / sumN = " << sumN << " / padding = " << zero_padding << " || ";
//    for ( k = 6 ; k > nth+2 ; k -- )
//        cout << ( ( 1<<k) & sumN ? 1 : 0 ) << ' ';
//    cout << a << ' ' << b << " ";
//    for ( k = nth ; k >= 0 ; k -- ) cout << "* ";
//    cout << " : " << ret  << '\n';
    return ret;
}

int main()
{
    fastio;
    ll l, r;
    cin >> l >> r ;

    memset(D, -1, sizeof(D));
    r = F(r, 0, 33, 0, 0, true) ;
    memset(D, -1, sizeof(D));
    l = F(l-1, 0, 33, 0, 0, true) ;

    cout << max(0ll, r - l) << '\n';
    return 0;
}


