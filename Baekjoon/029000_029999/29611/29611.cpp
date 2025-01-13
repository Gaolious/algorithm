#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

void init(){
}
pll F(ll b, ll k) {
    ld l = pow(10, (ld)(k-1) / b) ;
    ld r = pow(10, (ld)(k) / b) ;
    pll ret = { (ll)ceil(l), (ll)ceil(r) - 1 };
    return ret;
}
void process(int Case) {
    int K ;
    cin >> K;

    ll ans = 0 ;
    for ( ll b = 1; ; b ++ ) {
        auto [l, r] = F(b, K);
        if ( r < 2 ) break;
        l = max(2ll, l);
        if ( l <= r ) ans += r - l + 1;
    }
    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
