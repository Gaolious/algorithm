#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MAXN (15)
int Cost[MAXN+1][MAXN+1]={0,};
int D[0x7fff+1][MAXN+1];

vector<int> Mask[MAXN+1];
#define NTH(x) ( (1 << ( (x)-1) ) )

int main()
{
    fastio;
    int i, j;
    char c ;
    int N ;
    int from, to ;

    cin >> N ;

    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ ) {
            cin >> c ;
            Cost[i][j] = c - '0';
        }
    for ( i = 1 ; i < 1 << N ; i ++ )
        Mask[__builtin_popcount(i)].push_back(i);

    memset(D, -1, sizeof(D));

    D[1][1] = 0;
    int ret = 1;

    for ( i = 1 ; i < N ; i ++ ) {
        for (auto mask: Mask[i] ) {
            for ( from = 1 ; from <= N ; from ++ ) {
                if ( !(NTH(from) & mask ) ) continue;
                if ( D[mask][from] < 0 ) continue;

                for ( to = 1 ; to <= N ; to ++ ) {
                    if ( (NTH(to) & mask ) ) continue;
                    if ( D[mask | NTH(to) ][from] > Cost[from][to]) continue;

                    if ( D[mask|NTH(to)][to] < 0 || D[mask|NTH(to)][to] > Cost[from][to]) {
                        D[mask|NTH(to)][to] = Cost[from][to];
                        ret = max(ret, i+1);
#ifdef AJAVA_DEBUG
                    }
                }
            }
        }
    }
    cout << ret;
    return 0;
}


