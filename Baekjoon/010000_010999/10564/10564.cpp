#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int D[2][5001];
int Min[2], Max[2];

int S[11];
int preSum[11];
int N, M;
int multi(int a, int b) {
    if ( b == 0 ) return 1;
    int ret = multi(a, b/2);
    ret *= ret;
    if ( b % 2 == 1 ) ret *= a;
    return a;
}
void dump(int t, bool header) {
    int i, j;
    if ( header) {
        for ( j = 0 ; j <= N ; j ++ )
            cout << setw(3) << j << ' ';
        cout << '\n';
    }
    for ( j = 0 ; j <= N ; j ++ ) {
        cout << setw(3) << D[t][j] << ' ';
    }
    cout << '\n';
}
int F() {
    int i, j, l, r;
    int inning, turn;

    Min[0] = Min[1] = 0;
    Max[0] = Max[1] = 0;
    memset(D, -1, sizeof(D));
    memset(preSum, 0, sizeof(preSum));

    D[0][0] = 0;
    int ret = -1 ;

    for ( turn = inning = 1 ;  ; inning ++, turn = 1 - turn ) {
        for ( i = 0 ; i < M ; i ++ ) preSum[i] += S[i];
        if ( Min[1-turn] + preSum[0] > N) break;

        memset(D[turn], -1, sizeof(D[turn]));

        Min[turn] = N + 1;
        Max[turn] = 0;

        for ( i = 0 ; i < M ; i ++ ) {
            l = Min[1-turn] + preSum[i];
            r = min(N, Max[1-turn] + preSum[i]);

            for ( j = r ; j >= l ; j -- ) {
                if ( D[1-turn][j - preSum[i] ] >= 0 ) {
                    D[turn][j] = max(D[turn][j], D[1-turn][j-preSum[i]] + S[i] ) ;
                    Min[turn] = min(Min[turn], j);
                    Max[turn] = max(Max[turn], j);
                }
            }
        }
        ret = max(ret, D[turn][N]);
        // dump(turn, inning == 1);
    }
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int T, i;
    cin >> T;
    while ( T -- ) {
        cin >> N >> M ;
        for ( i = 0 ; i < M ; i ++ )
            cin >> S[ i ];
        sort(S, S+M);
        cout << F() << '\n';
    }
    return 0;
}


