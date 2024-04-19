#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MAXN (100000)
ll N, M, A;
vector<ll> S;

bool F(ll skill) {
    ll s = 0, l, r, m, ans;
    for ( ll i = 0 ; i < M && s < A; i ++ ) {
        l = 0, r = (ll)S.size() - 1;
        ans = 0;
        while ( l <= r ) {
            m = l + r >> 1 ;
            if ( S[m] <= skill ) {
                ans = max(ans, S[m]);
                l = m + 1 ;
            }
            else {
                r = m - 1 ;
            }
        }
        s += ans;
        skill += ans;
    }
    return s >= A;
}
int main()
{
    fastio;
    ll l, r, m ;

    cin >> N >> M >> A ;
    S.resize(N);
    for(auto &s: S) cin >> s ;

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());

    for ( l = 1 ; l <= 5 ; l ++ ) {
        cout << "F(" << l << ") = " << F(l) << '\n';
    }
    l = 1, r = 10000000000ll;
    ll ans = r;
    while ( l <= r ) {
        m = l+r >> 1;
        if ( F(m) ) {
            ans = min(ans, m);
            r = m - 1 ;
        }
        else l = m + 1;
    }

    cout << ans << '\n';

    return 0;
}


