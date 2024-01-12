#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
bool canUse[10];
ll P10[19];
ll D[13][2][2][100'00];
ll X, A, B;
int digitLength(ll n) {
    int ret ;
    for ( ret=1 ; n > 9 ; n /= 10, ret++);
    return ret;
}
ll F(ll N, ll cumN, int remain, ll needMod) {
    if ( remain == 0 )
        return cumN > 0 && needMod == 0 ? 1 : 0 ;
    if ( N < 0 )
        return 0;

    int isFullSearch = N >= P10[remain]*10l ? 1 : 0;
    int isZeroPadding = cumN == 0 ? 1 : 0;
    int e = N >= P10[remain]*10l ? 9 : (int)((N / P10[remain])%10) ;
    int i ;
    ll &ret = D[remain][isFullSearch][isZeroPadding?0:1][needMod];
    if ( ret >= 0 )
        return ret ;

    ret = 0;
    for ( i = 0 ; i <= e ; i ++ ) {
        if ( ! canUse[i] ) {
            if ( isZeroPadding && i == 0 ) {}
            else continue;
        }

        ret += F(N - i*P10[remain], cumN + i*P10[remain], remain - 1, (needMod + i * P10[remain]) % X);
    }
    return ret;
}
int main()
{
    fastio;
    string s ;
    int i ;
    for ( P10[0]=0, P10[1]=1, i=2 ; i< 19 ; i++)
        P10[i] = P10[i-1]*10;

    cin >> X >> A >> B ;
    cin >> s ;

    for ( auto c : s) canUse[ c - '0' ] = true;

    if ( X < 10000 ) {
        memset(D, -1, sizeof(D));
        ll a = F(B, 0, digitLength(B), 0) ;

        memset(D, -1, sizeof(D));
        A--;
        ll b = F(A, 0, digitLength(A), 0) ;
        cout << a - b << '\n';
    } else {
        ll l, r , n, t;
        ll ret = 0;
        l = (A/X)*X;
        r = (B/X)*X;
        while ( l < A) l += X;
        while ( r > B) l -= X;
        for ( n = l ; n <= r ; n += X ) {
            bool can = true ;
            for ( t = n ; can && t > 0 ; t /= 10 )
                can = canUse[ t % 10 ];
            if (can) ret ++;
        }
        cout << ret << '\n';
    }
    return 0;
}