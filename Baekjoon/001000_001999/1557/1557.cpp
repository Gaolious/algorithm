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
long long int Ans(long long int K) {
    long long int cnt = 0, i, j  ;
    bool found = false ;

    for ( i = 1 ;  ; i ++ )
    {
        found = false ;
        for ( j = 2 ; j*j <= i ; j ++ )
            if ( i % (j*j) == 0 ) {
                found = true ;
                break;
            }
        if ( !found) cnt++;
        if ( cnt == K ) return i;
    }

}
long long int FindK(long long int K) {
    long long int l, r, m, cnt, i, j ;
    const long long int MaxSR = 50000 ;

    int Cnt[ MaxSR ]={0,};

    //   1 2 3 4 5 6 7 8 9 10 | 11 12 13 14 15 16 17 18 19 20 | 21 22 23 24 25 26 27 28 29 30 | 31 32 33 34 35 36 37 38 39 40
    // -----------------------+-------------------------------+-------------------------------+------------------------------
    // 2       *       *      |     *           *           * |           *           *       |     *           *           *
    // 3                 *    |                       *       |                    *          |                 *
    // 4                      |                 *             |                               |     *
    // 5                      |                               |              *                |
    // 6                      |                               |                               |                 *
    // -----------------------+-------------------------------+-------------------------------+-------------------------------
    // 2 : 37/4  = -9    / [4]  = 1
    // 3 : 37/9  = -4    / [9]  = 1
    // 4 : 36/16 =  2    / [16] = 2
    // 5 : 36/25 = -1    / [25] = 1
    // 6 : 36/36 = -1    / [36] = 3

    // 2 : 34/4  = -8    / [4]  = 1
    // 3 : 34/9  = -3    / [9]  = 1
    // 4 : 34/16 =  2    / [16] = 2
    // 5 : 34/25 = -1    / [25] = 1

    for ( i = 2 ; i <= MaxSR ; i ++ ) {
        if ( Cnt[i] == 0 )
        {
            for ( j = i ; j <= MaxSR ; j += i )
            {
                if ( j % (i*i) == 0 )
                    Cnt[j] = -MaxSR;
                else
                    Cnt[j] ++;
            }
        }

        if ( Cnt[i] < 0 )
            Cnt[i] = 0;
        else if ( Cnt[i] % 2 == 1)
            Cnt[i] = -1 ;
        else
            Cnt[i] = 1;
    }

    r = K*2;
    l = 1 ;
    long long ret = 0 ;
    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        for ( cnt=m, i = 2 ; i * i <= m ; i ++ )
            cnt += ( m / (i*i) ) * Cnt[i] ;

        if ( cnt >= K ) {
            ret = m ;
            r = m - 1 ;
        }
        else {
            l = m + 1 ;
        }
    }
    return ret;
}
void process() {
    FIO fio;
    long long int K ;

    fio.Int(K);
    fio.write_IntLn(FindK(K));
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


