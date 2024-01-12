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
    bool Char(char &c)  { if ( !this->p || *this->p <= 0 ) return false ; c = *this->p++; return true ; }
    bool Line(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->Char(c) && c > 0 && c != '\n' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    bool Word(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->Char(c) && c > 0 && c > ' ' && len < maxLen ; len++ )
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
        if ( ! this->Char(c) )  return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( ! this->Char(c) ) return false ;
        }

        while ( c > ' ' )
        {
            n = n * 10 + c - 48 ;
            if ( ! this->Char(c) ) break;
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

long long A[10][10];
int N, M ;

// 0 1 4 9 6 5
bool is_prime(long long n) {
    long long t ;

    switch (n%10) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        case 9:
            t = (long long)( sqrt(n) + 0.5l ) ;
            return (t*t == n);
    }
    return false ;
}

long long Find(int y, int x) {
    int i, j, k, tx, ty ;
    long long t ;
    long long ret = -1 ;

    for ( i = -y ; i <= (N-1-y) ; i ++ ) {
        for ( j = -x ; j <= (M-1-x) ; j ++ ) {
            if ( i == 0 && j == 0 ) continue;

#ifdef AJAVA_DEBUG
//            printf("A[%d][%d] = %lld , Y=(%d ~ %d), X=(%d ~ %d), \n", y, x, A[y][x], -y, (N-1-y), -x, (M-1-x));
#endif
            for (t = A[y][x], ty=y+i, tx=x+j ; 0 <= ty && ty < N && 0 <= tx && tx < M ; ty += i, tx += j)
            {
                t = t * 10 + A[ty][tx] ;
#ifdef AJAVA_DEBUG
//                printf("\tA[%d][%d] = %lld / t=%lld\n", ty, tx, A[ty][tx], t);
#endif

                if (is_prime(t)) {
                    ret = max(ret, t);
                }
            }
        }
    }
    return ret ;
}

void process() {
    FIO fio;
    int i, j;
    char c ;
    long long ret = -1;

    fio.Int(N, M);
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ ) {
            fio.skip();
            fio.Char(c);
            A[i][j] = c - '0';
            if ( A[i][j] == 9 || A[i][j] == 4 || A[i][j] == 1 || A[i][j] == 0 )
                ret = max(ret, A[i][j]);
        }
    }
    for ( i = 0 ; i < N ; i ++ ) {
        for (j = 0; j < M; j++) {
            ret = max( Find(i, j), ret );
        }
    }
    fio.write_IntLn(ret);
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


