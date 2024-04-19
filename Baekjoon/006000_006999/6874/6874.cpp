#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1,0, -1};
int dx[] = { 1, 0,-1, 0};
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }


int Map[20][20];

void process() {
    int x, y, w, h, s;
    int ty, tx, d;
    bool canMove;

    cin >> X >> Y >> w >> h >> s ;

    y = 0, x = w, d = 0;
    Map[y][x] = 1;
    for ( int step = 2 ; ; step ++ ) {

        canMove = false;
        for ( auto td: {-1, 0, 1}) {
            ty = y + dy[ (d+td+4)%4 ];
            tx = x + dx[ (d+td+4)%4 ];
            if ( !valid(ty, tx) ) continue;
            if ( ty < h && ( tx < w || tx >= X-w ) ) continue;
            if ( ty >= Y-h && ( tx < w || tx >= X-w ) ) continue;
            if ( Map[ty][tx] != 0 ) continue;
            canMove = true;
            Map[ty][tx] = step ;
            y = ty, x = tx;
            d = d + td;
            if ( step == s + 1 ) {
                cout << x + 1 << '\n' << y + 1 << '\n';
                return;
            }
            break;
        }
        if ( canMove ) continue;
        break;
    }
    cout << x + 1 << '\n' << y + 1 << '\n';
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


