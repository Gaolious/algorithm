#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int T;
    ll n ;

    cin >> T ;
    while ( T-- ) {
        cin >> n ;
        cout << (n>=3 ? 3 : 1) << '\n';
    }
    return 0;
}


