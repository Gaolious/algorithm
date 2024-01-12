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

int M[16][16]={0,};
int D[3][16][16]={0,};
int N ;
bool is_range(int y, int x)
{
    return ( y >= 0 && y < N && x >= 0 && x < N );
}
bool move_right(int d, int y, int x)
{
    return (D[d][y][x] && is_range(y, x+1) && M[y][x+1] == 0 ) && ( d == 0 || d == 1 );
}
bool move_down(int d, int y, int x)
{
    return (D[d][y][x] && is_range(y+1, x) && M[y+1][x] == 0 ) && ( d == 1 || d == 2 );
}
bool move_diag(int d, int y, int x)
{
    return (D[d][y][x] && is_range(y+1, x+1) && M[y+1][x] == 0 && M[y][x+1] == 0 && M[y+1][x+1] == 0 );    
}

void dump()
{

}
void process()
{
    FIO fin ;    

    int d, x, y ;
    int tx, ty ;

    D[0][0][1] = 1;
    fin.Int(N);
    for ( y = 0 ; y < N ; y ++ )
        for ( x = 0 ; x < N ; x ++ )
            fin.Int(M[y][x]);

    for ( y = 0 ; y < N ; y ++ )
    {
        for ( x = 0 ; x < N ; x ++ )
        {
            for ( d = 0 ; d < 3 ; d ++ )
            {
                if ( move_right(d, y, x) ) 
                    D[0][y][x+1] += D[d][y][x];
                if ( move_diag(d, y, x) ) 
                    D[1][y+1][x+1] += D[d][y][x];
                if ( move_down(d, y, x) ) 
                    D[2][y+1][x] += D[d][y][x];
            }
        }
    }
    

    printf("%d\n", D[0][N-1][N-1] + D[1][N-1][N-1] + D[2][N-1][N-1]);
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


