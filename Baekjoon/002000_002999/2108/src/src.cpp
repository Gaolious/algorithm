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

int avg(int S, int N)
{
    int s = S < 0 ? -S : S ;
    int m = s / N ;

    s -= m * N ;
    if ( S > 0 )
    {
        if ( s * 2 >= N ) 
            m++;
    }
    else 
    {
        if ( s * 2 > N )
            m++;
    }

    return S < 0 ? -m : m ;
}


void process()
{
    int N ;
    FIO fin ;    
    int i ;
    int D[500000];
    int C[10000]={0,};
    int nMax, nMin, sum ;
    int max_cnt, cnt1, cnt2;

    fin.Int(N);

    sum = 0 , nMin=4001, nMax=-4001;
    for ( i = 0 ; i < N ; i ++ )
    {
        fin.Int(D[i]);

        sum += D[ i ] ;
        if ( nMin > D[ i ] ) nMin = D[ i ];
        if ( nMax < D[ i ] ) nMax = D[ i ];
        C[ D[i] + 4000 ] ++;
    }
    max_cnt = cnt1 = cnt2 = -100000 ;
    for ( i = 8000 ; i >= 0 ; i -- )
    if ( C[ i ] > 0 )
    {
        if (max_cnt < C[ i ])
        {
            max_cnt = C[ i ] ;
            cnt1 = cnt2 = i - 4000 ;
        }
        else if ( max_cnt == C[ i ] )
        {
            cnt1 = cnt2 ;
            cnt2 = i - 4000 ;
        }
    }

    sort(D, D+N);

    printf("%d\n", avg(sum, N));
    printf("%d\n", D[N/2]);
    printf("%d\n", cnt1);
    printf("%lld\n", (long long int)nMax - (long long int)nMin);
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


