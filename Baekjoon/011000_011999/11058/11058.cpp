#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll D[150+1];

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    int i, j ;

    cin >> N ;

    D[1] = 1;
    D[2] = 2;
    for ( i = 3 ; i <= N ; i ++ ) {
        D[i] = max(D[i], D[i-1] + 1);
        for ( j = 1 ; j <= 10 ; j ++ )
            D[i+j] = max(D[i+j], D[i-2] + D[i-2] * j);
    }
    cout << D[N];
    return 0;
}


