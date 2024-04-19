#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int Y, X;
vector<string> A;
bool check[10000];

#define P(ry,rx,by,bx) ( (ry)*1000 + (rx)*100 + (by)*10 + (bx) )
#define R(v, ry,rx,by,bx) (ry) = ((v)/1000)%10, (rx) = ((v)/100)%10, (by) = ((v)/10)%10, (bx) = ((v)/1)%10

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
#define invalid(ty, tx) ( ty < 0 || tx < 0 || ty >= Y || tx >= X || A[ty][tx] == '#' )
const int INF = 100000000;

bool move(int &y, int &x, int d) {
    int ty, tx ;
    ty = y + dy[d];
    tx = x + dx[d];

    if ( !invalid(ty, tx) ) {
        y=ty, x=tx;
        return true;
    }
    return false ;
}
bool can(int ry, int rx, int by, int bx, int d) {
    bool r1 = move(ry, rx, d);
    bool r2 = move(by, bx, d);
    if ( !r1 && !r2 ) return false ;
    if ( ry == by && rx == bx ) return false ;
    return true;
}
void dump(int ry, int rx, int by, int bx) {
    int i, j;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {

            if ( i == ry && j == rx ) cout << 'R';
            else if ( i == by && j == bx ) cout << 'B';
            else cout << A[i][j] ;
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
    int i, j;
    int ry=0, rx=0, by=0, bx=0;
    int d;
    bool holeR, holeB;

    cin >> Y >> X ;
    A.resize(Y);
    for ( i = 0 ; i < Y ; i ++ ) {
        cin >> A[ i ];
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[ i ][ j ] == 'R' ) ry=i, rx=j, A[i][j] = '.';
            else if ( A[ i ][ j ] == 'B' ) by=i, bx=j, A[i][j] = '.';
        }
    }

    queue<pair<int, int>> Q;
    Q.emplace(0, P(ry,rx,by,bx));
    check[ P(ry,rx,by,bx) ] = true;

    int ans = INF;
    while ( !Q.empty() ) {
        auto [step, v] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            R(v,ry,rx,by,bx);
            holeR = false, holeB = false;
            while ( can(ry, rx, by, bx, d) ) {
                move(ry, rx, d);
                move(by, bx, d);
                if ( !holeB && A[by][bx] == 'O' ) {holeB = true; by=bx=-1;}
                if ( !holeR && A[ry][rx] == 'O' ) {
                    holeR = true; ry=rx=-1;
                }
            }
            if ( holeB ) continue;
            if ( holeR ) {
                ans = min(ans, step+1);
                continue;
            }
            if ( check[ P(ry,rx,by,bx) ] ) continue;
            check[ P(ry,rx,by,bx) ] = true;
            Q.emplace(step+1, P(ry,rx,by,bx));
        }
    }
    if ( ans >= INF) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}


