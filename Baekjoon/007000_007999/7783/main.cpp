#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int Y, X;
int A[202][202];
int R[202];
int D[202];
int L[202];
int U[202];

void dump(int arr[][202]) {

    int i, j;
    for ( i = 1 ; i <= Y ; i ++ ) {
        for ( j = 1 ; j <= X ; j ++ ) {
            cout << setw(3) << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
void preprocess() {
    int y1, y2, x1, x2, t;
    int flag[202]{};
    int count = 0 ;

    for ( y1 = 0 ; y1 < Y ; y1 ++ ) {
        memset(flag, 0, sizeof(flag));
        count = X;

        for ( y2 = y1 + 1 ; y2 <= Y && count > 0 ; y2 ++ ) {
            for ( x1 = 0, x2 = 1; x2 <= X && count > 0  ; x2 ++ ) {
                if ( A[y2][x2] == 0 || flag[x2] ) {
                    x1 = x2;
                    if ( A[y2][x2] == 0 && flag[x2]++ == 0 )
                        count --;
                    continue;
                }
                t = (y2-y1) * (x2-x1);
                D[y2] = max( D[y2], t);
                U[y1+1] = max( U[y1+1], t);
            }
        }
    }

    for ( x1 = 0 ; x1 < X ; x1 ++) {
        memset(flag, 0, sizeof(flag));
        count = Y;
        for ( x2 = x1 + 1 ; x2 <= X && count > 0 ; x2 ++ ) {
            for ( y1 = 0, y2 = 1; y2 <= Y && count > 0  ; y2 ++ ) {
                if ( A[y2][x2] == 0 || flag[y2] ) {
                    y1 = y2;
                    if ( A[y2][x2] == 0 && flag[y2]++ == 0 )
                        count --;
                    continue;
                }

                t = (y2-y1) * (x2-x1);

                L[x2] = max( L[x2], t);
                R[x1+1] = max( R[x1+1], t);
            }
        }
    }

    for ( x1 = 1 ; x1 <= X ; x1 ++)
        L[x1] = max(L[x1-1], L[x1]);
    for ( x1 = X ; x1 >= 1 ; x1 --)
        R[x1] = max(R[x1+1], R[x1]);
    for ( y1 = 1 ; y1 <= Y ; y1 ++)
        D[y1] = max(D[y1-1], D[y1]);
    for ( y1 = Y ; y1 >= 1 ; y1 --)
        U[y1] = max(U[y1+1], U[y1]);
}
int main()
{
    fastio;
    int i, j;
    char c;

    cin >> Y >> X ;
    for ( i = 1 ; i <= Y ; i ++ )
        for ( j = 1 ; j <= X ; j ++ ) {
            cin >> c;
            A[i][j] = '1' - c;
        }

    preprocess();

    int ret = 0 ;
    for ( i = 1 ; i < Y ; i ++ )
        ret = max( ret, D[i] + U[i+1]);
    for ( i = 1 ; i < X ; i ++ )
        ret = max( ret, L[i] + R[i+1]);
    cout << ret << '\n';
    return 0;
}


