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
ll D[4'000'000+1]={0,};
vector<int> A;
int N, S;

void dfs1(int idx, ll s){
    if ( idx == A.size() / 2 ) {
        if ( -2'000'000 <= s && s <= 2'000'000 )
            D[ s + 2'000'000 ] ++;
    }
    else {
        dfs1(idx+1, s);
        dfs1(idx+1, s + A[idx]);
    }
}
ll dfs2(int idx, ll s ) {
    if ( idx == N ) {
        if ( -2'000'000 <= S - s && S - s <= 2'000'000 )
            return D[ S - s + 2'000'000 ];
        else
            return 0;
    }
    else {
        ll ret = 0 ;
        ret += dfs2(idx+1, s);
        ret += dfs2(idx+1, s + A[idx]);
        return ret ;
    }
}
void process() {
    fastio;
    int i, j ;
    cin >> N >> S ;
    A.resize(N);
    for ( i = 0 ; i < N ; i ++ )
        cin >> A[ i ] ;
    std::sort(A.begin(), A.end());

    dfs1(0, 0);
    ll ret = dfs2(A.size()/2, 0);
    if ( S == 0 ) ret --;
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


