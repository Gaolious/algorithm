#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

const ll INF = 1ll << 32;

string S ;
ll calc(ll a, ll b, char o) {
    if ( o == '+') return a+b;
    return ( o == '-') ? a-b : a*b;
}
bool isNum(char c) { return '0' <= c && c <= '9'; }
char Equation[50];
int tail = 0;
ll best = -INF;
int level(char c) {
    switch (c) {
        case '+': case '-': return 1;
        case '*': return 2;
        case '(': case ')': return 3;
    }
}
ll calc() {
    stack<ll> num;
    stack<char> oper;
    char c;
    ll a, b;
    auto pop_and_push = [&] {
        b = num.top(); num.pop();
        a = num.top(); num.pop();
        num.push( calc(a, b, oper.top()));
        oper.pop();
    };

    for ( int i = 0 ; i < tail ; i ++ ) {
        c = Equation[i];
        if ( isNum(c) )
            num.push( c - '0' );
        else {
            switch (c) {
                case '+':
                case '-':
                case '*':
                    while (!oper.empty() && level(oper.top()) != 3 && level(oper.top()) >= level(c) )
                        pop_and_push();
                    oper.push(c);
                break;
                case '(':
                    oper.push(c);
                break;
                case ')':
                    while ( !oper.empty() && oper.top() != '(' )
                        pop_and_push();
                    oper.pop();
                break;
            }
        }
    }
    while ( !oper.empty() ) {
        b = num.top(); num.pop();
        a = num.top(); num.pop();
        num.push( calc(a, b, oper.top()));
        oper.pop();
    }
    return num.top();
}
void F(int idx, int openCnt) {
    if ( idx >= S.size() ) {
        if ( openCnt != 0 ) return;
        ll ans = calc();
        best = max(best,ans);
        // cout << Equation << " : " << ans << " / best = " << best << '\n';
        return;
    }

    if ( isNum(S[idx]) ) {
        if ( openCnt == 0 ) {
            Equation[tail++] = '(';
            Equation[tail++] = S[idx];
            F(idx+1, openCnt+1);
            Equation[--tail] = 0x00;
            Equation[--tail] = 0x00;
        }
        else if ( openCnt == 1 ) {
            Equation[tail++] = S[idx];
            Equation[tail++] = ')';
            F(idx+1, openCnt-1);
            Equation[--tail] = 0x00;
            Equation[--tail] = 0x00;
            return;
        }
    }
    Equation[tail++] = S[idx];
    F(idx+1, openCnt);
    Equation[--tail] = 0x00;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int n;

    cin >> n ;
    cin >> S ;
    F(0, 0);
    cout << best ;
    return 0;
}
