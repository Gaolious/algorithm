#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
template <typename T> T exGCD(T a, T b, T &x, T &y) {
    if (b == 0) { x=1, y=0; return a; }
    auto t = exGCD(b, a % b, y, x);
    y -= a / b * x;
    return t;
}

template <typename T> T gcd( T a, T b ) {
    return b > 0 ? gcd(b, a % b) : a;
}

template <typename T> T mMUL( T a, T n, T m) {
    //  (a*b) % m
    T ans ;
    for ( ans=0; n > 0 ; n/= 2, a = (a + a) % m )
        if ( n % 2 ) ans = ( ans + a ) % m;
    return ans;
}


bool F(ll a, ll b, ll s ) {
    if ( a == 0 || b == 0 ) {
        if ( a == b ) return  s == 0;
        return 0 == ( ( a == 0 ) ? s % b : s % a) ;
    }
    long long int x, y ;
    auto g = exGCD( a, b, x, y);
    if ( s % g != 0 ) return false ;
    a/=g, b/=g, s/=g;


    x = mMUL(x, s, b);
    if ( (__int128)a*x > (__int128)s ) return false ;
    y = ( (__int128)s - ((__int128)a * x ) ) / b;

    while ( y > 0 ) {
        if ( gcd( x, y ) == 1 ) return true ;
        x += b ;
        y -= a ;
    }
    return false;
}

void process() {
    long long int A, B, S ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B >> S;

    if ( F(A, B, S) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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


