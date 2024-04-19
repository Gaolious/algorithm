#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
using namespace std;
typedef long long int ll;

ll Find(ll x) {
    ll l = 1, r = 1414213563ll, m, prevS;
    while ( true ) {
        m = (l+r) / 2 ;
        prevS = m * ( m - 1 ) / 2;

        if ( x > prevS + m ) l = m + 1;
        else if ( x <= prevS ) r = m - 1 ;
        else return m;
    }
}
void process() {
    ll x, len, a, b;
    cin >> x ;
    len = Find(x);
    x -= len * (len-1) / 2 ;
    a = x, b = len + 1 - x ;
    if ( len % 2 == 1 ) swap(a,b);
    cout << a << '/' << b;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


