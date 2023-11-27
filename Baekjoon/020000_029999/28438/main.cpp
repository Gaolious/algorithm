#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N, M, Q;
    int k, r, v;
    int i, j;
    cin >> N >> M >> Q ;

    vector<ll> R(N, 0), C(M, 0);
    while (Q--){
        cin >> k >> r >> v ;
        r --;
        if ( k == 1 ) R[r] += v;
        else if ( k == 2 ) C[r] += v;
    }

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ )
            cout << R[i] + C[j] << ' ';
        cout << '\n';
    }
    return 0;
}


