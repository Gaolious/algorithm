#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    ll x1, y1, r1;
    ll x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    x2 -= x1;
    y2 -= y1;
    if ( x2*x2 + y2*y2 >= (r1+r2)*(r1+r2) )
        cout << "NO\n";
    else
        cout << "YES\n";
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
