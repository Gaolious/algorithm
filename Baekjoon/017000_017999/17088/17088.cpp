#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll N ;
vector<ll> A;

ll F(ll d1, ll d2) {
    ll i, j, t, r;
    ll cnt = -1;

    if ( (A[N-1] - A[0]) % (N-1) == 0 ) {
        cnt = abs(d1) + abs(d2);

        r = (A[N-1] - A[0]) / (N-1) ;
        for ( i = 1 ; i < N - 1 ; i ++ ) {
            t = abs( A[0] + r*i - A[i] ) ;

            if ( t > 1 ) return -1;
            cnt += t;
        }
    }

    return cnt;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int r, i, t ;
    cin >> N ;
    A.resize(N);
    for (auto &a: A) cin >> a ;

    ll ans = -1, cnt;
    if ( N == 1 ) {
        cout << "0\n";
        return 0;
    }
    for ( auto d1 : {-1, 0, 1 }) {
        for ( auto d2 : {-1, 0, 1 }) {

            A[N-1] += d2;
            A[0] += d1;

            cnt = F(d1, d2);

            if ( cnt >= 0 && ( ans < 0 || ans > cnt ) )
                ans = cnt;

            A[0] -= d1;
            A[N-1] -= d2;
        }
    }

    cout << ans;
    return 0;
}


