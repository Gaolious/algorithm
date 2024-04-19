#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int INF = 100000000 ;

int main()
{
    fastio;
    int N ;
    int i, j, k;
    int MaxMask;
    int ret = INF, s;
    int R[20]{}, C[20]{};

    cin >> N ;
    MaxMask = (1 << (N-1) ) - 1 ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> k;
            R[i] += k;
            C[j] += k;
        }
    }

    for ( i = 0 ; i < MaxMask; i ++ ) {
        s = 0;
        for ( j = 0 ; j < N ; j ++ )
            s += ( (i>>j) & 1 ? 1 : -1) * (R[j] + C[j]);
        ret = min( ret, abs(s/2));
    }
    cout << ret << '\n';
    return 0;
}


