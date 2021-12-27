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
const int INF = -0xffff * 100;
const int MaxN = 100 ;
int N, M ;
int A[MaxN+1]={0,};
int S[MaxN+1]={0,};
int D[MaxN+2][MaxN+2][MaxN/2+1]={0,};


void process() {
    FIO fio;
    int i, j, k ;

    fio.Int(N, M);
    for ( i = 1 ; i <= N ; i ++ ){
        fio.Int(A[i]);
        S[i] = S[i-1] + A[i];
    }
    for ( i = 0 ; i <= N+1 ; i ++ )
        for ( j = 0 ; j <= N+1 ; j ++ )
            for ( k = 0 ; k <= M ; k ++ )
                D[i][j][k] = INF;

    int s, e, m ;
    for ( j = 1 ; j <= N ; j ++ ) {
        for ( i = 1 ; i + j - 1 <= N ; i ++ ) {
            s = i ;
            e = j + i - 1 ;
            D[s][e][1] = max(S[e] - S[s-1], max(D[s][e-1][1], D[s+1][e][1]));
#ifdef AJAVA_DEBUG
            printf("D[%d][%d][%d] = max(S[%d] - S[%d], max(D[%d][%d][%d], D[%d][%d][%d]))\n",
            s, e, 1, e, s-1, s, e-1, 1, s+1, e, 1);
            printf("%d = max(%d - %d, max(%d, %d))\n", D[s][e][1], S[e], S[s-1], D[s][e-1][1], D[s+1][e][1] );
#endif
        }
    }
    for ( k = 2 ; k <= M ; k ++ ) {
        for ( j = k+1 ; j <= N ; j ++ ) {
            for (i = 1; i + j - 1 <= N; i++) {
                s = i;
                e = j + i - 1;
                for ( m = i + 1 ; m < e ; m ++ )
                    D[s][e][k] = max(D[s][e][k], D[s][m-1][1] + D[m+1][e][k - 1]);
            }
        }
    }
#ifdef AJAVA_DEBUG

    for ( k = 0 ; k <= M ; k ++ ) {
        printf(" k = %d\n", k);
        for ( i = 1 ; i <= N ; i ++ ) {
            for (j = 1; j <= N; j++) {
                printf("%8d ", D[i][j][k] );
            }
            printf("\n");
        }
    }
#endif
    printf("%d\n", D[1][N][M]);

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


