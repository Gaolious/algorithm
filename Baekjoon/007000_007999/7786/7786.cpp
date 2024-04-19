#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

// digit Sum
long long int ZCount[10][10]={0ll,}; // zero padding count
long long int NCount[10][10]={0ll,}; // none zero count
void getN(long long int N, long long int &n10, int &i)
{
    for ( i=1, n10 = 1 ; n10*10 <= N ; i++)
        n10 *= 10ll;
}

ll F(ll N) {
    ll cnt[10]={0,};
    ll z;
    int i, j ;
    int ndigit;
    getN(N, z, ndigit);

    for ( i = 0 ; i < 10 ; i ++ )
        cnt[ i ] += NCount[ ndigit - 1 ][ i ] ;

    for ( i = 1 ; i <= (N/z)%10 ; i ++ )  // N= 2x,xxx => 1 x 10,000, 2 X x,xxx
    {
        cnt[ i ] += min(z, N - i*z + 1ll ) ;
        for ( j = 0 ; j < 10 && i > 1 ;j ++ )
            cnt[ j ] += NCount[ ndigit - 1 ][ j ] ;
    }

    for ( N %=z, z/=10, ndigit-- ; z > 0 ; z /= 10, ndigit -- )
    {
        for ( i = 0 ; i <= (N/z)%10 ; i ++ )
        {
            cnt[ i ] += min(z, N - i*z + 1ll );
            for ( j = 0 ; j < 10 && i > 0 ;j ++ )
                cnt[ j ] += ZCount[ ndigit-1 ][ j ] ;
        }
        N %= z;
    }
    ll ret = 0 ;
    for ( j = 0 ; j < 10 ;j ++ ) {
        ret += j * cnt[j];
    }
    return ret;
}
void pre() {
    int i, j ;
    ll z, t;
    for ( i = 1, z = 1ll, t=1ll ; i < 10 ; i ++, z *= 10ll, t=t*10ll + 1ll )
    {
        for ( j = 0 ; j < 10 ; j ++ )
            NCount[i][j] = ZCount[ i ][ j ] = i * z ;
        NCount[i][0] -= t ;
    }
}
int main()
{
    ll a, b;
    fastio;
    pre();
    cin >> a >> b;
    cout << F(b) - F(a-1) << '\n';
    return 0;
}


