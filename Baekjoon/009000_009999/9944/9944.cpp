#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 0, -1, 12345 };
int dx[] = { 1, 0, -1, 0, 12345 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

char A[30][30];
bool Visited[30][30];
const int INF = 1000000;
int best = INF;
void dump(int yp, int xp, int d, int step) {
    int y, x;
    cout << "Y=" << yp << ", X=" << xp << ", d=" << d << ", Step # " << step << '\n';
    for ( y = 0 ; y < Y ; y ++ ) {
        for (x = 0 ; x < X ; x ++ ) {
            if ( Visited[y][x] )
                cout << '@';
            else
                cout << A[y][x] ;
        }
        cout << '\n';
    }
    cout << endl;
}
bool can(int y, int x, int d) {
    int ty, tx;
    ty = y + dy[d];
    tx = x + dx[d];
    return ( valid(ty,tx) && !Visited[ty][tx] && A[ty][tx] == '.' );
}
void dfs(int y, int x, int prevDir, int step, int remain) {
    if ( step > best ) return;
    if (remain == 0 ) {
        best = min(best, step);
        return ;
    }
    Visited[y][x] = true;
    // dump(y, x, d, step);

    if( can(y, x, prevDir) ) {
        dfs(y + dy[prevDir], x + dx[prevDir], prevDir, step, remain-1);
    }
    else { // if ( step > 5 || check() ) {
        for (int d = 0 ; d < 4 ; d ++ ) {
            if ( can(y, x, d) ) {
                dfs(y + dy[d], x + dx[d],d , step+1, remain-1);
            }
        }
    }

    Visited[y][x] = false;
    // dump(y, x, d, step);
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int y, x, remain;
    for ( int test = 1 ; cin >> Y >> X ; test ++ ) {
        best = INF;
        memset(A, -1, sizeof(A));

        remain = 0;
        for ( y = 0 ; y < Y ; y ++ )
            for (x = 0 ; x < X ; x ++ ) {
                cin >> A[y][x];
                remain += ( A[y][x] == '.');
            }
        if ( remain == 0 ) best = 0;
        for ( y = 0 ; y < Y ; y ++ )
            for (x = 0 ; x < X ; x ++ )
                if ( A[y][x] == '.' ) {
                    memset(Visited, 0, sizeof(Visited));
                    dfs(y, x, 4, 0, remain-1);
                }

        cout << "Case " << test << ": " ;
        if ( best >= INF )
            cout << -1 ;
        else
            cout << best ;
        cout << '\n';
    }


    return 0;
}


