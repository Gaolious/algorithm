#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    ll i, j, a, b, s;
    cin >> a >> b;
    ll ans = 0 ;
    for ( i = 1 ; i <= 9 ; i ++ ) {
        s = 0;
        for (j = 0 ; j < 18 ; j ++ ) {
            s = s * 10 + i ;
            ans += a <= s && s <= b ;
        }
    }
    cout << ans <<'\n';
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
