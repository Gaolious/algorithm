#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Buy {
    ll a, b, c;
    Buy(): a(0), b(0), c(0){}
    Buy(ll aa, ll bb, ll cc): a(aa), b(bb), c(cc){}
    ll V() {
        return a*3 + b*(5) + c*(7);
    }
};
int main()
{
    fastio;
    int i;
    int N;

    ll t;
    cin >> N ;
    vector<Buy> P (N);
    for ( auto &p: P) cin >> p.a;

    for ( i = 1 ; i < N ; i ++ ) {
        t = min(P[i-1].a, P[i].a);
        P[i-1].a -=t;
        P[i].a -= t;
        P[i].b += t;
        if ( i > 1 ) {
            t = min(P[i-1].b, P[i].a);
            P[i-1].b -=t;
            P[i].a -= t;
            P[i].c += t;
        }
    }
    ll ret = 0 ;
    for ( i = 0 ; i < N ; i ++ ) {
        ret += P[i].V();
    }

    cout << ret;

    return 0;
}


