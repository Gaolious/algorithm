#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, i;
    long double a, b, c;
    int A[26]{};
    string s;
    stack<long double> S;
    cin >> N >> s ;
    for ( i = 0 ; i < N ; i ++ ) cin >> A[ i ] ;
    for ( auto c: s ) {
        switch (c) {
            case '+': b=S.top();S.pop(); a=S.top();S.pop(); S.push(a+b); break;
            case '-': b=S.top();S.pop(); a=S.top();S.pop(); S.push(a-b); break;
            case '*': b=S.top();S.pop(); a=S.top();S.pop(); S.push(a*b); break;
            case '/': b=S.top();S.pop(); a=S.top();S.pop(); S.push(a/b); break;
            default: S.emplace(A[c-'A']); break;
        }
    }
    cout << setprecision(2) << fixed << S.top() <<'\n';
    return 0;
}


