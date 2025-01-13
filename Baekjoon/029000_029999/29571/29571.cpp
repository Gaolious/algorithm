#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}

void init(){
}
ll V(ll n) {
    return n * ( n + 1 ) / 2 * ( n + 2 ) / 3;
}
void process(int Case) {
    ll n;
    cin >> n ;
    ll l, r, t, vr;
    for ( l=0, r = 0 ; r < 45000 ; r ++ ) {
        vr = V(r);
        t = vr - V(l);
        while ( l + 1 < r && t > n ) {
            l ++;
            t = vr - V(l);
        }

        if ( t == n) {
            if ( r > 0 && l == 0 ) {}
            else {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";

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
