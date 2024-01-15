# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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

int sqrtN ;
struct QUERY {
    int idx, s, e ;
    bool operator < (QUERY &o) const {
        return ( this->s / sqrtN == o.s / sqrtN ) ? e < o.e : this->s < o.s ;
    }
};
vector<int> A ;
vector<QUERY> Query;
vector<int> answer;
vector<int> P ;

int Count[1'000'000 ]={0,};
void update(int idx, int &currAnswer, bool plus ) {

    if ( plus ) {
        if ( Count[ A[idx] ] ++ == 0 )
            currAnswer ++ ;
    } else {
        if ( --Count[ A[idx] ] == 0 )
            currAnswer -- ;
    }
}
void process() {
    FIO fio;
    int N, M, i, j;
    int s, e, currAnswer ;

    fio.Int(N);

    A.resize(N);
    sqrtN = (int)(sqrt(N)) + 1;
    for ( i = 0 ; i < N ; i ++ )
    {
        fio.Int(A[i]);
        P.push_back(A[i]);
    }
    std::sort(P.begin(), P.end());
    P.erase(std::unique(P.begin(), P.end()), P.end());
    for ( i = 0 ; i < N ; i ++ )
        A[i] = std::lower_bound(P.begin(), P.end(), A[i]) - P.begin();

    fio.Int(M);
    answer.resize(M);

    for ( i = 0 ; i < M; i ++ )
    {
        fio.Int(s, e);
        Query.push_back({i, s-1, e-1});
    }

    std::sort(Query.begin(), Query.end());

    s = Query[0].s , e = Query[0].e ;
    currAnswer = 0;

    for ( i = s ; i <= e ; i ++ ) {
        update(i, currAnswer, true);
    }

    for ( i = 0 ; i < M ; i ++ ) {
        while ( Query[i].s < s ) update(--s, currAnswer, true);
        while ( s < Query[i].s  ) update(s++, currAnswer, false);
        while ( e < Query[i].e  ) update(++e, currAnswer, true);
        while ( Query[i].e < e  ) update(e--, currAnswer, false);

        answer[ Query[i].idx ] = currAnswer;
    }

    for ( i = 0 ; i < M ; i ++ )
        fio.write_IntLn(answer[i]);


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

