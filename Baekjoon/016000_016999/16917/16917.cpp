#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;


int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    ll A, B, C, X, Y;
    ll i, n, ans, a, b ;

    cin >> A >> B >> C >> X >> Y ;
    n = max(X, Y) * 2 ;

    ans = X * A + Y * B;
    for ( i = 0 ; i <= n ; i ++ ) {
        a = max(0ll, X-i/2);
        b = max(0ll, Y-i/2);
        ans = min( ans, i * C + a*A + b*B);
    }
    cout << ans ;

    return 0;
}


