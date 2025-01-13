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

struct Rect{
    pll s, e;
    void simplify(){
        if ( s.first > e.first ) swap(s.first, e.first);
        if ( s.second > e.second ) swap(s.second, e.second);
    }
    void overlap(Rect &o) {
        s.first = max(s.first, o.s.first);
        s.second = max(s.second, o.s.second);
        e.first = min(e.first, o.e.first);
        e.second = min(e.second, o.e.second);
    }
    ll area() {
        return max(0ll, e.first - s.first) * max(0ll, e.second - s.second );
    }
};
void init(){
}
void process(int Case) {
    Rect A, B, C;
    cin >> A.s >> A.e >> B.s >> B.e;
    A.simplify();
    B.simplify();
    C = A;
    C.overlap(B);
    cout << C.area();
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
