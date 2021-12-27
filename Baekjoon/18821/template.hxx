// 소수 판별
template <typename T> inline T ModAdd(T a, T b, T m) {
    a %= m;
    b %= m ;
    return a > m - b ? a - (m-b) : a + b;
}
template <typename T> inline T ModMul(T a, T b, T m ) {
    a %= m ;
    b %= m ;
    T r ;
    for ( r=0 ; b > 0 ; b /=2 ) {
        if ( b&1 )
            r = (r + a) % m ;
        a = ModAdd(a, a, m);
    }
    return r ;
}

template <typename T> inline T ModPow(T a, T n, T m) {
    a %= m ;
    T r  ;
    for ( r=1 ; n > 0 ; n /= 2 ) {
        if ( n % 2 == 1 )
            r = (r*a) % m ; // ModMul(r, a, m);
        a = (a*a) % m; // ModMul(a, a, m);
    }
    return r ;
}

template <typename T> inline bool miller(T n, T a) {
    T d ;
    for ( d = n - 1 ; d % 2 == 0 ; d /= 2 ) {
        if (ModPow(a, d, n) == n - 1 )
            return true ;
    }
    T t = ModPow(a, d, n);
    return ( t == n-1 || t == 1 );
}

template <typename T> inline bool is_prime(T n) {
    if ( n == 2 ) return true;
    if ( n < 2 || n % 2 == 0 ) return false ;

//    for ( T a: {2, 3, 5, 7, 11} ) {
    for ( T a: {2, 3} ) {
        if ( !miller(n, a) )
            return false ;
    }
    return true;
}


////////////////////////////
// GCD

int gcd(int a, int b) {
    if ( b > 0 ) return gcd (b, a % b);
    return a;
}

