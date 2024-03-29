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
#define fastio {}
#define cin fin
#define cout fout
#define endl ('\n')

int Cycle[100'000+1]={0,};
bool visited[100'000+1]={0,};
int A[100'000+1]={0,};
int findCycle(int startIndex) {
    if ( visited[startIndex] ) return 0 ;
    int i, j, cnt ;
    cnt = 0;
    for ( i = startIndex ; !visited[i] ; i = A[i]) {
        visited[i] = true ;
        Cycle[cnt++] = i ;
    }
    for ( j = 0 ; j < cnt ; j ++ )
        if ( Cycle[j] == i ) {
            return cnt - j;
        }
    return 0;
}
void process() {
    fastio;
    int T, N, i, c, ret;
    cin >> T ;

    while ( T -- ) {
        cin >> N ;
        memset(visited, 0, sizeof(visited));
        memset(Cycle, 0, sizeof(Cycle));
        memset(A, 0, sizeof(A));

        for ( i = 1 ; i <= N ; i ++ )
            cin >> A[i];
        for ( ret = 0, i = 1 ; i <= N ; i ++ )
            ret += findCycle(i);

        cout << N - ret << '\n';
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


