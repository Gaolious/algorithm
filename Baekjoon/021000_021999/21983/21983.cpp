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
void process(int Case) {
    ld N;
    cin >> N ;
    cout << setprecision(12) << fixed << 6*sqrt(N*2/(3*sqrt(3))) << '\n';
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
