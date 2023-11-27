#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

#define BUFF_LEN ( 1<< 21 )

class FIN_fread
{
    char buf[BUFF_LEN];
    char *p;
    int last_read;
public :
    FIN_fread()
    {
        this->p = buf + BUFF_LEN ;
        this->last_read = 0;
    }
    ~FIN_fread() {
    }
    void skip() { while ( this->p && *this->p && *this->p <= ' ' ) this->p++; }
    bool _byte(char &c)  {
        if ( p - buf >= BUFF_LEN )
        {
            last_read = (int)fread(buf, 1, sizeof(buf), stdin);
            p = buf ;
        }
        else if ( last_read < BUFF_LEN )
        {
            if ( (int)( p - buf) >= last_read ) // EOF
                return false;
        }
        c = *p++;
        return true ;
    }
    bool Char(char &c) { this->skip(); return this->_byte(c); }
    bool Line(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->_byte(c) && c > 0 && c != '\n' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    bool Word(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->_byte(c) && c > 0 && c > ' ' && len < maxLen ; len++ )
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
        if ( !this->_byte(c) )  return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( !this->_byte(c) ) return false ;
        }

        while ( c > ' ' )
        {
            n = n * 10 + c - 48 ;
            if ( !this->_byte(c) ) break;
        }
        if ( !flag ) n = -n;
        return true ;
    }
    template<typename T> bool Int(T &a, T &b) { return this->Int(a) && this->Int(b); }
    template<typename T> bool Int(T &a, T &b, T &c) { return this->Int(a, b) && this->Int(c); }
    template<typename T> bool Int(T &a, T &b, T &c, T &d) { return this->Int(a, b) && this->Int(c, d); }
};


class FIO: public FIN_fread {};
typedef long long int ll ;

struct Rect {
    ll sx, sy, ex, ey;
};
struct Data {
    ll x, sy, ey, diff;
    bool operator < (Data r) const {
        if ( x != r.x ) return x < r.x ;
        return diff > r.diff ;
    }
};

vector<int> Y;
vector<Data> R ;

class SegTree {
public:
    vector<ll> tree;
    vector<ll> data;
    int size;
    int N ;
    SegTree(int N ) {
        this->N = N ;
        for ( this->size = 1 ; this->size < N ; this->size *= 2 );
        this->tree.resize(this->size * 2 + 1, 0) ;
        this->data.resize(this->size * 2 + 1, 0) ;
    }
    void update(int treeIdx, int tL, int tR, int vL, int vR, int diff) {
        if ( tR < vL || vR < tL ) return ;

        if ( vL <= tL && tR <= vR ) {
            this->data[treeIdx] += diff ;
        } else {
            int m = (tL + tR) / 2;
            update(treeIdx * 2    , tL      , m, vL, vR, diff);
            update(treeIdx * 2 + 1, m + 1, tR, vL, vR, diff);
        }
        if ( this->data[treeIdx] > 0)
            this->tree[treeIdx] = Y[tR] - Y[tL-1] ;
        else
        {
            if ( tL == tR )
                this->tree[treeIdx] = 0;
            else
                this->tree[treeIdx] = this->tree[treeIdx*2] + this->tree[treeIdx*2+1];
        }

    }
    void update( int left, int right, int diff ) {
        this->update(1, 0, this->size-1, left, right, diff);
    }
    ll height() {
        return this->tree[1];
    }
    void dump() {
        int i, j ;
        for ( i = 1 ; i <= this->size ; i *= 2 ) {
            for ( j = 0 ; j < i ; j ++ ) {
                printf("%2lld(%2lld) ", this->tree[i+j], this->data[i+j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

long long getLength(vector<Rect> &rect_list) {
    int i ;
    ll prev, s ;

    R.clear();
    Y.clear();

    for ( auto &r: rect_list)
    {
        R.push_back(Data{r.sx, r.sy, r.ey, 1});
        R.push_back(Data{r.ex, r.sy, r.ey, -1});
        Y.push_back(r.sy);
        Y.push_back(r.ey);
    }

    std::sort(Y.begin(), Y.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());
    std::sort(R.begin(), R.end());

    int yIndex[20010]={0,};
    for ( i = 0 ; i < Y.size() ; i ++ )
        yIndex[ Y[i] + 10000] = i ;

    for ( auto &r: R ) {
        r.sy = yIndex[ r.sy + 10000 ] ;
        r.ey = yIndex[ r.ey + 10000 ] ;
    }

    SegTree tree(Y.size());

    s = prev = 0;
    for ( i = 0 ; i < R.size() ; i ++ ) {
        tree.update(R[i].sy+1, R[i].ey, R[i].diff);
        s += abs( prev - tree.height() );
        prev = tree.height();
#ifdef AJAVA_DEBUG
        tree.dump();
        printf("X[%lld] : Y[%lld] (cum:%lld)\n", R[i].x, tree.height(), s);
#endif
    }
    return s ;
}

void process() {
    FIO fio;
    int sx, sy, ex, ey;
    int i ;
    int N ;
    ll ret ;

    vector<Rect> rect_list ;
    fio.Int(N);
    for ( i = 0 ; i < N ; i ++ ) {
        fio.Int(sx, sy, ex, ey);
        if ( sx > ex ) swap(sx, ex);
        if ( sy > ey ) swap(sy, ey);
        rect_list.push_back(Rect{sx, sy, ex, ey});
    }

    // X 축 기준.

    ret = getLength(rect_list);
    for (auto &r: rect_list){
        swap(r.sx, r.sy);
        swap(r.ex, r.ey);
    }

    ret += getLength(rect_list);
    cout << ret << endl;
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


