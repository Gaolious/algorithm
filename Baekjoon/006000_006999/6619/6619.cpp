#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

void init() {}

ld Pow(ld a, ll n) {
    if ( n == 0 ) return 1;
    auto ret = Pow(a, n/2);
    ret = ret*ret;
    if ( n%2 ) ret *= a;
    return ret;
}
void process(int Case) {
    ll M;
    ll X, Y, N;
    ld r, rm, result;
    while( cin >> X >> Y >> N >> r ) {
        if ( X == 0 && Y == 0 && N == 0 && r == 0 ) break;
        r = r / 1200.0;
        M = N * 12 ;
        if ( r < 1.0e-18 ) {
            result = X - Y * M ;
        }
        else {
            rm = Pow(1+r, M);
            result = X*rm - Y*(rm-1)/r;
        }
        if ( result <= 1.0e-18 )
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
