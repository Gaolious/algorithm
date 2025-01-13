#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
istream &operator >>(istream &in, pll &a) {in >> a.first >> a.second; return in;}
ostream &operator <<(ostream &out, pll &a) {out << a.first << ' ' << a.second; return out;}
pll operator - (pll a, pll b){return {a.first-b.first, a.second-b.second};}
pll operator + (pll a, pll b){return {a.first+b.first, a.second+b.second};}
pll operator / (pll a, ll n){return {a.first/n, a.second/n};}
pll operator * (pll a, ld b){return {a.first*b, a.second*b};}

vector<pii> POS = { {0,1}, {0,2}, {1,2} };
void init(){
}
ll sign(ll v) {
    if (v < 0 ) return -1;
    if ( v > 0 ) return 1;
    return 0;
}
ll ccw(pll a, pll b, pll c) {
     return sign( (c.second - a.second) * (b.first - a.first) - (b.second - a.second) * (c.first - a.first));
}
bool is_on_segment(pll p, pll q1, pll q2) {
    return min(q1.first, q2.first) <= p.first && p.first <= max(q1.first, q2.first) &&
            min(q1.second, q2.second) <= p.second && p.second <= max(q1.second, q2.second) ;
}
bool line_intersect(pll p1, pll p2, pll q1, pll q2) {

    auto d1 = ccw(p1, q1, q2);
    auto d2 = ccw(p2, q1, q2);
    auto d3 = ccw(p1, p2, q1);
    auto d4 = ccw(p1, p2, q2);

    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;

    if (d1 == 0 && is_on_segment(p1, q1, q2) ) return true;
    if (d2 == 0 && is_on_segment(p2, q1, q2) ) return true;
    if (d3 == 0 && is_on_segment(q1, p1, p2) ) return true;
    if (d4 == 0 && is_on_segment(q2, p1, p2) ) return true;

    return false;
}
struct Triangle {
    pll p[3];
    Triangle extend() {
        Triangle ret;
        pll m;
        int k;
        for ( auto [i,j] : POS ) {
            k = 3 - i - j ;
            ret.p[k] = p[i] + p[j] - p[k];
        }
        return ret;
    }
    ll minX() {
        return min(p[0].first, min(p[1].first, p[2].first));
    }
    ll maxX() {
        return max(p[0].first, max(p[1].first, p[2].first));
    }
    ll minY() {
        return min(p[0].second, min(p[1].second, p[2].second));
    }
    ll maxY() {
        return max(p[0].second, max(p[1].second, p[2].second));
    }
    bool inside(pll pt){
        auto a = ccw(pt, p[0], p[1]);
        auto b = ccw(pt, p[1], p[2]);
        auto c = ccw(pt, p[2], p[0]);
        if ( a == b && b == c ) return true;
        return false;
    }
    bool intersect( Triangle &o) {
        int i, j ;
        if ( this->minX() > o.maxX() ) return false ;
        if ( this->minY() > o.maxY() ) return false ;
        if ( this->maxX() < o.minX() ) return false ;
        if ( this->maxY() < o.minY() ) return false ;

        for ( i = 0 ; i < 3 ; i ++ ) {
            if (this->inside(o.p[i]))
                return true;
            if (o.inside(p[i])) {
                return true;
            }
        }
        for ( i = 0 ; i < 3 ; i ++ )
            for ( j = 0 ; j < 3 ; j ++ )
                if (line_intersect(p[i], p[(i+1)%3], o.p[j], o.p[(j+1)%3]))
                    return true;
        return false;
    }
};

istream &operator >>(istream &in, Triangle &t) {
    for ( int i = 0 ; i < 3 ; i ++ ) cin >> t.p[ i ] ;
    return in;
}
ostream &operator << (ostream &out, Triangle &t) {
    for ( int i = 0 ; i < 3 ; i ++ ) out << t.p[ i ] << ' ';
    return out;
}
void process(int Case) {
    int N, i, j, cnt = 0 ;
    ll a, b;

    cin >> N;
    assert(2 <= N && N <= 50);
    vector<Triangle> A(N);
    for (auto &t: A) {
        for ( i = 0 ; i < 3 ; i ++ ) {
            cin >> a >> b ;
            assert( -100000000 <= a && a <= 100000000);
            assert( -100000000 <= b && b <= 100000000);
            t.p[i] = {a, b};
        }
    }

    cnt = 0 ;
    while(true) {
        for ( i = 0 ; i < N ; i ++ ) {
            for (j = i + 1; j < N; j++) {
                if (A[i].intersect(A[j])) {
                    cout << cnt << '\n';
                    return;
                }
            }
        }

        for ( i = 0 ; i < N ; i ++ ) {
            auto t = A[i].extend();
//            cout << t << "\n";
            A[i] = t;
        }
        cnt++;
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
