#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll D[1000001];

int main()
{
    fastio;
    int T, n ;
    int i, j;

    for ( i = 1 ; i <= 1000000 ; i ++ ) {
        for (j=i ; j <= 1000000 ; j += i )
            D [ j ] += i;
        D[ i ] += D[i-1];
    }
    cin >> T;
    while (T -- ) {
        cin >> n ;
        cout << D[n] << '\n';
    }
    return 0;
}


