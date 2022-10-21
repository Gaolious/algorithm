#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

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
class FOUT
{
    char out[BUFF_LEN]{};
    int nOut ;
public:
    FOUT () { this->nOut = 0; }
    ~FOUT() { this->write_flush(); }
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
class FIO: public FIN_fread, public FOUT {};

struct Node {
    ll max_val, min_val, sum_val;
    ll lazy_add, lazy_set;
};
ll A[100'000+1]={0,};
Node Tree[262144 + 1]={0,};

Node merge(Node a, Node b){
    return Node{
        max(a.max_val, b.max_val),
        min(a.min_val, b.min_val),
        a.sum_val + b.sum_val,
        0, 0
    };
}

void _update_lazy(int idx, int s, int e) {
    if ( Tree[idx].lazy_add == 0 && Tree[idx].lazy_set == 0)
        return ;

    if ( Tree[idx].lazy_set == 0 ) {
        Tree[idx].max_val += Tree[idx].lazy_add;
        Tree[idx].min_val += Tree[idx].lazy_add;
        Tree[idx].sum_val += Tree[idx].lazy_add * ( e - s + 1ll );
        if ( s != e ) {
            Tree[idx*2].lazy_add += Tree[idx].lazy_add;
            Tree[idx*2+1].lazy_add += Tree[idx].lazy_add;
        }
    } else {
        Tree[idx].max_val = Tree[idx].lazy_add + Tree[idx].lazy_set;
        Tree[idx].min_val = Tree[idx].lazy_add + Tree[idx].lazy_set;
        Tree[idx].sum_val = Tree[idx].min_val * ( e - s + 1ll );

        if ( s != e ) {
            Tree[idx*2].lazy_add = Tree[idx].lazy_add;
            Tree[idx*2+1].lazy_add = Tree[idx].lazy_add;
            Tree[idx*2].lazy_set = Tree[idx].lazy_set;
            Tree[idx*2+1].lazy_set = Tree[idx].lazy_set;
        }
    }
    Tree[idx].lazy_add = Tree[idx].lazy_set = 0;
}

void update_add(int idx, int s, int e, int l, int r, ll value ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return;
    if (l <= s && e <= r )
    {
        Tree[idx].lazy_add = value ;
        _update_lazy(idx, s, e);
        return ;
    }
    int m ;
    m = ( s + e ) / 2 ;
    update_add(idx * 2, s, m, l, r, value);
    update_add(idx * 2 + 1, m + 1, e, l, r, value);
    Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
}
ll floorSqrt(ll v) {
    ll i ;
    for ( i = 0 ; ; i ++ ) {
        if ( (i+1)*(i+1) > v)
            return i;
    }
}

void update_sqrt(int idx, int s, int e, int l, int r ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return;
    if (l <= s && e <= r )
    {
        ll fs_min = floor(sqrt(Tree[idx].min_val));
        ll fs_max = floor(sqrt(Tree[idx].max_val));

        if (fs_min == fs_max ) {
            Tree[idx].lazy_set = fs_min ;
            _update_lazy(idx, s, e);
            return ;
        }
        if ( Tree[idx].min_val + 1 == Tree[idx].max_val ) {
            Tree[idx].lazy_add = fs_min - Tree[idx].min_val;
            _update_lazy(idx, s, e);
            return ;
        }
    }
    int m ;
    m = ( s + e ) / 2 ;
    update_sqrt(idx * 2, s, m, l, r);
    update_sqrt(idx * 2 + 1, m + 1, e, l, r);
    Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
}

ll getSum(int idx, int s, int e, int l, int r ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return 0;
    if (l <= s && e <= r) return Tree[idx].sum_val;
    int m = ( s + e ) / 2 ;
    return getSum(idx * 2, s, m, l, r) + getSum(idx * 2 + 1, m + 1, e, l, r);
}

Node init(int idx, int s, int e) {
    if ( s == e ) {
        return Tree[idx] = Node{A[s], A[s], A[s], 0, 0};
    }
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m), init(idx*2+1, m+1, e) );
}
void dump(int N) {
#ifdef AJAVA_DEBUG
    int i, j ;
    printf("\n\n");
    for ( i = 1, j = 1 ; i <= N ; i *= 2 ) {
        for ( j = 0 ; j < i ; j ++ ) {
            Node &t = Tree[i+j];
            printf("[%d:Max:%lld,Min:%lld,sum:%lld,lazyAdd:%lld,lazySet:%lld] ",i+j, t.max_val, t.min_val, t.sum_val, t.lazy_add, t.lazy_set);
        }
        printf("\n");
    }
#endif
}

void process() {
    FIO fio;
    int N, M;
    int i ;
    int a, b, c, d;
    int T ;

    fio.Int(T) ;
    while ( T-- ) {
        memset(A, 0, sizeof(A));
        memset(Tree, 0, sizeof(Tree));

        fio.Int(N, M);

        for ( i = 1 ; i <= N ; i ++ )
        {
            fio.Int(A[i]);

//            update_add(1, 1, N, i, i, a);
        }
        init(1, 1, N);

        while ( M -- ) {
            fio.Int(a, b, c);

            switch (a) {
                case 1:
                    update_sqrt(1, 1, N, b, c);
                    break;
                case 2:
                    fio.write_IntLn(getSum(1, 1, N, b, c));
                    break;
                case 3:
                    fio.Int(d);
                    update_add(1, 1, N, b, c, d);
                    break;
            }
        }

    }
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


