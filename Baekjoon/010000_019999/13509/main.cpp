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

struct Point {
    int x, y ;
    int idxX, idxY;
    int idxN ;
};
vector<Point> P ;
vector<int> X, Y ;
int N ;
vector<int> Index[100][100];
int gapX, gapY ;

void makeIndex() {
    int x, y, i, j ;

    std::sort(X.begin(), X.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());

    std::sort(Y.begin(), Y.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

    std::sort(P.begin(), P.end(), [](Point &a, Point &b) -> bool {return a.x < b.x ; });
    for ( i = 0, j = 0 ; i < N ; i ++ ) {
        while ( X[j] < P[i].x ) j ++;
        P[i].idxX = j ;
    }

    std::sort(P.begin(), P.end(), [](Point &a, Point &b) -> bool {return a.y < b.y ; });
    for ( i = 0, j = 0 ; i < N ; i ++ ) {
        while ( Y[j] < P[i].y ) j ++;
        P[i].idxY = j ;
    }

    gapX = max(1, ( int )( X.size() + 1 ) / 100 );
    if ( gapX * 100 < X.size() + 1 ) gapX ++;

    gapY = max(1, ( int )( Y.size() + 1 ) / 100 );
    if ( gapY * 100 < Y.size() + 1 ) gapY ++;

    std::sort(P.begin(), P.end(), [](Point &a, Point &b) -> bool {return a.idxN < b.idxN ; });
    for ( i = 0; i < N ; i ++ ) {
        x = P[i].idxX / gapX ;
        y = P[i].idxY / gapY ;
        Index[y][x].push_back(i);
    }
}

typedef long long LL ;
LL build(int i, int lo, int hi)
{
    if (lo == hi) {
        printf("Tree[%d] = data[%d]\n", i, lo);
        return 0;
    }
    int mid = (lo + hi) / 2;
    return (build(i * 2, lo, mid) * build(i * 2 + 1, mid + 1, hi));
}

void process() {
    N = 10;
    build(1, 0, N-1);
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


