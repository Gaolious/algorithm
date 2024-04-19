#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Matrix {
    int Y, X;
    int curr;
    int M[2][300][300];
    Matrix(): curr(0) {}
    Matrix(int y, int x): Y(y), X(x), curr(0) {}

    void MoveCCW(int step) {
        int s, i, lenX, lenY, x, y, len, j, t;
        lenX = X ;
        lenY = Y;

        for ( s=0 ; s < Y/2 && s < X/2 ; s ++, lenX -=2, lenY -= 2 ) {
            vector<pair<int,int>> pos = vector<pair<int,int>>();
            x = y = s;
            for ( i = 1 ; i < lenY ; i ++)
                pos.emplace_back(++y, x);
            for ( i = 1 ; i < lenX ; i ++ )
                pos.emplace_back(y, ++x);
            for ( i = 1 ; i < lenY ; i ++ )
                pos.emplace_back(--y, x);
            for ( i = 1 ; i < lenX ; i ++ )
                pos.emplace_back(y, --x);
            len = pos.size();
            t = step % len ;
            for ( i = 0 ; i < len ; i ++ ) {
                j = ( i - t + len ) % len ;
                M[1-curr][ pos[i].first ][ pos[i].second ] = M[curr][ pos[j].first ][ pos[j].second ];
            }
        }
        curr = 1 - curr;

    }
    void dump() {
        int i, j;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ )
                cout << M[curr][i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
};

int main()
{
    int Y, X, R;
    int i, j;
    fastio;
    cin >> Y >> X >> R;
    Matrix M(Y, X);

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> M.M[0][i][j];

    M.MoveCCW(R);
    M.dump();
    return 0;
}


