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
namespace koosaga {
    const long long int mod = 1'000'000'007;
    using lint = long long;
    lint ipow(lint x, lint p){
        lint ret = 1, piv = x;
        while(p){
            if(p & 1) ret = ret * piv % mod;
            piv = piv * piv % mod;
            p >>= 1;
        }
        return ret;
    }
    vector<lint> berlekamp_massey(vector<lint> x){
        vector<lint> ls, cur;
        lint lf, ld;
        for(int i=0; i<x.size(); i++){
            lint t = 0;
            for(int j=0; j<cur.size(); j++){
                t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
            }
            if((t - x[i]) % mod == 0) continue;
            if(cur.empty()){
                cur.resize(i+1);
                lf = i;
                ld = (t - x[i]) % mod;
                continue;
            }
            lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
            vector<lint> c(i-lf-1);
            c.push_back(k);
            for(auto &j : ls) c.push_back(-j * k % mod);
            if(c.size() < cur.size()) c.resize(cur.size());
            for(int j=0; j<cur.size(); j++){
                c[j] = (c[j] + cur[j]) % mod;
            }
            if(i-lf+(int)ls.size()>=(int)cur.size()){
                tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
            }
            cur = c;
        }
        for(auto &i : cur) i = (i % mod + mod) % mod;
        return cur;
    }
    int get_nth(vector<lint> rec, vector<lint> dp, lint n){
        int m = rec.size();
        vector<lint> s(m), t(m);
        s[0] = 1;
        if(m != 1) t[1] = 1;
        else t[0] = rec[0];
        auto mul = [&rec](vector<lint> v, vector<lint> w){
            int m = v.size();
            vector<lint> t(2 * m);
            for(int j=0; j<m; j++){
                for(int k=0; k<m; k++){
                    t[j+k] += 1ll * v[j] * w[k] % mod;
                    if(t[j+k] >= mod) t[j+k] -= mod;
                }
            }
            for(int j=2*m-1; j>=m; j--){
                for(int k=1; k<=m; k++){
                    t[j-k] += 1ll * t[j] * rec[k-1] % mod;
                    if(t[j-k] >= mod) t[j-k] -= mod;
                }
            }
            t.resize(m);
            return t;
        };
        while(n){
            if(n & 1) s = mul(s, t);
            t = mul(t, t);
            n >>= 1;
        }
        lint ret = 0;
        for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
        return ret % mod;
    }
    int guess_nth_term(vector<lint> x, lint n){
        if(n < x.size()) return x[n];
        vector<lint> v = berlekamp_massey(x);
        if(v.empty()) return 0;
        return get_nth(v, x, n);
    }
    struct elem{lint x, y, v;}; // A_(x, y) <- v, 0-based. no duplicate please..
    vector<lint> get_min_poly(int n, vector<elem> M){
        // smallest poly P such that A^i = sum_{j < i} {A^j \times P_j}
        vector<int> rnd1, rnd2;
        mt19937 rng(0x14004);
        auto randint = [&rng](int lb, int ub){
            return uniform_int_distribution<int>(lb, ub)(rng);
        };
        for(int i=0; i<n; i++){
            rnd1.push_back(randint(1, mod - 1));
            rnd2.push_back(randint(1, mod - 1));
        }
        vector<lint> gobs;
        for(int i=0; i<2*n+2; i++){
            int tmp = 0;
            for(int j=0; j<n; j++){
                tmp += 1ll * rnd2[j] * rnd1[j] % mod;
                if(tmp >= mod) tmp -= mod;
            }
            gobs.push_back(tmp);
            vector<int> nxt(n);
            for(auto &i : M){
                nxt[i.x] += 1ll * i.v * rnd1[i.y] % mod;
                if(nxt[i.x] >= mod) nxt[i.x] -= mod;
            }
            rnd1 = nxt;
        }
        auto sol = berlekamp_massey(gobs);
        reverse(sol.begin(), sol.end());
        return sol;
    }
    lint det(int n, vector<elem> M){
        vector<int> rnd;
        mt19937 rng(0x14004);
        auto randint = [&rng](int lb, int ub){
            return uniform_int_distribution<int>(lb, ub)(rng);
        };
        for(int i=0; i<n; i++) rnd.push_back(randint(1, mod - 1));
        for(auto &i : M){
            i.v = 1ll * i.v * rnd[i.y] % mod;
        }
        auto sol = get_min_poly(n, M)[0];
        if(n % 2 == 0) sol = mod - sol;
        for(auto &i : rnd) sol = 1ll * sol * ipow(i, mod - 2) % mod;
        return sol;
    }
}
void process() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    cout << koosaga::guess_nth_term({272, 589185, 930336768}, n) << endl;
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


