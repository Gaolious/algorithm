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


int Map[2][1001][1001]={0,};
int N, M ;

typedef struct _DATA {
    int y, x, dist;
    int wall_break;
} DATA ;

void dump()
{
    int i, j ;
    printf("---------------------------------------------------\n");
    for ( i = 0 ; i < N ; i ++)
    {
        for ( j = 0 ; j < M ; j ++)
            printf("%3d ", Map[0][i][j]);
        printf("\n");
    }
    printf("\n");
    for ( i = 0 ; i < N ; i ++)
    {
        for ( j = 0 ; j < M ; j ++)
            printf("%3d ", Map[1][i][j]);
        printf("\n");
    }
    printf("\n");

}
void process()
{
    FIO fio ;    
    int i, j ;
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    int tx, ty;
    char c ;
    DATA start_data = { 0, 0, 1, 0 };

    queue<DATA> Q;
    fio.Int(N, M);
    for ( i = 0 ; i < N ; i ++)
    for ( j = 0 ; j < M ; j ++)
    {
        fio.skip();
        if ( fio.Char(c) && c == '1' )
            Map[1][i][j] = Map[0][i][j] = -1 ;
    }    

    Q.push(start_data);
    Map[0][0][0] = Map[1][0][0] = 1;

    while ( !Q.empty() )
    {
        DATA p = Q.front();
        Q.pop();

        for ( i = 0 ; i < 4 ; i ++ )
        {
            tx = p.x + dx[i];
            ty = p.y + dy[i];

            if ( tx >= 0 && tx < M && ty >= 0 && ty < N )
            {
                if ( Map[ p.wall_break ][ ty ][ tx ] == 0 || Map[ p.wall_break ][ ty ][ tx ] > p.dist + 1 )
                {
                    DATA new_p = {ty, tx, p.dist+1, p.wall_break};
                    Map[ new_p.wall_break ] [ new_p.y ][ new_p.x ] = new_p.dist ;
                    Q.push(new_p);

                    if ( new_p.wall_break == 0 )
                    {
                        if ( Map[1][new_p.y][new_p.x] == 0 || Map[1][new_p.y][new_p.x] > new_p.dist )
                        {
                            new_p.wall_break++;
                            Map[1][new_p.y][new_p.x] = new_p.dist;
                            Q.push(new_p);
                        }
                    }
                }
                else if ( p.wall_break == 0 && Map[ 1 ][ ty ][ tx ] == -1 )
                {
                    DATA new_p = {ty, tx, p.dist+1, p.wall_break + 1};
                    Map[ new_p.wall_break ] [ new_p.y ][ new_p.x ] = new_p.dist ;
                    Q.push(new_p);
                }
            }
        }
        // dump();
    }

    if ( Map[ 0 ][N-1][M-1] == 0 && Map[ 1 ][ N-1][ M-1] == 0) 
        printf("-1\n");
    else if ( Map[0][N-1][M-1] > 0 && Map[0][N-1][M-1] < Map[1][N-1][M-1] ) 
        printf("%d\n", Map[0][N-1][M-1]);
    else
        printf("%d\n", Map[1][N-1][M-1]);
        
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


