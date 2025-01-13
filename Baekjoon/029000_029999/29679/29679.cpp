#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void init(){
}
void process(int Case) {
    ld t, r, v;
    cin >> t >> r >> v;
    cout << setprecision(12) << fixed << max(0.0l, v - max( r/t, 2*r/t));
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
