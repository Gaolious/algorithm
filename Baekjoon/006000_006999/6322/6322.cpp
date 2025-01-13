#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    ll a, b, c;
    int i ;
    for (i=1; cin >> a >> b >> c && ( a || b || c ) ; i ++ ) {
        if ( i>1) cout << '\n';
        cout << "Triangle #" << i <<'\n';

        if ( c < 0 )
            cout << "c = " << setprecision(3) << fixed << sqrt(a*a+b*b) << '\n';
        else {
            c = c*c - ( max(a,0ll) * max(a,0ll) + max(b,0ll) * max(b,0ll) );
            if ( c <= 0 )
                cout << "Impossible.\n";
            else if ( a < 0 )
                cout << "a = " << setprecision(3) << fixed << sqrt(c) << '\n';
            else if ( b < 0 )
                cout << "b = " << setprecision(3) << fixed << sqrt(c) << '\n';
        }
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
