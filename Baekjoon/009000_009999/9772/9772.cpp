#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool is0(long double v) {
    return abs(v) < 1.0e-12;
}
void process(int Case) {
    long double x, y;
    while ( cin >> x >> y ) {
        if ( is0(x) || is0(y) )
            cout << "AXIS\n";
        else if ( x > 0 )
            cout << 'Q' << (y>0 ? 1 : 4) << '\n';
        else
            cout << 'Q' << (y>0 ? 2 : 3) << '\n';
        if (is0(x) && is0(y))
            break;
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
