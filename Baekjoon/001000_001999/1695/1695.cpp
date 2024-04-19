#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MaxN (5000)

int D[MaxN][MaxN];
int A[MaxN];
int F(int l, int r) {
    if ( l >= r ) return 0;
    if ( l + 1 == r ) return A[l] == A[r] ? 0 : 1;
    auto &ret = D[l][r];
    if ( ret < 0 ) {
        if ( A[l] == A[r] )
            ret = F(l+1, r-1);
        else
            ret = 1 + min(F(l+1, r), F(l, r-1));
    }
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, i ;

    memset(D, -1, sizeof(D));

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) cin >> A[ i ] ;

    cout << F (0, N-1);

    return 0;
}


