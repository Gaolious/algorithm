#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void init(){
}
void process(int Case) {
    ld H, W, w1, w2;
    ld ans;

    cin >> H >> W >> w1 >> w2 ;
    ans = w1 * W ;
    ans += (w1+w2)*H ;
    ans += sqrt( H*H+(w2-w1)*(w2-w1))*W;
    cout << setprecision(12) << fixed << ans ;
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
