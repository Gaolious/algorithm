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
    ll sum_val;
    ll lazy_add;
    ll lazy_cnt;
};
ll A[100'000+1]={0,};
Node Tree[262'144 + 1]={0,};
const ll INF = 1e16;
Node merge(Node a, Node b){
    return Node{
            a.sum_val + b.sum_val,
            0,
            0,
    };
}

void _update_lazy(int idx, int s, int e) {
    if ( Tree[idx].lazy_cnt == 0)
        return ;
    // s : 1, 5
    // add: 5
    // -----------------
    // 1 2 3 4 5
    // 5 6 7 8 9  : sum = 35
    // [add-1] * cnt + (cnt+1)*cnt / 2 : (5-1)*5 + (5*6)/2 = 20+15 = 35
    // cnt * (cnt+[add]*2+1) / 2 = 5 * (5+8+1) / 2 = 35

    ll cnt = e - s + 1 ;
    ll m = (s + e) / 2 ;
    ll addNum = Tree[idx].lazy_add - 1;

    Tree[idx].sum_val += cnt * ( cnt + addNum * 2 + 1) / 2 ;
    if ( s != e ) {
        Tree[idx*2].lazy_add += Tree[idx].lazy_add;
        Tree[idx*2+1].lazy_add += Tree[idx].lazy_add + (m+1-s) * Tree[idx].lazy_cnt;
        Tree[idx*2].lazy_cnt += Tree[idx].lazy_cnt;
        Tree[idx*2+1].lazy_cnt += Tree[idx].lazy_cnt;
    }
    Tree[idx].lazy_add = 0;
    Tree[idx].lazy_cnt = 0;

}

void update_add(int idx, int s, int e, int l, int r, ll value ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return;
    if (l <= s && e <= r )
    {

        Tree[idx].lazy_add = value + (s-l);
        Tree[idx].lazy_cnt += 1 ;
        _update_lazy(idx, s, e);
        return ;
    }
    int m = ( s + e ) / 2 ;

    update_add(idx * 2, s, m, l, r, value);
    update_add(idx * 2 + 1, m + 1, e, l, r, value);
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
        return Tree[idx] = Node{A[s], 0, 0};
    }
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m), init(idx*2+1, m+1, e) );
}
void dump(int N) {
#ifdef AJAVA_DEBUG
    int i, j ;
    printf("\n\n");
    for ( i = 1, j = 1 ; ; i *= 2 ) {
        for ( j = 0 ; j < i && j < N ; j ++ ) {
            Node &t = Tree[i+j];
            printf("[%d:S:%lld,+:%lld,C:%lld] ",i+j, t.sum_val, t.lazy_add, t.lazy_cnt);
        }
        printf("\n");
        if ( i >= N ) break;
    }
#endif
}

void process() {
    FIO fio;
    int N, M;
    int i ;
    int a, b, c, d;

    fio.Int(N);

    for ( i = 1 ; i <= N ; i ++ )
        fio.Int(A[i]);
    init(1, 1, N);
    fio.Int(M);
    dump(N);
    while ( M -- ) {
        fio.Int(a, b);
        switch (a) {
            case 1:
                fio.Int(c);
                if ( b > c ) swap(b, c);
                update_add(1, 1, N, b, c, 1);
                break;
            case 2:
                fio.write_IntLn(getSum(1, 1, N, b, b));
                break;

        }
        dump(N);

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


