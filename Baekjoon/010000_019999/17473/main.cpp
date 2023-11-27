#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
//typedef long long int ll;
//typedef unsigned long long int ull;
typedef unsigned int ll ;

using namespace std;

#define BUFF_LEN ( 1<< 21 )
class FIN_fread
{
    char buf[BUFF_LEN];
    char *p;
    int last_read;
public :
    FIN_fread()
    {
        this->p = buf + BUFF_LEN ;
        this->last_read = 0;
    }
    ~FIN_fread() {
    }
    void skip() { while ( this->p && *this->p && *this->p <= ' ' ) this->p++; }
    bool _byte(char &c)  {
        if ( p - buf >= BUFF_LEN )
        {
            last_read = (int)fread(buf, 1, sizeof(buf), stdin);
            p = buf ;
        }
        else if ( last_read < BUFF_LEN )
        {
            if ( (int)( p - buf) >= last_read ) // EOF
                return false;
        }
        c = *p++;
        return true ;
    }
    bool Char(char &c) { this->skip(); return this->_byte(c); }
    bool Line(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->_byte(c) && c > 0 && c != '\n' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    bool Word(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->_byte(c) && c > 0 && c > ' ' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    template<typename T> bool Int(T &n)
    {
        char c ;
        bool flag = true ;
        n = 0 ;
        this->skip();
        if ( !this->_byte(c) )  return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( !this->_byte(c) ) return false ;
        }

        while ( c > ' ' )
        {
            n = n * 10 + c - 48 ;
            if ( !this->_byte(c) ) break;
        }
        if ( !flag ) n = -n;
        return true ;
    }
    template<typename T> bool Int(T &a, T &b) { return this->Int(a) && this->Int(b); }
    template<typename T> bool Int(T &a, T &b, T &c) { return this->Int(a, b) && this->Int(c); }
    template<typename T> bool Int(T &a, T &b, T &c, T &d) { return this->Int(a, b) && this->Int(c, d); }
};

class FOUT
{
    char out[BUFF_LEN]{};
    int nOut ;
public:
    FOUT () { this->nOut = 0; }
    ~FOUT() { this->write_flush(); }
    void write_flush(){
        if ( this->nOut > 0 ) fwrite(this->out, 1, this->nOut, stdout);
        this->nOut = 0;
    }
    void write_Char(char c) { if ( this->nOut >= BUFF_LEN ) this->write_flush(); this->out[ this->nOut ++ ] = c ; }
    void write_CharLn(char c) { this->write_Char(c); this->write_Char('\n'); }
    void write_Str(char *c) { while ( c && *c) this->write_Char(*c++); }
    void write_Str(const char *c) { while ( c && *c) this->write_Char(*c++); }
    template<typename T> void write_Int(T a)
    {
        if ( a < 0 )
        {
            this->write_Char('-');
            a *= -1;
        }
        else if ( a == 0 )
            this->write_Char('0');
        char buff[30];
        int nBuff = 0;
        for ( int i = 0 ; a > 0; a /= 10 )
            buff[nBuff++] = '0' + (a%10);
        while ( nBuff > 0 )
            write_Char(buff[--nBuff]);
    }
    template<typename T> void write_IntLn(T a)
    {
        write_Int(a);
        write_Char('\n');
    }
};

class FIO: public FIN_fread, public FOUT {};

struct Node {
    ll max_val ;
    ll b1, b0;
    ll lazyAnd, lazyOr;
};
const int MaxN = (1<<18);
ll A[  MaxN + 1 ]={0,};
Node Tree[(MaxN * 2) + 1]={0,};
const ll initLazyAnd = 0;
const ll initLazyOr = 0;

Node merge(Node a, Node b){
    return Node{
        max(a.max_val, b.max_val),
        a.b1 & b.b1,
        a.b0 & b.b0,
        initLazyAnd, initLazyOr
    };
}

void _update_lazy(int idx, int s, int e) {
    Tree[idx].max_val |= Tree[idx].lazyOr;
    Tree[idx].b1 |= Tree[idx].lazyOr;
    Tree[idx].b0 -= Tree[idx].b0 & Tree[idx].lazyOr;

    Tree[idx].max_val &= ~Tree[idx].lazyAnd;
    Tree[idx].b1 -= Tree[idx].b1 & Tree[idx].lazyAnd;
    Tree[idx].b0 |= Tree[idx].lazyAnd;

    if ( s != e )
    {
        for ( auto i : { idx*2, idx*2+1} ) {
            Tree[i].lazyOr &= ~Tree[idx].lazyAnd ;
            Tree[i].lazyAnd &= ~Tree[idx].lazyOr ;
            Tree[i].lazyOr |= Tree[idx].lazyOr ;
            Tree[i].lazyAnd |= Tree[idx].lazyAnd ;
        }
    }
    Tree[idx].lazyAnd = initLazyAnd;
    Tree[idx].lazyOr = initLazyOr;
}

void update_and(int idx, int s, int e, int l, int r, ll V ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l) return;
    V -= Tree[idx].b0 & V;

    if (l <= s && e <= r && (V & Tree[idx].b1) )
    {
        Tree[idx].lazyAnd = V & Tree[idx].b1;
        V -= V & Tree[idx].b1;
        _update_lazy(idx, s, e);
    }
    if ( V == 0 ) return ;

    int m ;
    m = ( s + e ) / 2 ;
    update_and(idx * 2, s, m, l, r, V);
    update_and(idx * 2 + 1, m + 1, e, l, r, V);
    Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
}
void update_or(int idx, int s, int e, int l, int r, ll V ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l) return;
    V -= Tree[idx].b1 & V;

    if (l <= s && e <= r && (V & Tree[idx].b0) )
    {
        Tree[idx].lazyOr = V & Tree[idx].b0;
        V -= V & Tree[idx].b0;
        _update_lazy(idx, s, e);
    }
    if ( V == 0 ) return ;
    int m ;
    m = ( s + e ) / 2 ;
    update_or(idx * 2, s, m, l, r, V);
    update_or(idx * 2 + 1, m + 1, e, l, r, V);
    Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
}

ll getMax(int idx, int s, int e, int l, int r ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return 0;
    if (l <= s && e <= r) return Tree[idx].max_val;
    int m = ( s + e ) / 2 ;
    return max( getMax(idx * 2, s, m, l, r) , getMax(idx * 2 + 1, m + 1, e, l, r) );
}

Node init(int idx, int s, int e) {
    if ( s == e ) {
        return Tree[idx] = Node{A[s], A[s], ~A[s], initLazyAnd, initLazyOr};
    }
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m), init(idx*2+1, m+1, e) );
}
string bin(ll n) {
    string ret ;
    for ( int i = 0 ; i < 8 ; i ++ ) {
        ret.push_back( n%2 ? '1' : '0' );
        n/=2;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}
void dump(int N) {
#ifdef AJAVA_DEBUG
    int i, j ;
    for ( i = 1, j = 1 ; ; i *= 2 ) {
        for ( j = 0 ; j < i && j < N; j ++ ) {
            Node &t = Tree[i+j];
            printf("[%2d:Max:%d %8s,b0:%8s,b1:%8s,A:%d %5s,O:%d %5s] ",
                i+j,
                   t.max_val, bin(t.max_val).c_str(),
                   bin(t.b0).c_str(),
                   bin(t.b1).c_str(),
                   t.lazyAnd, bin(t.lazyAnd).c_str(),
                   t.lazyOr, bin(t.lazyOr).c_str()
           );
        }
        printf("\n");
        if ( i >= N) break;
    }
    printf("\n");

#endif
}

void process() {
    FIO fio;
    int N, M;
    int i ;
    int a, b, c, d;

    fio.Int(N);
    for ( i = 1 ; i <= N ; i ++ )
        fio.Int(A[i]);

    init(1, 1, N);

    fio.Int(M);
    while ( M -- ) {
        fio.Int(a, b, c);
        if ( b > c ) swap(b, c);
        switch (a) {
            case 1:
                fio.Int(d);
                update_and(1, 1, N, b, c, ~d);
                break;
            case 2:
                fio.Int(d);
                update_or(1, 1, N, b, c, d);
                break;
            case 3:
                fio.write_IntLn(getMax(1, 1, N, b, c));
                break;
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


