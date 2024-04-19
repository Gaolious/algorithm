#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
char A[100][100];
int C[100][100]{};
int L[100][100]{};
int U[100][100]{};
int Y, X;
bool valid(int y, int x) {
    return !( y < 0 || x < 0 || y >= Y || x >= X );
}
bool canFill(int y, int x, int size) {
    int i ;
    if (A[y][x] != '*') return false;
    if ( !valid( y-size, x) || !valid( y, x+size) ) return false;
    if ( L[y][x+size] < size*2+1 ) return false ;
    if ( U[y+size][x] < size*2+1 ) return false ;
    return true;
}
int Fill(int y, int x, int size, bool flag) {
    int i, ret;
    ret = 0;

    if ( flag ) {
        if ( C[y][x]++ == 0 ) ret ++;
        for ( i = 1 ; i <= size ; i ++ ) {
            if ( C[y][x+i] ++ == 0 ) ret++;
            if ( C[y][x-i] ++ == 0 ) ret++;
            if ( C[y+i][x] ++ == 0 ) ret++;
            if ( C[y-i][x] ++ == 0 ) ret++;
        }
    }
    else {
        if ( --C[y][x] == 0 ) ret ++;
        for ( i = 1 ; i <= size ; i ++ ) {
            if ( --C[y][x+i] == 0 ) ret++;
            if ( --C[y][x-i] == 0 ) ret++;
            if ( --C[y+i][x] == 0 ) ret++;
            if ( --C[y-i][x] == 0 ) ret++;
        }
    }
    return ret;
}
struct Data {
    int y, x, size;
};
Data Q[10001];
int QSize = 0;

void Dump() {
    int i, j ;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cout << setw(2) << C[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
bool F(int idx, int cnt) {
    int y, x, s, c, maxs;

    y = idx / X ;
    x = idx % X ;

    if ( cnt == 0 ) {
        return true;
    }

    if ( y >= Y )
        return false;

    // cout << "Y=" << y << ", X=" << x << ", Remain = " << cnt << '\n';
    // Dump();
    maxs = max(y+1, x+1);
    maxs = min(maxs, X - 1 - x);
    maxs = min(maxs, Y - 1 - y);
    for ( s = maxs ; s > 0 ; s -- ) {
        if ( canFill(y, x, s) ) {
            c = Fill(y, x, s, true);
            Q[QSize++] = {y, x, s};
            return F(idx+1, cnt - c );
        }
    }

    return F(idx+1, cnt);
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, k;
    int Total ;

    cin >> Y >> X ;

    Total = 0;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++) {
            cin >> A[i][j];
            if ( A[i][j] == '*' ) Total ++;
        }

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[i][j] != '*' ) {
                L[i][j] = 0;
                U[i][j] = 0;
            }
            else {
                L[i][j] = ( j == 0 ? 0 : L[i][j-1]) + 1;
                U[i][j] = ( i == 0 ? 0 : U[i-1][j]) + 1;
            }
        }
    }

    if ( F(0, Total) ) {
        cout << QSize << '\n';
        for ( i = 0 ; i < QSize ; i ++ ) {
            cout << Q[i].y + 1 << ' ' << Q[i].x + 1 << ' ' << Q[i].size << '\n';
        }
        return 0;
    }

    cout << "-1\n";

    return 0;
}


