#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MAX_BIT = 61;
const ll MAX_BITMASK = 0x1FFFFFFFFFFFFFFF;

void calculate(int nth, ll T, ll &in_buy, ll &in_sell, ll &out_buy, ll &out_sell ) {
    ll half_cycle = 1ll << nth ;
    ll cycle = half_cycle * 2 ;

    ll cycle_times = T / cycle ;
    in_buy = cycle_times * half_cycle;
    in_sell = cycle_times * half_cycle;
    out_buy = 0;
    out_sell = 0;

    ll remain = T - cycle * cycle_times;

    in_buy += min(remain, half_cycle);
    remain = max( 0ll, remain - half_cycle);
    in_sell += min(remain, half_cycle);

    remain = cycle * (cycle_times+1) - T;
    out_sell += min(remain, half_cycle);
    remain = max( 0ll, remain - half_cycle);
    out_buy += min(remain, half_cycle);
}
void process() {

    ll N, T, j;
    ll ret = 0 ;
    ll cum;

    int i ;
    char c ;
    cin >> N >> T;

    vector<ll> A(N+1);
    vector<ll> B(N+1);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> c ;
        A[i] = (int)(c-'1');
    }
    ret = 0;

    N = min(MAX_BIT, N);
    cum = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        cum |= ( 1ll << i ) * A[i];
    }

    for ( i = 0 ; i < N ; i ++ ) {
        ll b1, s1, b2, s2;
        ll b3, s3, b4, s4;
        calculate(i, cum, b1, s1, b2, s2);
        b2 = min(b2, T);
        s2 = min(s2, T-b2);

        ret += min(b2, s2) ;
        calculate(i, T+cum, b3, s3, b4, s4);

        ret += min(b3 - b1 - b2, s3 - s1 - s2);
    }
    for ( i = MAX_BIT ; i < A.size() - 1 ; i ++ )
        if ( A[i] == 0 ) B[i] += MAX_BITMASK - cum + 1;

#ifdef AJAVA_DEBUG
    for ( i = 0 ; i < A.size() - 1 ; i ++ ) cout << A[i]; cout << endl;
    for ( i = 0 ; i < A.size() - 1 ; i ++ ) cout << B[i]; cout << endl;
#endif
    ;
    for ( i=0, A[i] += T-1 ; i < A.size() - 1 ; i ++ ) {
        A[i+1] += A[i]/2;
        A[i] %= 2;
    }

    #ifdef AJAVA_DEBUG
    for ( i = 0 ; i < A.size() - 1 ; i ++ ) cout << A[i]; cout << endl;
    for ( i = 0 ; i < A.size() - 1 ; i ++ ) cout << B[i]; cout << endl;
#endif

    for ( i = MAX_BIT ; i < A.size() - 1 ; i ++ )
        if ( A[i] == 1 && B[i] > 0 )
            ret += min( B[i], T - (MAX_BITMASK-cum+1) ), B[i]--;

    #ifdef AJAVA_DEBUG
    for ( i = 0 ; i < A.size() - 1 ; i ++ ) cout << A[i]; cout << endl;
    for ( i = 0 ; i < A.size() - 1 ; i ++ ) cout << B[i]; cout << endl;
#endif

    cout << ret << '\n';
}
void process2() {
    int i;
    char c;

    ll N, T, j;
    ll ret = 0 ;
    cin >> N >> T;

    vector<ll> A(N+1);
    vector<ll> B(N+1);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> c ;
        A[i] = (int)(c-'1');
    }

    for ( i = 0 ; i < T ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) if ( A[j] == 1 && B[j] > 0 ) B[j] --, ret++;
        for ( j = 0 ; j < N ; j ++ ) if ( A[j] == 0 ) B[j] ++;

#ifdef AJAVA_DEBUG

        cout << "i = " << i << " : " << ret << endl;
        for ( j = 0 ; j < N ; j ++ ) cout << A[j]; cout << endl;
        for ( j = 0 ; j < N ; j ++ ) cout << B[j]; cout << endl;
#endif

        A[0]++;

        for ( j = 1 ; j <= N ; j ++ ) { A[j] += A[j-1]/2; A[j-1] %= 2; }

    }
    cout << ret << '\n';
}
int main()
{
    fastio;
    process();
    return 0;
}


