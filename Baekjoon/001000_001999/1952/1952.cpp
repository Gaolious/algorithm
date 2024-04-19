#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
typedef pair<ll, ll> pii ;

pii getPos(ll turn, ll Y, ll X) {
    ll jump = turn / 4 ;
    ll d = turn % 4;
    ll sy = jump+1;
    ll sx = jump;
    ll ey = Y - 1 - jump;
    ll ex = X - 1 - jump;
    ll y = jump, x = ex;
    while ( true ) {
        if ( d > 0 ) { d--; y = ey; ex--; } else break;
        if ( d > 0 ) { d--; x = sx; ey--; } else break;
        if ( d > 0 ) { d--; y = sy; sx++; } else break;
        if ( d > 0 ) { d--; x = ex; sy++; } else break;
    }
    // cout << turn << " : " << "[" << sy << "," << sx <<"] ~ [" << ey << "," << ex << "] : " << y << " , " << x << "\n";

    return {y, x};
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    ll y, x ;
    pii ret;

    cin >> y >> x ;

    ll turn =  x < y ? x*2-1 : y*2-2 ;

    // for ( auto i = 0 ; i <= turn ; i ++ ) {
        // ret = getPos(i, y, x);
    // }
    ret = getPos(turn, y, x);
    cout << turn << '\n' << ret.first + 1 << ' ' << ret.second + 1<< '\n';
    return 0;
}


