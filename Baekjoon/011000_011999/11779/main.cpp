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
    char Char() { char c = 0; while ( !eof && (c = B()) <= ' ' ) {} return c; }
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
#   define USE_FASTIO 0
#endif


#if !USE_FASTIO
#   define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
#else
#   define fastio {}
#   define cin _fin
#   define cout _fout
const char new_line = '\n';
#   define endl (new_line)
#endif

struct EDGE {
    int t, dist ;
};
void process() {
    fastio;
    int N, M ;
    int i, j, f, t, d ;
    vector<int> ans ;

    cin >> N >> M ;

    vector< EDGE > E[1000+1];
    vector<int> P(N+1, -1);
    vector<long long int> D(N+1, 10000000000);
    priority_queue<pair<long long int, int>> Q;

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> f >> t >> d ;
        E[f].push_back(EDGE{t, d});
    }
    cin >> f >> t ;
    D[f] = 0;
    Q.emplace(0, f);
    while ( !Q.empty() ) {
        long long int cost = -Q.top().first;
        int node = Q.top().second;
        Q.pop();

        if ( cost > D[t] ) continue;

        for ( auto &e: E[node] ) {
            if ( D[ e.t ] > D[node] + e.dist ) {
                D[ e.t ] = D[node] + e.dist;
                Q.emplace(-D[e.t], e.t);
                P[e.t] = node;
            }
        }
    }
    cout << D[t] << endl ;
    for ( i = t ; i > 0 ; i = P[i] )
        ans.push_back(i);
    cout << ans.size() << endl ;
    for (auto it = ans.rbegin() ; it != ans.rend() ; it ++ )
        cout << *it << ' ';
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


