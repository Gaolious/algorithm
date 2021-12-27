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
    void skip() {
        while ( this->p && *this->p && *this->p <= ' ' )
            this->p++;
    }
    bool _byte(char &c)  {
        if ( !this->p || *this->p <= 0 )
            return false ;
        c = *this->p++;
        return true ;
    }
    bool Char(char &c) {
        this->skip();
        c = *this->p++;
        return true;
    }
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
template<typename T> T op(T a, char c, T d) {
    if ( a <= 0 ) {
        return 0;
    }
    switch (c) {
        case '+' : return a + d;
        case '-' : return a - d;
        case '*' : return a * d;
        case '/' : return a / d;
    }
    return 0;
}
void process() {
    FIO fio;
    long long int D[2][2][2]={0,};
    int N, i, j, curr, prev ;
    char lc, rc ;
    long long int ln, rn ;

    fio.Int(N);
    D[0][0][0] = 1;
    D[0][0][1] = 1;
    for ( prev = 0, i = 1 ; i <= N ; i ++, prev = 1-prev ) {
        curr = 1 - prev ;

        fio.Char(lc);
        fio.Int(ln);
        fio.Char(rc);
        fio.Int(rn);

        D[curr][0][0] = max( op(D[prev][0][0], lc, ln), op(D[prev][0][1], lc, ln) );
        D[curr][0][1] = max( op(D[prev][0][0], rc, rn), op(D[prev][0][1], rc, rn) );

        D[curr][1][0] = max( op(D[prev][1][0], lc, ln), op(D[prev][1][1], lc, ln) );
        D[curr][1][0] = max( D[curr][1][0], D[prev][0][0]);

        D[curr][1][1] = max( op(D[prev][1][0], rc, rn), op(D[prev][1][1], rc, rn) );
        D[curr][1][1] = max( D[curr][1][1], D[prev][0][1]);
    }

    long long ret = 0;
    for ( i = 0 ; i < 2 ; i ++ ) {
        for ( j = 0 ; j < 2 ; j ++ ) {
            ret = max(ret, D[curr][i][j]);
        }
    }
    if ( ret <= 0 ) {
        fio.write_Str("ddong game");
    } else {
        fio.write_Int(ret);
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


