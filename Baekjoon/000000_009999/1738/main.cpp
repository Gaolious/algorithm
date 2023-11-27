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

struct Edge {
    ll from, to, dist ;
};
const ll INF = 20'000'000'000;
bool C[101][101];

bool print(vector<int> &P, vector<bool> cycle, int from ) {
    if ( from < 1 || cycle[from] )
        return false ;

    if ( from == 1 || print(P, cycle, P[from]) ) {
        cout << from << " ";
        return true ;
    }

    return false ;
}
void process() {
    fastio;
    int N, M ;
    ll f, t, d ;
    int i, j ;
    vector<Edge> E ;

    cin >> N >> M ;
    vector<ll> D(N+1, -INF);
    vector<int> P(N+1, -1) ;
    vector<bool> cycle(N+1, false);

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> f >> t >> d ;
        E.push_back(Edge{f,t,d});
        C[f][t] = true ;
    }
    for ( int m = 1 ; m <= N ; m ++ )
        for ( f = 1 ; f <= N ; f ++ )
        {
            if ( !C[f][m] ) continue;
            for (t = 1 ; t <= N ; t ++ )
            {
                if ( !C[m][t] ) continue;
                C[f][t] = true ;
            }
        }
    D[1] = 0;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( auto e : E ) {
            if ( D[e.from] == -INF ) continue;
            if ( D[e.to] < D[e.from] + e.dist ) {
                D[e.to] = D[e.from] + e.dist;
                P[e.to] = e.from ;
                if ( i == N-1) {
                    cycle[e.to] = true ;
                    cycle[e.from] = true ;
                }
            }
        }
    }
    for ( i = 1 ; i <= N ; i ++ ) {
        if ( cycle[i] && C[i][N] ) {
            cout << "-1\n";
            return;
        }
    }
    if ( cycle[1] || cycle[N] || D[N] == -INF || !print(P, cycle, N))
        cout << "-1\n";
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


