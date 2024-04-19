#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
// north, east, south, west
int dy[] = {-1, 0, 1, 0};
int dx[] = { 0, 1, 0, -1};
vector< vector<int> > Map;
int sy, sx, ey, ex;
void dump() {
    for (auto &row : Map){
        for (auto &col : row) {
            cout << col << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void Set(int y, int x, int n) {
    if ( sy <= y && y <= ey && sx <= x && x <= ex )
        Map[y-sy][x-sx] = n;
}
bool isCross(int y, int x, int dir, int len) {
    int y2, x2 ;
    y2 = y + dy[dir] * len;
    x2 = x + dx[dir] * len ;
    if ( y < sy && y2 < sy ) return false;
    if ( x < sx && x2 < sx ) return false;
    if ( y > ey && y2 > ey ) return false;
    if ( x > ex && x2 > ex ) return false;
    return true;
}
void draw(int N, int y, int x, int dir, int delta) {
    int n = 0;
    int len, i, j;
    int remain = N*N;

    Set(y, x, ++n);

    for ( i = 0 ; i < N-1 ; i++) {
        y = y + dy[dir];
        x = x + dx[dir];
        Set(y, x, ++n);
    }
    dir = (dir + delta + 4 ) % 4 ;

    for ( len = N-1 ; len > 0 ; len -- ) {
        for (j = 0 ; j < 2 ; j ++ ) {
            if ( isCross(y, x, dir, len) ) {
                for (i = 0; i < len; i++) {
                    y = y + dy[dir];
                    x = x + dx[dir];

                    Set(y, x, ++n);
                    if (--remain < 1) return;
                }
            }
            else {
                n += len;
                remain -= len;
                y = y + dy[dir]*len;
                x = x + dx[dir]*len;
            }
            dir = (dir + delta + 4 ) % 4 ;
        }
    }
}
pair<int,int> getStartPos(int N, int dir, int delta) {
    for ( auto y: {0, N-1}) {
        for (auto x: {0, N-1} ) {
            int ty = y + dy[ dir ] * (N-1);
            int tx = x + dx[ dir ] * (N-1);
            if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;

            ty = ty + dy[ ( dir + delta + 4 ) % 4 ] * (N-1);
            tx = tx + dx[ ( dir + delta + 4 ) % 4  ] * (N-1);
            if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;

            return {y, x};
        }
    }
    return {0, 0};
}
void process() {
    int N;

    string sDir, sDelta ;
    int dir, delta;

    cin >> N >> sDir >> sDelta;
    cin >> sx >> ex >> sy >> ey;

    if (sDir == "POLNOC" ) dir = 0; // north
    else if (sDir == "POLUDNIE" ) dir = 2; // south
    else if (sDir == "ZACHOD" ) dir = 3; // west
    else dir = 1;  // east

    if (sDelta == "PRAWO" ) delta = 1; // right
    else delta = -1; // west

    auto [y, x] = getStartPos(N, dir, delta);

    sy = N-sy;
    ey = N-ey;
    swap(sy, ey);
    sx--; ex--;

    Map.resize( ey-sy+1 , vector<int>(ex-sx+1, 0));
    draw(N, y, x, dir, delta);

    for (auto &row : Map){
        for (auto &col : row) {
            cout << col << ' ';
        }
        cout << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


