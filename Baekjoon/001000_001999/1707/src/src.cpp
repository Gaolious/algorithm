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
    void write_CharLn(char c) { 
        this->write_Char(c);
        this->write_Char('\n');
    }
    void write_Str(char *c) { 
        while ( c && *c)
            this->write_Char(*c++);
    }
    void write_Str(const char *c) { 
        while ( c && *c)
            this->write_Char(*c++);
    }
    void write_Strln(const char *c) { 
        while ( c && *c)
            this->write_Char(*c++);
        this->write_Char('\n');
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
    template<typename T> void write_IntLn(T a) 
    {
        write_Int(a);
        write_Char('\n');
    }
};


void process()
{
    FIO fio ;    
    int K ;

    fio.Int(K);
    while ( K -- )
    {
        int V, E ;
        int i,s,e, j ;

        fio.Int(V, E);
        vector<vector<int>> edge = vector<vector<int>>(V+1);

        for ( i = 0 ; i < E ; i ++ )
        {
            fio.Int(s, e);
            edge[s].push_back(e);
            edge[e].push_back(s);
        }

        vector<char> bip = vector<char>(V+1, 0);
        bool has_error = false ;
        for ( i = 1 ; i <=V && ! has_error; i ++ )
        {
            queue<int> Q;

            if ( bip[i] == 0 )
            {
                Q.push(i);
                bip[ i ] = 1;
            }

            while ( !has_error && !Q.empty() )
            {
                int v = Q.front();
                Q.pop();
                for ( vector<int>::iterator loop1 = edge[v].begin() ; loop1 != edge[v].end() ; loop1 ++ )
                {
                    if ( bip[*loop1] == 0 ) 
                    {
                        bip[*loop1] = 3 - bip[v];
                        Q.push(*loop1);
                    }
                    else if ( bip[*loop1] == bip[v] )
                    {
                        has_error = true ;
                        break;
                    }
                }
            }
        }

        if ( has_error )
            fio.write_Strln("NO");
        else 
            fio.write_Strln("YES");
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


