#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<vector<int>> D;
vector<int> A;
int K ;

int S(int n) {
    return n-K < 0 ? 0 : A[n] - A[n-K];
}

int F(int y, int x) {
    if ( y < 0 || (y+1)*K > x ) return 0;
    auto &ret = D[y][x];
    if ( ret < 0 )
        ret = max( F(y, x-1), S(x) + F(y-1, x-K));
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, i;
    cin >> N ;
    D.resize(3, vector<int>(N+1, -1));
    A.resize(N+1, 0);
    for ( i = 0 ; i < 3 ; i ++ ) D[i][0] = 0;
    for ( i = 1 ; i <= N ; i ++ ) { cin >> A[i]; A[i] += A[i-1]; }
    cin >> K ;
    cout << F(2, N) << '\n';
    return 0;
}


