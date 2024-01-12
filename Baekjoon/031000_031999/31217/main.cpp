#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 200000;
int A[MaxN+1];
const int MOD = 1000000007;

int main()
{
    fastio;
    int n, m ;
    int i , a, b;
    cin >> n >> m ;
    for ( i = 0 ; i < m ; i ++ ) {
        cin >> a >> b ;
        A[a] ++;
        A[b] ++;
    }
    int ret = 0;

    for ( i = 1 ; i <= n ; i ++ ) {
        ret += A[i] * (A[i]-1) * (A[i]-2) / 6;
        ret %= MOD ;
    }
    cout << ret ;
    return 0;
}


