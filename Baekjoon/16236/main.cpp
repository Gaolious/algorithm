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

#define USE_FASTIO 0
#if USE_FASTIO
#   define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
#else
#   define fastio {}
#   define cin _fin
#   define cout _fout
#   define endl ('\n')
#endif
struct Point {
    int x, y;
    int dist ;
    bool operator< (const Point &o) const {
        if ( dist != o.dist ) return dist < o.dist ;
        return ( y == o.y ) ? x < o.x : y < o.y ;
    }
};

Point shark{};
int A[20][20]={0,};
int N ;
int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

void input() {
    cin >> N ;
    int i, j, n ;

    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> A[i][j] ;
            if ( A[i][j] == 9 ) {
                shark.x = j;
                shark.y = i;
                shark.dist = 0;
                A[i][j] = 0;
            }
        }
}
Point update_dist(int x, int y, int shark_size) {
    int tx, ty;
    int d ;
    int D[20][20]={0,};
    Point ret = { -1, -1, N*N+10};

    queue<Point> Q;
    Q.push(Point{x, y, 1});
    D[y][x] = 1;

    while ( !Q.empty() ) {
        Point p = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            tx = p.x + dx[d];
            ty = p.y + dy[d];
            if ( tx < 0 || ty < 0 || tx >= N || ty >= N ) continue;
            if ( A[ty][tx] > shark_size ) continue;
            if ( D[ty][tx] != 0 ) continue;
            if ( p.dist + 1 > ret.dist ) continue;

            if ( D[ty][tx] == 0 || D[ty][tx] > p.dist + 1 ) {
                D[ty][tx] = p.dist + 1 ;
                Point next = { tx, ty, p.dist + 1 };
                Q.push(next);


                if ( A[ty][tx] > 0 && A[ty][tx] < shark_size && next < ret ) {
                    ret = next;
                }
            }
        }
    }
    return ret;
}
void process() {
    fastio;
    input();
    int shark_size, ret, cnt ;
    for ( ret = cnt = 0 , shark_size = 2 ; ; )
    {
        auto next = update_dist(shark.x, shark.y, shark_size);
        if ( next.x < 0 ) break;

        cnt++;
        A[next.y][next.x] = 0;
        ret += next.dist - 1;
        shark = next;

        if ( cnt == shark_size )
        {
            shark_size ++ ;
            cnt = 0;
        }
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


