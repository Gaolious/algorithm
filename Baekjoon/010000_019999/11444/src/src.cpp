#include <bits/stdc++.h>                                                                                                                         
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>

#include <stdio.h>

const long long MOD (1000000007ll);

class Matrix
{
public :    
    long long a, b, c, d ;
    Matrix(): a(1ll), b(0ll), c(0ll), d(1ll){}
    Matrix(long long a, long long b, long long c, long long d): a(a), b(b), c(c), d(d){}

    Matrix operator *(const Matrix &m) const {
        Matrix ret ;
        ret.a = ( (this->a * m.a) % MOD + (this->b * m.c) % MOD ) % MOD;
        ret.b = ( (this->a * m.b) % MOD + (this->b * m.d) % MOD ) % MOD;
        ret.c = ( (this->c * m.a) % MOD + (this->d * m.c) % MOD ) % MOD;
        ret.d = ( (this->c * m.b) % MOD + (this->d * m.d) % MOD ) % MOD;
        return ret ;
    }
    Matrix &operator =(const Matrix &other )
    {
        if ( this != &other)
        {
            this->a = other.a;
            this->b = other.b;
            this->c = other.c;
            this->d = other.d;
        }
        return *this ;
    }
    Matrix pow(long long n)
    {
        Matrix a = *this ;
        Matrix ret ;
        while ( n >= 1 )
        {
            if ( n % 2 == 1 )
                ret = ret * a ;
            a = a * a ;
            n/=2;
        }
        return ret ;
    }
    void dump(long long n)
    {
        printf("Matrix ^ %lld = \n", n);
        printf("| %8lld %8lld |\n", this->a, this->b);
        printf("| %8lld %8lld |\n", this->c, this->d);
        printf("\n");
    }
};

void process()
{
    long long N ;
    scanf("%lld", &N);

    Matrix m = Matrix(0, 1, 1, 1);
    m = m.pow(N);
    printf("%lld\n", m.b % MOD );
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


