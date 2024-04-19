#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
using namespace std;
typedef long long int ll;

ll P10[15]={1ll,};
ll InverseNumber(ll n, int digits) {
    ll ret = 0;
    int i ;
    for ( i=0, ret = 0 ; i < digits ; i++, n /= 10 )
        ret = ret * 10 + n % 10 ;
    return ret;

}

ll solve(ll N, int l, int r) {
    ll lv, rv, n ;
    bool inv = false;

    ll s ;
    ll L, R ;

    if ( N == 0 ) return 0 ;
    if ( l >= r ) return -1;

    L = ( N / P10[r-l] ) % 10ll ;
    R = ( N % 10 );

    s = N < 10 ? R : L + R;
    if ( s == 0 )
        lv = rv = l == 0 ? 1 : 0;
    else if ( s == 9 && L < 9)
        lv = L + 1, rv = 0, inv = true ;
    else if ( s == 10)
        lv = L, rv = 0;
    else
        return -1;
    n = N - ( (lv * P10[r - l] + rv ) - ( rv * P10[r - l] + lv) );
    if ( inv ) n = -n;

    if ( n % 10 != 0 || n < 0 ) return -1 ;
    n /= 10;

    ll ret;

    if ( n == 0 )
        return lv * P10[r - l] + rv ;
    else if ( (ret = solve(n, l+1, r-1)) >= 0 ) {
        ret = inv ? InverseNumber(ret, r-l-1) : ret;
        n = lv * P10[r-l-1] + ret ;
        n = n * 10 + rv ;
        return n;
    }
    else
        return -1;
}

void process() {
    fastio;
    int i ;
    ll N, ret ;
    cin >> N ;
    for ( i = 1 ; i < 15 ; i ++ ) P10[i] = P10[i-1] * 10ll;

    if ( N % 9 == 0 )
    {
        for ( i = 0 ; i <= 12 ; i ++ ) {
            if ( (ret = solve(N, 0, i) ) >= 0 ) {
                cout << ret << endl ;
                return;
            }
        }
    }
    cout << "-1\n";
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


