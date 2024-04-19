#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int dy[] = {0 ,1 ,0, -1};
int dx[] = {1 ,0, -1, 0};
typedef pair<int, int> pii;
typedef queue<pii> QT;
int Y, X, P ;

bool bfs(vector<string> &A, QT &Q, int S, int &count) {
    int ty, tx, d;
    bool ret = false ;
    int cnt;

    while ( !Q.empty() && S-- ) {
        cnt = Q.size();
        for ( int i = 0 ; i < cnt ; i ++ ) {
            auto [y,x] = Q.front();
            Q.pop();

            for (d = 0 ; d < 4 ; d ++ ) {
                ty = y + dy[d];
                tx = x + dx[d];
                if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) continue;
                if ( A[ty][tx] == '.' ) {
                    Q.emplace(ty, tx);
                    A[ty][tx] = A[y][x];
                    count++;
                    ret = true ;
                }
            }
        }
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
    int i, j;
    cin >> Y >> X >> P;

    vector<int> S(P);
    vector<int> C(P);
    vector<string> A(Y);
    vector<QT> Q(P);

    for (auto &s: S) cin >> s ;
    for ( i = 0 ; i < Y ; i ++ ) {
        cin >> A[i];
        for ( j = 0 ; j < X ; j ++ ) {
            if ( '0' <= A[i][j] && A[i][j] <= '9') {
                Q[ A[i][j] - '1' ].emplace(i,j);
                C[ A[i][j] - '1' ]++;
            }
        }
    }

    bool changed;
    int turn = 1;
    for ( turn = 0 ; ; turn = 1 - turn ) {
        changed = false;
        for (i = 0 ; i < P ; i ++ ) {
            if ( !Q[i].empty() )
                changed = bfs(A, Q[i], S[i], C[i]) || changed;
        }
        if ( !changed ) break;
    }
    for (auto s: C) cout << s << ' ';

    return 0;
}


