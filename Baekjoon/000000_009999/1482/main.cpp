#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll P10[20];
int cnt[10];

ll F(ll N, int mask, int total_digit, int remain, bool isFirst, int limitCount, int usedNumber=0, int maxCount=0) {
    int i, s, before;

    if ( remain == 0 ) {
        if ( N > 0 ) return -1;
        if ( maxCount != limitCount ) return -1;
        if ( total_digit != limitCount * usedNumber ) return -1;

        for ( i = 0 ; i < 10 ; i ++ )
            if ( cnt[i] != 0 && cnt[i] != maxCount )
                return -1;

        return 0;
    }
    if ( limitCount * usedNumber > total_digit) return -1;
    if ( total_digit % limitCount != 0 ) return -1;
    if ( total_digit > limitCount * 10 ) return -1;
    if ( maxCount > limitCount ) return -1;

    s = N < 0 ? 0 : (int)(N/P10[remain])%10;
    if ( isFirst) s = max(s, 1);
    for ( i = s ; i <= 9 ; i ++ ) {
        if ( N >= (i+1)*P10[remain] ) continue;
        if (usedNumber * maxCount > total_digit ) continue;

        before = cnt[i] ++;
        ll ret = F(
                N - i*P10[remain] ,
                mask | ( 1 << i ),
                total_digit ,
                remain-1,
                false,
                limitCount,
                before == 0 ? (usedNumber + 1) : usedNumber,
                max(maxCount, cnt[i])
        );
        if ( ret >= 0 ) {
            return  i * P10[remain] + ret;
        }
        cnt[i] --;
    }
    return -1;
}
int main()
{
    fastio;
    int remain, limitCount;
    ll N, ret ;
    int i, j, k;

    for (P10[0]=1, P10[1]=1, N=2 ; N<=19 ; N++)
        P10[N] = P10[N-1]*10;

    cin >> N ;
    for ( ret = N, remain=1 ; ret > 9 ; ret/=10, remain++);
    for ( ; remain <= 19; remain ++ ) {
        ll ans = -1;
        for ( limitCount=1 ; limitCount <= remain ; limitCount ++)
        {
            memset(cnt, 0, sizeof(cnt));
            if ( remain % limitCount != 0 ) continue;
            if ( (ret=F(N, 0, remain, remain, true, limitCount)) >= N ) {
                if ( ans < 0 || ret < ans )
                    ans = ret;
            }
        }
        if ( ans >= 0 )
        {
            cout << ans ;
            break;
        }
    }
    return 0;
}


