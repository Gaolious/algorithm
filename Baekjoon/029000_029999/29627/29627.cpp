#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void init(){}
void process(int Case) {
    int h, m, N, x, y, i, prevT, currT;
    char c;
    cin >> N >> x >> y ;
    bool isCharging = true;
    ld rate = 100.0;

    prevT = 0 ;
    for (i = 0 ; i < N ; i ++ ) {
        cin >> h >> c >> m;
        currT = h * 60 + m ;
        if ( isCharging )
            rate = min(100.0l, rate + (ld)min( currT - prevT, y ) / (ld)y * 100.0l );
        else
            rate = max(0.0l, rate - (ld)min( currT - prevT, x ) / (ld)x * 100.0l );
        isCharging = !isCharging;
        prevT = currT;
    }

    currT = 23*60 + 59;
    if ( isCharging )
        rate = min(100.0l, rate + (ld)min( currT - prevT, y ) / (ld)y * 100.0l );
    else
        rate = max(0.0l, rate - (ld)min( currT - prevT, x ) / (ld)x * 100.0l );

    cout << setprecision(12) << fixed << rate << '\n';
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
