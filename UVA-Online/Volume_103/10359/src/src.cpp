#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;
 
#define MAX_N (100)
#define MOD (10000)

struct NUM
{
    int number[MAX_N];
    int length ;
    NUM() { 
        this->length = 0 ;
        memset(this->number, 0x00, sizeof(this->number));
    }
    void set(int n)
    {
        int i;
        for ( i = 0 ; n > 0 ; i ++ )
        {
            number[i] = n%MOD ;
            n /= MOD;
            this->length = i;
        }
    }
    void add(NUM &a, NUM &b)
    {
        int i, j ;
        int len ;

        for ( len = i = j = 0 ; i <= a.length || j <= b.length ; len++)
        {
            if ( i <= a.length ) this->number[len] += a.number[i++];
            if ( j <= b.length ) this->number[len] += b.number[j++];

            if ( this->number[len] >= MOD )
            {
                this->number[len+1] += this->number[len] / MOD ;
                this->number[len] = this->number[len] % MOD ;

                if ( this->length < len+1 ) 
                    this->length = len+1 ;
             }
            if ( this->length < len ) 
                this->length = len ;
        }
    }
    void print()
    {
        for ( int i = this->length ; i >= 0 ; i -- )
        {
            if ( i == this->length ) printf("%d", this->number[i]);
            else printf("%04d", this->number[i] );
        }
    }
};
void process()
{
    NUM ans[251];
    int i ;

    ans[0].set(1);
    ans[1].set(1);
    for ( i = 2 ; i <= 250 ; i ++ )
    {
        NUM t ;
        t.add(ans[i-1], ans[i-2]);
        ans[i].add(t, ans[i-2]);
        // printf("%d : ", i);
        // ans[i].print(); 
        // printf("\n");
    }

    int n ;
    while ( scanf("%d ", &n) == 1 )
    {
        ans[n].print();
        printf("\n");
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
    printf("\n[Press Enter to Continue ...]");
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


