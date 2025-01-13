#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}

void process(int Case) {
    ll N, Nx, Ny, Nz;
    ll x, y, z;
    ll ans = 0 ;
    cin >> N ;

    for ( x = 1 ; x <= 63 ; x ++ ) {
        Nx = N - x*x*x*x*x;
        if ( Nx < 4 ) break;

        for ( y = 1 ; y <= 177 ; y ++ ) {
            Ny = Nx - y*y*y*y ;
            if ( Ny < 3 ) break;

            for ( z = 1 ; z <= 1000 ; z ++ ) {
                Nz = Ny - z*z*z ;
                if ( Nz < 2 ) break;
                ans += (ll)sqrt( Nz - 1 );
            }
        }
    }
    cout << ans << '\n';
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
