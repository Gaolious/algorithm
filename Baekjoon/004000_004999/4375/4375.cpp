#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N, ans, A;

    while ( cin >> N ) {
        if ( N < 0 ) break;
        for ( ans=1, A=1 ; ; A = A * 10 + 1, ans ++ ) {
            A %= N;
            if ( A == 0 ) break;
        }
        cout << ans << '\n';
    }
    return 0;
}


