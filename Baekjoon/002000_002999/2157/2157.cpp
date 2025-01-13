#include <bits/stdc++.h>
using namespace std;

const int MaxN = 301;
typedef pair<int, int> pii;

const int INF = 100000000;
int D[MaxN][MaxN];
int Score[MaxN][MaxN];
vector<vector<pii>> C;
int N, M, K ;

int F(int step, int city) {
    auto &ret = D[step][city];
    if ( ret < 0 ) {
        if ( step > M )
            return -1;
        if ( city == N-1 )
            return 0;
        for (auto [nxt, score] : C[city] ) {
            auto v = F(step + 1, nxt);
            if ( v < 0 ) continue;
            ret = max(ret, v + score);
        }
    }
    return ret;
}
void process(int Case) {
    int i, j, a, b, c;

    memset(D, -1, sizeof(D));
    memset(Score, -1, sizeof(Score));

    cin >> N >> M >> K ;

    C.resize(N, vector<pii>());
    for ( i = 0 ; i < K ; i ++ ) {
        cin >> a >> b >> c ;
        if ( a > b ) continue;
        a--; b--;
        Score[a][b] = max(Score[a][b], c);
    }
    for (i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( Score[i][j] > 0 )
                C[i].emplace_back(j, Score[i][j]);
        }
    }
    cout << F(1, 0) << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    process(0);
    return 0;
}

