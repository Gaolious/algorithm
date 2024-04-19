#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int B[610][610];

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;

    int Y, X, dy, dx;
    int i, j, ty, tx;

    cin >> Y >> X >> dy >> dx ;
    for ( i = 0 ; i < Y+dy ; i ++ )
        for ( j = 0 ; j < X +dx ; j ++ )
            cin >> B[i][j];

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            ty = i - dy;
            tx = j - dx;
            if ( ty >= 0 && tx >= 0 ) {
                B[i][j] -= B[ty][tx];
            }
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}


