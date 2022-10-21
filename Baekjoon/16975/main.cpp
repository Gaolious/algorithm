#include <bits/stdc++.h>
//#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
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
#define fastio {}
#define cin fin
#define cout fout
#define endl ('\n')

template <typename T>
class SegTree {
    vector<T> Tree;
    vector<T> Lazy;
    int N ;
    int size ;

    void _build(int idx, int s, int e) {
        for ( int i = this->size + this->N - 1 ; i > 1 ; i--)
            Tree[i/2] += Tree[i];
    }

    void _update_lazy(int idx, int s, int e) {
        if (this->Lazy[idx] != 0) {
            this->Tree[idx] += (e-s+1) * this->Lazy[idx];
            if (s != e ) {
                this->Lazy[idx * 2] += this->Lazy[idx];
                this->Lazy[idx * 2 + 1] += this->Lazy[idx];
            }
            this->Lazy[idx] = 0;
        }
    }

    void _update(int idx, int s, int e, int l, int r, T diff ) {
        this->_update_lazy(idx, s, e);

        if (s > r || e < l ) return;

        if (l <= s && e <= r )
        {
            this->Tree[idx] += (e - s + 1) * diff ;
            if ( s != e ) {
                this->Lazy[idx * 2] += diff;
                this->Lazy[idx * 2 + 1] += diff;
            }
        }
        else {
            int m = ( s + e ) / 2 ;
            this->_update(idx * 2, s, m, l, r, diff);
            this->_update(idx * 2 + 1, m + 1, e, l, r, diff);
            this->Tree[idx] = this->Tree[idx*2] + this->Tree[idx*2+1];
        }

    }

    T _query(int idx, int s, int e, int l, int r ) {
        this->_update_lazy(idx, s, e);
        if (s > r || e < l )
            return 0;
        if (l <= s && e <= r) {
            return this->Tree[idx];
        }
        int m = ( s + e ) / 2 ;
        return this->_query(idx * 2, s, m, l, r) + this->_query(idx * 2 + 1, m + 1, e, l, r);
    }

public :
    SegTree(int N) {
        this->N = N ;
        for ( this->size = 1 ; this->size < N ; this->size *= 2 ){}
        this->Tree.resize(this->size*2, 0);
        this->Lazy.resize(this->size*2, 0);
    }
    T &data(int idx) {
        return this->Tree[this->size + idx];
    }
    void init() {
        this->_build(1, 0, this->N - 1 );
    }
    void update(int rangeLeft, int rangeRight, T diff) {
        this->_update(1, 0, this->size-1, rangeLeft, rangeRight, diff);
    }
    T query(int rangeLeft, int rangeRight) {
        return this->_query(1, 0, this->size-1, rangeLeft, rangeRight);
    }
    void dump(){
#ifdef AJAVA_DEBUG
        int i, j ;
        printf("\n");
        for ( i = 1 ; i <= this->size ; i *= 2 ) {
            for ( j = 0 ; j < i ; j ++ )
                printf("%3lld ", this->Tree[i+j]);
            printf("\n");
        }
#endif
    }

};

void process() {
    fastio;
    int N, M ;
    int i;
    int a, b, c, d ;

    cin >> N ;
    SegTree<ll> tree(N);

    for ( i = 0 ; i < N ; i ++ )
        cin >> tree.data(i);

    cin >> M ;
    while ( M -- ) {
        cin >> a ;
        if ( a == 1 ) {
            cin >> b >> c >> d ;
            tree.update(b-1, c-1, d);
        } else if ( a == 2 ) {
            cin >> b ;
            cout << tree.query(b-1, b-1) << endl;
        }
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


