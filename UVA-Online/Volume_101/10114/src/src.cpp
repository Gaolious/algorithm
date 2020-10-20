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
    template<typename T> bool Float(T &n)
    {
        char c ;
        bool flag = true ;
        T prec = 1.0 ;
        n = 0;
        this->skip();
        if ( ! this->Char(c) )  return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( ! this->Char(c) ) return false ;
        }

        while ( c > ' ' && c != '.' )
        {
            n = n * 10 + c - 48 ;
            if ( ! this->Char(c) ) break;
        }
        if ( c == '.' )
        {
            for ( prec = 0.1 ; ; prec *= 0.1 )
            {
                if ( ! this->Char(c) || c < '0' || c > '9' ) break ;
                n += (c - '0') * prec ;
            }
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
    FIO fin ;
    // Each loan consists of one line containing the duration in months of the loan, the down payment, the amount of the loan, and the number of depreciation records that follow
    int month_loan, N ;
    double down_payment, amount_loan ;
    double car_value, loan ;
    int months ;
    int idx ; 
    vector<pair<int,double>> rate;
    int i ;

    int rate_month ;
    double rate_per_month ;

    while ( true )
    {
        fin.Int(month_loan);
        fin.Float(down_payment);
        fin.Float(amount_loan);
        fin.Int(N);
        if ( month_loan < 0 ) break;
        rate.clear();
        for ( i = 0 ; i < N ; i ++ )
        {
            fin.Int(rate_month);
            fin.Float(rate_per_month);
            rate.push_back(make_pair(rate_month,rate_per_month));
        }
        rate.push_back(rate[N-1]);

        idx = 0;
        car_value = amount_loan + down_payment;
        loan = amount_loan ;

        for ( months = 0 ; ; months ++ )
        {
            while ( months >= rate[idx+1].first && idx < N ) idx ++ ;
            car_value = car_value * (1.0 - rate[idx].second );

            // printf("month = %d : loan = %lf , car_value=%lf\n", months, loan, car_value );
            if ( car_value > loan ) break;

            loan -= amount_loan / month_loan ;
        }
        printf("%d month%s\n", months, months!=1 ? "s" : "");
    }
    /*
12 500.0 9999.99 2
0 .05
2 .1
    loan = 9999.99 / per month = 833.3325
    car value = 10499.99
    0 month 
        car value = 10499.99 * 0.95 = 9974.9905 
        loan = 9999.99
    1 month
        car value = 9476.240975
        loan = 9166.6575
    */
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


