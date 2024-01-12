#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MAXN (15)
int Cost[MAXN+1][MAXN+1]={0,};
int D[0x7fff+1][MAXN+1][11];
const int INF = 1e7 ;
int N ;
#define NTH(x) ( (1 << ( (x)-1) ) )

int F(int mask, int owner, int cost) {
    if ( mask == ( 1 << N ) - 1 )
        return 1;

    if ( D[mask][owner][cost] < 0 ) {
        int ret = 1;
        for ( int to = 2 ; to <= N ; to ++ ) {
            if ( mask & NTH(to) ) continue;
            if ( Cost[owner][to] < cost ) continue;
            ret = max(ret, F(mask | NTH(to), to, Cost[owner][to] ) + 1);
        }
        D[mask][owner][cost] = ret;
    }
    return D[mask][owner][cost];
}
int main()
{
    fastio;
    int i, j;
    char c ;

    cin >> N ;

    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ ) {
            cin >> c ;
            Cost[i][j] = c - '0';
        }

    memset(D, -1, sizeof(D));
    cout << F(1, 1, 0) << '\n';

    return 0;
}


