#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

vector<pii> A, C;
int N, D;

void init(){
}
int getDir(pii curr, pii nxt) {
    auto d = nxt - curr;
    return ( d.second == 0 ) ? (d.first > 0 ? 0 : 2) : (d.second > 0 ? 1 : 3);
}
void Extend(){
    int i, d;
    cin >> D >> N ;

    A.resize(N);
    for (auto &p: A) cin >> p;

    vector<int> B(N, 0);
    for ( i = 0 ; i < N ; i ++ ) {
        d = getDir(A[i], A[(i+1)%N]);
        B[i] |= 1 << ( (d+3)%4 );
        B[(i+1)%N] |= 1 << ( (d+3)%4 );
    }
    for ( auto [x,y]: A)
        C.emplace_back(x*10, y*10);
    D *= 10;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( d = 0 ; d < 4 ; d ++ ) {
            if ( B[i] & ( 1 << d ) ) {
                C[i].first += dx[d] * D;
                C[i].second += dy[d] * D;
            }
        }
    }
}
void process(int Case) {
    int d, i, j;

    vector<int> X;
    vector<int> Y;

    Extend();

    for ( auto [x,y]: C) {
        for ( j = -5 ; j <= 5 ; j += 5 ) {
            X.push_back(x + j);
            Y.push_back(y + j);
        }
    }

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

    for ( auto &[x, y]: C) {
        x = std::lower_bound(X.begin(), X.end(), x) - X.begin();
        y = std::lower_bound(Y.begin(), Y.end(), y) - Y.begin();
    }
    vector Map (Y.size(), vector<bool>(X.size(), false));

    auto prev = C[0];
    for ( i = 0 ; i <= N ; i ++ ) {
        d = getDir(prev, C[i%N]);
        while ( prev != C[i%N] ) {
            Map[ prev.second ][ prev.first ] = true;
            prev.second += dy[d];
            prev.first += dx[d];
        }
    }
    vector<pii> ans;
    auto [sx, sy] = C[0];
    ans.emplace_back(sx, sy);
    d = 0;
    int nd;
    do {
        nd = -1 ;
        for ( i = 0 ; i < 4 ; i ++ ) {
            int ty = sy + dy[( d + 3 + i ) % 4 ];
            int tx = sx + dx[( d + 3 + i ) % 4 ];
            if ( ty < 0 || ty >= Y.size() || tx < 0 || tx > X.size() || !Map[ty][tx]) continue;
            nd = ( d + 3 + i ) % 4;
            break;
        }
        if ( nd < 0 )
            break;

        if ( d != nd ) {
            ans.emplace_back(sx, sy);
            d = nd ;
        }
        Map[sy][sx] = false;
        sy += dy[d];
        sx += dx[d];
    } while (true);

    int startIndex = 0;
    for ( i = 0 ; i < ans.size() ; i ++ ) {
        if ( ans[startIndex] > ans[i] ) startIndex = i;
    }
    cout << ans.size() << '\n';
    for ( i = 0 ; i < ans.size() ; i ++ ) {
        cout << X[ ans[ (i+startIndex) % ans.size() ].first ]/10 << ' ' << Y[ ans[ (i+startIndex) % ans.size() ].second ]/10 << '\n';
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
