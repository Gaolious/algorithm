#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Matrix {
    int Y, X;
    int curr;
    int M[2][100][100];
    Matrix(): curr(0) {}
    Matrix(int y, int x): Y(y), X(x), curr(0) {}

    void flipY() {
        int i, j;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                swap(M[1-curr][Y-1-i][j], M[curr][i][j]);
            }
        }
        curr = 1 - curr;
    }
    void flipX() {
        int i, j;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                swap(M[1-curr][i][j], M[curr][i][X-1-j]);
            }
        }
        curr = 1 - curr;
    }
    void rot90() {
        int i, j;
        for ( i = 0 ; i < X ; i ++ ) {
            for ( j = 0 ; j < Y ; j ++ ) {
                M[1-curr][i][j] = M[curr][Y-1-j][i];
            }
        }
        swap(X, Y);
        curr = 1 - curr;
    }
    void rot180() {
        int i, j;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                M[1-curr][i][j] = M[curr][Y-1-i][X-1-j];
            }
        }
        curr = 1 - curr;
    }
    void rot270() {
        int i, j;
        for ( i = 0 ; i < X ; i ++ ) {
            for ( j = 0 ; j < Y ; j ++ ) {
                M[1-curr][i][j] = M[curr][j][X-1-i];
            }
        }
        swap(X, Y);
        curr = 1 - curr;
    }
    void halfCW() {
        int i, j;
        int Y2 = Y/2, X2 = X/2;
        for ( i = 0 ; i < Y2 ; i ++ ) {
            for ( j = 0 ; j < X2 ; j ++ ) {
                M[1-curr][i][j] = M[curr][Y2+i][j];
                M[1-curr][Y2+i][j] = M[curr][Y2+i][X2+j];
                M[1-curr][Y2+i][X2+j] = M[curr][i][X2+j];
                M[1-curr][i][X2+j] = M[curr][i][j];
            }
        }
        curr = 1 - curr;
    }
    void halfCCW() {
        int i, j;
        int Y2 = Y/2, X2 = X/2;
        for ( i = 0 ; i < Y2 ; i ++ ) {
            for ( j = 0 ; j < X2 ; j ++ ) {
                M[1-curr][Y2+i][j] = M[curr][i][j] ;
                M[1-curr][Y2+i][X2+j] = M[curr][Y2+i][j] ;
                M[1-curr][i][X2+j] = M[curr][Y2+i][X2+j] ;
                M[1-curr][i][j] = M[curr][i][X2+j] ;
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
    int i, j, c;
    fastio;

    cin >> Y >> X >> R;
    Matrix M(Y, X);

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> M.M[0][i][j];

    while (R--) {
        cin >> c ;
        switch (c) {
            case 1: M.flipY(); break;
            case 2: M.flipX(); break;
            case 3: M.rot90(); break;
            case 4: M.rot270(); break;
            case 5: M.halfCW(); break;
            case 6: M.halfCCW(); break;
        }
    }
    M.dump();
    return 0;
}


