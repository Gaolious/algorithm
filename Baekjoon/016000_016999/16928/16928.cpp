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

void process() {
    fastio;
    int N, M ;
    int A[101];
    int D[101];
    int i, j, k ;

    for ( i = 0 ; i <= 100 ; i ++ ) {
        A[i] = i ;
        D[i] = -1;
    }
    cin >> N >> M ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> j >> k ;
        A[j] = k ;
    }

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> j >> k ;
        A[j] = k ;
    }

    D[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<> > Q;
    Q.emplace(0, 1);

    while ( !Q.empty() ) {
        int dist = Q.top().first;
        int pos = Q.top().second;
        Q.pop();
        for ( i = 1 ; i <= 6 && pos + i <= 100 ; i ++ ) {
            int next = A[pos + i ];
            if ( D[ next ] < 0 || D[ next ] > dist + 1 ) {
                D[next] = dist + 1 ;
                Q.emplace(dist +1, next);
            }
        }
    }
    cout << D[100] << endl;
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


