#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init() {}
ll N, B, C;
ll Pow(ll a, ll b){
    if ( b == 0 ) return 1;
    auto ret = Pow(a, b/2);
    ret *= ret;
    if ( b%2 ) ret *=a;
    return ret;
}
ll Count(ll n, ll nDigit) {
    ll ret = 0 ;
    for ( ll i = 0 ; i <= n ; i ++ ) {
        if ( i < C )
            ret += Pow(B, nDigit-1) - Pow(C, nDigit-1);
        else
            ret += Pow(B, nDigit-1);
    }
    return ret;
}
void process(int Case) {
    cin >> N >> B >> C ;
    ll k, i, t;
    for (k=1 ; Pow(B, k) - Pow(C, k) < N ; k ++);

    ll ans = 0 ;

    for ( i = k ; i >= 1 ; i -- ) {
        for ( t = 0 ; Count(t, i) < N ; t ++ );
        N -= Count(t-1, i);
        ans += t * Pow(B, i-1);
        if ( t >= C ) {
            ans += N ;
            break;
        }
    }
    cout << ans - 1 << '\n';
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
