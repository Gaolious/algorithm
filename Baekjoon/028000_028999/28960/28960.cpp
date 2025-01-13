#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    ll h, l, a, b;
    cin >> h >> l >> a >> b ;
    int i, j;
    for ( j = 0 ; j < 2 ; j ++ ) {
        swap(a, b);
        if ( l < a ) continue;
        if ( h*2 < b) continue;
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
