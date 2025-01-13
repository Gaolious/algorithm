#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
template <typename T> ll DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DISTm(pair<T,T>  a) {return abs(a.first) + abs(a.second);}

void init(){
}
ll lower(ll n) {
    ll l = 0, r = (1ll << 31) - 1 ;
    ll m, ret = 0 ;
    while ( l < r ) {
        m = ( l + r ) / 2;
        if ( m * (m-1) + 1 <= n) {
            ret = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return ret;
}
ll upper(ll n) {
    ll l = 0, r = (1ll << 31) - 1 ;
    ll m, ret = 0 ;
    while ( l < r ) {
        m = ( l + r ) / 2;
        if ( n <= m * (m+1)) {
            ret = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return ret;
}
void process(int Case) {

    ll a, b, len, i, j;
    ll minI, maxI;
    cin >> a >> b ;

    len = b - a ;
    if ( len == 0 ) {
        cout << 0 ;
        return;
    }
    minI = lower(len);
    maxI = upper(len);
    for ( i = minI ; i <= maxI; i ++ ) {
        if ( i * ( i - 1 ) + 1 <= len && len <= i * ( i + 1 ) ) {
            if (len <= i * i)
                cout << i * 2 - 1 << '\n';
            else
                cout << i * 2 << '\n';
            return;
        }
    }
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
