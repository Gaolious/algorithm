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
const int MaxN = 100100;
int D[MaxN+1];
int P[MaxN+1];
int best = MaxN;

struct DATA {
    int t ;
    int p ;
    bool operator < (DATA d) const {
        return abs(this->t - best) < abs(d.t - best) ;
    }
};
priority_queue<DATA> Q ;

bool is_valid(DATA &d) {
    if ( d.t < 0 || d.t >= best ) return false ;
    if ( d.p < 0 || d.p > MaxN ) return false ;
    if ( D[d.p] <= d.t ) return false ;
    return true ;
}
void addItem(DATA &d, int srcPos) {

    D[d.p] = d.t;
    P[d.p] = srcPos ;
    Q.push(d);
}
void process() {
    FIO fio;

    int i, N, K ;
    DATA new_data ;

    fio.Int(N, K);
    if ( K < N )
        best = N - K + 1;
    else
    {
        best = K - N + 1 ;
        for ( i = N ; i < MaxN && i > 0 ; i *= 2 ){
            best = min( best, abs(i - K) + 1 );
        }
    }
    best += 1 ;

    for ( i = 0 ; i <= MaxN ; i ++ )
    {
        D[ i ] = best ;
        P[ i ] = -1;
    }
    new_data = DATA {0, N};
    addItem(new_data, N);

    while ( !Q.empty() ) {
        auto d = Q.top();
        Q.pop();
        if ( d.t >= best ) continue;

        new_data = DATA{ d.t + 1, d.p - 1};
        if (is_valid(new_data))
            addItem(new_data, d.p);

        new_data = DATA{ d.t + 1, d.p + 1};
        if (is_valid(new_data))
            addItem(new_data, d.p);

        new_data = DATA{ d.t, d.p * 2};
        if (is_valid(new_data))
            addItem(new_data, d.p);

        if ( D[K] != best )
        {
            best = min(D[K], best);
#ifdef AJAVA_DEBUG
            printf("updated best : %d \n", best);
#endif
        }
    }
    fio.write_IntLn(best);

//    vector<int> O ;
//    for ( i = K ; i >= 0 ; i = P[i] ) {
//        O.push_back(i);
//        if ( i == P[i] ) break;
//    }
//
//    for ( i = O.size()-1; i >= 0 ; i -- )
//    {
//        fio.write_Int( O[i]);
//        fio.write_Char(' ');
//    }
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


