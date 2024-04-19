#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

int X, Y;

bool Check1(int x1, int y1, int idx) {
    if ( x1 == X && y1 == Y )
    {
        if ( idx != 1 ) cout << "Z\n";
        cout << "0 0 " << X << ' ' << Y << '\n';
        if ( idx != 2 ) cout << "Z\n";
        return true;
    }
    return false;
}
bool Check2(int x1, int y1, int x2, int y2) {
    int sx, sy, ex, ey;
    if ( x1 <= X && x2 <= X && x1+x2 >= X && y1 == Y && y2 == Y ) {
        sx = 0, sy = 0 ;
        ex = x1, ey = Y;
        cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';

        sx = X-x2, sy = 0 ;
        ex = X, ey = Y;
        cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
        return true;
    }

    if ( y1 <= Y && y2 <= Y && x1 == X && x2 == X && y1+y2 >= Y) {
        sx = 0, sy = 0 ;
        ex = X, ey = y1;
        cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';

        sx = 0, sy = Y-y2 ;
        ex = X, ey = Y;
        cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
        return true;
    }
    return false;
}
void process() {
    int i, j;
    vector<pair<int,int>> P(2);

    cin >> X >> Y ;
    for ( auto &[x,y] : P ) {
        cin >> x >> y;
    }

    // 1
    for ( i = 0 ; i < 2 ; i ++ ) {
        for ( j = 0 ; j < 2 ; j ++ ) {
            if ( Check1(P[i].first, P[i].second, i+1) )
                return;
            swap(P[i].first, P[i].second);
        }
    }

    for ( i = 0 ; i < 2 ; i ++ ) {
        swap(P[0].first, P[0].second);
        for ( j = 0 ; j < 2 ; j ++ ) {
            swap(P[1].first, P[1].second);
            if (Check2(P[0].first, P[0].second, P[1].first, P[1].second))
                return;
        }
    }
    cout << "EI SAA\n";

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


