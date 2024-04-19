#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const char *dc[] = {"R", "DR", "D", "DL", "L", "UL", "U", "UR"};
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

vector<vector<int>> A;
const char *RL="RL";
const char *DU="DU";
void valid_check(string &t) {
    vector Visited = vector(Y, vector<bool>(X));
    int cnt = 1;
    int y = 0, x = 0;
    Visited[y][x] = true;
    for (auto c: t ) {

        if ( c == 'R' ) x++;
        else if ( c == 'L' ) x--;
        else if ( c == 'U' ) y--;
        else if ( c == 'D' ) y++;
        else assert( false );
        assert ( 0 <= x && x < X );
        assert ( 0 <= y && y < Y );
        assert( Visited[y][x] == false );
        Visited[y][x] = true;
        cnt++;
    }
    assert (cnt >= Y*X - 1);
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int y, x, i, j, t;
    int cy=0, cx = 0;

    cin >> Y >> X;
    string ans ;

    A.resize(Y, vector<int>(X, 0));
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];

    if ( Y % 2 ) {
        for ( y = 0 ; y < Y ; y ++ ) {
            if ( y ) ans.push_back('D');
            for ( x = 1 ; x < X ; x ++ ) ans.push_back( RL[y%2] );
        }
    }
    else if ( X % 2 ) {
        for ( x = 0 ; x < X ; x ++ ) {
            if ( x ) ans.push_back('R');
            for ( y = 1 ; y < Y ; y ++ ) ans.push_back( DU[x%2] );
        }
    }
    else {
        y=0, x=1;
        for ( i = 0 ; i < Y ; i ++ )
            for ( j = 1-(i%2) ; j < X ; j +=2 )
                if ( A[y][x] > A[i][j] ) y=i, x=j;

        if ( y < x ) {
            cy = 0 , cx = 0;
            for ( j = 0 ; j < X ; j += 2 ) {
                if ( j <= x && x <= j+1 ) {
                    A[y][x] = -1;
                    bool move = true ;
                    while ( move ) {
                        move = false;
                        for (auto d : {0, 4, 2} ) {
                            int ty = cy + dy[d];
                            int tx = cx + dx[d];
                            if ( ty < 0 || ty >= Y || tx < j || tx > j+1 ) continue;
                            if ( A[ty][tx] == -1 ) continue;
                            ans += dc[d];
                            A[cy=ty][cx=tx] = -1;
                            move = true;
                            break;
                        }
                    }
                }
                else {
                    if ( j ) ans.push_back('R');
                    t = (j + ( j < x ? 0 : 1 ) ) % 2 ;
                    for ( i = 1 ; i < Y ; i ++ ) ans.push_back(DU[ t ] );
                    ans.push_back('R');
                    for ( i = 1 ; i < Y ; i ++ ) ans.push_back( DU[ 1 - t] );
                    cx = j + 1;
                }
            }
        }
        else {
            cy = 0 , cx = 0;

            for ( i = 0 ; i < Y ; i += 2 ) {
                if ( i <= y && y <= i + 1) {
                    A[y][x] = -1;
                    bool move = true ;
                    while ( move ) {
                        move = false;
                        for (auto d : {2, 6, 0} ) {
                            int ty = cy + dy[d];
                            int tx = cx + dx[d];
                            if ( ty < i || ty > i + 1 || tx < 0 || tx >= X ) continue;
                            if ( A[ty][tx] == -1 ) continue;
                            ans += dc[d];
                            A[cy=ty][cx=tx] = -1;
                            move = true;
                            break;
                        }
                    }
                }
                else {
                    if ( i ) ans.push_back('D');
                    t = (i + ( i < y ? 1 : 0 ) ) % 2 ;
                    for ( j = 1 ; j < X ; j ++ ) ans.push_back(RL[ 1 - t ] );
                    ans.push_back('D');
                    for ( j = 1 ; j < X ; j ++ ) ans.push_back(RL[ t ] );
                    cy = i + 1;
                }
            }
        }
    }
    cout << ans << '\n';
    // valid_check(ans);
    return 0;
}


