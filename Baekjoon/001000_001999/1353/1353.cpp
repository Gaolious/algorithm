#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

const ll MaxN = 1'000'000'000ll;
const ld e = 2.7182818284590452353602874713526624977572l;

void init(){
}
void process(int Case) {
    ll S, P;
    ld p;
    cin >> S >> P ;

    if ( pow(e, S/e) >= P ) {
        if ( S == P ) {
            cout << 1;
            return;
        }
        p = -1;
        for (int i = 2;; i++) {
            ld l = (long double) S / i;
            ld r = pow(P, 1.0l / i);
            if ( p > l ) break;
            if ( l >= r ) {
                cout << i;
                return;
            }
        }
    }
    cout << -1 ;
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
