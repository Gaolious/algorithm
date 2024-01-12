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

int N, M ;

int A[100][100]={0,};
bool C[100][100]={0,};
int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

void extend(int y, int x){
    int ty, tx;
    queue< pair<int,int> > Q ;
    Q.emplace(y, x);
    if ( C[y][x] ) return ;
    if ( A[y][x] != 0 ) return ;

    while (!Q.empty()) {
        y = Q.front().first;
        x = Q.front().second;
        C[y][x] = true ;
        Q.pop();

        for ( int d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || ty >= N || tx < 0 || tx >= M ) continue;
            if ( C[ty][tx] ) continue;
            if ( A[ty][tx] != 0 ) continue;

            C[ty][tx] = true ;
            Q.emplace(ty, tx);
        }
    }
}
int Count(int y, int x) {
    int ty, tx;
    int ret = 0;
    for ( int d = 0 ; d < 4 ; d ++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || ty >= N || tx < 0 || tx >= M ) continue;
        if ( C[ty][tx] && A[ty][tx] == 0 ) ret++;
    }
    return ret;
}
void dump() {
    cout << endl;
    for ( int i = 0 ; i < N ; i ++ ) {
        for ( int j = 0 ; j < M ; j ++ ) {
            cout << A[i][j] << " " ;
        }
        cout << endl;
    }
}
void process() {
    fastio;
    int i, j , cnt;

    vector< pair<int,int> > P ;

    cin >> N >> M ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ ) {
            cin >> A[i][j];
            if ( A[i][j] == 1 )
                P.emplace_back(i, j);
        }
    }
    extend(0,0);

    for ( cnt = 0 ; !P.empty() ; cnt ++ ) {
        vector< pair<int,int> > nextPoints, will_remove ;
        for ( auto &p: P ) {
            if ( Count(p.first, p.second) >= 2 ) {
                will_remove.push_back(p);
            } else {
                nextPoints.push_back(p);
            }
        }
        for (auto &p: will_remove)
            A[p.first][p.second] = 0;
        for (auto &p: will_remove)
            extend(p.first, p.second);
//        dump();
        P.clear();
        P.assign(nextPoints.begin(), nextPoints.end());
    }
    cout << cnt << endl;
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


