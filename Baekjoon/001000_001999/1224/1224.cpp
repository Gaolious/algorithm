#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pair<pll, pll> findFraction(ll A, ll B, ll C) {
    pll L={0, 1}, R={1, 1};
    pair<pll, pll> ret = {L, R};
    ll l, r, m, ans;
    if ( A == 0 ) {
        return {L, L};
    }
    if ( B <= C ) {
        L = R = {A,B};
        return {L, R};
    }
    while (L.second <= C && R.second <= C ) {
        pll M = {L.first + R.first , L.second + R.second };
        if (M.second > C )
            return {L, R};

        ll v1 = A * M.second ;
        ll v2 = B * M.first ;

        if ( v1 == v2 )
            return {M, M};

        else if ( v1 > v2 ) {  //  [A/B] > mid.first/mid.second  => right side
            l = 1;
            r = (C - L.second) / R.second ;
            ans = 1;
            while ( l <= r ) {
                m = (l+r)/2;
                v1 = A * (L.second + R.second * m ) ;
                v2 = B * (L.first + R.first * m ) ;
                if ( v1 > v2 ) {
                    ans = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            L = {L.first + R.first * ans , L.second + R.second * ans };
        }
        else { //  [A/B]  <  mid.first/mid.second  =>  left side
            l = 1;
            r = (C - R.second) / L.second ;
            ans = 1;
            while ( l <= r ) {
                m = (l+r)/2;
                v1 = A * (L.second * m + R.second ) ;
                v2 = B * (L.first * m + R.first ) ;
                if ( v1 < v2 ) {
                    ans = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            R = {L.first * ans + R.first , L.second * ans + R.second };
        }
    }

    return ret;
}
void process(int Case) {
    ll a, b, c;
    cin >> a >> b >> c;
//    auto g = gcd(a, b);
    auto [L, R] = findFraction(a, b, c);
    cout << L.first << ' ' << L.second << ' ' << R.first << ' ' << R.second << "\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
