#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

const ld EPS = 1.0e-12;
void init(){
}
void process(int Case) {
    ll a, b, S, sqt, L;
    // 정사각형 L
    // (L-a) * (L-b) = S
    // L^2 - (a+b)L + ab - S = 0;

    cin >> a >> b >> S ;

    if ( (a+b)*(a+b) - 4*(a*b-S) < 0 )
        cout << "-1\n";
    sqt = (ld)(sqrt( (ld)((a+b)*(a+b) - 4*(a*b-S)) ) + EPS);

    for (auto sq: {-sqt , sqt }) {
         L = (a+b+sq) / 2 ;
         if ( L > min(a,b) && (L-a)*(L-b) == S) {
             cout << L << '\n';
             return;
         }
    }
    cout << "-1\n";
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
