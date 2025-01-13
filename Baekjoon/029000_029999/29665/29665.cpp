#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){}

pair<ll, ll> eGCD(ll a, ll b) {
    // a*x + b*y = gcd(a,b)
    // ret : x, y
    if (b == 0) return { 1, 0 };
    auto t = eGCD(b, a%b);
    return { t.second, t.first - t.second*(a / b) };
}
ll inverse(ll a, ll m) {
    auto [x, y] = eGCD(a, m);
    return (x+m)%m;
}
ll comb(ll n, ll k, ll m) {
    if ( n < k ) return 0;
    ll ret = 1, i, j , cnt=0;
    for ( i = k+1 ; i <= n ; i ++ ) {
        for ( j = i ; j % m == 0 ; j/=m, cnt++);
        ret = ret * j % m ;
    }
    for ( i = 1 ; i <= n-k ; i ++ ) {
        for ( j = i ; j % m == 0 ; j/=m, cnt--);
        ret = ret * inverse(j, m) % m ;
    }
    if (cnt > 0)
        ret = 0;
    return ret;
}
void process(int Case) {
    ll N, K, M;
    cin >> N >> K >> M ;

    cout << comb(N-K+1, K, M) << '\n';
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
