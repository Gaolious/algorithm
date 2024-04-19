#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#define BUFF_LEN (1<<21)

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

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
    ll V;
    ll lazyMul;
    ll lazyAdd;
};
ll A[100'000]={0,};
Node Tree[4'000'000]={0,};
int N ;
const ll MOD = 1'000'000'007;

Node merge(Node a, Node b){
    return Node{ (a.V + b.V) % MOD, 1, 0};
}

void _update_lazy(int idx, int s, int e) {

    if ( Tree[idx].lazyMul == 1 && Tree[idx].lazyAdd == 0 ) return ;

    ll &a = Tree[idx].lazyMul ;
    ll &b = Tree[idx].lazyAdd ;

    Tree[idx].V = (Tree[idx].lazyMul * Tree[idx].V) % MOD + b * (e-s+1) % MOD;
    Tree[idx].V %= MOD ;
    for ( int i = 0 ; i <= 1 ; i ++ ) {
        Tree[idx*2 + i ].lazyMul = ( Tree[idx*2 + i ].lazyMul * a ) % MOD ;
        Tree[idx*2 + i ].lazyAdd = ( Tree[idx*2 + i ].lazyAdd * a + b ) % MOD  ;
    }
    a = 1;
    b = 0;
}

void update(int idx, int s, int e, int l, int r, ll mul, ll add ) {
    _update_lazy(idx, s, e);

    if (s > r || e < l ) return;

    if (l <= s && e <= r )
    {
        ll &a = Tree[idx].lazyMul ;
        ll &b = Tree[idx].lazyAdd ;
        a = ( a * mul ) % MOD ;
        b = ( b * mul + add ) % MOD ;
        _update_lazy(idx, s, e);
    }
    else
    {
        int m ;
        m = ( s + e ) / 2 ;
        update(idx * 2, s, m, l, r, mul, add);
        update(idx * 2 + 1, m + 1, e, l, r, mul, add);
        Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
    }
}

ll query(int idx, int s, int e, int l, int r ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return 0;
    if (l <= s && e <= r) return Tree[idx].V %= MOD;
    int m = ( s + e ) / 2 ;
    return (query(idx * 2, s, m, l, r) + query(idx * 2 + 1, m + 1, e, l, r) ) % MOD;
}

Node init(int idx, int s, int e) {
    if ( s == e ) {
        return Tree[idx] = Node{A[s], 1, 0};
    }
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m), init(idx*2+1, m+1, e) );
}
void process() {
    FIO fio;
    int N, M ;
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
                fio.Int( d);
                update(1, 1, N, b, c, 1ll, d);
                break;
            case 2:
                fio.Int( d);
                update(1, 1, N, b, c, d, 0);
                break;
            case 3:
                fio.Int( d);
                update(1, 1, N, b, c, 0, d);
                break;
            case 4:
                fio.write_IntLn(query(1, 1, N, b, c));
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


