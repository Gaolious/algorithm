#include <bits/stdc++.h>


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


typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef pair<int, int> pii ;
typedef long long int ll ;

struct SpanningTree {
    int nNode;
    vector<vector<pii>> E;
    vector<ll> W;
    SpanningTree(int nNode) {
        this->nNode = nNode;
        this->E.resize(nNode);
        this->W.resize(nNode);
    }
    void addEdge(int from, int to, int dist ) {
        this->E[from].emplace_back(to, dist);
    }
    void findMST() {
        int i ;
        vector<bool> used(this->nNode, false);

        for ( i = 0 ; i < this->nNode ; i ++ ) {
            if ( used[i] ) continue;
            priority_queue<pii, vector<pii>, greater<pii> > Q;
            Q.emplace(0, i);

            while ( !Q.empty() ) {
                int curr = Q.top().second ;
                int dist = Q.top().first ;
                Q.pop();

                if ( used[ curr ] ) continue ;

                this->W[ curr ] = dist;
                used[ curr ] = true ;

                for ( auto e: this->E[curr]) {
                    if ( used[ e.first ] ) continue;
                    Q.emplace( e.second, e.first );
                }
            }
        }
    }
};

void process() {
    FIO fio;
    int N, M ;
    int f, t, d;
    int i ;

    fio.Int(N, M);

    SpanningTree st(N);

    for ( i = 0 ; i < M ; i ++ ) {
        fio.Int(f, t, d);
        st.addEdge(f-1, t-1, d);
        st.addEdge(t-1, f-1, d);
    }

    st.findMST();
    ll sumW, maxW ;
    sumW = 0, maxW = -1;
    for ( i = 0 ; i < N ; i ++ ) {
        sumW += st.W[i];
        maxW = max( maxW, st.W[i] );
    }
    cout << sumW - maxW << endl;
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


