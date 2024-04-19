#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int Y, X;
#define FL(i, N) for ( (i) = 0 ; (i) < (N) ; (i) ++ )

const int MaxN = 15;
char A[MaxN][MaxN];
int C[MaxN][MaxN];
int M[MaxN * MaxN];

void flip(int y, int x, int s, char c) {
    A[y][x-s] = A[y-s][x] = c;
    A[y][x+s] = A[y+s][x] = c;
}

bool can(int y, int x, int s) {
    if ( y-s < 0 || x-s < 0 || y+s >= Y || x+s >= X ) return false;
    return ( A[y][x-s] == '#' && A[y-s][x] == '#' && A[y][x+s] == '#' && A[y+s][x] == '#' );
}
int best = -1;

int F(int idx, int score) {
    int i, y, x, s;
    int ret = 0 ;

    for ( i = idx ; i < Y*X ; i ++ ) {
        y = i / X ;
        x = i % X ;
        if ( score * M[i] <= best )
            break;
        if ( A[y][x] != '#') continue;
        for (s = 0 ; can(y, x, s) ; s ++ )
            ret = max(ret, 1 + s*4);
    }
    return ret * score;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> Y >> X ;
    int i, j, s, k, y, x ;

    FL(i, Y) FL(j, X) cin >> A[i][j];
    FL(i, Y) FL(j, X) {
        for ( k = 0 ; can(i, j, k) ; k ++ )
            C[i][j] = 1+k*4;
    }
    M[(Y-1)*(X-1)] = C[Y-1][X-1];
    for ( i = Y*X-2 ; i >= 0 ; i -- )
        M[i] = max(C[i/X][i%X], M[ i + 1 ]);

    for ( i = 0 ; i < Y*X ; i ++ ) {
        y = i / X ;
        x = i % X ;
        if ( M[i]*M[i] <= best )
            break;
        if ( A[y][x] != '#') continue;
        for (s = 0 ; can(y, x, s) ; s ++ ) {
            flip(y, x, s, '.');
            best = max(best, F(i+1, 1 + s*4));
        }
        for ( --s ; s >= 0 ; s -- ) flip(y, x, s, '#');
    }

    cout << best ;
    return 0;
}


