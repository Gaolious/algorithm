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
    int i, j, a, b;
    int Y, X;
    cin >> Y >> X ;
    vector A(10, vector<string>(Y));
    vector M(10, vector<int>(10));

    for ( auto &row : A ) {
        for ( i = 0 ; i < Y ; i ++ )
            cin >> row[i] ;
    }
    for ( i = 0 ; i < 10 ; i ++ ) {
        for ( j = i + 1 ; j < 10 ; j ++ ) {
            for ( a = 0 ; a<Y ; a++){
                for ( b = 0 ; b < X ; b ++ ) {
                    M[i][j] += A[i][a][b] != A[j][a][b];
                    M[j][i] += A[i][a][b] != A[j][a][b];
                }
            }
        }
    }

    ll ans = 0;
    int pH1, pH0, pM1, pM0, h, m;
    pH1=pH0=pM1=pM0=0;
    for ( i = 0 ; i <= 24 ; i ++ ) {
        for ( j = 0 ; j < 60 ; j ++ ) {
            h = i % 24;
            m = j % 60;
            ans += M[pH1][h / 10], pH1 = h / 10;
            ans += M[pH0][h % 10], pH0 = h % 10;
            ans += M[pM1][m / 10], pM1 = m / 10;
            ans += M[pM0][m % 10], pM0 = m % 10;

            if ( i == 24 ) break;
        }
    }

    cout << ans << '\n';
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
