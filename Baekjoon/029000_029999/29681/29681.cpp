#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void init(){
}
int sign(ld v) {
    if ( v < 0 ) return -1;
    if ( v > 0 ) return 1;
    return 0;
}
void process(int Case) {
    ld w, h;
    ld d, vx, vy, t, x, y;
    cin >> w >> h >> vx >> vy >> t;
    d = sqrt(vx * vx + vy * vy);
    vx/=d, vy/=d;
    x = vx*t, y = vy*t;

    y -= max(0.0l, ceil( abs(y) / (2*h))) * (2*h) * sign(y);
    x -= max(0.0l, ceil( abs(x) / (2*h))) * (2*w) * sign(x);

    while ( true ) {
        if ( abs(y) > h/2 ) y = h*sign(y) - y ;
        else if ( abs(x) > w/2 ) x = w*sign(x) - x ;
        else break;
    }
    cout << setprecision(12) << fixed;
    cout << x << ' ' << y << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
