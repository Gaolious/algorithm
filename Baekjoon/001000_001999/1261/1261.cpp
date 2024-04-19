#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[100][101];
char S[100][101];
int Y, X;
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};

#define XY2P(y, x) ( (y) * 1000 + (x) )
#define I2X(n) ( (n) % 1000 )
#define I2Y(n) ( (n) / 1000 )
int Spread() {
    queue<pair<int, int>> Q;
    A[0][0] = 0;
    Q.emplace(0, 0);
    int tx, ty, d, y, x, t;
    while ( !Q.empty() ) {
        auto [cnt, T] = Q.front();
        y = I2Y(T);
        x = I2X(T);

        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];

            if ( ty < 0 || ty >= Y || tx < 0 || tx >= X )
                continue;
            t = cnt + ( S[ty][tx] == '1' ? 1 : 0 );
            if ( A[ty][tx] > t  ) {
                A[ty][tx] = t ;
                Q.emplace(t, XY2P(ty,tx));
            }
        }
    }
    return A[Y-1][X-1];
}

int main()
{
    fastio;
    int i, j, step;
    char c;
    cin >> X >> Y ;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> c ;
            S[i][j] = c;
            A[i][j] = 100000;
        }
    }
    step = Spread();
    cout << step << '\n';
    return 0;
}


