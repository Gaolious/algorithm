#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>

using namespace std;
class FIO
{
    char *p;
public :
    FIO()
    {
        struct stat rstat;
        this->p = NULL ;
        
        if ( fstat(0, &rstat) == 0 && rstat.st_size > 0 )
            this->p = (char*)mmap(0, rstat.st_size, PROT_READ, MAP_SHARED, 0, 0) ;
        
        if ( this->p == MAP_FAILED ) this->p = NULL ;
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
};
int max(int a, int b, int c) { return max(a, max(b,c)); }
int min(int a, int b, int c) { return min(a, min(b,c)); }

#define MAX_N (100)
void process()
{
    FIO fio ;
    int len, idx, i ;
    char str[1500+1];
    char ans[][15]={
        "ENGLISH", 
        "SPANISH",
        "GERMAN",
        "FRENCH",
        "ITALIAN",
        "RUSSIAN",
        "UNKNOWN",
    };

    for ( i=1 ; fio.line(str, len, sizeof(str)-1) && strcmp(str, "#") != 0; i ++)
    {
        if ( strcmp(str, "HELLO") == 0 ) idx = 0;
        else if ( strcmp(str, "HOLA") == 0 ) idx = 1;
        else if ( strcmp(str, "HALLO") == 0 ) idx = 2;
        else if ( strcmp(str, "BONJOUR") == 0 ) idx = 3;
        else if ( strcmp(str, "CIAO") == 0 ) idx = 4;
        else if ( strcmp(str, "ZDRAVSTVUJTE") == 0 ) idx = 5;
        else idx = 6;
        
        printf("Case %d: %s\n", i, ans[idx]);
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
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


