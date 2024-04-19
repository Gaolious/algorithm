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

int Minlen, MaxLen, S ;
int Count[1000+1]={0,};
int choose[51][51]={0,};
bool check(int target) {

    int i, j ;
    vector<int> Num;
    int C[100000]={0, };
    for ( i = Minlen ; i <= MaxLen ; i ++ )
        for ( j = 0 ; j < Count[i] ; j ++ )
            Num.push_back(i);
    for (auto n : Num)
    {
        for ( i = target ; i > n ; i -- )
            C[ i ] += C[i - n ];
        C[n]=1;
        if ( C[target] == 1 )
            return true ;
    }
    return C[target] == 1;
}
bool F(int idx, int last_idx, int s, int target) {
    if ( S / target == idx ) {
        return true ;
    }
    if ( s > target) return false ;
    if ( ! check(target-s) )
        return false ;

    bool ret ;
    int i;
    for ( i = last_idx ; i <= MaxLen && i <= target - s ; i ++ ) {
        if ( Count[i] == 0 ) continue;

        choose[idx][0]++;
        choose[idx][ choose[idx][0] ] = i ;
        Count[i]--;

        if ( s + i == target ) {
            ret = F(idx+1, Minlen, 0, target);
        } else {
            ret = F(idx, i, s + i, target);
        }
        if ( ret )
            return ret;

        choose[idx][ choose[idx][0] ] = 0;
        choose[idx][0]--;
        Count[i]++;
    }
    return false;
}
void process() {
    FIO fio;
    int i ;
    int N, a ;

    Minlen = 1000 ;
    MaxLen = 1 ;
    S = 0 ;

    fio.Int(N);
    for ( i = 0 ; i < N ; i ++ )
    {
        fio.Int(a);
        MaxLen = max(MaxLen, a);
        Minlen = min(Minlen, a);
        Count[a]++;
        S += a ;
    }
    for ( i = MaxLen ; i <= S ; i ++ ) {
        if (S % i != 0) continue;
        memset(choose, 0, sizeof(choose));

        if (F(0, Minlen, 0, i)) {
            fio.write_IntLn(i);
            for (int j = 0; j < S / i; j++) {
                for (int k = 1; k <= choose[j][0]; k++) {
                    fio.write_Int(choose[j][k]);
                    fio.write_Char(' ');
                }
                fio.write_Char('\n');
            }
        }
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


