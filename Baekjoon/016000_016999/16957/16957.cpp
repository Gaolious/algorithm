#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<int, int> pii;

pii P[500][500];
int A[500][500];

int Y, X;

pii Find(pii p) {
    return P[p.first][p.second] = ( P[p.first][p.second] == p) ? p : Find(P[p.first][p.second]);
}

int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1};

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, d, ty, tx, min_d, min_v;

    cin >> Y >> X;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[i][j];
            P[i][j] = {i, j};
        }
    }

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            min_v = A[i][j], min_d = -1;

            for (d = 0 ; d < 8 ; d ++ ) {
                ty = i + dy[d];
                tx = j + dx[d];
                if ( ty < 0 || ty >= Y || tx < 0 || tx >= X) continue;
                if ( min_v > A[ty][tx] ) {
                    min_v = A[ty][tx];
                    min_d = d;
                }
            }
            if ( min_d >= 0 )
                P[i][j] = Find({i+dy[min_d],j+dx[min_d]});
        }
    }

    memset(A, 0, sizeof(A));

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            auto t = Find({i, j});
            A[t.first][t.second] ++;
        }
    }
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}


