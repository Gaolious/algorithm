#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

class FIO
{
    #define BUFF_LEN (1<<22)
    char *p;
    char out[BUFF_LEN]{};
    int nOut ;
public :
    FIO()
    {
        struct stat rstat{};
        this->p = nullptr ;

        if ( fstat(0, &rstat) == 0 && rstat.st_size > 0 )
            this->p = (char*)mmap(nullptr, rstat.st_size, PROT_READ, MAP_SHARED, 0, 0) ;

        if ( this->p == MAP_FAILED ) this->p = nullptr ;
        nOut = 0;
    }
    ~FIO() {
        this->write_flush();
    }
    void skip() { while ( this->p && *this->p && *this->p <= ' ' ) this->p++; }
    bool _byte(char &c)  { if (!this->p || *this->p <= 0 ) return false ; c = *this->p++; return true ; }
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

typedef long long int ll ;

template <typename T> inline T gcd(T a, T b) {
    if ( b > 0 ) return gcd (b, a % b);
    return a;
}
ll P(ll a, ll r, ll m) {
    if ( r == 0 ) return 1;
    else if ( r == 1 ) return a ;
    else if ( r % 2 == 0 ) {
        ll t = P(a, r/2, m);
        return t*t % m ;
    }
    else
        return P(a, r-1, m) * a % m;
}
// a^(r)
//  if f(2x+1) = 1 + a^1 + ... + a^(2x + 1)
//          = [ 1 + a^1 + ... + a^x ] + a^(x+1) * [ 1 + a^1 + ... + a^x ]
//          = F(x/2) * ( 1 + a^(x+1) )
//
//  if f(2x) = 1 + a^1 + ... + a^(2x)
//          = F(2x-1) + a^(2x)

ll F(ll a, ll r, ll m) {
    ll t ;
    if ( r == 0 ) t = 1;
    else if ( r == 1 ) t = ( a + 1 ) % m ;
    else if ( r % 2 == 0 ) {
        t = F(a, r-1, m) % m + P(a, r, m) % m;
    }
    else {
        ll r2 = r / 2 ;
        t = F(a, r2, m) * ( 1 + P(a, r2 + 1, m) ) % m;
    }
    return t ;
}

void process() {
    FIO fio;
    ll a, r, n, m ;
    fio.Int(a, r, n, m);
    if ( m <= 1 )
        fio.write_IntLn(0);
    else
        fio.write_IntLn( F(r, n-1, m) * a % m );
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


