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
    char out[BUFF_LEN]{};
    int nOut ;
public :
    FIO()
    {
        struct stat rstat{};
        this->p = nullptr ;

        if ( fstat(0, &rstat) == 0 && rstat.st_size > 0 )
            this->p = (char*)mmap(nullptr, rstat.st_size, PROT_READ, MAP_SHARED, 0, 0) ;

        if ( this->p == MAP_FAILED ) this->p = nullptr ;
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
        if ( this->nOut > 0 ) fwrite(this->out, 1, this->nOut, stdout);
        this->nOut = 0;
    }
    void write_Char(char c) { if ( this->nOut >= BUFF_LEN ) this->write_flush(); this->out[ this->nOut ++ ] = c ; }
    void write_CharLn(char c) { this->write_Char(c); this->write_Char('\n'); }
    void write_Str(char *c) { while ( c && *c) this->write_Char(*c++); }
    void write_Str(const char *c) { while ( c && *c) this->write_Char(*c++); }
    template<typename T> void write_Int(T a)
    {
        if ( a < 0 )
        {
            this->write_Char('-');
            a *= -1;
        }
        else if ( a == 0 )
            this->write_Char('0');
        char buff[30];
        int nBuff = 0;
        for ( int i = 0 ; a > 0; a /= 10 )
            buff[nBuff++] = '0' + (a%10);
        while ( nBuff > 0 )
            write_Char(buff[--nBuff]);
    }
    template<typename T> void write_IntLn(T a)
    {
        write_Int(a);
        write_Char('\n');
    }
};

int gcd(int a, int b) {
    if ( b > 0 ) return gcd (b, a % b);
    return a;
}

bool use[100];
struct POINT {
    int y, x ;
    int dist(POINT &p) {
        return abs(p.x - this->x) + abs(p.y - this->y);
    }
};
struct DIST {
    int store_idx ;
    int dist ;
    bool operator < (DIST d) const {
        return this->dist < d.dist ;
    }
};
vector<POINT> House, Store ;
vector<DIST> Dist[2500] ;
int best = -1;
const int INF = 2500*100 + 1;

int get_dist() {
    int distance = 0;
    int i ;
    for ( i = 0 ; i < House.size() ; i ++ ) {
        for (auto d: Dist[i]) {
            if ( use[d.store_idx] ) {
                distance += d.dist;
                break;
            }
        }
    }
    return distance == 0 ? INF : distance;
}

int find(int idx, int remain) {
    int total_dist = remain > 0 ? INF : get_dist();
    int ret ;
    if ( idx >= 0 )
    {
        use[idx]=false;
        ret = find(idx-1, remain-1);
        total_dist = min(total_dist, ret);
        use[idx]=true;

        ret = find(idx-1, remain);
        total_dist = min(total_dist, ret);
    }

    return total_dist;
}

void process() {
    FIO fio;
    int n, d ;
    int i, j ;
    int N, M ;

    fio.Int(N, M);
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            fio.Int(n);
            if ( n == 1 )
                House.push_back(POINT{i, j});
            else if ( n == 2 )
                Store.push_back(POINT{i, j});
        }
    }

    for ( i = 0 ; i < House.size() ; i ++ ) {
        use[i] = true ;
        for ( j = 0 ; j < Store.size() ; j ++ ) {
            d = House[i].dist(Store[j]);
            Dist[i].push_back(DIST{j, d} );
        }
        std::sort(Dist[i].begin(), Dist[i].end());
    }

    fio.write_IntLn(find((int)(Store.size())-1, (int)(Store.size()) - M ));
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


