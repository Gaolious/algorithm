#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

typedef long long int ll ;
const ll MaxM = 2000 ;
ll D[MaxM][MaxM];
ll nCr (ll n, ll r, ll m) {
    ll &ret = D[n][r];
    if ( ret < 0 ) {
        if ( n == 0 ) return r == 0 ? 1 : 0 ;
        if ( r == 0 || r == n )
            ret = 1ll;
        else {
            ret = nCr(n-1, r-1, m) + nCr(n-1, r, m);
            ret %= m ;
        }
    }
    return ret;
}
vector<ll> split_digits(ll n, ll prime) {
    vector<ll> ret;
    while ( n > 0 ) {
        ret.push_back(n % prime);
        n /= prime;
    }
    return ret;
}
ll lucas(ll n, ll k, ll prime) {
    ll ret = 1 ;
    int i ;
    vector<ll> A = split_digits(n, prime);
    vector<ll> B = split_digits(k, prime);
    for ( i = 0 ; i < A.size() || i < B.size() ; i ++ ) {
        ll N, K ;
        N = ( i < A.size() ) ? A[i] : 0;
        K = ( i < B.size() ) ? B[i] : 0;

        ret = ( ret * nCr(N, K, prime) ) % prime ;
    }
    return ret;
}
void process() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int N, K, M ;

    cin >> N >> K >> M ;
    memset(D, -1, sizeof(D));
    cout << lucas(N, K, M);
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


