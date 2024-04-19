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

struct DATA {
    int num ;
    int type ;
    int idx;
    int orderH ;
    int orderF ;
//    int orderJ ;

    bool operator < (DATA a) const {
        return this->num < a.num ;
    }
};
vector<DATA> Total;

void process() {
    FIO fio;
    int N, v;
    int i ;
    int Q, a, b, c, k ;

    fio.Int(N);

    for ( i = 0 ; i < N ; i ++ ) {
        fio.Int(v);
        Total.push_back(DATA{v, 1, i+1, 1, 0});
    }
    for ( i = 0 ; i < N ; i ++ ) {
        fio.Int(v);
        Total.push_back(DATA{v,2, i+1, 0, 1});
    }
//    for ( i = 0 ; i < N ; i ++ ) {
//        fio.Int(v);
//        Total.push_back(DATA{v,3, i+1, 0, 0, 1});
//    }
    std::sort(Total.begin(), Total.end());
    for ( i = 1 ; i < Total.size() ; i ++ ) {
        Total[i].orderH += Total[i-1].orderH;
        Total[i].orderF += Total[i-1].orderF;
//        Total[i].orderJ += Total[i-1].orderJ;
    }
    fio.Int(Q);

    int total_idx ;
    int l, r, m, cnt ;

    for ( i = 0 ; i < Q ; i ++ ) {
        fio.Int(a, b, k);
        l = 0, r = (int)(Total.size()-1);
        while ( l <= r ) {
            m = (l+r)/2;
            cnt = min(a, Total[m].orderH) + min(b, Total[m].orderF) ; //+ min(c, Total[m].orderJ);

            if ( cnt < k ) l = m + 1 ;
            else {
                if ( cnt == k )
                    total_idx = m ;
                r = m - 1;
            }

        }
        fio.write_Int(Total[total_idx].type);
        fio.write_Char(' ');
        fio.write_IntLn(Total[total_idx].idx);

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


