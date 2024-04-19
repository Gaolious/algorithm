#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char A[10][10];
bool B[10][10];

int C[5] = {5, 5, 5, 5, 5};
int best = -1;
bool Can(int y, int x, int s) {
    int i ;
    if ( y + s >= 10 || x + s >= 10 ) return false;
    for ( i = 0 ; i <= s ; i ++ ) {
        if ( B[y+i][x+s] || B[y+s][x+i] ) return false;
        if ( A[y+i][x+s] == '0' || A[y+s][x+i] == '0' ) return false;
    }
    return true;
}
void Fill(int y, int x, int s, bool f) {
    int i ;
    for ( i = 0 ; i <= s ; i ++ ) {
        B[y+s][x+i] = f;
        B[y+i][x+s] = f;
    }
}
void dumpB() {
    int i, j ;
    for ( i = 0 ; i < 5  ; i ++ )
        cout << "C[" << i << "] = " << C[i] << ' ';
    cout << '\n';

    for ( i = 0 ; i < 10  ; i ++ ) {
        for ( j = 0 ; j < 10 ; j ++ ) {
            if ( B[i][j] ) cout << 'F' << ' ';
            else cout << '.' << ' ';
        }
        cout <<'\n';
    }
    cout << endl;
}

void F(int idx, int cnt) {
    int y, x, size;
    if ( idx >= 100) {
        if ( best < 0 || best > cnt ) best = cnt ;
        return;
    }
    if ( best > 0 && cnt >= best ) return ;
    y = idx / 10 ;
    x = idx % 10 ;
    if ( A[y][x] == '0' || B[y][x] ) {
        F(idx+1, cnt);
        return;
    }
    for ( size = 0 ; size < 5 && Can(y, x, size); size++ ) {
        if ( C[size] == 0 ) continue;

        C[size]--;
        Fill(y, x, size, true);

        // cout << "Fill y=" << y << ", x=" << x << ", size=" << size << '\n';
        // dumpB();

        F(idx+1, cnt+1);

        C[size]++;
    }
    for ( --size ; size >= 0 ; size -- ) {
        Fill(y, x, size, false);
        // cout << "unFill y=" << y << ", x=" << x << ", size=" << size << '\n';
        // dumpB();
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;
    for ( i = 0 ; i < 10 ; i ++ )
        for ( j = 0 ; j < 10 ; j ++ )
            cin >> A[ i ][ j ] ;
    F(0, 0);
    cout << best << '\n';
    return 0;
}


