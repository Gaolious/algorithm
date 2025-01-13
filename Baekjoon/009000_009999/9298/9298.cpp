#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T>
int DIST(pair<T,T>  a) {
    return abs(a.first) + abs(a.second);
}
void init(){
}
void process(int Case) {
    pdd p, m1, m2;
    int N ;
    cin >> N ;
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> p ;
        if ( i == 0 ) m1 = m2 = p ;
        m1.first = min(m1.first, p.first);
        m1.second = min(m1.second, p.second);
        m2.first = max(m2.first, p.first);
        m2.second = max(m2.second, p.second);
    }
    pdd area = m2-m1;
    cout << "Case " << Case
         << ": Area " << fixed << setprecision(12) << abs(area.first * area.second)
         << ", Perimeter " << fixed << setprecision(12) << 2 * ( abs(area.first) + abs(area.second) ) << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
