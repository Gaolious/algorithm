#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

class FIO
{
    #define BUFF_LEN (1<<21)
    char *p;
    char out[BUFF_LEN];
    int nOut ;
public :
    FIO()
    {
        struct stat rstat;
        this->p = NULL ;
        
        if ( fstat(0, &rstat) == 0 && rstat.st_size > 0 )
            this->p = (char*)mmap(0, rstat.st_size, PROT_READ, MAP_SHARED, 0, 0) ;
        
        if ( this->p == MAP_FAILED ) this->p = NULL ;
        nOut = 0;
    }
    ~FIO() {
        this->write_flush();
    }
    void skip() { while ( this->p && *this->p && *this->p <= ' ' ) this->p++; }
    bool Char(char &c)  { if ( !this->p || *this->p <= 0 ) return false ; c = *this->p++; return true ; }
    bool line(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();
        
        for ( len = 0 ; this->Char(c) && c > 0 && c != '\n' && len < maxLen ; len++ )
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
        if ( this->nOut > 0 )
        {
            fwrite(this->out, 1, this->nOut, stdout);
            this->nOut = 0;
        }
    }
    void write_Char(char c) { 
        if ( this->nOut >= BUFF_LEN )
            this->write_flush();
        this->out[ this->nOut ++ ] = c ;
    }
    void write_Str(char *c) { 
        while ( c && *c)
            this->write_Char(*c++);
    }
    void write_Str(const char *c) { 
        while ( c && *c)
            this->write_Char(*c++);
    }
    template<typename T> void write_Int(T a) 
    {
        if ( a < 0 ) 
        {
            this->write_Char('-');
            a *= -1;
        }
        else if ( a == 0 ) 
        {
            this->write_Char('0');
        }
        char buff[30];
        int nBuff = 0;
        for ( int i = 0 ; a > 0; a /= 10 )
        {
            buff[nBuff++] = '0' + (a%10);
        }
        while ( nBuff > 0 )
            write_Char(buff[--nBuff]);
    }
};


int C[51][51][51]={0,};

int w(int a, int b, int c)
{
    if ( a <= 0 || b <= 0 || c <= 0)
        return 1;

    if ( a > 20 || b > 20 || c > 20 )
        return w(20, 20, 20);

    int &ret = C[a][b][c] ;
    if (ret == 0)
    {
        if ( a < b && b < c )
            ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

        else 
            ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) ;

    }
    return ret;
}
void process()
{
    FIO fio;

    int a, b, c ;

    while ( fio.Int(a,b,c) && !( a == -1 && b == -1 && c == -1 ) )
    {
        fio.write_Str("w(");
        fio.write_Int(a);
        fio.write_Str(", ");
        fio.write_Int(b);
        fio.write_Str(", ");
        fio.write_Int(c);
        fio.write_Str(") = ");
        fio.write_Int(w(a,b,c));
        fio.write_Char('\n');
    }
}

int main() 
{ 
#ifndef ONLINE_JUDGE 
    clock_t t = clock();
#else  
#endif 

    process(); 

#ifndef ONLINE_JUDGE 
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);    
#else 
#endif 
    return 0; 
} 


