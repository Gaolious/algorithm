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

int gcd(int a, int b) {
    if ( b > 0 ) return gcd (b, a % b);
    return a;
}

const int M = 1000 ;
int MOD ( int n ) {
    return ( n < 0 ) ? -(abs(n) % M ) : (n%M);
}
struct Mat {
    int a, b, c, d ;
    Mat operator * (Mat o) {
        return Mat {
            MOD(MOD(this->a * o.a) + MOD(this->b * o.c))  ,
            MOD(MOD(this->a * o.b) + MOD(this->b * o.d)) ,
            MOD(MOD(this->c * o.a) + MOD(this->d * o.c))   ,
            MOD(MOD(this->c * o.b) + MOD(this->d * o.d)) ,
        };
    }
    Mat pow(int n) {
        if ( n == 1 )
            return *this ;
        if ( n % 2 == 0 ) {
            Mat ret = this->pow(n/2);
            return ret*ret;
        }
        else {
            return this->pow(n-1) * (*this);
        }
    }
    int answer() {
        return MOD( MOD( this->c * 6) + MOD(this->d * 2) + 2*M - 1 )  ;
    }
    void dump() {
        printf("| %7d %7d |\n", this->a, this->b);
        printf("| %7d %7d |\n", this->c, this->d);
    }
};

void process() {
    /*
5.23606797749979 ^ n = X

a = 3+sqrt(5)
b = 3-sqrt(5)

a+b = 6
ab = 4
a-b = sqrt(20)

a = 6-b
a = 6 - 4/a

a^2 = 6a - 4
b^2 = 6b - 4

a^2 + b^2 = 6a+6b - 4*2
          = 6(a+b) - 2ab

a^3 = 6a^2 - 4a
b^3 = 6b^2 - 4b

a^n + b^n = 6 ( a^(n-1) + b^(n-1) ) - 4( a^(n-2) + b^(n-2) ) = Cn

Cn   = 6 ( a^(n-1) + b^(n-1) ) - 4( a^(n-2) + b^(n-2) )
Cn+1 = 6 ( a^(n) + b^(n) ) - 4( a^(n-1) + b^(n-1) )
     = 6 C(n) - 4 C(n-1)
Cn+2 = 6 C(n+1) - 4 C(n)
     = 36 C(n) - 24C(n-1) - 4C(n)
     = 32 C(n) - 24C(n-1)

C(0) = (3+sqrt(5))^0 + (3-sqrt(5))^0 = 2
C(1) = 6
C(2) = 28 = 6*C(1) - 4C(0) = 36 - 8 = 28
C(3) = 6*C(2) - 4*C(1) = 6*28 - 24 = 168 - 24 = 144

| C(n+2) | = | 6 -4 | | C(n+1)|
| C(n+1) |   | 1  0 | | C(n)  |

| C(n+1) |  = | 6 -4 | ^n = | C(2) |
| C(n)   |    | 1  0 |      | C(1) |
     * */
    Mat a = Mat{ 6, -4, 1, 0 };
    int T, n, i ;
    FIO fio ;

    fio.Int(T);
    char buff[1024];
//
//    for ( i = 1 ; i<=10 ; i ++ ) {
//        auto b = a.pow(i);
//        printf("pow(%d) = %d\n", i, b.answer() );
//        b.dump();
//    }

    for ( i = 1 ; i <= T ; i ++ ) {
        fio.Int(n);
        sprintf(buff, "Case #%d: %03d\n", i, a.pow(n).answer());
        fio.write_Str(buff);
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


