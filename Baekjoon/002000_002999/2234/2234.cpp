#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int LEFT  = 0x1;
const int UP    = 0x2;
const int RIGHT = 0x4;
const int DOWN  = 0x8;

int Y, X;
int A[50][50];
int ROOM[50][50];
int dy[] = { 0, -1, 0, 1};
int dx[] = { -1, 0, 1, 0};
vector<int> RoomSize;

int bfs(int _y, int _x, int roomNo) {
    queue<pair<int, int>> Q;
    Q.emplace(_y, _x);
    ROOM[_y][_x] = roomNo;
    int ret = 1 ;
    int d, ty, tx;

    while (!Q.empty() ) {
        auto [y, x] = Q.front();
        Q.pop();
        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= Y || tx >= X )
                continue;
            if ( A[y][x] & ( 1 << d ) )
                continue;
            if ( ROOM[ty][tx] != -1)
                continue;
            ROOM[ty][tx] = roomNo;
            Q.emplace(ty, tx);
            ret++;
        }
    }
    return ret;
}
int mergeTwoRoom() {
    int d, ty, tx;
    int y, x;
    int ret = -1;
    for ( y = 0 ; y < Y ; y ++ ) {
        for ( x = 0 ; x < X ; x ++ ) {
            for ( d = 0 ; d < 4 ; d ++ ) {
                ty = y + dy[d];
                tx = x + dx[d];
                if ( ty < 0 || tx < 0 || ty >= Y || tx >= X )
                    continue;
                if ( ROOM[y][x] == ROOM[ty][tx])
                    continue;
                if ( !(A[y][x] & ( 1 << d ) ) )
                    continue;
                ret = max(ret, RoomSize[ROOM[y][x]] + RoomSize[ROOM[ty][tx]]);
            }
        }
    }
    return ret;
}
void dump() {
    int i, j ;

    for (i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ )
            cout << setw(3) << ROOM[i][j] << ' ' ;
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
    cin >> X >> Y;

    for (i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[ i ][ j ] ;
            ROOM[ i ][ j ] = -1;
        }
    }
    int maxRoomSize = -1;
    for (i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( ROOM[i][j] < 0 ) {
                int s = bfs(i, j, RoomSize.size());
                RoomSize.push_back(s);
                maxRoomSize = max(maxRoomSize, s);
            }
        }
    }
    cout << RoomSize.size() << '\n';
    cout << maxRoomSize << '\n';
    cout << mergeTwoRoom() << '\n';
    return 0;
}


