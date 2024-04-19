#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct DATA {
    string s ;
    int n ;
};
int N, K ;
ll D[1 << 15 ][ 101 ] ;
vector<int> P10;
vector<DATA> A;
ll F(int mask, int remain ) {
    ll &ret = D[mask][remain];
    if ( ret == -1 ) {
        if ( mask + 1 == 1 << N ) {
            ret = remain == 0 ? 1 : 0;
        } else {
            ret = 0 ;
            for ( int i = 0 ; i < N ; i ++ ) {
                if ( !( mask & ( 1 << i ) ) ) {
                    ret += F(
                    mask | ( 1 << i ) ,
                    ( remain * P10[A[i].s.length()] + A[i].n ) % K
                    );
                }
            }
        }
    }
    return ret;
}
template <typename T> T GCD( T a, T b ) {
    return b > 0 ? GCD(b, a % b) : a;
}
void process() {
    fastio;
    int t;
    int i ;
    cin >> N ;
    memset( D, -1, sizeof(D) );
    A.resize(N);
    P10.resize(100);

    for ( auto &a : A) cin >> a.s ;
    cin >> K ;

    for ( auto &a : A ) {
        t = 0 ;
        for ( auto c : a.s )
            t = (t * 10 + (c - '0')) % K ;
        a.n = t ;
    }
    P10[0] = 1 % K ;
    for ( i = 1 ; i < 100 ; i ++ )
        P10[i] = ( P10[i-1] * 10 ) % K ;

    ll ret = F(0, 0) ;
    if ( ret == 0 ) {
        cout << "0/1\n";
    } else {
        ll p = 1;
        for ( i = 2 ; i <= N ; i ++) p *= i ;
        ll g = GCD(ret, p);
        ret /= g;
        p /= g;
        cout << ret << '/' << p << '\n';
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


