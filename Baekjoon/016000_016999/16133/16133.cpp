#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

stack<char> opers;
stack<ll> nums;

bool isNum(char c) {
    return ( '0' <= c && c <= '9' );
}
int OP(char c) {
    switch (c) {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^' : return 3;
        case '#' : return 4;
        case '(' :
        case ')' : return 5;
    }
    return 0;
}
ll power(ll a, ll b) {
    if ( b == 0 ) return 1;
    if ( b == 1 ) return a;
    ll ret = 1, t;
    if ( b % 2 == 1) ret = a ;
    t = power(a, b/2);
    return ret * t * t ;
}
ll PopNum() {
    auto t = nums.top();
    nums.pop();
    return t;
}
char calc() {
    long double t;
    ll a, b;

    char c = opers.top();
    opers.pop();

    switch (c) {
        case '+' : {
            b = PopNum(); a = PopNum();
            nums.push(a + b);
#ifdef AJAVA_DEBUG
            cout << a << ' ' << c << ' ' << b << '=' << nums.top() << endl;
#endif
            break;
        }
        case '-' : {
            b = PopNum(); a = PopNum(); nums.push(a - b);
#ifdef AJAVA_DEBUG
            cout << a << ' ' << c << ' ' << b << '=' << nums.top() << endl;
#endif
            break;
        }
        case '*' : {
            b = PopNum(); a = PopNum(); nums.push(a * b);
#ifdef AJAVA_DEBUG
            cout << a << ' ' << c << ' ' << b << '=' << nums.top() << endl;
#endif
            break;
        }
        case '/' : {
            b = PopNum(); a = PopNum();
            t = (long double)a / b ;
            nums.push( (ll)( ( t < 0 ) ? ceil(t) : floor(t)) );
#ifdef AJAVA_DEBUG
            cout << a << ' ' << c << ' ' << b << '=' << nums.top() << endl;
#endif
            break;
        }
        case '^' : {
            b = PopNum(); a = PopNum();
            nums.push(power(a, b));
#ifdef AJAVA_DEBUG
            cout << a << ' ' << c << ' ' << b << '=' << nums.top() << endl;
#endif
            break;
        }
        case '#' : {
            a = PopNum();
            t = sqrt((long double)a);
            nums.push( (ll)( ( t < 0 ) ? ceil(t) : floor(t)) );
#ifdef AJAVA_DEBUG
            cout << "sqrt(" << a << ')' << nums.top() << endl;
#endif
            break;
        }
        case '(' :
        case ')' :
            break;
    }
    return c;
}
int main()
{
    fastio;
    string s ;
    ll n;

    cin >> s;

    int i = 0 ;
    for ( i = 0 ; i < s.length();  ) {
        if ( s[i] == '=') {
            break;
        }
        if ( isNum(s[i]) ) {
            for ( n = 0; i < s.length() && isNum(s[i]) ; i ++ )
                n = n * 10 + s[i] - '0';
            nums.push(n);
            continue;
        }

        if ( s[i] == ')' ) {
            while ( calc() != '(' );
            i++;
            continue;
        }
        while ( true ) {
            if ( opers.empty()) break;
            if ( opers.top() == '(') break;
            if ( OP(opers.top()) < OP(s[i]) ) break;
            if ( OP(opers.top()) == OP(s[i]) && OP(s[i]) != 2 && OP(s[i]) != 1 ) break;
            calc();
        }
        opers.push(s[i++]);
    }
    while ( !opers.empty() )
        calc();

    cout << nums.top() << '\n';
    return 0;
}


