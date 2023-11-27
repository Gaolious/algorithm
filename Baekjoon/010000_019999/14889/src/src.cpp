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

int M[20][20]={0,};
int N, Tsum, Rsum[20]={0,}, Csum[20]={0,} ;
int best = -1 ;
int ABS(int a) { return a < 0 ? -a : a ; }
void recur(int idx, int curr, int s)
{
    int i, j, k ;
    int max_n = N - (N/2 - idx - 1);

    if ( idx == N/2 )
    {
        if ( best < 0 || best > ABS(s) )
            best = ABS(s) ;
        return ;
    }
    for ( int i = curr ; i < max_n ; i ++ )
    {
        recur(idx + 1, i + 1, s - Rsum[i] - Csum[i]);
    }
}
void process()
{
    FIO fio ;
    int i, j;
    fio.Int(N);

    Tsum = 0 ;
    for ( i = 0 ; i < N ; i ++ )
    for ( j = 0 ; j < N ; j ++ )
    {
        fio.Int(M[ i ][ j ]);
        Tsum += M[ i ][ j ] ;
        Rsum[ i ] += M[ i ][ j ] ;
        Csum[ j ] += M[ i ][ j ] ;
    }
    
    recur(0, 0, Tsum);
    printf("%d\n", best);
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


