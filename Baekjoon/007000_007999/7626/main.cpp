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
typedef long long int ll ;

struct Rect {
    ll x, sy, ey, diff;
    bool operator < (Rect r) const {
        if ( x != r.x ) return x < r.x ;
        return diff > r.diff ;
    }
};
vector<int> X, Y;
vector<Rect> R ;

class SegTree {
public:
    vector<ll> tree;
    vector<ll> data;
    int size;
    int N ;
    SegTree(int N ) {
        this->N = N ;
        for ( this->size = 1 ; this->size < N ; this->size *= 2 );
        this->tree.resize(this->size * 2 + 1, 0) ;
        this->data.resize(this->size * 2 + 1, 0) ;
    }
    void update(int treeIdx, int tL, int tR, int vL, int vR, int diff) {
        if ( tR < vL || vR < tL ) return ;

        if ( vL <= tL && tR <= vR ) {
            this->data[treeIdx] += diff ;
        } else {
            int m = (tL + tR) / 2;
            update(treeIdx * 2    , tL      , m, vL, vR, diff);
            update(treeIdx * 2 + 1, m + 1, tR, vL, vR, diff);
        }
        if ( this->data[treeIdx] > 0)
            this->tree[treeIdx] = Y[tR] - Y[tL-1] ;
        else
        {
            if ( tL == tR )
                this->tree[treeIdx] = 0;
            else
                this->tree[treeIdx] = this->tree[treeIdx*2] + this->tree[treeIdx*2+1];
        }

    }
    void update( int left, int right, int diff ) {
        this->update(1, 0, this->N-1, left, right, diff);
    }
    ll height() {
        return this->tree[1];
    }
    void dump() {
        int i, j ;
        for ( i = 1 ; i <= this->size ; i *= 2 ) {
            for ( j = 0 ; j < i ; j ++ ) {
                printf("%2lld(%2lld) ", this->tree[i+j], this->data[i+j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

void process() {
    FIO fio;
    int sx, sy, ex, ey;
    int i ;
    int N ;

    fio.Int(N);
    for ( i = 0 ; i < N ; i ++ ) {
        fio.Int(sx, ex, sy, ey);
        R.push_back( Rect{ sx, sy, ey, 1});
        R.push_back( Rect{ ex, sy, ey, -1});
        Y.push_back(sy);
        Y.push_back(ey);
    }
    std::sort(Y.begin(), Y.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());
    std::sort(R.begin(), R.end());

    for ( auto &r: R ) {
        r.sy = std::lower_bound(Y.begin(), Y.end(), r.sy) - Y.begin();
        r.ey = std::lower_bound(Y.begin(), Y.end(), r.ey) - Y.begin();
    }
    SegTree tree(Y.size());

    i = 0;
    ll area = 0 ;
    for ( i = 0 ; i < R.size()-1 ; i ++ ) {
        tree.update(R[i].sy+1, R[i].ey, R[i].diff);
        area += ( R[i+1].x - R[i].x ) * tree.height();
#ifdef AJAVA_DEBUG
        tree.dump();
        printf("X[%lld ~ %lld] * Y[%lld] : AREA : %lld\n", R[i].x , R[i+1].x, tree.height(), area);
#endif
    }

    fio.write_IntLn(area);
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


