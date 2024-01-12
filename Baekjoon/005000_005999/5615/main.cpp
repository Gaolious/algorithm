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

template <typename T> T gcd(T a, T b) {
    if ( b > 0 ) return gcd (b, a % b);
    return a;
}
template <typename T> inline T ModAdd(T a, T b, T m) {
    a %= m;
    b %= m ;
    return a > m - b ? a - (m-b) : a + b;
}
template <typename T> inline T ModMul(T a, T b, T m ) {
    a %= m ;
    b %= m ;
    T r ;
    for ( r=0 ; b > 0 ; b /=2 ) {
        if ( b&1 )
            r = (r + a) % m ;
        a = ModAdd(a, a, m);
    }
    return r ;
}

template <typename T> inline T ModPow(T a, T n, T m) {
    a %= m ;
    T r  ;
    for ( r=1 ; n > 0 ; n /= 2 ) {
        if ( n % 2 == 1 )
            r = (r*a) % m ; // ModMul(r, a, m);
        a = (a*a) % m; // ModMul(a, a, m);
    }
    return r ;
}

template <typename T> inline bool miller(T n, T a) {
    T d ;
    for ( d = n - 1 ; d % 2 == 0 ; d /= 2 ) {
        if (ModPow(a, d, n) == n - 1 )
            return true ;
    }
    T t = ModPow(a, d, n);
    return ( t == n-1 || t == 1 );
}

template <typename T> inline bool is_prime(T n) {
    if ( n == 2 ) return true;
    if ( n < 2 || n % 2 == 0 ) return false ;

//    for ( T a: {2, 3, 5, 7, 11} ) {
    for ( T a: {2, 3} ) {
        if ( !miller(n, a) )
            return false ;
    }
    return true;
}

void process() {
    /*
     * 2xy + x + y = N
     * 4xy + 2x + 2y = 2N
     * 2x(2y+1) + 2y = 2N
     * (2x + 1)(2y+1) = 2N + 1
     * */
    int N ;
    unsigned long long int a, cnt ;
    FIO fio;
    fio.Int(N);
    for ( cnt = 0 ; N -- ;  ) {
        fio.Int(a);
        if ( a < 4 || is_prime(a*2+1) )
            cnt ++;
    }
    fio.write_IntLn(cnt);
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


