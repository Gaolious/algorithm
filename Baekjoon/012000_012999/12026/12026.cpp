#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int D[1000];
int N ;
string S;
const int INF = 1000000000;
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;

    cin >> N >> S;

    for ( i = 0 ; i <N ; i ++ ) D[ i ] = INF;

    D[0] = 0;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = i + 1 ; j < N ; j++ ) {
            if ( S[i] == 'B' && S[j] != 'O' ) continue;
            if ( S[i] == 'O' && S[j] != 'J' ) continue;
            if ( S[i] == 'J' && S[j] != 'B' ) continue;
            D[j] = min(D[j], D[i] + (j-i)*(j-i));
        }

    if ( D[N-1] >= INF )
        cout << "-1\n";
    else
        cout << D[N-1] << '\n';
    return 0;
}


