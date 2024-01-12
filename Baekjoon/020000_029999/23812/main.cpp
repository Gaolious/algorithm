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
struct DATA {
    int start, end;
    int people;
    bool operator < (DATA other) const {
        if (this->end == other.end ) return this->start < other.start;
        return this->end < other.end;
    }
};

int IDX(vector<int> &X, int val) {
    int l = 0, r = X.size()-1;
    int m;
    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        if (X[m] == val) return m;
        if (val > X[m]) l = m + 1;
        else r = m-1;
    }
}
int find_start_idx(vector<DATA> &A, int t) {
    int l = 0, r = A.size() - 1;
    int m ;
    int ret = A.size();

    while ( l <= r ) {
        m = (l+r)/2;
        if ( A[m].end == t ) {
            ret = m ;
            r = m - 1;
        }
        if ( t > A[m].end ) l = m + 1 ;
        else r = m - 1;
    }
    return ret;
}
int D[200000 + 1]={0,};

void process() {
    FIO fio;
    int N, i, s, e, p , j;
    vector<DATA> A;
    vector<int> X;


    fio.Int(N);

    for ( i = 0 ; i < N ; i ++ ) {
        fio.Int(s, e, p);
        A.push_back(DATA{s, e, p});
        X.push_back(s);
        X.push_back(e);
    }
    std::sort(A.begin(), A.end());
    std::sort(X.begin(), X.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());

    for ( i = 1 ; i < X.size() ; i ++ ) {
        D[i] = D[i-1];

        for ( j = find_start_idx(A, X[i]) ;  j < N && A[j].end == X[i] ; j ++ ) {
            int idx = IDX(X, A[j].start);
            if ( D[idx] + A[j].people > D[i] ) {
                D[i] = D[idx] + A[j].people;
            }
        }
    }
    fio.write_IntLn(D[X.size()-1]);
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


