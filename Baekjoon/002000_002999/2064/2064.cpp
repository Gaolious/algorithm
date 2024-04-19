#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
void dump(unsigned int mask) {
    cout << ( ( mask >> 24 ) & 0xff ) << '.'
        << ( ( mask >> 16 ) & 0xff ) << '.'
        << ( ( mask >> 8 ) & 0xff ) << '.'
        << ( ( mask >> 0 ) & 0xff ) << '\n' ;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int n, a, b, c, d, i;
    char k ;
    unsigned int subnetMask = -1, lo, hi, t;
    lo=-1, hi=0;
    cin >> n ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a >> k >> b >> k >> c >> k >> d;
        t = (a << 24) | (b<<16) | (c << 8) | d;
        lo = min(lo, t);
        hi = max(hi, t);
    }
    while ( (lo & subnetMask) != (hi & subnetMask) )
        subnetMask -= (subnetMask & -subnetMask);

    unsigned int IP = lo & subnetMask;
    dump(IP);
    dump(subnetMask);
    return 0;
}


