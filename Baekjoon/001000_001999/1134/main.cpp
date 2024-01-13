#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
string A, B, C;

struct Candidate {
    int a, b, c;
    Candidate(): a(-1), b(-1), c(-1) {}
    Candidate(int aa, int bb, int cc): a(aa), b(bb), c(cc) {}
};
struct Result {
    string a;
    string b;
    string c;
    bool has;

    Result() : has(false){}
    Result(string &aa, string &bb, string &cc): a(aa), b(bb), c(cc), has(true) {}
    bool operator < ( const Result &o ) const {
        if ( c.length() != o.c.length() ) return c.length() < o.c.length();
        for (int i = c.length() - 1 ; i >= 0 ; i -- )
            if ( c[i] != o.c[i] )
                return c[i] < o.c[i];

        if ( a.length() != o.a.length() ) return a.length() < o.a.length();
        for (int i = a.length() - 1 ; i >= 0 ; i -- )
            if ( a[i] != o.a[i] )
                return a[i] < o.a[i];

        return false;
    }
    void push(Candidate &o) {
        if ( a.length() < A.length() ) a.push_back('0' + o.a), has = true;
        if ( b.length() < B.length() ) b.push_back('0' + o.b), has = true;
        if ( c.length() < C.length() ) c.push_back('0' + o.c), has = true;
    }
    bool empty() const {
        return !has;
    }
    void rev() {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
    }
};

Result D[50][2]; // idx, has carry T/F

void input() {
    string s;
    int plus, equal, i;
    cin >> s ;
    plus = s.find('+');
    equal = s.find('=', plus);

    for ( i = plus-1 ; i>= 0 ; i -- ) A.push_back(s[i]);
    for ( i = equal-1 ; i> plus ; i -- ) B.push_back(s[i]);
    for ( i = s.length()-1 ; i> equal ; i -- ) C.push_back(s[i]);
}

void generate_candidates(int idx, int needCarry, int hasCarry, vector<Candidate> &candinates) {
    candinates.clear();
    vector<int> va ;
    vector<int> vb ;
    if ( idx >= A.length() ) va.push_back(0);
    else {
        for ( int a = 0 ; a < 10 ; a ++ ) {
            if ( A[idx] != '?' && A[idx] != (a+'0')) continue;
            if ( A.length() > 1 && idx == A.length() - 1 && a == 0 ) continue; // zero padding
            va.push_back(a);
        }
    }
    if ( idx >= B.length() ) vb.push_back(0);
    else {
        for ( int b = 0 ; b < 10 ; b ++ ) {
            if ( B[idx] != '?' && B[idx] != (b+'0')) continue;
            if ( B.length() > 1 && idx == B.length() - 1 && b == 0 ) continue;
            vb.push_back(b);
        }
    }

    for ( int c = 0 ; c < 10 ; c ++ ) {
        if ( C[idx] != '?' && C[idx] != (c+'0')) continue;
        if ( C.length() > 1 && idx == C.length() - 1 && c == 0 ) continue;

        for ( auto a: va) {
            for (auto b: vb ) {
                if ( a + b + needCarry == c + 10 * hasCarry) {
                    candinates.emplace_back(a, b, c);
                }
            }
        }
    }
}

void process() {

    int idx;
    int hasCarry ;
    int needCarry;
    vector<Candidate> candidates ;

    for ( idx = 0 ; idx < C.length() ; idx ++ ) {
        for ( needCarry = 0 ; needCarry < 2 ; needCarry ++ ) {
            if ( idx == 0 && needCarry ) continue; // first digit
            if ( idx > 0 && D[idx-1][needCarry].empty()) continue;

            for ( hasCarry = 0 ; hasCarry < 2 ; hasCarry ++ ) {
                if ( idx == C.length() - 1 && hasCarry ) continue; // last digit

                generate_candidates(idx, needCarry, hasCarry, candidates);

                for (auto &candi : candidates ) {
                    Result sol = idx == 0 ? Result() : D[idx-1][needCarry] ;
                    sol.push(candi);
                    D[idx][hasCarry] = max(D[idx][hasCarry], sol);
                }
            }
        }
    }
}
bool check(Result &ret) {
    if ( ret.a.length() != A.length()) return false ;
    if ( ret.b.length() != B.length()) return false ;
    if ( ret.c.length() != C.length()) return false ;

    return true;
}
int main()
{
    fastio;
    input();

    process();

    auto ret = max(D[C.length()-1][0], D[C.length()-1][1]);
    if ( check(ret) ) {
        auto &o = ret;
        o.rev();
        cout << o.a << '+' << o.b << '=' << o.c << '\n';
    }
    else {
        cout << "-1\n";
    }
    return 0;
}