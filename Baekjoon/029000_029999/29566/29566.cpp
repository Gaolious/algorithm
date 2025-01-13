#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using Pt = pair<ld, ld> ;

template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> operator + (pair<T,T> a, pair<T,T> b){return {a.first+b.first, a.second+b.second};}
template <typename T> pair<T,T> operator * (pair<T,T> a, T n){return {a.first * n , a.second * n };}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
template <typename T> T DIST2(pair<T,T> a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DISTm(pair<T,T>  a) {return abs(a.first) + abs(a.second);}
template <typename T> T DIST(pair<T,T> a) {return sqrt(DIST2(a));}

void init(){
}
const ld EPS = 1.0e-12;

bool IsZero(ld v) {
    return abs(v) < EPS;
}
struct Circle {
    Pt p;
    ld r;

    ld dist(Circle &o) {
        return DIST(p-o.p);
    }
    bool intersection(Circle &o, Pt &p1, Pt &p2) {
        auto d = dist(o);
        if ( d > r + o.r ) return false;
        if ( d < abs(r-o.r) ) return false;
        if (IsZero(d) && IsZero(r-o.r) ) return false;

        auto a = (r*r - o.r*o.r + d*d) / (2*d);
        auto h = sqrt(r*r - a*a);

        auto cp = p + ( o.p - p ) * (a / d) ;
        auto diff = (o.p - p) * (h/d);

        p1 = cp + Pt( diff.second, -diff.first );
        p2 = cp + Pt( -diff.second, diff.first );
        return true;
    }
};
void process(int Case) {
    int i;
    Circle A[3];
    Pt p1, p2;

    for ( i = 0 ; i < 3 ; i ++ ) cin >> A[i].p ;
    for ( i = 0 ; i < 3 ; i ++ ) cin >> A[i].r ;

    // circle 3개 가 만나는 지점
    if ( A[0].intersection(A[1], p1, p2) ) {
        if (IsZero( DIST(p1-A[2].p) - A[2].r ) ) {
            cout << setprecision(18) << fixed << p1 << '\n';
            return;
        }
        if (IsZero( DIST(p2-A[2].p) - A[2].r ) ) {
            cout << setprecision(18) << fixed << p2 << '\n';
            return;
        }
    }

    cout << "Impossible" << endl;
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
