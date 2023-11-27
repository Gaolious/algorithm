#include <bits/stdc++.h>
#define fastio do {cout.tie(0);cin.tie(0)->sync_with_stdio(0);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 1000000007L;
#ifdef AJAVA_DEBUG
const int MaxN = 20;
#else
const int MaxN = 1'000'000;
#endif
ll F[MaxN + 3];
ll A[MaxN + 3];

int main()
{
    fastio;
    int N, Q, i, l, r;
    F[1] = F[2] = 1L ;
    for ( i = 3 ; i <= MaxN ; i ++ )
        F[i] = (F[i-1] + F[i-2]) % MOD ;

    cin >> N ;
    cin >> Q ;
    while ( Q-- ) {
        cin >> l >> r ;
        A[l] ++;
        A[r+1] -= F[r-l+2];
        A[r+2] -= F[r-l+1];
    }
    for ( i = 1 ; i <= N ; i ++ ) {
        cout << A[i] << ' ';
        A[i+1] = ((A[i+1] + A[i-1] + A[i]) % MOD + MOD )%MOD;
    }
    return 0;
}


