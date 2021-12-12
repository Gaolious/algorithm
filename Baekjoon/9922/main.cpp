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

int SumColumn[5];
int SumRow[5];
int SumDiag[2];

int BlankColumn[5];
int BlankRow[5];
int BlankDiag[2];

bool usedNumber[25+1]={0,};

int A[5][5]={0,};
int S ;
int N, K ;

void setNumber(int y, int x, int n) {
    usedNumber[n] = true;
    BlankRow[y] --;
    SumRow[y] += n;

    BlankColumn[x] --;
    SumColumn[x] += n;

    if ( y == x ) {
        SumDiag[0] += n;
        BlankDiag[0] --;
    }
    if ( y + x + 1 == N ) {
        SumDiag[1] += n;
        BlankDiag[1] --;
    }
    A[y][x] = n;
}

void unsetNumber(int y, int x, int n) {
    usedNumber[n] = false;
    BlankRow[y] ++;
    SumRow[y] -= n;

    BlankColumn[x]++;
    SumColumn[x] -= n;

    if ( y == x ) {
        SumDiag[0] -= n;
        BlankDiag[0] ++;
    }
    if ( y + x + 1 == N ) {
        SumDiag[1] -= n;
        BlankDiag[1] ++;
    }
    A[y][x] = 0;
}
typedef struct possibles {
    int y, x ;
    int start ;
    int end ;
} POSSIBLE;

int comp(const void *_a, const void *_b) {
    const auto *a = (const POSSIBLE *)_a ;
    const auto *b = (const POSSIBLE *)_b ;
    if ( a->end - a->start < b->end - b->start ) return -1 ;
    if ( a->end - a->start > b->end - b->start ) return 1 ;
    return 0;
}
bool Find(int pos, int remainCnt) {
    int y, x ;
    int tmpSumInc[25+1]={0,};
    int tmpSumDec[25+1]={0,};
    int i, j ;
    POSSIBLE possible[25]={0,};

    if ( remainCnt == 0 )
        return true ;

//    for ( ; pos < N*N  && A[pos/N][pos%N] != 0; pos ++) {}
//    y = pos / N ;
//    x = pos % N ;


    for ( i = 1, j = 1 ; i <= N*N ; i ++ ) {
        if ( !usedNumber[i] ) {
            tmpSumInc[j] = i ;
            tmpSumDec[remainCnt - j + 1] = i ;
            j ++;
        }
    }
    for ( i = 1 ; i <= remainCnt ; i ++ ){
        tmpSumInc[i] += tmpSumInc[i-1];
        tmpSumDec[i] += tmpSumDec[i-1];
    }

    int start_number = tmpSumInc[1] ;
    int end_number = tmpSumDec[1];

    for ( i = 0, j = 0 ; i < N*N ; i ++ ) {
        start_number = tmpSumInc[1] ;
        end_number = tmpSumDec[1];

        y = i / N ;
        x = i % N ;
        if ( A[y][x] > 0 ) continue;

        start_number += max(0, S - start_number - SumRow[y] - tmpSumDec[ BlankRow[y] -1 ]);
        start_number += max(0, S - start_number - SumColumn[x] - tmpSumDec[ BlankColumn[x] - 1 ]);
        if ( y == x ) {
            start_number += max(0, S - start_number - SumDiag[0] - tmpSumDec[ BlankDiag[0] - 1 ]);
        } else if ( x + y + 1 == N ) {
            start_number += max(0, S - start_number - SumDiag[1] - tmpSumDec[ BlankDiag[1] - 1 ]);
        }

        end_number -= max(0, end_number + SumRow[y] + tmpSumInc[ BlankRow[y]-1 ] - S);
        end_number -= max(0, end_number + SumColumn[x] + tmpSumInc[ BlankColumn[x]-1 ] - S);
        if ( y == x ) {
            end_number -= max(0, end_number + SumDiag[0] + tmpSumInc[ BlankDiag[0]-1 ] - S);
        } else if ( x + y + 1 == N ) {
            end_number -= max(0, end_number + SumDiag[1] + tmpSumInc[ BlankDiag[1]-1 ] - S);
        }
        if ( end_number < start_number ) return false;

        possible[j].y = y;
        possible[j].x = x;
        possible[j].start = start_number ;
        possible[j].end  = end_number ;

        j++;
    }
    if ( j != remainCnt ) return false ;

    qsort(possible, j, sizeof(POSSIBLE), comp);

    y = possible[0].y ;
    x = possible[0].x ;
    start_number = possible[0].start;
    end_number = possible[0].end ;

    for ( i = start_number ; i <= end_number ; i ++ )
    {
        if ( usedNumber[i] ) continue;

        setNumber(y, x, i);

        bool ret = Find(pos+1, remainCnt-1);
        if (ret) return ret;

        unsetNumber(y, x, i);
    }

    return false ;
}

void process() {
    FIO fio;
    int i, j, x, y, v ;

    fio.Int(N, K);
    assert( 2<= N && N <= 5);
    assert ( 1<= K && K <= N*N);

    S = N * ( N*N + 1 ) / 2;

    for ( i = 1 ; i <= N*N ; i ++ )
        usedNumber[i] = false;

    for ( j = 0 ; j < N ; j ++ ) {
        SumColumn[j] = SumRow[j] = 0;
        BlankColumn[j] = BlankRow[j] = N;
    }
    BlankDiag[0] = BlankDiag[1] = N;
    SumDiag[0] = SumDiag[1] = 0;

    for ( i = 0 ; i < K ; i ++ ) {
        fio.Int(y, x, v);
        assert ( 1<= y && y <= N);
        assert ( 1<= x && x <= N);
        assert ( 1<= v && v <= N*N);

        setNumber(y-1, x-1, v);
    }

    if ( Find(0, N*N - K) ) {
        fio.write_Str("yes\n");

#ifdef AJAVA_DEBUG
        for (i = 0 ; i < N ; i ++ ) {
            for (j=0 ; j < N; j ++ ) {
                fio.write_Int(A[i][j]);
                fio.write_Char(' ');
            }
            fio.write_Int(SumRow[i]);
            fio.write_Char('\n');
        }
        for (j=0 ; j < N; j ++ ) {
            fio.write_Int(SumColumn[j]);
            fio.write_Char(' ');
        }
        fio.write_Char('\n');
        fio.write_Int(SumDiag[0]);
        fio.write_Char(' ');
        fio.write_Int(SumDiag[1]);
#endif
    } else {
        fio.write_Str("no\n");
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


