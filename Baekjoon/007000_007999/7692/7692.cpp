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
    ll G, N;
    int i, j, k;

    while ( cin >> G >> N  && ( G != 0 || N != 0 )) {
        vector A(G, vector<ll>(N+1));
        vector Idx( G, 1);
        vector Drop(N+1, false);
        for (auto &row : A) {
            for ( auto &n: row) cin >> n ;
        }
        for ( k = 1 ; k < N ; k ++ ) {
            vector<ll> S(N+1, 0);
            for ( i = 0 ; i < G ; i ++ ) {
                while ( Idx[i] < A[i].size() && Drop[ A[i][ Idx[i] ] ] ) Idx[i]++;

                if ( Idx[i] < A[i].size() )
                    S[A[i][Idx[i]]] += A[i][0];
            }

            int dropIndex = -1;
            for ( i = 1 ; i <= N ; i ++ ) {
                if ( Drop[i] ) continue;
                if ( dropIndex < 0 || S[ dropIndex ] > S[ i ] ) dropIndex = i;
                else if ( S[ dropIndex ] == S[ i ] && dropIndex < i) dropIndex = i;
            }
            Drop[ dropIndex ] = true;
//            cout << "Round " << k << '\n';
//            for ( i = 1 ; i <= N ; i ++ ) {
//                cout << "\tno " << i << " : " << S[ i ] << '\n';
//            }
//            cout << "\t Drop : " << dropIndex << '\n';
        }
        for ( i = 1 ; i <= N ; i ++ )
            if ( !Drop[i] ) {
                cout << i << '\n';
                break;
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
