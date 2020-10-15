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
        fstat(0, &rstat);
        this->p = (char*)mmap(0, rstat.st_size, PROT_READ,MAP_FILE|MAP_PRIVATE, 0, 0);
    }
    void skip() { while ( *this->p && *this->p <= ' ' ) this->p++; }
    bool Char(char &c)  { if ( *this->p <= 0 ) return false ; c = *this->p++; return true ; }
    template<typename T> bool Int(T &n)
    {
        char c ;
        bool flag = true ;
        this->skip();
        if ( ! this->Char(c) )  return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( ! this->Char(c) ) return false ;
        }

        n = 0 ;
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

#define MAX_N (100)
void process()
{
    FIO fio ;
    int t, n ;

    fio.Int(t);
    while (t--)
    {
        fio.Int(n);
        n = n * 315 + 37460 - 498 ;
        if (n<0) n=-n;
        printf("%d\n", (n/10)%10);
    }
    // Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide by 47, then subtract 498. What is the digit in the tens column?
    // ( n * 63 + 7492 ) * 5 - 498
    // 

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
    printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);    
    printf("\n[Press Enter to Continue ...]");
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


