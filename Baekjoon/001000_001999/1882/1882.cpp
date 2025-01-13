#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll N, K;
const int MaxN = 40'000;

int phi[MaxN+1];
pll gcd(pll a){
    auto g = gcd(a.first, a.second);
    return {a.first/g, a.second/g};
}
pll operator +(pll a, pll b) {
    pll ret= {a.first*b.second + a.second*b.first, a.second*b.second};
    return gcd(ret);
}
pll operator -(pll a, pll b) {
    pll ret= {a.first*b.second - a.second*b.first, a.second*b.second};
    return gcd(ret);
}
pll operator /(pll a, ll b) {
    pll ret = {a.first, a.second * b};
    return gcd(ret);
}
pll operator *(pll a, ll b) {
    pll ret = {a.first * b, a.second};
    return gcd(ret);
}
bool operator <(pll a, pll b) {
    return a.first*b.second < a.second*b.first;
}

pll F(pll L, pll R){
    ll ans = 0;
    auto m = (L+R) / 2 ;
    ll i ;
    for ( i = 1 ; i <= N ; i ++ ) {
        ll cnt = m.first * i / m.second;
        ans += cnt * phi[ i ];
    }
    if ( ans == K ) return m;
    return (K < ans) ? F(L, m) : F(m, R);
}

void process(int Case) {
    ll i, j;

    cin >> N >> K ;
    phi[N]=1;
    for ( i = N-1 ; i > 0 ; i -- ) {
        phi[i] = 1;
        for ( j = 2 ; i * j <= N ; j ++ )
            phi[i] -= phi[i*j];
    }

    pll M = F( {0,1}, {1,1} );
    double best = 1.0;
    double m = (double)M.first / M.second;
    ll a, b;
    for(i = 1 ; i <= N ; i++ ) {
        ll cnt = M.first * i / M.second ;
        double q = (double)cnt / (double)(i);
        if ( m - q < best ) {
            best = m - q;
            a = cnt;
            b = i;
        }

    }
    cout << a << ' ' << b << '\n';
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
