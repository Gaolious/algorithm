#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;
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
    template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
    _FIN& operator>> (T &n) { n=this->Int<T>(); return *this; }
};
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
    void outChar(char c) { *outp++ = c ; if ( outp - outbuf >= BUFF_LEN ) flush(); }
    void flush() { fwrite(outbuf, sizeof(char), outp - outbuf, stdout); outp = outbuf; }
    template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
    _FOUT& operator<< (T n) { outInt<T>(n); return *this; }
    _FOUT& operator<< (char c) { outChar(c); return *this; }
};

_FIN fin ;
_FOUT fout;
#ifdef fastio
#undef fastio
#endif
#define fastio {}
#define cin fin
#define cout fout
#define endl ('\n')


template <typename T> T GCD( T a, T b ) {
    return b > 0 ? GCD(b, a % b) : a;
}
const int MaxN = 50'000 ;
int mobius [ MaxN + 1] ;

void setMobius() {
    int i, j ;
    mobius[ 1 ] = 1 ;
    for ( i = 1 ; i <= MaxN ; i ++ ) {
        for ( j=i+i ; j<= MaxN ; j += i )
            mobius[j] -= mobius[i];
        mobius[i] += mobius[i-1];
    }
}

int F(int from, int to) {
    int i, a, b;
    int ret = 0, n ;
    for ( i = 1, n = 0 ; i <= from ; i = n + 1) {
        a = from / i ;
        b = to / i ;
        n = min( from / a, to / b );
        ret += (mobius[n] - mobius[i-1] ) * a * b;
    }
    return ret;
}

void process() {
    fastio;
    int T, a, b, d ;

    cin >> T ;
    setMobius();
    while ( T -- ) {
        cin >> a >> b >> d;
        int lower = min(a,b);
        int higher = max(a,b);

        cout << F(lower / d, higher / d) << endl ;
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


