#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Data {
    int z, y, x;
};
char R[5][4][5][5];
// char A[5][5][5];

vector<Data> delta;
int Order[] = {0, 1, 2, 3, 4};
int Rotate[] = {0, 0, 0, 0, 0};

const int inf = 10000000;
int best = inf;
int D[5][5][5];

int sol() {
    int tz, ty, tx;
    queue<Data> Q;
    memset(D, -1, sizeof(D));

    Q.push({0, 0, 0});
    D[0][0][0] = 0;

    while ( !Q.empty() ) {
        auto [z,y,x] = Q.front();
        Q.pop();
        if ( best > 0 && best <= D[z][y][x] ) continue;
        for (auto [dz, dy, dx] : delta ) {
            tz = z + dz ;
            ty = y + dy ;
            tx = x + dx ;
            if ( tz < 0 || ty < 0 || tx < 0 ) continue;
            if ( tz >= 5 || ty >= 5 || tx >= 5 ) continue;
            if ( D[tz][ty][tx] != -1 ) continue;
            if ( R[ Order[z] ][ Rotate[z] ][y][x] != '1' )
                continue;

            D[tz][ty][tx] = D[z][y][x] + 1;
            Q.push({tz, ty, tx});
        }
    }
    return D[4][4][4] < 0 ? inf : D[4][4][4];
}
void R90(char src[5][5], char dest[5][5]) {
    int i, j ;
    for ( i = 0 ; i < 5 ; i ++ )
        for ( j = 0 ; j < 5 ; j ++ )
            dest[i][j] = src[4-j][i];
}
void dump(char src[5][5]) {
    int i, j ;
    for ( i = 0 ; i < 5 ; i ++ ) {
        for ( j = 0 ; j < 5 ; j ++ ) {
            cout << src[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, k, r, a, b, c, d, e;

    for ( i = 0 ; i < 5 ; i ++ )
        for ( j = 0 ; j < 5 ; j ++ )
            for ( k = 0 ; k < 5 ; k ++ )
                cin >> R[ i ][ 0 ][ j ][ k ];

    for (i = -1 ; i <= 1 ; i ++ )
        for ( j=-1 ; j <= 1 ; j ++ )
            for ( k=-1 ; k <= 1 ; k ++ )
                if ( abs(i) + abs(j) + abs(k) == 1 )
                    delta.push_back({i, j, k});

    for ( i = 0 ; i < 5 ; i ++ )
        for ( j = 1 ; j < 4; j ++ )
            R90(R[i][j-1], R[i][j]);

    do {
        bool p1, p2;
        p1 = p2 = false;
        for ( a = 0 ; a < 4 ; a ++ ) {
            p1 = R[ Order[0] ][ a ][ 0 ][ 0 ] == '1' || p1 ;
            p2 = R[ Order[4] ][ a ][ 4 ][ 4 ] == '1' || p2 ;
        }
        if ( !p1 || !p2 ) continue;

        for ( a = 0 ; a < 4 ; a ++ ) {
            if ( R[ Order[0] ][a][0][0] != '1' ) continue;
            Rotate[0] = a;
            for (b=0 ; b<4 ; b++ ) {
                Rotate[1] = b;
                for (c=0 ; c<4 ; c++ ) {
                    Rotate[2] = c;
                    for (d=0 ; d<4 ; d++) {
                        Rotate[3] = d;
                        for (e=0 ; e<4 ; e++ ) {
                            if ( R[ Order[4] ][e][4][4] != '1' )
                                continue;
                            Rotate[4] = e;
                            best = min(best, sol());
                        }
                    }
                }
            }
        }
    } while ( next_permutation(Order, Order+5));

    if ( best >= inf )
        cout << "-1\n";
    else
        cout << best << '\n';
    return 0;
}


