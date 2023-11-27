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

struct NODE {
    int n ;
    int idx;
};

class SegTree {
public:
    vector<NODE> tree;
//    vector<int> data;
    vector<int> comp_data;
    int size ;
    int N ;
    int diff ;

    SegTree(int N){
        this->N = N ;
        for ( this->size = 1 ; this->size < this->N ; this->size *= 2 ){}
        this->tree.resize(this->size * 2);
        this->comp_data.resize(this->N);

        int i;
        for ( i = 0 ; i < this->size; i ++ )
            this->tree[i].n = 0;
        for ( i = 0 ; i < this->N ; i ++ )
            this->comp_data[i] = 0;

        this->diff = 0;
    }

    void updateTree(int treeIdx) {
        int offset;

        for ( offset = treeIdx / 2  ; offset >= 1 ; offset /= 2 ) {
            int maxIdx = ( this->tree[offset * 2 ].n < this->tree[offset * 2 + 1].n ) ? offset * 2 + 1 : offset * 2 ;
            if ( this->tree[offset].n != this->tree[maxIdx].n ) {
                this->tree[offset] = this->tree[maxIdx] ;
            } else {
                return ;
            }
        }
    }

    void build(int treeIdx, int left, int right) {

        if ( left >= right ) {
            return;
        }
        if ( treeIdx < this->tree.size() )
        {
            int m = (left+right)/2;
            build(treeIdx * 2, left, m);
            build(treeIdx * 2 + 1 , m+1, right);

            if ( this->tree[treeIdx*2].n < this->tree[treeIdx*2+1].n )
                this->tree[treeIdx] = this->tree[treeIdx*2+1];
            else
                this->tree[treeIdx] = this->tree[treeIdx*2] ;
        }

    }

    void set_number(int idx, int n) {
        this->tree[this->size+idx].n = n;
        this->tree[this->size+idx].idx = idx;
    }
    void set_comp_number(int idx, int n) {
        this->comp_data[idx] = n;
        if ( abs(this->at(idx)) != n )
            this->diff ++ ;
    }

    void swap(int i, int j){
        int v1 = this->at(i);
        int v2 = this->at(j);
        this->updateData(i, v2);
        this->updateData(j, v1);
    }
    void updateData(int idx, int n) {
        if ( this->comp_data[idx] != abs(this->at(idx)) && this->comp_data[idx] == abs(n) )
            this->diff--;
        else if ( this->comp_data[idx] == abs(this->at(idx)) && this->comp_data[idx] != abs(n) )
            this->diff++;

        this->tree[ this->size + idx ].n = n ;
        this->updateTree(this->size + idx);
    }

    int at(int idx) const {
        return this->tree[ this->size + idx ].n ;
    }
    NODE top() const {
        return this->tree[1];
    }
    void remove(int idx) {
        this->updateData(idx, -this->at(idx));
    }
    void dump() {
        int i, j ;
        printf("\ntree \n");

        for ( i = 1 ; i < this->size*2 ; i *= 2 ) {
            for ( j = 0 ; j < i ; j ++ )
                printf("%d ", this->tree[i+j].n);
            printf("\n");
        }
        printf("\n");
    }

};
void process() {
    FIO fio;
    int N, n ;
    int i ;
    fio.Int(N);
    SegTree tree(N);

    for ( i = 0 ; i < N ; i ++ )
    {
        fio.Int(n);
        tree.set_number(i, n);
    }
    tree.build(1, 1, tree.size );
    for ( i = 0 ; i < N ; i ++ )
    {
        fio.Int(n);
        tree.set_comp_number(i, n);
    }

    if ( tree.diff == 0 ) {
        fio.write_Str("1\n");
        return;
    }
    for ( i = N-1 ; i >= 0 ; i -- ) {
        NODE t = tree.top();
        if ( t.n != tree.at(i) ){
            tree.swap(i, t.idx);
        }
        tree.remove(i);

        if ( tree.diff == 0 ) {
            fio.write_Str("1\n");
            return;
        }
    }
    fio.write_Str("0\n");
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


