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

int N, M, T, S, Cnt ;
int IDX[50] = {0,}, A[50][50];

void spin(int idx, int dir, int cnt) {
    int i ;
    for ( i = idx - 1 ; i < N ; i += idx ) {
        IDX[i] = ( IDX[i] + M + (dir == 1 ? cnt : -cnt ) ) % M ;
    }
}

#define V(y, x) ( A[ (y) ][ ( (x) + IDX[(y)] + (M) ) % (M) ] )

int remove() {
    int i, j;
    int C[51][51]={0,};
    int cnt = 0;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ ) {
            if ( V(i, j) == 0 ) continue;

            if ( V(i, j) == V(i, j+1) )
                C[i][j] = 1;
            else if ( V(i, j) == V(i, j-1) )
                C[i][j] = 1;
            else if ( i > 0 && V(i, j) == V(i-1, j) )
                C[i][j] = 1;
            else if ( i < N-1 && V(i, j) == V(i+1, j) )
                C[i][j] = 1;
        }
    }

    for ( i = 0 ; i < N ; i ++ )
        for (j = 0; j < M; j++)
            if ( C[i][j] == 1 )
            {
                cnt++;
                S -= V(i, j);
                V(i, j) = 0;
            }

    return cnt;
}

void process() {
    FIO fio;
    int i, j ;
    int x, d, k ;

    fio.Int(N, M, T);
    assert( 2 <= N );
    assert( 2 <= M );
    assert( N <= 50 );
    assert( M <= 50 );
    assert( 1 <= T && T <= 50 );

    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < M ; j ++ )
        {
            fio.Int(A[i][j]);
            assert(1 <= A[i][j]);
            assert(A[i][j] <= 1000);
            S += A[i][j];
        }
    Cnt = N * M ;

    while ( T-- )
    {
        fio.Int(x, d, k);

        spin(x, d, k);

        int nRemoved = remove();
        if ( Cnt == 0 || S == 0) {
            break;
        }
        Cnt -= nRemoved;
        if ( nRemoved == 0 ) {
            int inc = 0 ;
            for ( i = 0 ; i < N ; i ++ )
                for ( j = 0 ; j < M ; j ++ ) {
                    if ( A[i][j] == 0 ) continue;
                    if ( A[i][j] * Cnt < S )
                    {
                        A[i][j] ++;
                        inc += 1;
                    }
                    else if ( A[i][j] * Cnt > S)
                    {
                        A[i][j] --;
                        inc -= 1;
                    }
                }
            S += inc ;
        }
    }

    printf("%d\n", S);
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


