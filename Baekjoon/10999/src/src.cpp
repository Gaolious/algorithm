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

#ifndef ONLINE_JUDGE 
long long Tree[100];
long long Lazy[100];
#else
long long Tree[1<<21 + 1];
long long Lazy[1<<21 + 1];
#endif

long long build(int idx, int child_left, int child_right, int L, int R)
{
    int m = ( child_right + child_left ) / 2 ;
    if ( child_left > R  || child_right < L ) return 0;
    if ( child_left == child_right)
        return Tree[idx];

    Tree[idx] = build( idx*2, child_left, m, L, R) + build(idx*2+1 , m+1, child_right, L, R);
    return Tree[idx];
}
void prop(int idx, int l, int r)
{
    Lazy[2*idx] += Lazy[idx];    
    Lazy[2*idx+1] += Lazy[idx];
    Tree[idx] += Lazy[idx] * ( r - l + 1ll );
    Lazy[idx] = 0;
}
long long Sum(int idx, int l, int r, int rangeL, int rangeR)
{
    prop(idx, l, r);    

    if ( l > rangeR  || r < rangeL ) return 0ll;
    if ( rangeL <= l && r <= rangeR )
        return Tree[idx];
    int m = ( r + l ) / 2 ;
    return Sum(idx*2, l, m, rangeL, rangeR) + Sum(idx*2+1, m+1, r, rangeL, rangeR);
}
void Add(int idx, int l, int r, int L, int R, long long value)
{
    prop(idx, l, r);    
    
    if ( l > R  || r < L ) return ;
    else if ( L <= l && r <= R )
    {
        Lazy[idx] += value ;
        prop(idx, l, r);
    }
    else
    {
        int m ;
        m = ( r + l ) / 2 ;
        Add(idx*2, l, m, L, R, value);
        Add(idx*2+1, m+1, r, L, R, value);
        Tree[idx] = Tree[idx*2] + Tree[idx*2+1];
    }
}

void process()
{
    FIO fin ;    
    int height;
    int N, M, K ;
    int i, j ;
    int idx;
    int a, b, c ;
    long long d ;

    fin.Int(N, M, K);
    
    height = ceil(log(N) / log(2));
    
    idx = 1 << height;
    for ( i = 0 ; i < N ; i ++ )
        fin.Int(Tree[ idx + i ]);

    build(1, 1, 1 << height , 1, N);

    while ( M > 0 || K > 0 )
    {
        fin.Int(a);
        if ( a == 1 )
        {
            fin.Int(b, c);
            fin.Int(d);
            M --;
            Add(1, 1, 1 << height, b, c, d);
        }
        else if ( a == 2 )
        {
            fin.Int(b, c);
            K --;
            printf("%lld\n", Sum(1, 1, 1 << height, b, c));
        }
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


