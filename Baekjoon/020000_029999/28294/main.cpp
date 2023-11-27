#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 1'000'000'007;

ll POW(ll n, ll a) {
    if ( a == 0 ) return 1 ;
    else if ( a % 2 == 0 ) {
        ll t = POW(n, a/2);
        return t * t % MOD ;
    }
    else {
        return n * POW(n, a-1) % MOD;
    }
}
ll InvPow(ll n) {
    return POW(n, MOD-2);
}

int main()
{
    fastio;
    /*
     * i = 0 : ( N^a - N(a-1) ) * N * (N-1)^0       => (N^(a+1) - N^a) * (N-1)^0
     *                                              => N^a * (N-1)^(i+1)
     *                                                 4^3 * 3 = 192
     *      한변길이 : N^a / 제외된 길이 : N^(a-1) / 개수 : N
     *
     * i = 1 : ( N^(a-1) - N(a-2) ) * N * (N-1)^1   => ( N^(a) - N^(a-1) ) * (N-1)
     *                                              => N^(a-i) * (N-1)^(i+1)
     *                                                 4^2 * 9 = 144
     *      한변길이 : N^(a-1) / 제외된 길이 : N^(a-2) / 개수 : N * (N-1)
     *
     * i = 2 : ( N^(a-2) - N(a-3) ) * N * (N-1)^2   => ( N^(a-1) - N^(a-2) ) * (N-1)^2
     *                                              => N^(a-i) * (N-1)^(i+1)
     *                                                 4 * 3^3 = 108
     *      한변길이 : N^(a-2) / 제외된 길이 : N^(a-3) / 개수 : N * (N-1)^2
     *
     * i = 3 : N^(a-3) * N * (N-1)^3                => N^(a-2) * (N-1)^3
     *      한변길이 : N^(a-3) / 제외된 길이 : 0 / 개수 : N * (N-1)^3
     *
     * -----------------------------------------------------------
     * i=0 : N^(a+1) * (N-1)^0    / N^(a+0) * (N-1)^0     => N^a * (N-1) * [ (N-1)/N ] ^ 0
     * i=1 : N^(a+0) * (N-1)^1    / N^(a-1) * (N-1)^1     => N^a * (N-1) * [ (N-1)/N ] ^ 1
     * i=2 : N^(a-1) * (N-1)^2    / N^(a-2) * (N-1)^2     => N^a * (N-1) * [ (N-1)/N ] ^ 2
     * i=3 : N^(a-2) * (N-1)^3
     *
     * n0 = N^a * (N-1)
     * r = (N-1) / N
     *                          (N-1)^a
     *                     1 - --------
     *                           N^a
     * Sn = N^a * (N-1) * --------------    + N * (N-1)^a
     *                          (N-1)
     *                     1 - --------
     *                            N
     *
     *                 N^a - (N-1)^a
     *               ---------------
     *                     1
     *    = (N-1) * ------------------    + N * (N-1)^a
     *                     1
     *               ----------------
     *                     N
     *
     *    = (N-1) * N * [ N^a - (N-1)^a ] + N * (N-1)^a
     *    = (N-1) * N * [ N^a - (N-1)^a + (N-1)^(a-1) ]
     */
    ll N, a, S ;

    cin >> N >> a ;
    S = (POW(N, a) - POW(N-1, a) + MOD + POW(N-1, a-1)) % MOD * N % MOD * (N-1) % MOD;
    cout << S ;
}


