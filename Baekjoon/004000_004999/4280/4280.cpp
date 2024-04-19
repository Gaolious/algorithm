#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

int getColor(ld W, ld H, ld rW, ld rH, ld x, ld y) {
    int color = 1;
    ld sx, sy, ex, ey ;
    ld mx, my ;

    sx = 0, sy = 0;
    ex = W, ey = H ;

    // 왼쪽 위와 오른쪽 아래의 작은 직사각형은 그대로 유지됩니다.
    // 다른 두 직사각형의 색상은 뒤집힙니다(검은색에서 흰색 또는 흰색에서 검은색으로) 그리고 각각이 큰 직사각형에 수행된 작업에 따라 계속됩니다.
    while ( true ) {
        mx = sx + (ex-sx) * rW ;
        my = sy + (ey-sy) * rH ;
        if ( sx < x && x < mx && sy < y && y < my ) { // Left-bottom
            ex = mx ;
            ey = my ;
            color = 1 - color;
            continue;
        }
        if ( mx < x && x < ex && my < y && y < ey ) { // right - up
            sx = mx;
            sy = my;
            color = 1 - color;
            continue;
        }
        break;
    }
    return color;
}
void process() {
    int T;

    long double W, H, rW, rH;
    int N;
    long double x, y;

    for ( T = 1 ; cin >> W >> H >> rW >> rH && W > 0 && H > 0 && rW > 0 && rH > 0 ; T++ ) {
        cin >> N ;
        cout << "Case " << T << ":\n";
        while ( N -- ) {
            cin >> x >> y ;

            if (getColor(W, H, rW, rH, x, y) == 0 )
                cout << "white\n";
            else
                cout << "black\n";
        }
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


