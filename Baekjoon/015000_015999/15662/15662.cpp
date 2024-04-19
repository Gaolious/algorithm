#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Gear {
    char G[9];
    int topIndex;
    char L() {
        topIndex %= 8;
        return G[(topIndex - 2 + 8) % 8];
    }
    char R() {
        topIndex %= 8;
        return G[(topIndex + 2 + 8) % 8];
    }
    char T() {
        topIndex %= 8;
        return G[(topIndex + 8) % 8];
    }
    void rot(int dir) {
        topIndex %= 8;
        topIndex = ( topIndex - dir + 8 ) % 8;
    }
    void dump() {
        for ( int i = 0 ; i < 8 ; i ++ )
            cout << G[ (topIndex + i ) % 8] << ' ';
        cout << '\n';
    }
};

void rotate(vector<Gear> &gear, int idx, int dir) {
    int l, r ;
    l = r = 0;
    while ( idx - l >  0 && gear[idx - l - 1].R() != gear[idx - l].L() ) l++;
    while ( idx + r + 1 < gear.size() && gear[idx+r].R() != gear[idx+r+1].L() ) r++;
    while ( l > 0 ) {
        gear[idx-l].rot( l % 2 ? -dir : dir );
        l--;
    }
    while ( r >= 0 ) {
        gear[idx+r].rot( r % 2 ? -dir : dir );
        r--;
    }
}

int main()
{
    fastio;
    int T, K, i, d;
    cin >> T;
    vector<Gear> gear(T);
    for (auto &g: gear) cin >> g.G;

    cin >> K;
    while ( K -- ) {
        cin >> i >> d ;
        rotate(gear, i-1, d);
    }
    int ret = 0;
    for ( auto &g: gear)
        if ( g.T() == '1') ret ++;
    cout << ret << '\n';
    return 0;
}


