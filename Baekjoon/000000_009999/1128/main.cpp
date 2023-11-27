#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
#define BUFF_LEN ( 1<< 21 )

class FIN
{
    char buf[BUFF_LEN];
    char *p;
    int last_read;
public :
    FIN()
    {
        this->p = buf + BUFF_LEN ;
        this->last_read = 0;
    }
    ~FIN() {
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

        if (!this->p || *this->p <= 0 ) return false ; c = *this->p++; return true ;
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

class FIO: public FIN, public FOUT {};

typedef long long int ll ;

struct Data {
    ll weight;
    ll price ;
    bool operator < (Data d) const {
        return this->weight == d.weight ?
            this->price < d.price : this->weight < d.weight;
    }
    Data operator + (Data d) const {
        return Data{ this->weight + d.weight , this->price + d.price };
    }
};

vector<Data> A;
vector<Data> S;
map<ll, ll> D[50];

ll F(int index, ll max_weight) {
    ll ret = 0 ;

    if ( index < 0 )
        ret = 0;
    else if ( D[index].count(max_weight) )
        return D[index][max_weight];
    else if ( index == 0 )
        ret = (max_weight < S[index].weight ) ? 0 : S[index].price;
    else if (S[index].weight <= max_weight )
        ret = S[index].price ;
    else
    {
        ll including = 0;
        ll excluding = 0;

        if ( A[index].weight <= max_weight)
            including = A[index].price + F(index-1, max_weight - A[index].weight);
        excluding = F(index-1, max_weight);
        ret = max(including, excluding);
    }
    return D[index][max_weight] = ret ;
}

void process() {
    FIO fio;
    ll C, w, p;
    int i, N ;

    fio.Int(N);
    for ( i = 0 ; i < N ; i ++ )
    {
        fio.Int(w, p);
        A.push_back(Data{w, p});
    }
    std::sort(A.begin(), A.end());
    for (i = 0 ; i < N ; i ++ ) {
        if ( i == 0 )
            S.push_back(A[i]);
        else {
            S.push_back(S[i - 1] + A[i]);
        }
    }
    fio.Int(C);
    ll ret = F(N-1, C);

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


