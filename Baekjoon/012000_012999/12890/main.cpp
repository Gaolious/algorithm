#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll D[50][50][20];
int d1, d2 ;

ll F(ll N, int c1, int c2, int remain, ll p10, bool isFirst ) {
    if (p10 == 0)
        return ( N <= 0 && c1 <= 0 && c2 <= 0 ) ? 0 : -1;
    if ( remain < c1+c2)
        return -1;

    ll &ret = D[20 +  c1][20 + c2][remain];
    if ( ret < 0 ) {
        int s = N < 0 ? 0 : (int)(N/p10);
        int next_c1, next_c2 ;
        if (isFirst) s = max(1, s);
        for ( int i = s ; i <= 9 ; i ++ ) {
            next_c1 = ( i == d1 ) ? c1-1 : c1;
            next_c2 = ( i == d2 ) ? c2-1 : c2;
            if ( N >= (i+1)*p10 ) continue;
            ret = F( N - i*p10, next_c1, next_c2, remain-1, p10/10, false);
            if ( ret >= 0 ) {
                return ret + i * p10 ;
            }
        }
    }
    return ret = -1;
}
int main()
{
    fastio;
    ll N ;
    int c1, c2 ;

    memset(D, -1, sizeof(D));

    cin >> N >> d1 >> c1 >> d2 >> c2 ;

    int len;
    ll p10, ret;

    for ( len = 1, p10=1 ; ; len++, p10 *=10 ) {
        if ( (ret = F(N, c1, c2, len, p10, true) ) >= N )
        {
            cout << ret << '\n';
            break;
        }
    }
    return 0;
}
