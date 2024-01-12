#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
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
            this->Tree[idx] = (e-s+1) - this->Tree[idx];

            if (s != e ) {
                this->Lazy[idx * 2] = 1 - this->Lazy[idx * 2];
                this->Lazy[idx * 2 + 1] = 1 - this->Lazy[idx * 2 + 1];
            }
            this->Lazy[idx] = 0;
        }
    }

    void _update(int idx, int s, int e, int l, int r) {
        this->_update_lazy(idx, s, e);

        if (s > r || e < l ) return;

        if (l <= s && e <= r )
        {
            this->Tree[idx] = (e - s + 1) - this->Tree[idx] ;
            if ( s != e ) {
                this->Lazy[idx * 2] = 1 - this->Lazy[idx * 2] ;
                this->Lazy[idx * 2 + 1] = 1 - this->Lazy[idx * 2 + 1];
            }
        }
        else {
            int m = ( s + e ) / 2 ;
            this->_update(idx * 2, s, m, l, r);
            this->_update(idx * 2 + 1, m + 1, e, l, r);
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
    void update(int rangeLeft, int rangeRight) {
        this->_update(1, 0, this->size-1, rangeLeft, rangeRight);
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
    FIO fio;
    int N, M, a, b, c ;
    fio.Int(N, M);

    SegTree<int> tree(N);
    while ( M-- ) {
        fio.Int(a, b, c);
        if ( a == 0 ) {
            tree.update(b-1, c-1);
        } else {
            fio.write_IntLn(tree.query(b-1, c-1));
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


