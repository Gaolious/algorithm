#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    ll k, a, b, c, d;
    cin >> k >> a >> b >> c >> d ;
    if ( a*k+b == c*k+d ) {
        cout << "Yes " << a*k+b << '\n';
    }
    else
        cout << "No" << '\n';
    return 0;
}


