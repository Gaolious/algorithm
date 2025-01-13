#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
template <typename T> ll DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DISTm(pair<T,T>  a) {return abs(a.first) + abs(a.second);}

void init(){}
string OP(string a, string b, char o, int base) {
    string ans;
    int N1 = a.size(), N2=b.size();
    int i, j, carry, v1, v2, v;

    if ( o == '+' ) {
        for ( carry = 0, i = 0 ; i < N1 || i < N2 || carry != 0 ; i ++ ) {
            v1 = (i<N1) ? a[i]-'0' : 0 ;
            v2 = (i<N2) ? b[i]-'0' : 0 ;
            ans.push_back( (v1+v2+carry) % base + '0' );
            carry = (v1+v2+carry) / base;
        }
    }
    else if ( o == '-') {

        for ( carry = 0, i = 0 ; i < N1 || i < N2 || carry != 0 ; i ++ ) {
            v1 = (i<N1) ? a[i]-'0' : 0 ;
            v2 = (i<N2) ? b[i]-'0' : 0 ;
            v = (v1-v2+carry) ;
            for (carry = 0 ; v < 0 && i < N1; carry--)
                v+=base;
            ans.push_back( v % base + '0' );
        }
    }
    else if ( o == '*' ) {
        for ( i = 0 ; i < N1 ; i ++ ) {
            for ( carry=0, j = 0 ; j < N2 || carry != 0 ; j ++ ) {
                v1 = (i<N1) ? a[i]-'0' : 0 ;
                v2 = (j<N2) ? b[j]-'0' : 0 ;
                v = (v1*v2+carry) + (i+j < ans.size() ? ans[i+j]-'0' : 0);

                if ( i + j >= ans.size() ) {
                    ans.push_back(v % base + '0');
                    carry = v / base;
                }
                else {
                    ans[i+j] = v % base + '0';
                    carry = v / base;
                }
            }
        }
        while( ans.back() == '0' && ans.size() > 1 ) ans.pop_back();
    }
    return ans;
}
void process(int Case) {
    string A[3];
    char q, w;
    int minBase=2;
    cin >> A[0] >> q >> A[1] >> w >> A[2] ;
    for ( int i = 0 ; i < 3 ; i ++) {
        std::reverse(A[i].begin(), A[i].end());
        for (auto c: A[i])
            if ( c - '0' >= minBase )
                minBase = c - '0' + 1 ;
    }

    ll n[3];
    vector<int> ans;
    for ( int base=minBase ; base<=10 ; base++) {
        auto ret = OP(A[0], A[1], q, base);

        if (A[2] == ret )
            ans.push_back(base);
    }

    cout << ans.size() << '\n';
    for (auto &a: ans) cout << a << ' ';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
