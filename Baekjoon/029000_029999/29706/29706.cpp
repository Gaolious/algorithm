#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char Map[512][51];

int Down(int x, int W, int H ) {
    for ( int y = 0 ; y < H ; y ++ ) {
        if ( Map[y][x] == 'L' ) x--;
        else if ( Map[y][x] == 'R' ) x++;
    }
    return x;
}
int UP(int x, int W, int H ) {
    for ( int y = H-1 ; y >= 0 ; y-- ) {
        if ( Map[y][x] == 'L' ) x--;
        else if ( Map[y][x] == 'R' ) x++;
    }
    return x;
}
bool Try(int x1, int x2, int W, int H ) {
    for ( int y = 0 ; y <= H ; y ++ ) {
        if ( Map[y][x1] == 'L' ) x1--;
        else if ( Map[y][x1] == 'R' ) x1++;

        if ( Map[y][x2] == 'L' ) x2--;
        else if ( Map[y][x2] == 'R' ) x2++;

        if ( abs(x1-x2) == 1 ) {
            cout << min(x1,x2)+1 << ' ' << y << '\n';
            return true;
        }
    }
    return false;
}
void dumpMap(int W, int H) {
    for ( int i = 0 ; i < H ; i ++ ) {
        for ( int j = 0 ; j < W ; j ++ ) {
            if ( Map[i][j] ) cout << Map[i][j] ;
            else cout << '|';
            cout << "  ";
        }
        cout << '\n';
    }
}

void process() {
    int N, M, P, Q, x;
    int W, H;

    while ( cin >> N >> M >> P >> Q && N ) {
        // N:수직선, M: 수평선, P: 시작, Q: 도착
        P--; Q--;
        W = N;
        H = M+1;

        memset(Map, 0, sizeof(Map));

        for ( int i = 0 ; i < M ; i ++ ) {
            cin >> x;
            Map[ i + 1 ][ x ] = 'L';
            Map[ i + 1 ][ x-1 ] = 'R';
        }
        auto dest = Down(P, W, H);
        if ( dest == Q ) {
            cout << "OK\n";
            continue;
        }
        auto x2 = UP(Q, W, H);
        if ( !Try(P, x2, W, H) )
            cout << "NG\n";
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


