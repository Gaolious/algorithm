#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll P10[19] = {};
int cnt[10]={0,};
int nUsed = 0 ;
ll D[2048][19]={0,};

int digitCount(ll n) {
    int ret = 0 ;
    while ( n > 0 ) {
        ret ++;
        n/=10;
    }
    return ret;
}

ll find(ll N, int K, int remainDigitCount, ll p10, ll mask, bool isFirst) {
    if (remainDigitCount == 0 )
        return K == nUsed ? 0 : -1;
    ll i ;
    ll &ret = D[mask][remainDigitCount];
    if ( ret >= 0 )
        return ret ;
    int s ;
    s = N < 0 ? 0 : (int)( N / p10 );
    if ( isFirst) s = max(1,s);
    for ( i = s ; i <= 9 ; i ++ ) {
        if ( cnt[i] == 0 && nUsed >= K ) continue; // 사용되지 않은 수 i, 개수 제한 <= K
        if ( N >= (i+1)*p10 ) continue; // 수 i를 사용할 때 N 보다 크거나 같은 수를 만들 수 없을 때
        if ( remainDigitCount + nUsed + ( cnt[i] == 0 ? 1:0 ) < K ) continue;
        if ( cnt[i]++ == 0 ) nUsed ++; // 사용되지 않은 수 i / 개수 +1

        ret = find(N - i*p10, K, remainDigitCount - 1, p10 / 10ll, mask | ( 1 << i ) , false);
        if ( ret >= 0 ) {
            return ret + i * p10;
        }
        if ( --cnt[i] == 0) nUsed --;
    }
    return ret = -1;
}
void process() {
    fastio;
    int i, K ;
    ll N, ret ;

    memset(D, -1, sizeof(D));

    for ( P10[0] = 1ll, i = 1 ; i < 19 ; i ++ )
        P10[i] = P10[i-1] * 10ll;

    cin >> N >> K ;

    int digitCnt = digitCount(N);
    ll p10 = P10[digitCnt - 1];

    if ( digitCnt >= K && (ret = find(N, K, digitCnt, p10, 0, true) ) >= N )
        cout << ret ;
    else {
        int len = digitCnt + 1 ;
        if (len < K ) len = K ;
        p10 = P10[len - 1];

        ret = find(p10, K, len, p10, 0, true);
        cout << ret ;
    }
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


