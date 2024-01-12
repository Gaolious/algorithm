#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N, x, y;
    int sx, sy, ex, ey;
    sx = sy = 1000000;
    ex = ey = -1000000;
    cin >> N ;
    while (N--) {
        cin >> x >> y ;
        sx = min(sx, x);
        sy = min(sy, y);
        ex = max(ex, x);
        ey = max(ey, y);
    }
    cout << (ey-sy)*(ex-sx) << '\n';
    return 0;
}


