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
    void outString(string &s) { for (auto c : s) outChar(c); }
    void outChar(char &c) { *outp++ = c ; if ( outp - outbuf >= BUFF_LEN ) flush(); }
    void flush() { fwrite(outbuf, sizeof(char), outp - outbuf, stdout); outp = outbuf; }
    template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
    _FOUT& operator<< (T &n) { outInt<T>(n); return *this; }
    _FOUT& operator<< (char &c) { outChar(c); return *this; }
    _FOUT& operator<< (string &s) { outString(s); return *this; }
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

void process() {
    fastio;
    ll N, c3, c2, c1, s;
    ll n2, n1;
    ll min3, min2, min1, max1;

    int i, j, k;

    vector<ll> A(6);
    int Connect[6][6] = {
            {0, 1, 1, 1, 1, 0},
            {1, 0, 1, 1, 0, 1},
            {1, 1, 0, 0, 1, 1},
            {1, 1, 0, 0, 1, 1},
            {1, 0, 1, 1, 0, 1},
            {0, 1, 1, 1, 1, 0},
    };
    cin >> N;
    for (s = 0, i = 0; i < 6; i++){
        cin >> A[i];
        s += A[i];
    }

    min3 = min2 = min1 = 10000000000000000 ;
    max1 = -min1;
    for ( i = 0 ; i < 6 ; i ++ ) min1 = min( min1, A[i] ), max1 = max(max1, A[i]);
    for ( i = 0 ; i < 6 ; i ++ ) {
        for ( j = i+1 ; j < 6 ; j ++ ) {
            if ( !Connect[i][j] ) continue;

            min2 = min( min2, A[i] + A[j] );

            for ( k = j+1 ; k < 6 ; k ++ ) {
                if ( !Connect[i][k] || !Connect[j][k]) continue;
                if ( j == k ) continue;
                min3 = min(min3, A[i] + A[j] + A[k]);
            }
        }
    }
    if ( N == 1 ) {

        cout << s - max1 << endl ;

    } else {

        n1 = max( 0ll, N-1);
        n2 = max( 0ll, N-2);

        c3 = 4 ;
        c2 = n1 * 4 + n2 * 4;
        c1 = n2 * n1 * 4 + n2 * n2;

        cout << c1 * min1 + c2 * min2 + c3 * min3 << endl;
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


