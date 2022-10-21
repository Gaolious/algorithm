#include <bits/stdc++.h>

using namespace std;
const int BUFF_LEN = 1 << 21;
class FIN_fread
{
    char buf[BUFF_LEN+1];
    char *p;
    int last_read;
    bool eof ;
public :
    FIN_fread()
    {
        this->eof = false;
        this->p = buf + BUFF_LEN ;
        this->last_read = 0;
    }

    bool _byte(char &c)  {
        if ( p - buf >= BUFF_LEN )
        {
            last_read = (int)fread(buf, 1, BUFF_LEN, stdin);
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

    bool Char(char &c) {
        c = 0;
        while ( c <= ' ' ) {
            if ( !this->_byte(c) ) return false ;
        }
        return true;
    }
    bool Line(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        while ( c <= ' ' ) {
            if ( !this->_byte(c) ) return false ;
        }
        for ( len = 0 ; this->_byte(c) && c > 0 && c != '\n' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    bool Word(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        while ( c <= ' ' ) if ( !this->_byte(c) ) return false ;

        for ( len = 0 ; c > ' ' && len < maxLen ; len++ )
        {
            *s++ = c ;
            if ( !this->_byte(c) ) return false ;
        }
        *s = 0x00;
        return c || len > 0;
    }
    template<typename T> bool Int(T &n)
    {
        char c = 0;
        bool flag = true ;
        n = 0 ;
        while ( c <= ' ' ) if ( !this->_byte(c) ) return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( !this->_byte(c) ) return false ;
        }
        if ( c <= ' ' ) return false ;
        for ( n = 0 ; c > ' ' ; )
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

void process() {
    FIO fio ;
    int T ;
    int N ;
    int C ;
    int i, idx, best ;

    fio.Int(T);
    while ( T-- ) {
        unordered_set<int> D[2];
        fio.Int(N, C);
        vector<int> A(N);

        for ( auto &a: A) fio.Int(a);

        std::sort(A.begin(), A.end());
        idx = 0;
        best = 0 ;
        for ( auto n : A ) {
            if ( n > C ) break;
            for( auto d: D[1-idx] ) {
                for ( auto k : { d, d+n } )
                {
                    if ( k > C ) continue;
                    D[idx].insert( k );
                    best = max(best, k);
                }
            }
            D[idx].insert(n);
            best = max(best, n);
            idx = 1 - idx;
        }
        fio.write_IntLn(best);
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


