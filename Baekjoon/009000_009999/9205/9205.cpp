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
//template <typename T> ll DIST(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DIST(pair<T,T>  a) {return abs(a.first) + abs(a.second);}

void init(){}

void process(int Case) {
    int N, i, j ;
    cin >> N ;
    N +=2 ;
    vector<pii> A(N);
    vector<vector<int>> C(N);
    vector<bool> D(N, false);

    for(auto &p: A) cin >> p;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = i+1 ; j < N ; j ++ ) {
            if ( DIST(A[i] - A[j]) > 1000 ) continue;
            C[i].push_back(j);
            C[j].push_back(i);
        }
    }

    queue<int> Q;
    Q.push(0);
    D[0] = true;
    while ( !Q.empty() ) {
        auto curr = Q.front();
        Q.pop();
        for ( auto nxt: C[curr] ) {
            if ( D[nxt] ) continue;
            D[nxt] = true;
            Q.push(nxt);
        }
    }
    if ( D[N-1] ) cout << "happy\n";
    else cout << "sad\n";
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
