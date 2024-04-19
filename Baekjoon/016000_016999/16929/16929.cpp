#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
string A[50];
int V[50][50];
int H[50][50];
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int Y, X ;
    int i, j, k, x, y ;
    cin >> Y >> X ;

    for ( i = 0 ; i < Y ; i ++ )
        cin >> A[i];

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( H[i][j] == 0 ) {
                for ( k = j ; k < X && A[i][j] == A[i][k] ; k ++ )
                    H[i][k] = k - j + 1;
            }
            if ( V[i][j] == 0 ) {
                for ( k = i ; k < Y && A[i][j] == A[k][j] ; k ++ )
                    V[k][j] = k - i + 1;
            }
        }
    }
    for ( i = Y - 1 ; i > 0 ; i -- ) {
        for ( j = X - 1 ; j > 0 ; j -- ) {
            if ( H[i][j] <= 1 || V[ i ][ j ] <= 1 )
                continue;
            for ( y = i - V[i][j] + 1 ; y < i ; y ++ ) {
                for ( x = j - H[i][j] + 1 ; x < j ; x ++ ) {
                    if ( A[i][j] == A[y][x] && H[y][j] >= (j-x+1) && V[i][x] >= (y-i+1) ) {
                        cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}


