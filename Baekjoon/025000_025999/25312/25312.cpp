#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
pll operator+(pll a, pll b) {
    pll ret = { a.first*b.second + a.second*b.first, a.second*b.second };
    auto g = gcd(ret.first, ret.second);
    return {ret.first/g, ret.second/g};
}
pll operator*(pll a, ll n) {
    pll ret = { a.first *n, a.second};
    auto g = gcd(ret.first, ret.second);
    return {ret.first/g, ret.second/g};
}
void init(){
}
void process(int Case) {
    ll N, M ;
    cin >> N >> M ;
    vector<pll> A(N);
    for( auto &[x, y]: A) cin >> y >> x;
    std::sort(A.begin(), A.end(), [](pll a, pll b) {
        return a.first*b.second - a.second*b.first > 0;
    });
    pll ret = {0, 1};
    for (auto a: A) {
        ll t = min(a.second, M);
        ret = ret + a * t;
        M -= t;
        if ( M < 1 ) break;
    }
    cout << ret.first << '/' << ret.second << '\n';
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
