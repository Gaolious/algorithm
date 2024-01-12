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
    template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
    _FIN& operator>> (T &n) { n=this->Int<T>(); return *this; }
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
#define USE_FASTIO 0
#else
#define USE_FASTIO 1
#endif

#if !USE_FASTIO
#   define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
#else
#   define fastio {}
#   define cin _fin
#   define cout _fout
#   define endl ('\n')
#endif

int T[51]={0,};
int P[51][51]={0,};

void process() {
    fastio;
    int N, M ;
    int i, j, n ;

    cin >> N >> M ;
    cin >> n ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> j ;
        T[j] = 1;
    }
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> j;
        while ( j -- )
        {
            cin >> n;
            P[i][n] = 1;
        }
    }

    queue<int> Q;
    for ( i = 1 ; i <= N ; i ++ )
        if ( T[i] == 1 )
            Q.push(i);

    while ( !Q.empty() ) {
        n = Q.front();
        Q.pop();
        for ( i = 0 ; i < M ; i ++ )
            if ( P[i][n] == 1 ) {
                for ( j = 1 ; j <= N ; j ++ ) {
                    if ( P[i][j] == 1 && T[j] == 0 ) {
                        T[j] = 1;
                        Q.push(j);
                    }
                }
            }
    }
    int ret = 0 ;

    for ( i = 0 ; i < M ; i ++ ) {
        bool found = false ;
        for ( j = 1 ; j <= N ; j ++ ) {
            if ( P[i][j] == 1 && T[ j ] == 1 ) {
                found = true ;
                break;
            }
        }
        if ( !found )
            ret ++;
    }
    cout << ret << endl;
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


