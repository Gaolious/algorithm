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
    ll lazy;
};
ll A[100'000+1]={0,};
Node Tree[400'000]={0,};
int N ;

Node merge(Node a, Node b){
    return Node{ a.V ^ b.V, 0};
}

void _update_lazy(int idx, int s, int e) {

    if ( Tree[idx].lazy ) {
        if ( (e-s+1) % 2 == 1 )
            Tree[idx].V ^= Tree[idx].lazy;

        Tree[idx*2].lazy ^= Tree[idx].lazy ;
        Tree[idx*2+1].lazy ^= Tree[idx].lazy ;
        Tree[idx].lazy = 0;
    }
}

void update(int idx, int s, int e, int l, int r, ll minValue ) {
    _update_lazy(idx, s, e);

    if (s > r || e < l ) return;

    if (l <= s && e <= r )
    {
        Tree[idx].lazy ^= minValue ;
        _update_lazy(idx, s, e);
    }
    else
    {
        int m ;
        m = ( s + e ) / 2 ;
        update(idx * 2, s, m, l, r, minValue);
        update(idx * 2 + 1, m + 1, e, l, r, minValue);
        Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
    }
}

ll getXOR(int idx, int s, int e, int l, int r ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return 0;
    if (l <= s && e <= r) return Tree[idx].V;
    int m = ( s + e ) / 2 ;
    return getXOR(idx * 2, s, m, l, r) ^ getXOR(idx * 2 + 1, m + 1, e, l, r);
}

Node init(int idx, int s, int e) {
    if ( s == e ) {
        return Tree[idx] = Node{A[s], 0};
    }
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m), init(idx*2+1, m+1, e) );
}

void process() {
    FIO fio;
    int N, M, Q ;
    int i ;
    int a, b, c, d;

    fio.Int(N, M, Q);
    for ( i = 1 ; i <= N ; i ++ )
        fio.Int(A[i]);

    init(1, 1, N);

    fio.Int(M);
    while ( M -- ) {
        fio.Int(a, b);
        b++;

        switch (a) {
            case 1:
                fio.Int(c, d);
                c++;
                if ( b > c ) swap(b, c);
                update(1, 1, N, b, c, d);
                break;
            case 2:
                fio.write_IntLn(getXOR(1, 1, N, b, b));
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


