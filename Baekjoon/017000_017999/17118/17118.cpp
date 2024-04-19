#include <bits/stdc++.h>
using namespace std;

#define BUFF_LEN (1<<21)

struct _FIN {
    char *p;
    char buf[BUFF_LEN+1];
    int last_read;
    bool eof;

    _FIN() { p=buf+BUFF_LEN; last_read=0; eof=false;}
    char B() {
        if ( p - buf >= BUFF_LEN ) last_read = (int)fread(p=buf, 1, BUFF_LEN, stdin);
        if ( last_read < BUFF_LEN && (int)( p - buf) >= last_read ) { eof = true; return 0; }
        return *p++;
    }
    char Char() { char c = 0; while ( !eof && (c = B()) <= ' ' ) ; return c; }
    template <typename T> T Int() {
        char c = 0; T n; bool flag = true ;
        while ( !eof && (c = B()) <= ' ' ) ;
        if ( c == '-' ) flag = false, c = B();
        for ( n=0 ; !eof && '0' <= c && c <= '9'; c = B() ) n = n * 10 + c - '0' ;
        return flag ? n : -n ;
    }
    string Word() {
        string ret ;
        char c = 0 ;
        while ( !eof && (c = B()) <= ' ' ) ;
        for ( ; !eof && c > ' '; c = B() ) ret.push_back(c);
        return ret;
    }
    template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
    _FIN& operator>> (T &n) { n=this->Int<T>(); return *this; }
    _FIN& operator>> (string &s) { s = this->Word(); return *this; }
} _fin;
struct _FOUT {
    char *outp;
    char outbuf[BUFF_LEN + 20];
    _FOUT() { outp = outbuf; }
    ~_FOUT() { if ( outp>outbuf) flush(); }
    template <typename T> void outInt(T &n) {
        if ( n < 0 ) n = -n, *outp++ = '-';
        char *end = outp;
        do { *end++ = (n%10) + '0'; n/=10; } while ( n > 0 );
        reverse(outp, end);
        outp = end ;
        if ( outp - outbuf >= BUFF_LEN ) flush();
    }
    void outString(string s) { for (auto c : s) outChar(c); }
    void outChar(char c) { *outp++ = c ; if ( outp - outbuf >= BUFF_LEN ) flush(); }
    void flush() { fwrite(outbuf, sizeof(char), outp - outbuf, stdout); outp = outbuf; }
    template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
    _FOUT& operator<< (T n) { outInt<T>(n); return *this; }
    _FOUT& operator<< (char c) { outChar(c); return *this; }
    _FOUT& operator<< (string s) { outString(s); return *this; }
} _fout;


#ifdef AJAVA_DEBUG
#   define USE_FASTIO 0
#else
#   define USE_FASTIO 1
#endif


#if !USE_FASTIO
#   define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
#else
#   define fastio {}
#   define cin _fin
#   define cout _fout
#   define endl ('\n')
#endif
typedef long long int ll ;

vector<ll> primes;
bool isPrime(ll n) {
    for (auto p : primes ) {
        if ( p * p > n ) break;
        if ( n % p == 0 ) return false ;
    }
    return true ;
}
ll getNextPrime() {
    if ( primes.empty() )
        primes.push_back(2);
    else {
        ll n = primes.back() ;
        if ( n % 2 == 0 ) n ++ ;
        else n += 2 ;
        for (; ; n += 2 ) {
            if (isPrime(n) ) {
                primes.push_back(n);
                break;
            }
        }
    }
    return primes.back();
}


ll mMUL( ll a, ll n, ll m) {
    // a*n % m
    ll ans;
    for ( ans=0; n > 0 ; n/= 2, a = (a + a) % m )
        if ( n % 2 )
            ans = ( ans + a ) % m;
    return ans;
}

void process() {
    fastio;
/*
 * 키파는 소수를 좋아한다. 키파가 제일 좋아하는 소수를 p라 하자.
 * a = 860798509, b = 198609463, N = p, x0 = n으로
 *
 * LCG를 돌려서 xp의 값을 출력하라.
 * LCG(Linear Congruential Generator)의 정의는 다음과 같은 수열 {xi}이다: 모든 자연수 k에 대해,
 *  x(k) = a * x(k-1) + b (mod N), 0 ≤ x(k) < N.

LCG는 다양한 곳에서 사용되는데, 예를 들어 C의 rand(), Java의 Random.nextInt(), 그리고 제1회 구데기컵의 이 문제가 있다.
 * */
    // n = 1159672501
    // x(p) = ?
    // 860798509 * X(p-1) +
    ll A = 860798509;
    ll B = 198609463;
    ll p, x;

    // x1 = a * x0 + b
    // x2 = a * x1 + b
    //    = a * ( a * x0 + b ) + b
    //    = a^2 * x0 + a * b + b
    // x3 = a^3 * x0 + a^2 * b + a * b + b
    // a^(1000000007) * x0 + a^(1000000006)*b
    p = 1000000007;
    ll a, ret ;
    int i;
    ll x0 = 1159672501 ;
    cout <<  (x0 * 860798509 + 198609463 ) % p << endl ;
    cout <<  (mMUL(x0,860798509,p) + 198609463 ) % p << endl ;
    ret = 0;
    a = 1;
    for ( i = 0 ; i < p ; i ++ ) {
        ret = ( ret + a * B ) % p ;
        a = (a*A) % p;
    }
    cout << "a^1000000007 = " << a << endl ;
    cout << "sum 0 to " << i << " = " << ret << endl ;
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


