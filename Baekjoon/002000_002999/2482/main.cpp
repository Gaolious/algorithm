#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 1000;
const int MOD = 1'000'000'003;

int Data[3][MaxN+1]={0,};
#define D(i,j) Data[ ( (i) + 3 ) % 3 ][ (j) ]

int main()
{
    fastio;
    int N, K;
    int i, j;
    cin >> N >> K;
    D(0, 0) = D(1,0) = D(1, 1) = 1;
    for ( i = 2 ; i < N ; i ++ ) {
        D(i, 0) = 1;

        for ( j = 1 ; j*2-1 <= i ; j ++ ) {
            D(i, j) = (D(i-2, j-1) + D(i-1, j)) % MOD;
        }
    }
    cout << ( D(N-1, K) + D(N-3, K-1) ) % MOD << '\n';

    return 0;
}

