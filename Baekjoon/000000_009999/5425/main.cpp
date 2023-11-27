#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll Sum9 [20][10];
ll nDigit[] = {
        1ll,
        1ll,
        10ll,
        100ll,
        1000ll,
        10000ll,
        100000ll,
        1000000ll,
        10000000ll,
        100000000ll,
        1000000000ll,
        10000000000ll,
        100000000000ll,
        1000000000000ll,
        10000000000000ll,
        100000000000000ll,
        1000000000000000ll,
};

ll GetSum(ll n)
{
    ll i2, j2 ;
    ll i, j;
    ll ret = 0 ;

    if ( n < 1 ) return 0ll;

    ret = 0 ;
    for ( j=n , i=0 ; j > 0 ; i ++, j/=10 );

    for ( ; i > 0 ; i --)
    {
        j = (ll)(n / nDigit[ i ]) ;
        n %= nDigit[i] ;
        if ( j == 0 ) continue ;

        i2 = i; j2 = j-1 ;
        if ( j2 < 1 ) i2-=1, j2=9;
        ret += Sum9[ i2 ][ j2 ] + j * ( 1 + n );
    }

    return ret;
}

void process() {
    fastio;
    ll N, a, b, i, j ;

    ll prev_sum = 0;
    for ( i = 1 ; i < 20 ; i ++)
    {
        for ( j = 1 ; j < 10 ; j ++ )
            Sum9[ i ][ j ] = nDigit[i] * j + prev_sum;
        for ( j = 1 ; j < 10 ; j ++ )
            prev_sum += Sum9 [ i ][ j ] ;
    }

    for ( prev_sum = 0 , i = 1 ; i < 20 ; i ++)
        for ( j = 1 ; j < 10 ; j ++ )
        {
            Sum9[ i ][ j ] += prev_sum ;
            prev_sum = Sum9[i][j];
        }

    cin >> N ;
    while ( N -- ) {
        cin >> a >> b ;
        cout << GetSum(b) - GetSum(a-1) << '\n';
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


