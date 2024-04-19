#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define LEN(a, b, c) ( ( (a) + (b) )*( (a) + (b) ) + (c)*(c) )

int main()
{
    fastio;
    int T, i, s, ret;
    ll a, b, c, ans[3];
    cin >> T;
    while( T--) {
        cin >> a >> b >> c ;
        ans[0] = LEN(a,b,c);
        ans[1] = LEN(a,c,b);
        ans[2] = LEN(b,c,a);
        cout << min(min(ans[0], ans[1]), ans[2]) <<'\n';
    }
    return 0;
}


