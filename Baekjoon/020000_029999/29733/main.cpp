#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
char DATA[ 100 ][ 100 ][ 100 + 1 ];
int dz[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int dy[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1};

int main()
{
    fastio;
    int Y, X, Z;
    int z, y, x, d, tx, ty, tz, c;
    cin >> Y >> X >> Z ;

    for ( z = 0 ; z < Z ; z ++ )
        for ( y = 0 ; y < Y ; y ++ )
            for ( x = 0 ; x < X ; x ++ )
                cin >> DATA[z][y][x];

    for ( z = 0 ; z < Z ; z ++ )
        for ( y = 0 ; y < Y ; y ++ ) {
            for ( x = 0 ; x < X ; x ++ ) {
                c = 0;
                if ( DATA[z][y][x] != '*') {
                    for ( d = 0 ; d < 26 ; d++ ) {
                        tz = z + dz[d];
                        ty = y + dy[d];
                        tx = x + dx[d];
                        if ( tz < 0 || tz >= Z || ty < 0 || ty >= Y || tx < 0 || tx >= X ) continue;
                        if ( DATA[tz][ty][tx] == '*') c ++;
                    }
                    DATA[z][y][x] = '0' + (c%10);
                }
            }
        }

    for ( z = 0 ; z < Z ; z ++ )
        for ( y = 0 ; y < Y ; y ++ )
            cout << DATA[z][y] << '\n';
    return 0;
}


