#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

void init(){
}
const int INF = 100000000;
int N, M, x, y;
vector<vector<int>> D;
vector<pii> P; // 최소, 최대 점수

int point(int p) {
    if ( p == 0 ) return 0;
    if ( p < 10 ) return x;
    return y;
}

void process(int Case) {
    int i, j, k, score, turn;
    cin >> N >> M >> x >> y;

    P.resize(N);
    for (i = 0; i < N; i++) cin >> P[i];
    D.resize(2, vector<int>(M + 1, INF));

    D[1][0] = 0;
    for ( turn = 0, i = 0 ; i < N ; i ++, turn = 1 - turn ) {
        std::fill(D[turn].begin(), D[turn].end(), INF);

        for ( j = P[i].first ; j <= P[i].second ; j ++ ) {
            score = point(j);
            for (k=0 ; j+k <= M ; k++ ) {
                D[turn][j+k] = min(D[turn][j+k], D[1-turn][k] + score );
            }
        }
#ifdef AJAVA_DEBUG
        for (j = 0 ; j <= M ; j ++ ) {
            if ( D[turn][j] >= INF )
                cout << setw(2) << '-' << ' ';
            else
                cout << setw(2) << D[turn][j] << ' ';
        }
        cout << '\n';
#endif
    }

    if ( D[1-turn][M] >= INF )
        cout << "-1\n";
    else
        cout << D[1-turn][M] << '\n';
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
